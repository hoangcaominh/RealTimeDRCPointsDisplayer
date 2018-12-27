#pragma once

#include "ProcessJSON.h"

// unsigned long long for convenience
typedef unsigned long long ull;

// unsigned long for convenience (PC-98 only)
typedef unsigned long ul;

// Global drc points for both categories
float drcpoints_survival, drcpoints_score;

// game index (global)
const char* idx_game[] = { "HRtP", "SoEW", "PoDD", "LLS", "MS", "EoSD", "PCB", "IN", "PoFV", "MoF", "SA", "UFO", "GFW", "TD", "DDC", "LoLK", "HSiFS" };

// difficulty index (global)
const char* idx_difficulty[] = { "Easy", "Normal", "Hard", "Lunatic", "Extra", "Phantasm" };

// Global variables
static char game, character, type, difficulty, misses, bombs;
static std::string shottype;
static ull score;

// misses and bombs variables
static float miss; static char firstBomb, bomb;
// survival variables
unsigned short surv_base; float surv_exp;
// scoring variables
unsigned short score_base; float score_exp;

// Variables for IN
char ls_capped;

// Variables for HSiFS
static unsigned short releases;
// Rubric variables
char season, firstRelease; float release;

// Used for resetting information
DWORD frame_count;

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
	surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	surv_exp = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
	miss = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["miss"].get<float>();
	firstBomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["firstBomb"].get<char>();
	bomb = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["bomb"].get<char>();
}

/*
// get rubrics for survival, exclusively for PoDD and PoFV
void getSurvRubrics()
{
	surv_base = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["surv_base"].get<unsigned short>();
	min = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["min"].get<char>();
	lives = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["lives"].get<char>();
	noBombBonus = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["noBombBonus"].get<char>();
}
*/

// get rubrics for scoring
void getScoreRubrics()
{
	score_base = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	score_exp = Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
}

void getRubrics()
{
	getSurvRubrics();
	getScoreRubrics();
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

	/* PCB is not implemented yet 
	if (idx_game[game] == "PCB")
	{
		n += borderBreaks * bomb;
	}
	*/

	if (idx_game[game] == "HSiFS")
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

	drcpoints_survival = roundf(surv_base * pow(surv_exp, -n));

	if (idx_game[game] == "IN")
	{
		if (idx_difficulty[difficulty] == "Extra")
		{
			drcpoints_survival += (ls_capped == 1) ? 5 : 0;
		}
		else
		{
			drcpoints_survival += ls_capped * (idx_difficulty[difficulty] == "Easy") ? 1 : 2;
		}
	}

	if (idx_difficulty[difficulty] != "Extra" && idx_difficulty[difficulty] != "Phantasm")
	{
		drcpoints_survival = roundf(drcpoints_survival * getMultiplier(idx_game[game], shottype.c_str()));
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
		wr = (Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].is_object())
			? Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"][shottype].get<ull>()
			: Rubrics["SCORE"][idx_game[game]][idx_difficulty[difficulty]]["wr"].get<ull>();
	}
	else
	{
		std::string _shottype = removeSeason(shottype);
		_shottype += (idx_game[game] == "HSiFS") ? bestSeason() : "";
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][_shottype][0].get<ull>();
	}

	drcpoints_score = (score >= wr) ? roundf(score_base) : roundf(score_base * (float)pow((long double)score / wr, score_exp));
}

// calculating DRC points for survival and scoring
void calculateDRCPoints()
{
	survivalPoints();
	scoringPoints();
}

// IN final section and last spell capture status
inline void printFinalStage(char stage)
{
	if (idx_difficulty[difficulty] == "Extra")
	{
		std::cout << "Imperishable Shooting Captured: " << ((ls_capped == 1) ? "True" : "False") << std::endl;
	}
	else
	{
		switch (stage)
		{
		case 6: // 6A
			std::cout << "Final: A" << std::endl;
			std::cout << "Last spells captured: " << int(ls_capped) << "/" << Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalA"] << std::endl;
			break;
		case 7:	// 6B
			std::cout << "Final: B" << std::endl;
			std::cout << "Last spells captured: " << int(ls_capped) << "/" << Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalB"] << std::endl;
			break;
		default:
			std::cout << "Final: ?" << std::endl;
			std::cout << "Last spells captured: " << int(ls_capped) << "/?" << std::endl;
			break;
		}
	}
}

// print status
void printStatus(int arg0 = 0)
{
	setcolor(LIGHTGRAY);
	std::cout << "Game: " << idx_game[game] << std::endl;
	std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;
	std::cout << "Shottype: " << shottype << std::endl;

	setcolor(LIGHTRED);
	std::cout << "Misses: " << int(misses) << std::endl;
	setcolor(LIGHTGREEN);
	std::cout << "Bombs: " << int(bombs) << std::endl;

	// Print Releases (HSiFS only)
	if (idx_game[game] == "HSiFS")
	{
		setcolor(YELLOW);
		std::cout << "Releases: " << arg0 << std::endl;
	}
	setcolor(WHITE);
	std::cout << "Score: " << score << std::endl;

	// Print IN extra status
	if (idx_game[game] == "IN")
	{
		setcolor(LIGHTGRAY);
		printFinalStage(arg0);
	}

	setcolor(LIGHTGRAY);
	std::cout << "Survival points: " << drcpoints_survival << std::endl;
	std::cout << "Scoring points: " << drcpoints_score << std::endl;
}
