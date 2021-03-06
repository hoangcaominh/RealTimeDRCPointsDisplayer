#pragma once

#include "drc_assets.h"

namespace ns_gfw
{
	// variables for manually counting misses (2 byte int)
	uint16_t lives, _lives;

	// variables for recording key pressed
	uint32_t p_is_bomb;
	bool is_bomb, x_reset;

	// use route instead of character
	uint8_t &route = character;

	// route index
	const char* idx_route[] = { "A1", "A1", "A1", "A1", "A2", "A2", "B1", "B1", "B1", "B2", "B2", "C1", "C1", "C1", "C2", "C2", "-" };

	void getShottype()
	{
		shottype = idx_route[route];
	}

	void countMisses()
	{
		if (lives == _lives - 10000)	// miss
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
			SCORE = 0x004B4CC4,
			DIFFICULTY = 0x004B4D0C,
			ROUTE = 0x004B4D14,
			FRAME_COUNT = 0x004B4D20,
			LIVES = 0x004B4D64,
			P_IS_BOMB = 0x004B892C
		};

		score = 0;

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(uint32_t), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)ROUTE, &route, sizeof(route), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(lives), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x40), &is_bomb, sizeof(is_bomb), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			misses = bombs = 0;
		}

		getShottype();

		countMisses();
		countBombs();

		
	}
}
