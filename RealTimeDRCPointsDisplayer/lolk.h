#pragma once

#include "drc_assets.h"

namespace ns_lolk
{
	// Global variables
	// used for resetting counters (reset to 0 when a new stage is loaded)
	DWORD frame_count;

	const char* shottype;
	char character, difficulty, misses, bombs, mode;
	ull score;
	// new variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	float exp, exp_s;
	char firstBomb, bomb, firstRelease;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sanae", "Reisen" };

	void getShottype()
	{
		shottype = idx_character[character];

		std::cout << "Shottype: " << shottype << std::endl;
	}

	void getRubrics()
	{
		std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;
		getSurvRubrics("LoLK", idx_difficulty[difficulty], base, exp, firstBomb, bomb);
		getScoreRubrics("LoLK", idx_difficulty[difficulty], base_s, exp_s);
	}

	void countBombs()
	{
		if (is_bomb && x_reset)	// player is bombing
		{
			bombs++;
			x_reset = false;
		}
		else if (!is_bomb)	// player is not bombing
		{
			x_reset = true;
		}
	}

	void calculateDRCPoints()
	{
		char n = 0;
		// make a copy if bombs used
		char _bombs = bombs;

		n += misses * 2;	// default is 2
		if (bombs > 0)
		{
			n += firstBomb;
			_bombs--;
		}
		n += _bombs * 1;	// default for bomb is 1

		drcpoints_survival = roundf(base * pow(exp, -n));
		if (idx_difficulty[difficulty] != "Extra")
		{
			drcpoints_survival = roundf(drcpoints_survival * getMultiplier("LoLK", shottype));
		}

		ull wr = getWR<ull>("LoLK", idx_difficulty[difficulty], shottype);
		drcpoints_score = (score >= wr) ? roundf(base_s) : roundf(base_s * (float)pow((long double)score / wr, exp_s));
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			FRAME_COUNT = 0x004E73FC,
			SCORE = 0x004E740C,
			CHARACTER = 0x004E7404,
			MODE = 0x004E7795,
			DIFFICULTY = 0x004E7410,
			MISSES = 0x004E742C,
			P_IS_BOMB = 0x004E9A68,
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x24), &is_bomb, sizeof(bool), 0);

		score *= 10;
		if (frame_count == 0 && score == 0)
		{
			// initialize
			misses = 0;
			bombs = 0;
		}

		getShottype();
		getRubrics();

		countBombs();

		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(misses) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bombs) << std::endl;
		setcolor(WHITE);
		std::cout << "Score: " << score << std::endl;

		calculateDRCPoints();
		printDRCPoints();
	}
}
