#pragma once

#include "drc_assets.h"

namespace ns_wbawc
{
	// Array for storing tokens in WBaWC
	uint32_t token_array[5], tokens;

	// Variable for checking whether the player is in hyper mode
	bool is_hyper, roar_break_counted;
	uint32_t hyper_bar[2], prev_hyper_bar[2];

	// Array for counting occurrences of goasts
	// There are at least 11 kinds of tokens for now
	uint8_t occurrence[11];

	// variables for recording key pressed
	uint32_t p_is_bomb;
	bool is_bomb, x_reset;

	const char* idx_character[] = { "Reimu", "Marisa", "Youmu" };
	const char* idx_type[] = { "W", "O", "E" };

	void getShottype()
	{
		shottype = idx_character[character];
		shottype += idx_type[type];
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

	void countGoasts()
	{
		if (tokens == 5 && !is_hyper)
		{
			is_hyper = true;

			for (uint32_t i : token_array)
			{
				occurrence[i]++;
			}

			// occurrence from wolves to eagles
			for (uint8_t i = 1; i <= 3; i++)
			{
				if (occurrence[i] >= 3)
				{
					switch (i)
					{
					case 1:
						wolves++;
						break;
					case 2:
						otters++;
						break;
					case 3:
						eagles++;
						break;
					}
				}
			}
		}
		else if (tokens != 5)
		{
			is_hyper = roar_break_counted = false;
			memset(occurrence, 0, sizeof(occurrence));
		}

		if (tokens == 5 && !roar_break_counted &&
			(prev_hyper_bar[0] - hyper_bar[0] > 18 || prev_hyper_bar[1] - hyper_bar[1] > 18) &&	// Seems that the "hyper_bar" value keeps decreasing by 2, so I set this to 18
			(hyper_bar[0] < 42 || hyper_bar[1] < 42))	// If the player breaks the "hype" both value will be set to either 38 or 39, so I set to 42
		{
			roar_breaks++;
			roar_break_counted = true;
		}

		prev_hyper_bar[0] = hyper_bar[0];
		prev_hyper_bar[1] = hyper_bar[1];
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			FRAME_COUNT = 0x004B59E8,
			SCORE = 0x004B59FC,
			DIFFICULTY = 0x004B5A00,
			CHARACTER = 0x004B59F4,
			TYPE = 0x004B59F8,
			TOKEN_ARRAY = 0x004B5A64,
			TOKENS = 0x004B5A60,
			P_IS_BOMB = 0x004B7688,
			MISSES = 0x004B5A18,
			HYPER_BAR = 0x004B5AA4
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(uint32_t), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(misses), 0);
		ReadProcessMemory(gameProc, (void*)TOKEN_ARRAY, &token_array, sizeof(token_array), 0);
		ReadProcessMemory(gameProc, (void*)TOKENS, &tokens, sizeof(tokens), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x30), &is_bomb, sizeof(is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)HYPER_BAR, &hyper_bar, sizeof(hyper_bar), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			bombs = 0;
			wolves = otters = eagles = roar_breaks = 0;
		}

		getShottype();
		/* Not available yet
		getRubrics();
		*/

		countBombs();
		countGoasts();
	}
}
