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

// get world record
template <typename T>
T getWR(const char* game, const char* difficulty, const char* shottype_route)
{
	return WRs[game][difficulty][shottype_route][0].get<T>();
}

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
void getSurvRubrics(const char* game, const char* difficulty, unsigned short &base, float &exp, char &firstBomb, char &bomb)
{
	base = Rubrics["SURV_RUBRICS"][game][difficulty]["base"].get<unsigned short>();
	exp = Rubrics["SURV_RUBRICS"][game][difficulty]["exp"].get<float>();
	firstBomb = Rubrics["SURV_RUBRICS"][game][difficulty]["firstBomb"].get<char>();
	bomb = Rubrics["SURV_RUBRICS"][game][difficulty]["bomb"].get<char>();
}

// get rubrics for survival, exclusively for PoDD and PoFV
void getSurvRubrics(const char* game, const char* difficulty, unsigned short &base, char &min, char &lives, char &noBombBonus)
{
	base = Rubrics["SURV_RUBRICS"][game][difficulty]["base"].get<unsigned short>();
	min = Rubrics["SURV_RUBRICS"][game][difficulty]["min"].get<char>();
	lives = Rubrics["SURV_RUBRICS"][game][difficulty]["lives"].get<char>();
	noBombBonus = Rubrics["SURV_RUBRICS"][game][difficulty]["noBombBonus"].get<char>();
}

// get rubrics for survival, exclusively for HSiFS
void getSurvRubrics(const char* game, const char* difficulty, unsigned short &base, float &exp, char &firstBomb, char &bomb, char &firstRelease)
{
	base = Rubrics["SURV_RUBRICS"][game][difficulty]["base"].get<unsigned short>();
	exp = Rubrics["SURV_RUBRICS"][game][difficulty]["exp"].get<float>();
	firstBomb = Rubrics["SURV_RUBRICS"][game][difficulty]["firstBomb"].get<char>();
	firstRelease = Rubrics["SURV_RUBRICS"][game][difficulty]["firstRelease"].get<char>();
}

// get rubrics for scoring
void getScoreRubrics(const char* game, const char* difficulty, unsigned short &base, float &exp)
{
	base = Rubrics["SCORE_RUBRICS"][game][difficulty]["base"].get<unsigned short>();
	exp = Rubrics["SCORE_RUBRICS"][game][difficulty]["exp"].get<float>();
}
