#pragma once

#include "drc_assets.h"

namespace ns_in
{
	uint8_t team, type, deathbombs;
	DWORD p_score;
	uint32_t spell_bonus, spell_id, _spell_id;

	// used for counting last spell captures
	bool checked = false, failed = false;

	// team index
	const char* idx_team[] = { "BorderTeam", "MagicTeam", "ScarletTeam", "GhostTeam", "Reimu", "Yukari", "Marisa", "Alice", "Sakuya", "Remilia", "Youmu", "Yuyuko" };

	void getShottype()
	{
		shottype = idx_team[team];
	}

	void countLastSpellsCaptured()
	{
		auto compare = [](uint16_t a, uint16_t val, uint16_t b) { return a <= val && val <= b; };
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
		if (spell_id != _spell_id)
		{
			checked = false;
			failed = false;
			_spell_id = spell_id;
		}
		if (compare(STAGE1, spell_id, STAGE1 + 2) || compare(STAGE2, spell_id, STAGE2 + 2) || compare(STAGE3, spell_id, STAGE3 + 2) ||
			compare(STAGE4A, spell_id, STAGE4A + 2) || compare(STAGE4B, spell_id, STAGE4B + 2) || compare(STAGE5, spell_id, STAGE5 + 2) ||
			compare(STAGE6A - 1, spell_id, STAGE6A + 2) || compare(STAGE6B1 - 1, spell_id, STAGE6B5 + 2) || spell_id == STAGEEX)
		{
			if (!checked)
			{
				last_spells_captured++;
				checked = true;
			}
			if (spell_bonus < (0 + 100 * 8000) && !failed)	// assuming that a player can get the maximum number of time orbs in 0.1s is 100
			{
				last_spells_captured--;
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
			SPELL_ID = 0x004EA678,
			SPELL_BONUS = 0x004EA76C,
			TEAM = 0x0164D0B1,
			DIFFICULTY = 0x0160F538,
			P_SCORE = 0x0160F510,
			MISSES = 0x0164CFA4,
			BOMBS = 0x0164CFA8,
			DEATHBOMBS = 0x0164CFAC

			// TIMER = 0x004EA780
		};

		ReadProcessMemory(gameProc, (void*)FRAME_COUNT, &frame_count, sizeof(frame_count), 0);
		ReadProcessMemory(gameProc, (void*)STAGE, &stage, sizeof(stage), 0);
		ReadProcessMemory(gameProc, (void*)SPELL_ID, &spell_id, sizeof(spell_id), 0);
		ReadProcessMemory(gameProc, (void*)SPELL_BONUS, &spell_bonus, sizeof(spell_bonus), 0);
		ReadProcessMemory(gameProc, (void*)TEAM, &team, sizeof(team), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(difficulty), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(misses), 0);
		ReadProcessMemory(gameProc, (void*)BOMBS, &bombs, sizeof(bombs), 0);
		ReadProcessMemory(gameProc, (void*)DEATHBOMBS, &deathbombs, sizeof(deathbombs), 0);
		ReadProcessMemory(gameProc, (void*)P_SCORE, &p_score, sizeof(p_score), 0);
		ReadProcessMemory(gameProc, (void*)p_score, &score, sizeof(uint32_t), 0);

		// ReadProcessMemory(gameProc, (void*)TIMER, &timer, sizeof(timer), 0);

		score *= 10;
		// reset last spells captured
		if (reset())
		{
			last_spells_captured = 0;
		}

		// total bombs used
		bombs += deathbombs;

		getShottype();
		getRubrics();

		countLastSpellsCaptured();

		
	}
}
