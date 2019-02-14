#pragma once

#include "ProcessJSON.h"
#include <iostream>

// unsigned long long for convenience
typedef unsigned long long ull;

// unsigned long for convenience (PC-98 only)
typedef unsigned long ul;

// Global drc points for both categories
float drcpoints_survival, drcpoints_scoring;

// game index (global)
const char* idx_game[] = { "HRtP", "SoEW", "PoDD", "LLS", "MS", "EoSD", "PCB", "IN", "PoFV", "MoF", "SA", "UFO", "GFW", "TD", "DDC", "LoLK", "HSiFS" };

// difficulty index (global)
const char* idx_difficulty[] = { "Easy", "Normal", "Hard", "Lunatic", "Extra", "Phantasm" };

// Global variables
char game, character, type, difficulty, misses, bombs;
std::string shottype;
ull score;

// misses and bombs variables
float miss; char firstBomb, bomb;
// survival variables
unsigned short surv_base; float surv_exp;
// scoring variables
unsigned short score_base; float score_exp;

// Variables for PCB
char borderBreaks;

// Variables for IN
char ls_capped, stage;

// Variables for Phantasmagorias
char min, lives, noBombBonus; bool noCharge;

// Variables for UFO
char ufos, ufos_red, ufos_green, ufos_blue, ufos_rainbow;

// Variables for TD
unsigned short spirits; char trances;

// Variables for HSiFS
unsigned short releases;
// Rubric variables
char season, firstRelease; float release;

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
		surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
		surv_exp = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
		miss = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["miss"].get<float>();
		firstBomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["firstBomb"].get<char>();
		bomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["bomb"].get<char>();
	}
	else
	{
		surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
		min = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["min"].get<char>();
		lives = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["lives"].get<char>();
		noBombBonus = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["noBombBonus"].get<char>();
	}
}

// get rubrics for scoring
void getScoreRubrics()
{
	score_base = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	score_exp = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
}

void getRubrics()
{
	getSurvRubrics();
	// scoring rubric for MoF is not ready yet
	if (strcmp(idx_game[game], "MoF") != 0)
		getScoreRubrics();
}

// calculate points for Phantasmagorias
void phantasmagoria()
{
	float shottypeMultiplier = getMultiplier(idx_game[game], shottype.c_str());
	if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
		shottypeMultiplier = 1.0f;

	drcpoints_survival = roundf(shottypeMultiplier * ((surv_base - ((surv_base - min) / lives * misses)) + (noCharge ? noBombBonus : 0) ));
}

// calculate points for normal game format
void survivalPoints()
{
	float n = 0;
	// make a copy of bombs
	char _bombs = bombs;

	n += misses * miss;
	if (bombs > 0)
	{
		n += firstBomb;
		_bombs--;
	}
	n += _bombs * bomb;

	if (strcmp(idx_game[game], "PCB") == 0)
	{
		n += borderBreaks * bomb;
	}

	if (strcmp(idx_game[game], "TD") == 0)
	{
		n += trances * bomb;
	}

	if (strcmp(idx_game[game], "HSiFS") == 0)
	{
		float decrement = 0;
		// make a copy of releases
		unsigned short _releases = releases;

		if (releases > 0)
		{
			n += firstRelease;
			_releases--;
		}
		while (_releases > 0)
		{
			for (int i = 0; i < 10; i++)
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
			drcpoints_survival += (ls_capped == 1) ? 5 : 0;
		}
		else
		{
			drcpoints_survival += ls_capped * ((strcmp(idx_difficulty[difficulty], "Easy") == 0) ? 1 : 2);
		}
	}

	if (strcmp(idx_difficulty[difficulty], "Extra") != 0 && strcmp(idx_difficulty[difficulty], "Phantasm") != 0)
	{
		drcpoints_survival = drcpoints_survival * getMultiplier(idx_game[game], shottype.c_str());
	}
}

std::string removeSeason(std::string shottype)
{
	const char* season[] = { "Spring", "Summer", "Autumn", "Winter" };
	for (size_t i = 0; i < 4; i++)
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
	ull _wr_max = 0;
	for (json::iterator it = WRs["HSiFS"][idx_difficulty[difficulty]].begin(); it != WRs["HSiFS"][idx_difficulty[difficulty]].end(); it++)
	{
		std::string _shottype = it.key();
		if (_shottype.find(idx_character[character]) == std::string::npos)
		{
			continue;
		}

		ull _wr = WRs["HSiFS"][idx_difficulty[difficulty]][_shottype][0].get<ull>();
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
	ull wr;
	if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]], "basedOn"))
	{
		std::string basedOn = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["basedOn"].get<std::string>();
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][basedOn][0].get<ull>();
	}
	else if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]], "wr"))
	{
		if (Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].is_object())
		{
			if (keyExist(Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"], shottype.c_str()))
			{
				wr = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"][shottype].get<ull>();
			}
			else // consider this case as a normal one
			{
				std::string _shottype = removeSeason(shottype);
				_shottype += (strcmp(idx_game[game], "HSiFS") == 0) ? bestSeason() : "";
				wr = WRs[idx_game[game]][idx_difficulty[difficulty]][_shottype][0].get<ull>();
			}
		}
		else
		{
			wr = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].get<ull>();
		}
	}
	else
	{
		std::string _shottype = removeSeason(shottype);
		_shottype += (strcmp(idx_game[game], "HSiFS") == 0) ? bestSeason() : "";
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][_shottype][0].get<ull>();
	}

	drcpoints_scoring = (score >= wr) ? score_base : score_base * (float)pow((long double)score / wr, score_exp);

	// not calculating MoF scoring points yet
	if (strcmp(idx_game[game], "MoF") == 0)
	{
		drcpoints_scoring = -1.0f;
	}
}

// calculating DRC points for survival and scoring
void calculateDRCPoints()
{
	if (strcmp(idx_game[game], "PoDD") != 0 && strcmp(idx_game[game], "PoFV") != 0)
		survivalPoints();
	else
		phantasmagoria();
	
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
