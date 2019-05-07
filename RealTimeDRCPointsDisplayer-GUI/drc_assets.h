#pragma once

#include "ProcessJSON.h"
#include <iostream>

// Global drc points for both categories
float drcpoints_survival, drcpoints_scoring;

// game index (global)
const char* idx_game[] = { "HRtP", "SoEW", "PoDD", "LLS", "MS", "EoSD", "PCB", "IN", "PoFV", "MoF", "SA", "UFO", "GFW", "TD", "DDC", "LoLK", "HSiFS", "WBaWC" };

// difficulty index (global)
const char* idx_difficulty[] = { "Easy", "Normal", "Hard", "Lunatic", "Extra", "Phantasm" };

// Global variables
uint8_t game, character, type, difficulty;
int8_t misses, bombs;
std::string shottype;
uint64_t score;

// misses and bombs variables
float miss; uint8_t firstBomb, bomb;
// survival variables
uint16_t surv_base; float surv_exp;
// scoring variables
uint16_t score_base; float score_exp;

// Variables for PCB
uint8_t border_breaks;

// Variables for IN
uint8_t last_spells_captured, stage;
// unsigned int timer;

// Variables for Phantasmagorias
uint8_t min, lives, no_bomb_bonus; bool no_charge;

// Variables for UFO
uint8_t ufos, ufos_red, ufos_green, ufos_blue, ufos_rainbow;

// Variables for TD
uint16_t spirits; uint8_t trances;

// Variables for HSiFS
uint16_t releases;

// Variables for WBaWC
uint16_t wolves, otters, eagles, roar_breaks;

// Rubric variables
uint8_t season, first_release; float release;

// Used for resetting information
DWORD frame_count;

// reset status
bool reset()
{
	if (frame_count <= 0x0F && score == 0)
		return true;
	return false;
}

// get multiplier for shottype / route
float getMultiplier(const char* game, const char* shottype_route)
{
	if (keyExist(Rubrics["SURV"][game]["multiplier"], shottype_route))
	{
		return Rubrics["SURV"][game]["multiplier"][shottype_route].get<float>();
	}
	else
		return 1.0f;
}

// get rubrics for survival
void getSurvRubrics()
{
	if (strcmp(idx_game[game], "PoDD") != 0 && strcmp(idx_game[game], "PoFV") != 0)
	{
		surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<uint16_t>();
		surv_exp = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
		miss = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["miss"].get<float>();
		firstBomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["firstBomb"].get<uint8_t>();
		bomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["bomb"].get<uint8_t>();
	}
	else
	{
		surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<uint16_t>();
		min = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["min"].get<uint8_t>();
		lives = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["lives"].get<uint8_t>();
		no_bomb_bonus = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["noBombBonus"].get<uint8_t>();
	}
}

// get rubrics for scoring
void getScoreRubrics()
{
	score_base = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<uint16_t>();
	score_exp = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
}

void getRubrics()
{
	getSurvRubrics();
	// scoring rubric for MoF is in mofFormula
	if (strcmp(idx_game[game], "MoF") != 0)
		getScoreRubrics();
}

// calculate points for Phantasmagorias
void phantasmagoria()
{
	float shottypeMultiplier = getMultiplier(idx_game[game], shottype.c_str());
	if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
		shottypeMultiplier = 1.0f;

	drcpoints_survival = roundf(shottypeMultiplier * ((surv_base - ((surv_base - min) / lives * misses)) + (no_charge ? no_bomb_bonus : 0) ));
}

// calculate points for normal game format
void survivalPoints()
{
	float n = 0;
	// make a copy of bombs
	uint8_t _bombs = bombs;

	n += misses * miss;
	if (bombs > 0)
	{
		n += firstBomb;
		_bombs--;
	}
	n += _bombs * bomb;

	if (strcmp(idx_game[game], "PCB") == 0)
	{
		n += border_breaks * bomb;
	}

	if (strcmp(idx_game[game], "TD") == 0)
	{
		n += trances * bomb;
	}

	if (strcmp(idx_game[game], "HSiFS") == 0)
	{
		float decrement = 0;
		// make a copy of releases
		uint16_t _releases = releases;

		if (releases > 0)
		{
			n += first_release;
			_releases--;
		}
		while (_releases > 0)
		{
			for (uint8_t i = 0; i < 10; i++)
			{
				n += release - decrement;
				_releases--;
				if (_releases == 0)
					break;
			}
			decrement += (decrement == 0.4f) ? 0 : 0.1f;
		}
	}

	drcpoints_survival = surv_base * pow(surv_exp, -n);

	if (strcmp(idx_game[game], "IN") == 0)
	{
		if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
		{
			drcpoints_survival += (last_spells_captured == 1) ? 5 : 0;
		}
		else
		{
			drcpoints_survival += last_spells_captured * ((strcmp(idx_difficulty[difficulty], "Easy") == 0) ? 1 : 2);
		}
	}

	if (strcmp(idx_difficulty[difficulty], "Extra") != 0 && strcmp(idx_difficulty[difficulty], "Phantasm") != 0 && !(strcmp(idx_game[game], "LoLK") == 0 && bombs > 0)) 
	{
		drcpoints_survival = drcpoints_survival * getMultiplier(idx_game[game], shottype.c_str());
	}
}

std::string removeSeason(std::string shottype)
{
	const char* season[] = { "Spring", "Summer", "Autumn", "Winter" };
	for (uint8_t i = 0; i < 4; i++)
	{
		size_t pos = shottype.find(season[i]);
		if (pos != std::string::npos)
		{
			shottype.erase(pos, 6);
		}
	}
	return shottype;
}

std::string bestSeason()
{
	const char* idx_character[] = { "Reimu", "Cirno", "Aya", "Marisa" };
	std::string season;
	uint64_t _wr_max = 0;
	for (json::iterator it = WRs["HSiFS"][idx_difficulty[difficulty]].begin(); it != WRs["HSiFS"][idx_difficulty[difficulty]].end(); it++)
	{
		std::string _shottype = it.key();
		if (_shottype.find(idx_character[character]) == std::string::npos)
		{
			continue;
		}

		uint64_t _wr = WRs["HSiFS"][idx_difficulty[difficulty]][_shottype][0].get<uint64_t>();
		if (_wr > _wr_max)
		{
			season = _shottype.substr(strlen(idx_character[character]));
			_wr_max = _wr;
		}
	}

	return season;
}

void scoringPoints()
{
	uint64_t wr;
	if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]], "basedOn"))
	{
		std::string basedOn = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["basedOn"].get<std::string>();
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][basedOn][0].get<uint64_t>();
	}
	else if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]], "wr"))
	{
		if (Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].is_object())
		{
			if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"], shottype.c_str()))
			{
				wr = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"][shottype].get<uint64_t>();
			}
			else // consider this case as a normal one
			{
				std::string _shottype = removeSeason(shottype);
				_shottype += (strcmp(idx_game[game], "HSiFS") == 0) ? bestSeason() : "";
				wr = WRs[idx_game[game]][idx_difficulty[difficulty]][_shottype][0].get<uint64_t>();
			}
		}
		else
		{
			wr = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].get<uint64_t>();
		}
	}
	else
	{
		std::string _shottype = removeSeason(shottype);
		_shottype += (strcmp(idx_game[game], "HSiFS") == 0) ? bestSeason() : "";
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][_shottype][0].get<uint64_t>();
	}

	drcpoints_scoring = (score >= wr) ? score_base : score_base * (float)pow((long double)score / wr, score_exp);
}

void mofFormula()
{
	// Set point to 0 for increment
	drcpoints_scoring = 0;

	// rubric currently only determined for Easy, Lunatic ReimuB and Lunatic MarisaC
	if (strcmp(idx_difficulty[difficulty], "Easy") != 0 && strcmp(idx_difficulty[difficulty], "Lunatic") != 0)
	{
		drcpoints_scoring = -1.0f;
		return;
	}
	else if (strcmp(idx_difficulty[difficulty], "Lunatic") == 0 && shottype != "ReimuB" && shottype != "MarisaC")
	{
		drcpoints_scoring = -1.0f;
		return;
	}

	// Get scoring rubric
	json thresholds = Rubrics["MOF_THRESHOLDS"][idx_difficulty[difficulty]][shottype];

	if (score < thresholds["score"][0])
	{
		drcpoints_scoring = (float)pow(((long double)score / thresholds["score"][0].get<uint64_t>()), 2) * ((strcmp(idx_difficulty[difficulty], "Easy") == 0) ? 220 : 200);
		return;
	}

	drcpoints_scoring = thresholds["base"][0].get<float>();

	for (int i = thresholds["increment"].size() - 1; i >= 0; i--)
	{
		float increment = thresholds["increment"][i].get<float>();
		uint32_t step = thresholds["step"][i].get<uint32_t>();

		while (score - step >= thresholds["score"][i])
		{
			drcpoints_scoring += increment;
			score -= step;
		}
	}
	
	drcpoints_scoring = min(drcpoints_scoring, ((strcmp(idx_difficulty[difficulty], "Easy") != 0) ? 375 : 500));
}

// calculating DRC points for survival and scoring
void calculateDRCPoints()
{
	if (strcmp(idx_game[game], "PoDD") != 0 && strcmp(idx_game[game], "PoFV") != 0)
		survivalPoints();
	else
		phantasmagoria();
	
	if (strcmp(idx_game[game], "MoF") == 0)
		mofFormula();
	else
		scoringPoints();
}

/*

// print status
{
	setcolor(LIGHTGRAY);
	std::cout << "Game: " << idx_game[game] << std::endl;
	std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;

	// print route instead of shottype if it's GFW and it's not Extra
	if (idx_game[game] == "GFW")
	{
		if (idx_difficulty[difficulty] != "Extra")
			std::cout << "Route: " << shottype << std::endl;
	}
	else
	{
		std::cout << "Shottype: " << shottype << std::endl;
	}

	setcolor(LIGHTRED);
	std::cout << "Misses: " << int(misses) << std::endl;
	setcolor(LIGHTGREEN);
	if (idx_game[game] != "PoDD" && idx_game[game] != "PoFV")
	{
		std::cout << "Bombs: " << int(bombs) << std::endl;
	}
	else
	{
		std::cout << "No Charge: " << (noCharge ? "True" : "False") << std::endl;
	}

	// Print Border Breaks (PCB only)
	if (idx_game[game] == "PCB")
	{
		setcolor(LIGHTMAGENTA);
		std::cout << "Border Breaks: " << (int)borderBreaks << std::endl;
	}
	
	// Print UFO summons (UFO only)
	if (idx_game[game] == "UFO")
	{
		setcolor(YELLOW);
		std::cout << "UFO Summons: " << (int)ufos << std::endl;
	}
	// Print Trances (TD only)
	if (idx_game[game] == "TD")
	{
		setcolor(LIGHTMAGENTA);
		std::cout << "Trances: " << (int)trances << std::endl;
	}
	// Print Releases (HSiFS only)
	if (idx_game[game] == "HSiFS")
	{
		setcolor(YELLOW);
		std::cout << "Releases: " << (int)releases << std::endl;
	}
	setcolor(WHITE);
	std::cout << "Score: " << score << std::endl;

	// Print IN extra status
	if (idx_game[game] == "IN")
	{
		setcolor(LIGHTGRAY);
		printFinalStage();
	}

	setcolor(LIGHTGRAY);
	std::cout << "Survival points: " << drcpoints_survival << std::endl;
	std::cout << "Scoring points: " << drcpoints_scoring << std::endl;

	// Print UFO specific ufos
	if (idx_game[game] == "UFO")
	{
		std::cout << std::endl;
		setcolor(LIGHTRED);
		std::cout << "Red UFOs: " << (int)ufos_red << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Green UFOs: " << (int)ufos_green << std::endl;
		setcolor(LIGHTBLUE);
		std::cout << "Blue UFOs: " << (int)ufos_blue << std::endl;
		setcolor(YELLOW);
		std::cout << "Rainbow UFOs: " << (int)ufos_rainbow << std::endl;
	}

	// reset text color
	setcolor(LIGHTGRAY);
}

*/
