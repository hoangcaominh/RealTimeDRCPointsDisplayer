#pragma once

#include "drc_assets.h"

namespace ns_td
{
	// variables for manually counting misses
	char lives, _lives;

	// variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset, is_trance, trance_reset;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sanae", "Youmu" };

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

	void countTrances()
	{
		if (is_trance && trance_reset)
		{
			trances++;
			trance_reset = false;
		}
		else if (!is_trance)
		{
			if (lives == _lives - 1)
			{
				misses++;
				if (!trance_reset)
				{
					trances--;
				}
			}
			_lives = lives;
			trance_reset = true;
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			CHARACTER = 0x004BD7B8,
			SCORE = 0x004BD7C0,
			DIFFICULTY = 0x004BD7C4,
			LIVES = 0x004BD7F4,
			SPIRITS = 0x004BD808,
			FRAME_COUNT = 0x004BD828,
			IS_TRANCE = 0x004BD831,
			P_IS_BOMB = 0x004C1170
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(lives), 0);
		ReadProcessMemory(gameProc, (void*)SPIRITS, &spirits, sizeof(spirits), 0);
		ReadProcessMemory(gameProc, (void*)IS_TRANCE, &is_trance, sizeof(is_trance), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x40), &is_bomb, sizeof(is_bomb), 0);

		score *= 10;
		if (reset())
		{
			misses = 0;
			bombs = 0;
			trances = 0;
		}

		getShottype();
		getRubrics();

		countBombs();
		countTrances();

		
	}
}
