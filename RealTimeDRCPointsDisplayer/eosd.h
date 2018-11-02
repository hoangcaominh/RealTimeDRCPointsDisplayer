#pragma once

#include "color.h"
#include "ProcessJSON.h"

namespace ns_eosd
{
	// Global variables
	char character, type, difficulty, miss_deathbomb, bomb, false_miss = 0, _miss_deathbomb, _bomb;
	ull score;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	char first_bomb;
	float exp, exp_s;
	char frame_count;	// used when a deathbomb is performed
	
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
		MARISA
	};
	enum _TYPE
	{
		TYPE_A,
		TYPE_B
	};

	float getMultiplier(char character, char type)
	{
		if (character == REIMU && type == TYPE_A)
			return 1.05f;
		else if (character == MARISA && type == TYPE_A)
			return 1.1f;
		else
			return 1.0f;
	}

	ull getWr(char difficulty, char character, char type)
	{
		ull wr;
		switch (difficulty)
		{
		case EASY:
			switch (character)
			{
			case REIMU:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.easy.ReimuA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.easy.ReimuB;
					break;
				}
				break;
			case MARISA:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.easy.MarisaA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.easy.MarisaB;
					break;
				}
				break;
			}
			break;
		case NORMAL:
			switch (character)
			{
			case REIMU:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.normal.ReimuA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.normal.ReimuB;
					break;
				}
				break;
			case MARISA:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.normal.MarisaA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.normal.MarisaB;
					break;
				}
				break;
			}
			break;
		case HARD:
			switch (character)
			{
			case REIMU:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.hard.ReimuA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.hard.ReimuB;
					break;
				}
				break;
			case MARISA:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.hard.MarisaA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.hard.MarisaB;
					break;
				}
				break;
			}
			break;
		case LUNATIC:
			switch (character)
			{
			case REIMU:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.lunatic.ReimuA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.lunatic.ReimuB;
					break;
				}
				break;
			case MARISA:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.lunatic.MarisaA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.lunatic.MarisaB;
					break;
				}
				break;
			}
			break;
		case EXTRA:
			switch (character)
			{
			case REIMU:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.extra.ReimuA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.extra.ReimuB;
					break;
				}
				break;
			case MARISA:
				switch (type)
				{
				case TYPE_A:
					wr = EoSD.wrs.extra.MarisaA;
					break;
				case TYPE_B:
					wr = EoSD.wrs.extra.MarisaB;
					break;
				}
				break;
			}
			break;
		}
		return wr;
	}

	void getRubrics(char difficulty)
	{
		std::cout << "Difficulty: ";

		switch (difficulty)
		{
		case EASY:
			std::cout << "Easy" << std::endl;
			base = 50;
			exp = 1.05f;
			first_bomb = 2;
			base_s = 350;
			exp_s = 4.0f;
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
			base = 320;
			exp = 1.05f;
			first_bomb = 5;
			base_s = 500;
			exp_s = 2.0f;
			break;
		case EXTRA:
			std::cout << "Extra" << std::endl;
			base = 110;
			exp = 1.08f;
			first_bomb = 3;
			base_s = 450;
			exp_s = 2.5f;
			break;
		}
	}

	void printShottype(char character, char type)
	{
		std::cout << "Shottype: ";

		switch (character)
		{
		case REIMU:
			switch (type)
			{
			case TYPE_A:
				std::cout << "ReimuA" << std::endl;
				break;
			case TYPE_B:
				std::cout << "ReimuB" << std::endl;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				std::cout << "MarisaA" << std::endl;
				break;
			case TYPE_B:
				std::cout << "MarisaB" << std::endl;
				break;
			}
			break;
		}
	}

	void calculate_drcp(char real_miss)
	{
		char n = 0;
		n += real_miss * 2;	// 2 is rubric miss base in any difficulty
		if (bomb > 0)
		{
			n += first_bomb;
			bomb--;
		}
		n += bomb * 1;	// 1 is rubric bomb base in any difficulty

		ull wr = getWr(difficulty, character, type);
		drcpoints_survival = (unsigned short)(base * pow(exp, (0 - n)) * getMultiplier(character, type));
		if (score >= wr)
		{
			drcpoints_score = roundf(base_s);
		}
		else
		{
			drcpoints_score = roundf(base_s * (float)pow((double)score / wr, exp_s));
		}
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			CHARACTER = 0x0069D4BD,
			TYPE = 0x0069D4BE,
			DIFFICULTY = 0x0069BCB0,
			SCORE = 0x0069BCA0,
			MISS_DEATHBOMB = 0x0069BCC0,
			BOMB = 0x0069BCC4
		};

		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)TYPE, &type, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)MISS_DEATHBOMB, &miss_deathbomb, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)BOMB, &bomb, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);

		// reset false miss
		if (score == 0)
		{
			false_miss = 0;
		}

		// deathbomb case
		if (miss_deathbomb > _miss_deathbomb || frame_count > 0)	// when a miss or a deathbomb is performed, frame_count starts counting
			frame_count++;
		if (bomb > _bomb && frame_count > 0 && frame_count < 5)	// this is true if a deathbomb is performed within 0.5 second
		{
			false_miss++;
			frame_count = 0;	// reset frame_count
		}
		if (frame_count >= 5)	// this is a normal miss
			frame_count = 0;	// reset frame count
		
		_miss_deathbomb = miss_deathbomb;
		_bomb = bomb;

		getRubrics(difficulty);
		printShottype(character, type);

		char real_miss = miss_deathbomb - false_miss;
		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(real_miss) << std::endl;
		// std::cout << "Misses + Deathbomb: " << int(miss_deathbomb) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bomb) << std::endl;
		setcolor(WHITE);
		std::cout << "Score: " << score << std::endl;

		calculate_drcp(real_miss);

		setcolor(LIGHTGRAY);
		std::cout << "DRC points for survival: " << (int)drcpoints_survival << std::endl;
		std::cout << "DRC points for scoring: " << (int)drcpoints_score << std::endl;
	}
}
