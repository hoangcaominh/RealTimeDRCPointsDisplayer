#pragma once

#include "drc_assets.h"

namespace ns_pofv
{
	// Variables for measuring gauge bar
	float charge;

	DWORD p_score, p_charge;
	// lost round variables
	char loss, _loss;

	// character index
	const char* idx_character[] = { "Reimu", "Marisa", "Sakuya", "Youmu", "Reisen", "Cirno", "Lyrica", "Mystia", "Tewi", "Yuuka", "Aya", "Medicine", "Komachi", "Eiki", "Merlin", "Lunasa" };

	void getShottype()
	{
		shottype = idx_character[character];
	}

	void countMisses()
	{
		if (loss == _loss + 1)	// miss
		{
			misses++;
		}
		_loss = loss;
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			P_CHARGE = 0x004A7D94,
			P_SCORE = 0x004A7DAC,
			CHARACTER = 0x004A7DB0,
			LOSS = 0x004A7E9C,
			FRAME_COUNT = 0x004A7EBC,
			DIFFICULTY = 0x004B3538
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LOSS, &loss, sizeof(loss), 0);
		ReadProcessMemory(gameProc, (void*)P_SCORE, &p_score, sizeof(p_score), 0);
		ReadProcessMemory(gameProc, (void*)(p_score + 0x04), &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)P_CHARGE, &p_charge, sizeof(p_charge), 0);
		ReadProcessMemory(gameProc, (void*)(p_charge + 0x30384), &charge, sizeof(charge), 0);

		score *= 10;
		if (reset())
		{
			misses = 0;
			noCharge = true;
		}

		getShottype();
		getRubrics();

		countMisses();

		if (charge >= 100.0f)
		{
			noCharge = false;
		}

		
	}
}
