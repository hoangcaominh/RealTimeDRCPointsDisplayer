#pragma once

#include "drc_assets.h"

namespace ns_pcb
{
	// Float type variables because of zun coding :P
	float _misses, _bombs;
	bool borderOn, _borderOn, inGame, reset;

	// Pointer to dynamic variables
	DWORD ptr;
	unsigned int cherry, cherryMax, cherryPlus, _cherryMax;

	// For dealing with awkward random value in cherry variables
	unsigned int cherryOff;

	// team index
	const char* idx_character[] = { "Reimu", "Marisa", "Sakuya" };
	const char* idx_type[] = { "A", "B" };

	void getShottype()
	{
		shottype = idx_character[character];
		shottype += idx_type[type];
	}

	void countBB()
	{
		if (!borderOn && _borderOn && cherryMax < _cherryMax + 10000)
		{
			borderBreaks++;
		}
		_borderOn = borderOn;
		_cherryMax = cherryMax;
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
			INGAME = 0x0062F8C7,
			CHERRY = 0x0062F888,
			CHERRYMAX = 0x0062F88C,
			CHERRYPLUS = 0x0062F890
		};

		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(type), 0);
		ReadProcessMemory(gameProc, (void*)INGAME, &inGame, sizeof(inGame), 0);
		ReadProcessMemory(gameProc, (void*)BORDERON, &borderOn, sizeof(borderOn), 0);
		ReadProcessMemory(gameProc, (void*)PTR, &ptr, sizeof(ptr), 0);
		ReadProcessMemory(gameProc, (void*)ptr, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)(ptr + 0x50), &_misses, sizeof(_misses), 0);
		ReadProcessMemory(gameProc, (void*)(ptr + 0x6C), &_bombs, sizeof(_misses), 0);
		ReadProcessMemory(gameProc, (void*)CHERRY, &cherry, sizeof(cherry), 0);
		ReadProcessMemory(gameProc, (void*)CHERRYMAX, &cherryMax, sizeof(cherryMax), 0);
		ReadProcessMemory(gameProc, (void*)CHERRYPLUS, &cherryPlus, sizeof(cherryPlus), 0);
		
		score *= 10;
		if (inGame && reset)
		{
			borderBreaks = 0;
			cherryOff = cherryPlus;
			_borderOn = false;
			reset = false;
		}
		else if (!inGame)
		{
			reset = true;
		}

		getShottype();
		getRubrics();

		misses = (char)_misses;
		bombs = (char)_bombs;
		cherry -= cherryOff;
		cherryMax -= cherryOff;
		cherryPlus -= cherryOff;

		countBB();

		
	}
}
