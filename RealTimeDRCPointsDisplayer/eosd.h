#pragma once

#include "drc_assets.h"

namespace ns_eosd
{
	// Global variables
	bool reset;
	char character, type, difficulty, misses_deathbombs, bombs, real_misses, false_misses = 0, _misses_deathbombs, _bombs;
	ull score;
	std::string shottype;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	char firstBomb, bomb;
	float exp, exp_s;
	char frame_count;	// used when a deathbomb is performed

	// character index
	const char* idx_character[] = { "Reimu", "Marisa" };
	// type index
	const char* idx_type[] = { "A", "B" };

	void getShottype()
	{
		shottype = idx_character[character];
		shottype += idx_type[type];
		std::cout << "Shottype: " << shottype << std::endl;
	}

	void getRubrics()
	{
		std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;
		getSurvRubrics("EoSD", idx_difficulty[difficulty], base, exp, firstBomb, bomb);
		getScoreRubrics("EoSD", idx_difficulty[difficulty], base_s, exp_s);
	}

	void countMisses()
	{
		// deathbomb case
		if (misses_deathbombs > _misses_deathbombs || frame_count > 0)	// when a miss or a deathbomb is performed, frame_count starts counting
			frame_count++;
		if (bombs > _bombs && frame_count > 0 && frame_count < 5)	// this is true if a deathbomb is performed within 0.5 second
		{
			false_misses++;
			frame_count = 0;	// reset frame_count
		}
		if (frame_count >= 5)	// this is a normal miss
			frame_count = 0;	// reset frame count

		_misses_deathbombs = misses_deathbombs;
		_bombs = bombs;

		real_misses = misses_deathbombs - false_misses;
	}

	void calculateDRCPoints()
	{
		char n = 0;
		n += real_misses * 2;	// 2 is rubric miss base in any difficulty
		if (bombs > 0)
		{
			n += firstBomb;
			bombs--;
		}
		n += bombs * 1;	// 1 is rubric bombs base in any difficulty
		drcpoints_survival = base * pow(exp, (0 - n)) * getMultiplier("EoSD", shottype.c_str());

		ull wr = getWR<ull>("EoSD", idx_difficulty[difficulty], shottype.c_str());
		drcpoints_score = (score >= wr) ? roundf(base_s) : roundf(base_s * (float)pow((long double)score / wr, exp_s));
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			CHARACTER = 0x0069D4BD,
			TYPE = 0x0069D4BE,
			DIFFICULTY = 0x0069BCB0,
			SCORE = 0x0069BCA0,
			MISS_DEATHBOMB = 0x0069BCC0,
			BOMB = 0x0069BCC4
		};

		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)MISS_DEATHBOMB, &misses_deathbombs, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)BOMB, &bombs, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);

		// reset false miss
		if (score == 0 && reset)
		{
			false_misses = 0;
			reset = false;
		}
		if (score > 0)
			reset = true;

		getRubrics();
		getShottype();

		countMisses();
		
		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(real_misses) << std::endl;
		// std::cout << "Misses + Deathbomb: " << int(misses_deathbombs) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bombs) << std::endl;
		setcolor(WHITE);
		std::cout << "Score: " << score << std::endl;

		calculateDRCPoints();

		setcolor(LIGHTGRAY);
		std::cout << "DRC points for survival: " << (int)drcpoints_survival << std::endl;
		std::cout << "DRC points for scoring: " << (int)drcpoints_score << std::endl;
	}
}
