#pragma once

#include "drc_assets.h"

namespace ns_pofv
{
	DWORD p_score;
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
			CHARACTER = 0x004A7DB0,
			P_SCORE = 0x004F5830,
			DIFFICULTY = 0x004F5834,
			LOSS = 0x004F5864,
			FRAME_COUNT = 0x004A7EBC
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)LOSS, &loss, sizeof(loss), 0);
		ReadProcessMemory(gameProc, (void*)P_SCORE, &p_score, sizeof(p_score), 0);
		ReadProcessMemory(gameProc, (void*)p_score, &score, sizeof(int), 0);

		score *= 10;
		if (reset())
		{
			misses = 0;
		}

		getShottype();
		getRubrics();

		countMisses();

		calculateDRCPoints();
		printStatus();
	}
}
