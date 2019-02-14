#pragma once

#include "drc_assets.h"

namespace ns_hsifs
{	
	// variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;
	// for final spell
	DWORD p_spellID;
	char spellID;
	// variables for HSiFS
	unsigned short release_petals, _release_petals;

	// character index
	const char* idx_character[] = { "Reimu", "Cirno", "Aya", "Marisa" };
	const char* idx_season[] = { "Spring", "Summer", "Autumn", "Winter" };

	void getShottype()
	{
		shottype = idx_character[character];

		if (strcmp(idx_difficulty[difficulty], "Extra") != 0)
		{
			shottype += idx_season[season];
		}
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
	
	void countReleases()
	{
		if (release_petals < _release_petals && !(spellID >= 90 && spellID <= 105))
		{
			releases++;
		}

		_release_petals = release_petals;
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			FRAME_COUNT = 0x004A57A0,
			SCORE = 0x004A57B0,
			CHARACTER = 0x004A57A4,
			SEASON = 0x004A57AC,
			DIFFICULTY = 0x004A57B4,
			MISSES = 0x004A57CC,
			P_IS_BOMB = 0x004A6DA8,
			RELEASE_PETALS = 0x004A5808,	// 190 petals = 1 level / level 6 = 1140 petals
			P_SPELLID = 0x004A6DB0
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(character), 0);
		ReadProcessMemory(gameProc, (void*)SEASON, &season, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(misses), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(p_is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x30), &is_bomb, sizeof(is_bomb), 0);
		ReadProcessMemory(gameProc, (void*)RELEASE_PETALS, &release_petals, sizeof(release_petals), 0);
		ReadProcessMemory(gameProc, (void*)P_SPELLID, &p_spellID, sizeof(p_spellID), 0);
		ReadProcessMemory(gameProc, (void*)(p_spellID + 0x74), &spellID, sizeof(spellID), 0);

		score *= 10;
		if (reset())
		{
			// initialize
			bombs = 0;
			releases = 0;
			_release_petals = 0;
			spellID = 0;
		}

		getShottype();

		getRubrics();
		firstRelease = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["firstRelease"].get<char>();
		release = Rubrics["SURV"][idx_game[game]][idx_difficulty[difficulty]]["release"].get<float>();

		countBombs();
		countReleases();

		
	}
}
