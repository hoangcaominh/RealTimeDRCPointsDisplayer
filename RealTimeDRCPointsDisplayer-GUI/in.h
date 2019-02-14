#pragma once

#include "drc_assets.h"

namespace ns_in
{
	char team, type, deathbombs;
	DWORD p_score;
	unsigned int spellbonus, spellID, _spellID;
	// used for counting last spell captures
	bool checked = false, failed = false;

	// team index
	const char* idx_team[] = { "BorderTeam", "MagicTeam", "ScarletTeam", "GhostTeam", "Reimu", "Yukari", "Marisa", "Alice", "Sakuya", "Remilia", "Youmu", "Yuyuko" };

	void getShottype()
	{
		shottype = idx_team[team];
	}

	void countLs_capped()
	{
		auto compare = [](unsigned short a, unsigned short val, unsigned short b) { return a <= val && val <= b; };
		// Last spells (enum), default is Normal
		enum LASTSPELLS
		{
			STAGE1 = 10,
			STAGE2 = 29,
			STAGE3 = 51,
			STAGE4A = 74,
			STAGE4B = 97,
			STAGE5 = 116,
			STAGE6A = 144,	// easy will be 144 - 1
			STAGE6B1 = 172,
			STAGE6B5 = 188,
			STAGEEX = 204 // Imperishable Shooting
		};

		// reset checkers when another spellcard is declared
		if (spellID != _spellID)
		{
			checked = false;
			failed = false;
			_spellID = spellID;
		}
		if (compare(STAGE1, spellID, STAGE1 + 2) || compare(STAGE2, spellID, STAGE2 + 2) || compare(STAGE3, spellID, STAGE3 + 2) ||
			compare(STAGE4A, spellID, STAGE4A + 2) || compare(STAGE4B, spellID, STAGE4B + 2) || compare(STAGE5, spellID, STAGE5 + 2) ||
			compare(STAGE6A - 1, spellID, STAGE6A + 2) || compare(STAGE6B1 - 1, spellID, STAGE6B5 + 2) || spellID == STAGEEX)
		{
			if (!checked)
			{
				ls_capped++;
				checked = true;
			}
			if (spellbonus < (0 + 100 * 8000) && !failed)	// assuming that a player can get the maximum number of time orbs in 0.1s is 100
			{
				ls_capped--;
				failed = true;
			}
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			FRAME_COUNT = 0x0164D0AC,
			STAGE = 0x004E4850,
			SPELLID = 0x004EA678,
			SPELLBONUS = 0x004EA76C,
			TEAM = 0x0164D0B1,
			DIFFICULTY = 0x0160F538,
			P_SCORE = 0x0160F510,
			MISSES = 0x0164CFA4,
			BOMBS = 0x0164CFA8,
			DEATHBOMBS = 0x0164CFAC
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)STAGE, &stage, sizeof(stage), 0);
		ReadProcessMemory(gameProc, (void*)SPELLID, &spellID, sizeof(spellID), 0);
		ReadProcessMemory(gameProc, (void*)SPELLBONUS, &spellbonus, sizeof(spellbonus), 0);
		ReadProcessMemory(gameProc, (void*)TEAM, &team, sizeof(team), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(misses), 0);
		ReadProcessMemory(gameProc, (void*)BOMBS, &bombs, sizeof(bombs), 0);
		ReadProcessMemory(gameProc, (void*)DEATHBOMBS, &deathbombs, sizeof(deathbombs), 0);
		ReadProcessMemory(gameProc, (void*)P_SCORE, &p_score, sizeof(p_score), 0);
		ReadProcessMemory(gameProc, (void*)p_score, &score, sizeof(int), 0);

		score *= 10;
		// reset last spells captured
		if (reset())
		{
			ls_capped = 0;
		}

		// total bombs used
		bombs += deathbombs;

		getShottype();
		getRubrics();

		countLs_capped();

		
	}
}
