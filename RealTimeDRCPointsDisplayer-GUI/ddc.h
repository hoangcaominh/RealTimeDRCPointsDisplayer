#pragma once

#include "drc_assets.h"

namespace ns_ddc
{
	// variables for manually counting misses
	char lives, _lives;

	// variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sakuya" };
	// type index
	const char* idx_type[] = { "A", "B" };

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
			P_IS_BOMB = 0x004DB52C,
			CHARACTER = 0x004F5828,
			TYPE = 0x004F582C,
			SCORE = 0x004F5830,
			DIFFICULTY = 0x004F5834,
			LIVES = 0x004F5864,
			FRAME_COUNT = 0x004F58B0
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(lives), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x40), &is_bomb, sizeof(is_bomb), 0);

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
