#pragma once

#include "drc_assets.h"

namespace ns_td
{
	// variables for manually counting misses
	uint8_t lives, _lives;

	// variables for recording key pressed
	uint32_t p_is_bomb;
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
			CHARACTER = 0x004BE7B8,
			SCORE = 0x004BE7C0,
			DIFFICULTY = 0x004BE7C4,
			LIVES = 0x004BE7F4,
			SPIRITS = 0x004BE808,
			FRAME_COUNT = 0x004BE828,
			IS_TRANCE = 0x004BE831,
			P_IS_BOMB = 0x004C2170
		};

		score = 0;

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(uint32_t), 0);
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
			misses = bombs = trances = 0;
		}

		getShottype();
		getRubrics();

		countBombs();
		countTrances();

		
	}
}
