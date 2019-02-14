#pragma once

#include "drc_assets.h"

namespace ns_lolk
{
	// mode in LoLK
	char mode;
	// variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sanae", "Reisen" };

	void getShottype()
	{
		shottype = idx_character[character];
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
			FRAME_COUNT = 0x004E73FC,
			SCORE = 0x004E740C,
			CHARACTER = 0x004E7404,
			MODE = 0x004E7795,
			DIFFICULTY = 0x004E7410,
			MISSES = 0x004E742C,
			P_IS_BOMB = 0x004E9A68,
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(misses), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x24), &is_bomb, sizeof(is_bomb), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			bombs = 0;
		}

		getShottype();
		getRubrics();

		countBombs();

		
	}
}
