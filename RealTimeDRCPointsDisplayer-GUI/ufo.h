#pragma once

#include "drc_assets.h"

namespace ns_ufo
{
	// variables for UFO
	uint32_t vault_array[3]; uint8_t vaults; bool is_ufo;

	// variables for manually counting misses
	uint8_t lives, _lives;

	// variables for recording key pressed
	uint32_t p_is_bomb;
	bool is_bomb, x_reset;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sanae" };
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

	void countUFOs()
	{
		if (vaults == 3 && !is_ufo)
		{
			is_ufo = true;
			ufos++;

			// specific ufo
			if (vault_array[0] == 1 && vault_array[1] == 1)
			{
				ufos_red++;
			}
			else if (vault_array[0] == 2 && vault_array[1] == 2)
			{
				ufos_blue++;
			}
			else if (vault_array[0] == 3 && vault_array[1] == 3)
			{
				ufos_green++;
			}
			else
			{
				ufos_rainbow++;
			}
		}
		else if (vaults != 3)
		{
			is_ufo = false;
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			SCORE = 0x004B0C44,
			VAULT_ARRAY = 0x004B0C4C,		// vault_array type is 4-byte int in ZUN's code
			VAULTS = 0x004B0C58,	// number of vaults collected
			CHARACTER = 0x004B0C90,
			TYPE = 0x004B0C94,
			LIVES = 0x004B0C98,
			DIFFICULTY = 0x004B0CA8,
			FRAME_COUNT = 0x004B0CBC,
			P_IS_BOMB = 0x004B43C4
		};

		score = 0;

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(uint32_t), 0);
		ReadProcessMemory(gameProc, (void*)VAULT_ARRAY, vault_array, sizeof(vault_array), 0);
		ReadProcessMemory(gameProc, (void*)VAULTS, &vaults, sizeof(vaults), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(lives), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x3C), &is_bomb, sizeof(is_bomb), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			misses = bombs = 0;
			ufos = ufos_red = ufos_green = ufos_blue = ufos_rainbow = 0;
		}

		getShottype();

		countMisses();
		countBombs();
		countUFOs();

		
	}
}
