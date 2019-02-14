#pragma once

#include "drc_assets.h"

namespace ns_mof
{
	// variables for manually counting misses
	char lives, _lives;

	// variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa" };
	// type index
	const char* idx_type[] = { "A", "B", "C" };

	void getShottype()
	{
		shottype = idx_character[character];
		shottype += idx_type[type];
	}

	void countMisses()
	{
		if (lives == _lives - 1)	// miss
		{
			misses++;
		}
		_lives = lives;
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

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			P_IS_BOMB = 0x004776EC,
			SCORE = 0x00474C44,
			CHARACTER = 0x00474C68,
			TYPE = 0x00474C6C,
			LIVES = 0x00474C70,
			DIFFICULTY = 0x00474C74,
			FRAME_COUNT = 0x00474C88
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(lives), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x28), &is_bomb, sizeof(is_bomb), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			misses = 0;
			bombs = 0;
		}

		getShottype();
		getRubrics();

		countMisses();
		countBombs();

		
	}
}
