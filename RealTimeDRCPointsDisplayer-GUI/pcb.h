#pragma once

#include "drc_assets.h"

namespace ns_pcb
{
	// Float type variables because of zun coding :P
	float _misses, _bombs;
	bool border_on, _border_on, in_game, reset;

	// Pointer to dynamic variables
	uint32_t ptr;
	uint32_t cherry, cherry_max, cherry_plus, _cherry_max;

	// For dealing with awkward random value in cherry variables
	unsigned int cherry_off;

	// team index
	const char* idx_character[] = { "Reimu", "Marisa", "Sakuya" };
	const char* idx_type[] = { "A", "B" };

	void getShottype()
	{
		shottype = idx_character[character];
		shottype += idx_type[type];
	}

	void countBorderBreaks()
	{
		if (!border_on && _border_on && cherry_max < _cherry_max + 10000)
		{
			border_breaks++;
		}
		_border_on = border_on;
		_cherry_max = cherry_max;
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			BORDERON = 0x004BFEE5,
			PTR = 0x00626278,
			DIFFICULTY = 0x00626280,
			CHARACTER = 0x0062F645,
			TYPE = 0x0062F646,
			IN_GAME = 0x0062F8C7,
			CHERRY = 0x0062F888,
			CHERRY_MAX = 0x0062F88C,
			CHERRY_PLUS = 0x0062F890
		};

		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)IN_GAME, &in_game, sizeof(in_game), 0);
		ReadProcessMemory(gameProc, (void*)BORDERON, &border_on, sizeof(border_on), 0);
		ReadProcessMemory(gameProc, (void*)PTR, &ptr, sizeof(ptr), 0);
		ReadProcessMemory(gameProc, (void*)ptr, &score, sizeof(uint32_t), 0);
		ReadProcessMemory(gameProc, (void*)(ptr + 0x50), &_misses, sizeof(_misses), 0);
		ReadProcessMemory(gameProc, (void*)(ptr + 0x6C), &_bombs, sizeof(_misses), 0);
		ReadProcessMemory(gameProc, (void*)CHERRY, &cherry, sizeof(cherry), 0);
		ReadProcessMemory(gameProc, (void*)CHERRY_MAX, &cherry_max, sizeof(cherry_max), 0);
		ReadProcessMemory(gameProc, (void*)CHERRY_PLUS, &cherry_plus, sizeof(cherry_plus), 0);
		
		score *= 10;
		if (in_game && reset)
		{
			border_breaks = 0;
			cherry_off = cherry_plus;
			_border_on = false;
			reset = false;
		}
		else if (!in_game)
		{
			reset = true;
		}

		getShottype();
		getRubrics();

		misses = (int8_t)_misses;
		bombs = (int8_t)_bombs;
		cherry -= cherry_off;
		cherry_max -= cherry_off;
		cherry_plus -= cherry_off;

		countBorderBreaks();

		
	}
}
