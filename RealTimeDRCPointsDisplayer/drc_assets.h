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
char game, character, type, difficulty, misses, bombs;
std::string shottype;
ull score;
// Variables for IN
char ls_capped;
// Variables for HSiFS
char season, firstRelease;
float release;
unsigned short releases;
// Used for resetting information
DWORD frame_count;

// rubric structure for normal games
struct RUBRIC
{
	// misses and bombs variables
	char miss, firstBomb, bomb;
	// survival variables
	unsigned short base; float exp;
	// scoring variables
	unsigned short base_s; float exp_s;
} rubric;

// get multiplier for shottype / route
float getMultiplier(const char* game, const char* shottype_route)
{
	if (keyExist(Rubrics["SURV_RUBRICS"][game]["multiplier"], shottype_route))
	{
		return Rubrics["SURV_RUBRICS"][game]["multiplier"][shottype_route].get<float>();
	}
	else
		return 1.0f;
}

// get rubrics for survival
void getSurvRubrics()
{
	rubric.base = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	rubric.exp = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
	rubric.miss = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["miss"].get<char>();
	rubric.firstBomb = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["firstBomb"].get<char>();
	rubric.bomb = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["bomb"].get<char>();
}

/*
// get rubrics for survival, exclusively for PoDD and PoFV
void getSurvRubrics()
{
	rubric.base = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	rubric.min = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["min"].get<char>();
	rubric.lives = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["lives"].get<char>();
	rubric.noBombBonus = Rubrics["SURV_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["noBombBonus"].get<char>();
}
*/

// get rubrics for scoring
void getScoreRubrics()
{
	rubric.base_s = Rubrics["SCORE_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["base"].get<unsigned short>();
	rubric.exp_s = Rubrics["SCORE_RUBRICS"][idx_game[game]][idx_difficulty[difficulty]]["exp"].get<float>();
}

void getRubrics()
{
	setcolor(LIGHTGRAY);
	std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;
	getSurvRubrics();
	getScoreRubrics();
}

// calculate points for normal game format
void survivalPoints()
{
	float n = 0;
	// make a copy of bomb
	char _bombs = bombs;

	n += misses * rubric.miss;
	if (bombs > 0)
	{
		n += rubric.firstBomb;
		_bombs--;
	}
	n += _bombs * rubric.bomb;

	/* PCB is not implemented yet 
	if (idx_game[game] == "PCB")
	{
		n += borderBreaks * rubric.bomb;
	}
	*/

	if (idx_game[game] = "HSiFS")
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

	drcpoints_survival = roundf(rubric.base * pow(rubric.exp, -n));

	if (idx_game[game] == "IN")
	{
		unsigned short ls_points;
		switch (difficulty)
		{
		case 0:	// easy
			ls_points = ls_capped * 1;
			break;
		case 4:	// extra
			ls_points = ls_capped * 5;
			break;
		default:
			ls_points = ls_capped * 2;
			break;
		}

		drcpoints_survival += ls_points;
	}

	if (idx_difficulty[difficulty] != "Extra" && idx_difficulty[difficulty] != "Phantasm")
	{
		drcpoints_survival = roundf(drcpoints_survival * getMultiplier(idx_game[game], shottype.c_str()));
	}
}

std::string removeSeason()
{
	const char* idx_character[] = { "Reimu", "Cirno", "Aya", "Marisa" };
	return shottype.substr(0, strlen(idx_character[character]));
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
	if (idx_game[game] == "LoLK" && idx_difficulty[difficulty] == "Lunatic")
	{
		if (shottype == "Reimu")
		{
			wr = 2500000000;
		}
		else if (shottype == "Marisa")
		{
			wr = 2400000000;
		}
		else
		{
			wr = WRs[idx_game[game]][idx_difficulty[difficulty]][shottype][0].get<ull>();
		}
	}
	else if (idx_game[game] == "HSiFS" && idx_difficulty[difficulty] == "Hard")
	{
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]]["AyaAutumn"][0].get<ull>();
	}
	else
	{
		wr = WRs[idx_game[game]][idx_difficulty[difficulty]][removeSeason() + (idx_game[game] == "HSiFS" ? bestSeason() : "")][0].get<ull>();
	}

	drcpoints_score = (score >= wr) ? roundf(rubric.base_s) : roundf(rubric.base_s * (float)pow((long double)score / wr, rubric.exp_s));
}

// calculating DRC points for survival and scoring
void calculateDRCPoints()
{
	survivalPoints();
	scoringPoints();
}

// print DRC points
void printDRCPoints()
{
	setcolor(LIGHTGRAY);
	std::cout << "DRC points for survival: " << drcpoints_survival << std::endl;
	std::cout << "DRC points for scoring: " << drcpoints_score << std::endl;
}
