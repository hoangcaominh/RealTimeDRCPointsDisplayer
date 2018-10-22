#pragma once

#include "color.h"
#include "ProcessJSON.h"

namespace ns_in
{
	// Global variables
	char stage, team, type, difficulty, misses, bombs, deathbombs, bombs_sum;
	DWORD p_score;
	ull score;
	unsigned int spellbonus, spellID, _spellID;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	float exp, exp_s;
	char first_bomb;
	// used for counting last spell captures
	bool checked = false, failed = false;
	unsigned short ls_capped;

	enum _DIFFICULTY
	{
		EASY,
		NORMAL,
		HARD,
		LUNATIC,
		EXTRA
	};
	enum _TEAM
	{
		BORDER,
		MAGIC,
		SCARLET,
		GHOST,
		REIMU,
		YUKARI,
		MARISA,
		ALICE,
		SAKUYA,
		REMILIA,
		YOUMU,
		YUYUKO
	};

	float getMultiplier()
	{
		switch (team)
		{
		case MAGIC:
			return 1.05f;
		case SCARLET:
			return 1.05f;
		case REIMU:
			return 1.1f;
		case YUKARI:
			return 1.05f;
		case MARISA:
			return 1.05f;
		case ALICE:
			return 1.2f;
		case SAKUYA:
			return 1.2f;
		case REMILIA:
			return 1.1f;
		case YUYUKO:
			return 1.1f;
		default:
			return 1.0f;
		}
	}

	ull getWr()
	{
		ull wr;
		switch (difficulty)
		{
		case EASY:
			switch (team)
			{
			case BORDER:
				wr = _IN.wr.easy.BorderTeam;
				break;
			case MAGIC:
				wr = _IN.wr.easy.MagicTeam;
				break;
			case SCARLET:
				wr = _IN.wr.easy.ScarletTeam;
				break;
			case GHOST:
				wr = _IN.wr.easy.GhostTeam;
				break;
			case REIMU:
				wr = _IN.wr.easy.Reimu;
				break;
			case YUKARI:
				wr = _IN.wr.easy.Yukari;
				break;
			case MARISA:
				wr = _IN.wr.easy.Marisa;
				break;
			case ALICE:
				wr = _IN.wr.easy.Alice;
				break;
			case SAKUYA:
				wr = _IN.wr.easy.Sakuya;
				break;
			case REMILIA:
				wr = _IN.wr.easy.Remilia;
				break;
			case YOUMU:
				wr = _IN.wr.easy.Youmu;
				break;
			case YUYUKO:
				wr = _IN.wr.easy.Yuyuko;
				break;
			}
			break;
		case NORMAL:
			switch (team)
			{
			case BORDER:
				wr = _IN.wr.normal.BorderTeam;
				break;
			case MAGIC:
				wr = _IN.wr.normal.MagicTeam;
				break;
			case SCARLET:
				wr = _IN.wr.normal.ScarletTeam;
				break;
			case GHOST:
				wr = _IN.wr.normal.GhostTeam;
				break;
			case REIMU:
				wr = _IN.wr.normal.Reimu;
				break;
			case YUKARI:
				wr = _IN.wr.normal.Yukari;
				break;
			case MARISA:
				wr = _IN.wr.normal.Marisa;
				break;
			case ALICE:
				wr = _IN.wr.normal.Alice;
				break;
			case SAKUYA:
				wr = _IN.wr.normal.Sakuya;
				break;
			case REMILIA:
				wr = _IN.wr.normal.Remilia;
				break;
			case YOUMU:
				wr = _IN.wr.normal.Youmu;
				break;
			case YUYUKO:
				wr = _IN.wr.normal.Yuyuko;
				break;
			}
			break;
		case HARD:
			switch (team)
			{
			case BORDER:
				wr = _IN.wr.hard.BorderTeam;
				break;
			case MAGIC:
				wr = _IN.wr.hard.MagicTeam;
				break;
			case SCARLET:
				wr = _IN.wr.hard.ScarletTeam;
				break;
			case GHOST:
				wr = _IN.wr.hard.GhostTeam;
				break;
			case REIMU:
				wr = _IN.wr.hard.Reimu;
				break;
			case YUKARI:
				wr = _IN.wr.hard.Yukari;
				break;
			case MARISA:
				wr = _IN.wr.hard.Marisa;
				break;
			case ALICE:
				wr = _IN.wr.hard.Alice;
				break;
			case SAKUYA:
				wr = _IN.wr.hard.Sakuya;
				break;
			case REMILIA:
				wr = _IN.wr.hard.Remilia;
				break;
			case YOUMU:
				wr = _IN.wr.hard.Youmu;
				break;
			case YUYUKO:
				wr = _IN.wr.hard.Yuyuko;
				break;
			}
			break;
		case LUNATIC:
			switch (team)
			{
			case BORDER:
				wr = _IN.wr.lunatic.BorderTeam;
				break;
			case MAGIC:
				wr = _IN.wr.lunatic.MagicTeam;
				break;
			case SCARLET:
				wr = _IN.wr.lunatic.ScarletTeam;
				break;
			case GHOST:
				wr = _IN.wr.lunatic.GhostTeam;
				break;
			case REIMU:
				wr = _IN.wr.lunatic.Reimu;
				break;
			case YUKARI:
				wr = _IN.wr.lunatic.Yukari;
				break;
			case MARISA:
				wr = _IN.wr.lunatic.Marisa;
				break;
			case ALICE:
				wr = _IN.wr.lunatic.Alice;
				break;
			case SAKUYA:
				wr = _IN.wr.lunatic.Sakuya;
				break;
			case REMILIA:
				wr = _IN.wr.lunatic.Remilia;
				break;
			case YOUMU:
				wr = _IN.wr.lunatic.Youmu;
				break;
			case YUYUKO:
				wr = _IN.wr.lunatic.Yuyuko;
				break;
			}
			break;
		case EXTRA:
			switch (team)
			{
			case BORDER:
				wr = _IN.wr.extra.BorderTeam;
				break;
			case MAGIC:
				wr = _IN.wr.extra.MagicTeam;
				break;
			case SCARLET:
				wr = _IN.wr.extra.ScarletTeam;
				break;
			case GHOST:
				wr = _IN.wr.extra.GhostTeam;
				break;
			case REIMU:
				wr = _IN.wr.extra.Reimu;
				break;
			case YUKARI:
				wr = _IN.wr.extra.Yukari;
				break;
			case MARISA:
				wr = _IN.wr.extra.Marisa;
				break;
			case ALICE:
				wr = _IN.wr.extra.Alice;
				break;
			case SAKUYA:
				wr = _IN.wr.extra.Sakuya;
				break;
			case REMILIA:
				wr = _IN.wr.extra.Remilia;
				break;
			case YOUMU:
				wr = _IN.wr.extra.Youmu;
				break;
			case YUYUKO:
				wr = _IN.wr.extra.Yuyuko;
				break;
			}
			break;
		}
		return wr;
	}

	void getRubrics()
	{
		std::cout << "Difficulty: ";
		switch (difficulty)
		{
		case EASY:
			std::cout << "Easy" << std::endl;
			base = 45;
			exp = 1.05f;
			first_bomb = 2;
			base_s = 375;
			exp_s = 4.0f;
			break;
		case NORMAL:
			std::cout << "Normal" << std::endl;
			base = 90;
			exp = 1.05f;
			first_bomb = 3;
			base_s = 400;
			exp_s = 3.0f;
			break;
		case HARD:
			std::cout << "Hard" << std::endl;
			base = 140;
			exp = 1.05f;
			first_bomb = 3;
			base_s = 450;
			exp_s = 2.5f;
			break;
		case LUNATIC:
			std::cout << "Lunatic" << std::endl;
			base = 290;
			exp = 1.05f;
			first_bomb = 5;
			base_s = 500;
			exp_s = 2.7f;
			break;
		case EXTRA:
			std::cout << "Extra" << std::endl;
			base = 110;
			exp = 1.08f;
			first_bomb = 3;
			base_s = 450;
			exp_s = 3.0f;
			break;
		}
	}

	void getStageFinal()
	{
		if (difficulty == EXTRA)
		{
			std::cout << "Imperishable Shooting Captured: " << ((ls_capped == 1) ? "True" : "False") << std::endl;
			//std::cout << "Last Spell Captured: " << int(ls_capped) << std::endl;
		}
		else
		{
			std::cout << "Final: ";
			switch (stage)
			{
			case 6:	// 6A
				std::cout << "A" << std::endl;
				std::cout << "Last spells captured: " << int(ls_capped);
				switch (difficulty)
				{
				case EASY:
					std::cout << "/1" << std::endl;
					break;
				default:
					std::cout << "/6" << std::endl;
					break;
				}
				break;
			case 7:	// 6B
				std::cout << "B" << std::endl;
				std::cout << "Last spells captured: " << int(ls_capped);
				switch (difficulty)
				{
				case EASY:
					std::cout << "/6" << std::endl;
					break;
				default:
					std::cout << "/10" << std::endl;
					break;
				}
				break;
			default:
				std::cout << "?" << std::endl;
				std::cout << "Last spells captured: " << int(ls_capped) << "/?" << std::endl;
				break;
			}
		}
	}

	void printShottype()
	{
		std::cout << "Shottype: ";
		switch (team)
		{
		case BORDER:
			std::cout << "Border team" << std::endl;
			break;
		case MAGIC:
			std::cout << "Magic team" << std::endl;
			break;
		case SCARLET:
			std::cout << "Scarlet team" << std::endl;
			break;
		case GHOST:
			std::cout << "Ghost team" << std::endl;
			break;
		case REIMU:
			std::cout << "Reimu solo" << std::endl;
			break;
		case YUKARI:
			std::cout << "Yukari solo" << std::endl;
			break;
		case MARISA:
			std::cout << "Marisa solo" << std::endl;
			break;
		case ALICE:
			std::cout << "Alice team" << std::endl;
			break;
		case SAKUYA:
			std::cout << "Sakuya team" << std::endl;
			break;
		case REMILIA:
			std::cout << "Remilia team" << std::endl;
			break;
		case YOUMU:
			std::cout << "Youmu team" << std::endl;
			break;
		case YUYUKO:
			std::cout << "Yuyuko solo" << std::endl;
			break;
		}
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

	void calculate_drcp()
	{
		unsigned short ls_points;
		switch (difficulty)
		{
		case EASY:
			ls_points = ls_capped * 1;
			break;
		case EXTRA:
			ls_points = ls_capped * 5;
			break;
		default:
			ls_points = ls_capped * 2;
			break;
		}

		char n = 0;
		n += misses * 2;	// default is 2
		if (bombs_sum > 0)
		{
			n += first_bomb;
			bombs_sum--;
		}
		n += bombs_sum * 1;	// default is 1
		drcpoints_survival = base * pow(exp, (0 - n)) * getMultiplier() + ls_points;

		ull wr = getWr();
		if (score >= wr)
		{
			drcpoints_score = roundf(base_s);
		}
		else
		{
			// drcpoints_score = (unsigned short)(base_s * pow((double)score / wr, exp_s));
			drcpoints_score = roundf(base_s * (float)pow((long double)score / wr, exp_s));
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
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

		ReadProcessMemory(gameProc, (void*)STAGE, &stage, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)SPELLID, &spellID, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)SPELLBONUS, &spellbonus, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)TEAM, &team, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)BOMBS, &bombs, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DEATHBOMBS, &deathbombs, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)P_SCORE, &p_score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)p_score, &score, sizeof(int), 0);

		score *= 10;	// score in IN misses a 0
		if (score == 0)
		{
			ls_capped = 0;	// reset last spells capped
		}

		bombs_sum = bombs + deathbombs;

		getRubrics();
		printShottype();

		countLs_capped();

		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(misses) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bombs_sum) << std::endl;
		setcolor(WHITE);
		std::cout << "Score: " << score << std::endl;
		setcolor(LIGHTGRAY);

		getStageFinal();
		calculate_drcp();

		std::cout << "DRC points for survival: " << (int)drcpoints_survival << std::endl;
		std::cout << "DRC points for scoring: " << (int)drcpoints_score << std::endl;
	}
}
