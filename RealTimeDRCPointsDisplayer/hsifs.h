#pragma once

#include "color.h"
#include "ProcessJSON.h"

namespace ns_hsifs
{
	// Global variables
	bool reset;
	char character, season, difficulty, lives, misses, bombs, bombs_used;
	// for final spell
	DWORD p_spellID;
	char spellID;
	ull score;
	// variables for HSiFS
	unsigned short release_petals, _release_petals, releases;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	float exp, exp_s;
	char first_bomb;

	enum _DIFFICULTY
	{
		EASY,
		NORMAL,
		HARD,
		LUNATIC,
		EXTRA
	};
	enum _CHARACTER
	{
		REIMU,
		CIRNO,
		AYA,
		MARISA
	};
	enum _SEASON
	{
		SPRING,
		SUMMER,
		AUTUMN,
		WINTER
	};

	float getMultiplier()
	{
		switch (character)
		{
		case REIMU:
			switch (season)
			{
			case SPRING:
				return 1.15f;
			case SUMMER:
				return 1.15f;
			}
		case CIRNO:
			switch (season)
			{
			case SPRING:
				return 1.2f;
			case SUMMER:
				return 1.2f;
			case AUTUMN:
				return 1.1f;
			case WINTER:
				return 1.1f;
			}
		case AYA:
			switch (season)
			{
			case SPRING:
				return 1.15f;
			case SUMMER:
				return 1.15f;
			case AUTUMN:
				return 1.05f;
			case WINTER:
				return 1.05f;
			}
		case MARISA:
			switch (season)
			{
			case SPRING:
				return 1.15f;
			case SUMMER:
				return 1.15f;
			}
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
			switch (character)
			{
			case REIMU:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.easy.Reimu.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.easy.Reimu.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.easy.Reimu.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.easy.Reimu.Winter;
					break;
				}
				break;
			case CIRNO:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.easy.Cirno.Spring;
					break;				
				case SUMMER:			
					wr = HSiFS.wrs.easy.Cirno.Summer;
					break;				
				case AUTUMN:			
					wr = HSiFS.wrs.easy.Cirno.Autumn;
					break;				
				case WINTER:			
					wr = HSiFS.wrs.easy.Cirno.Winter;
					break;
				}
				break;
			case AYA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.easy.Aya.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.easy.Aya.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.easy.Aya.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.easy.Aya.Winter;
					break;
				}
				break;
			case MARISA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.easy.Marisa.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.easy.Marisa.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.easy.Marisa.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.easy.Marisa.Winter;
					break;
				}
				break;
			}
			break;
		case NORMAL:

			switch (character)
			{
			case REIMU:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.normal.Reimu.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.normal.Reimu.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.normal.Reimu.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.normal.Reimu.Winter;
					break;
				}
				break;
			case CIRNO:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.normal.Cirno.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.normal.Cirno.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.normal.Cirno.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.normal.Cirno.Winter;
					break;
				}
				break;
			case AYA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.normal.Aya.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.normal.Aya.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.normal.Aya.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.normal.Aya.Winter;
					break;
				}
				break;
			case MARISA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.normal.Marisa.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.normal.Marisa.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.normal.Marisa.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.normal.Marisa.Winter;
					break;
				}
				break;
			}
			break;
		case HARD:

			switch (character)
			{
			case REIMU:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.hard.Reimu.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.hard.Reimu.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.hard.Reimu.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.hard.Reimu.Winter;
					break;
				}
				break;
			case CIRNO:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.hard.Cirno.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.hard.Cirno.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.hard.Cirno.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.hard.Cirno.Winter;
					break;
				}
				break;
			case AYA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.hard.Aya.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.hard.Aya.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.hard.Aya.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.hard.Aya.Winter;
					break;
				}
				break;
			case MARISA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.hard.Marisa.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.hard.Marisa.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.hard.Marisa.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.hard.Marisa.Winter;
					break;
				}
				break;
			}
			break;
		case LUNATIC:

			switch (character)
			{
			case REIMU:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.lunatic.Reimu.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.lunatic.Reimu.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.lunatic.Reimu.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.lunatic.Reimu.Winter;
					break;
				}
				break;
			case CIRNO:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.lunatic.Cirno.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.lunatic.Cirno.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.lunatic.Cirno.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.lunatic.Cirno.Winter;
					break;
				}
				break;
			case AYA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.lunatic.Aya.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.lunatic.Aya.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.lunatic.Aya.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.lunatic.Aya.Winter;
					break;
				}
				break;
			case MARISA:
				switch (season)
				{
				case SPRING:
					wr = HSiFS.wrs.lunatic.Marisa.Spring;
					break;
				case SUMMER:
					wr = HSiFS.wrs.lunatic.Marisa.Summer;
					break;
				case AUTUMN:
					wr = HSiFS.wrs.lunatic.Marisa.Autumn;
					break;
				case WINTER:
					wr = HSiFS.wrs.lunatic.Marisa.Winter;
					break;
				}
				break;
			}
			break;
		case EXTRA:
			switch (character)
			{
			case REIMU:
				wr = HSiFS.wrs.extra.Reimu;
			case CIRNO:
				wr = HSiFS.wrs.extra.Cirno;
			case AYA:
				wr = HSiFS.wrs.extra.Aya;
			case MARISA:
				wr = HSiFS.wrs.extra.Marisa;
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
			base = 50;
			exp = 1.06f;
			first_bomb = 2;
			base_s = 375;
			exp_s = 3.0f;
			break;
		case NORMAL:
			std::cout << "Normal" << std::endl;
			base = 100;
			exp = 1.05f;
			first_bomb = 3;
			base_s = 400;
			exp_s = 3.0f;
			break;
		case HARD:
			std::cout << "Hard" << std::endl;
			base = 150;
			exp = 1.05f;
			first_bomb = 3;
			base_s = 450;
			exp_s = 2.5f;
			break;
		case LUNATIC:
			std::cout << "Lunatic" << std::endl;
			base = 300;
			exp = 1.05f;
			first_bomb = 3;
			base_s = 500;
			exp_s = 2.0f;
			break;
		case EXTRA:
			std::cout << "Extra" << std::endl;
			base = 105;
			exp = 1.07f;
			first_bomb = 3;
			base_s = 450;
			exp_s = 3.0f;
			break;
		}
	}

	void printShottype()
	{
		std::cout << "Shottype: ";
		switch (character)
		{
		case REIMU:
			std::cout <<"Reimu";
			break;
		case CIRNO:
			std::cout <<"Cirno";
			break;
		case AYA:
			std::cout <<"Aya";
			break;
		case MARISA:
			std::cout <<"Marisa";
			break;
		}
		if (difficulty != EXTRA)
			switch (season)
			{
			case SPRING:
				std::cout << " Spring" << std::endl;
				break;
			case SUMMER:
				std::cout << " Summer" << std::endl;
				break;
			case AUTUMN:
				std::cout << " Autumn" << std::endl;
				break;
			case WINTER:
				std::cout << " Winter" << std::endl;
				break;
			}
		else
			std::cout << std::endl;
	}

	void countReleases()
	{
		if (release_petals < _release_petals && !(spellID >= 90 && spellID <= 105))
		{
			releases++;
		}

		_release_petals = release_petals;
	}
	
	void calculate_drcp()
	{
		char n = 0;
		n += misses * 2;	// default is 2
		if (bombs_used > 0)
		{
			n += first_bomb;
			bombs_used--;
		}
		n += bombs_used * 1;	// default is 1
		drcpoints_survival = base * pow(exp, (0 - n)) * getMultiplier();

		ull wr = getWr();
		if (wr == 0)
		{
			std::cout << "This difficulty with this shottype hasn't had a world record yet." << std::endl;
		}
		if (score >= wr)
		{
			drcpoints_score = roundf(base_s);
		}
		else
		{
			drcpoints_score = roundf(base_s * (float)pow((long double)score / wr, exp_s));
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			SCORE = 0x004A57B0,
			CHARACTER = 0x004A57A4,
			SEASON = 0x004A57AC,
			DIFFICULTY = 0x004A57B4,
			LIVES = 0x004A57F4,
			BOMBS = 0x004A5800,
			RELEASE_PETALS = 0x004A5808,	// 190 petals = 1 level / level 6 = 1140 petals
			P_SPELLID = 0x004A6DB0
		};

		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)SEASON, &season, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)LIVES, &lives, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)BOMBS, &bombs, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)RELEASE_PETALS, &release_petals, sizeof(unsigned short), 0);
		ReadProcessMemory(gameProc, (void*)P_SPELLID, &p_spellID, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)(p_spellID + 0x74), &spellID, sizeof(char), 0);

		score *= 10;
		if (score == 0 && reset)
		{
			// reset misses, bombs, 
			misses = 0;
			bombs_used = 0;
			releases = 0;
			_release_petals = 0;
			spellID = 0;

			reset = false;	// reset once
		}
		if (score > 0)
			reset = true;

		getRubrics();
		printShottype();

		countReleases();

		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(misses) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bombs_used) << std::endl;
		setcolor(YELLOW);
		std::cout << "Release: " << releases << std::endl;
		setcolor(WHITE);
		std::cout << "Score: " << score << std::endl;
		setcolor(LIGHTGRAY);

		calculate_drcp();

		std::cout << "DRC points for survival: " << (int)drcpoints_survival << std::endl;
		std::cout << "DRC points for scoring: " << (int)drcpoints_score << std::endl;
	}
}
