#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "ProcessJSON.h"

constexpr auto GAME_AVAILABLE = 12;

using string = std::string;

// a handle for found game
HANDLE gameProc;

// Global variables
int drcpoints_survival, drcpoints_score;
char character, type, difficulty, miss_deathbomb, bomb, false_miss = 0, _miss_deathbomb, _bomb;
int score;

string GameName[GAME_AVAILABLE] = {
	"東方紅魔郷.exe",
	"Th07.exe",
	"th08.exe",
	"th09.exe",
	"th10.exe",
	"th11.exe",
	"th12.exe",
	"th128.exe",
	"th13.exe",
	"th14.exe",
	"th15.exe",
	"th16.exe"
};

// color for output
enum color
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

void setcolor(WORD color)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd     color
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
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

float getMultiplier(int character, int type)
{
	if (character == REIMU && type == TYPE_A)
		return 1.05;
	else if (character == MARISA && type == TYPE_A)
		return 1.1;
	else
		return 1;
}

int getWr(int difficulty, int character, int type)
{
	int wr;
	switch (difficulty)
	{
	case EASY:
		switch (character)
		{
		case REIMU:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.easy.ReimuA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.easy.ReimuB;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.easy.MarisaA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.easy.MarisaB;
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
				wr = _EoSD.wr.normal.ReimuA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.normal.ReimuB;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.normal.MarisaA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.normal.MarisaB;
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
				wr = _EoSD.wr.hard.ReimuA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.hard.ReimuB;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.hard.MarisaA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.hard.MarisaB;
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
				wr = _EoSD.wr.lunatic.ReimuA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.lunatic.ReimuB;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.lunatic.MarisaA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.lunatic.MarisaB;
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
				wr = _EoSD.wr.extra.ReimuA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.extra.ReimuB;
				break;
			}
			break;
		case MARISA:
			switch (type)
			{
			case TYPE_A:
				wr = _EoSD.wr.extra.MarisaA;
				break;
			case TYPE_B:
				wr = _EoSD.wr.extra.MarisaB;
				break;
			}
			break;
		}
		break;
	}
	return wr;
}

void ReadMemory_EoSD()
{
	if (!gameProc)
	{

	}
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
	if (miss_deathbomb > _miss_deathbomb && bomb > _bomb)
	{
		false_miss++;
	}
	_miss_deathbomb = miss_deathbomb;
	_bomb = bomb;
	int base, base_s;
	double exp, exp_s;
	std::cout << "Difficulty: ";
	switch (difficulty)
	{
	case EASY:
		std::cout << "Easy" << std::endl;
		base = 50;
		exp = 1.05;
		base_s = 350;
		exp_s = 4;
		break;
	case NORMAL:
		std::cout << "Normal" << std::endl;
		base = 100;
		exp = 1.05;
		base_s = 400;
		exp_s = 3;
		break;
	case HARD:
		std::cout << "Hard" << std::endl;
		base = 150;
		exp = 1.05;
		base_s = 450;
		exp_s = 2.5;
		break;
	case LUNATIC:
		std::cout << "Lunatic" << std::endl;
		base = 320;
		exp = 1.05;
		base_s = 500;
		exp_s = 2;
		break;
	case EXTRA:
		std::cout << "Extra" << std::endl;
		base = 110;
		exp = 1.08;
		base_s = 450;
		exp_s = 2.5;
		break;
	}
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

	int real_miss = miss_deathbomb - false_miss;
	setcolor(LIGHTRED);
	std::cout << "Misses (Experimental): " << real_miss << std::endl;
	std::cout << "Misses + Deathbomb: " << int(miss_deathbomb) << std::endl;
	setcolor(LIGHTGREEN);
	std::cout << "Bombs: " << int(bomb) << std::endl;
	setcolor(WHITE);
	std::cout << "Score: " << score << std::endl;

	int n = 0;
	n += real_miss * 2;	// 2 is rubric miss base in any difficulty
	if (bomb > 0)
	{
		n += 3;	// 3 is rubric first bomb base in any difficulty
		bomb--;
	}
	n += bomb * 1;	// 1 is rubric bomb base in any difficulty

	int wr = getWr(difficulty, character, type);
	drcpoints_survival = int(base * pow(exp, (0 - n)) * getMultiplier(character, type));
	if (score >= wr)
	{
		drcpoints_score = base_s;
	}
	else
	{
		drcpoints_score = int(base_s * pow(float(score) / wr, exp_s));
	}
	
	setcolor(LIGHTGRAY);
	std::cout << "DRC points for survival: " << drcpoints_survival << std::endl;
	std::cout << "DRC points for scoring: " << drcpoints_score << std::endl;
}

void ReadMemory_PCB()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_IN()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_PoFV()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_MoF()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_SA()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_UFO()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_GFW()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_TD()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_DDC()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_LoLK()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
}

void ReadMemory_HSiFS()
{
	std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;
	// Score
	char buffer_score[4];
	// ull score;
	ReadProcessMemory(gameProc, (void*)0x004A57B0, buffer_score, 1, 0);

	// score = int(buffer_score[0]) + int(buffer_score[1]) * pow(16, 2) + int(buffer_score[2]) * pow(16, 4) + int(buffer_score[3]) * pow(16, 6) + 10;

	// Character value (0 - 3)
	char buffer_character[1];
	ReadProcessMemory(gameProc, (void*)0x004A57A4, buffer_character, 1, 0);

	// Season value (0 - 3)
	char buffer_season[1];
	ReadProcessMemory(gameProc, (void*)0x004A57AC, buffer_season, 1, 0);

	// Difficulty value (0 - 4)
	char buffer_diff[1];
	ReadProcessMemory(gameProc, (void*)0x004A57B4, buffer_diff, 1, 0);
	/*
0x004A57B4: difficulty value (0 = easy, 4 = extra)
0x004A57F4: number of lives
0x004A5800: number of bombs
0x004A5808: number of release petal (each 190 petals = 1 level, LV6 = 1140 max)
	*/
}

string GetProcess()
{
	HANDLE hProcessSnap;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		std::cout << "Failed to snap process." << std::endl;
		return false;
	}

	PROCESSENTRY32 pe32;

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Now walk the snapshot of processes, and
	// find the process name which matches GameName
	if (Process32First(hProcessSnap, &pe32))
	{
		while (Process32Next(hProcessSnap, &pe32))
		{
			// for loop
			for (int i = 0; i < GAME_AVAILABLE; i++)
			{
				if ((string)pe32.szExeFile == GameName[i])
				{
					// Open game process
					gameProc = OpenProcess(PROCESS_VM_READ, false, pe32.th32ProcessID);

					if (!gameProc)
					{
						std::cout << "Failed to open game process." << std::endl;
						CloseHandle(hProcessSnap);
						return "";
					}

					// Found game, return game name

					CloseHandle(hProcessSnap);
					return GameName[i];
				}
			}
		}
	}

	CloseHandle(hProcessSnap);
	return "";
}

bool ReadMemory(string title)
{
	// EoSD
	if (title == GameName[0])
	{
		ReadMemory_EoSD();
		return true;
	}
	// PCB
	else if (title == GameName[1])
	{
		ReadMemory_PCB();
		return true;
	}
	// IN
	else if (title == GameName[2])
	{
		ReadMemory_IN();
		return true;
	}
	// PoFV
	else if (title == GameName[3])
	{
		ReadMemory_PoFV();
		return true;
	}
	// MoF
	else if (title == GameName[4])
	{
		ReadMemory_MoF();
		return true;
	}
	// SA
	else if (title == GameName[5])
	{
		ReadMemory_SA();
		return true;
	}
	// UFO
	else if (title == GameName[6])
	{
		ReadMemory_UFO();
		return true;
	}
	// GFW
	else if (title == GameName[7])
	{
		ReadMemory_GFW();
		return true;
	}
	// TD
	else if (title == GameName[8])
	{
		ReadMemory_TD();
		return true;
	}
	// DDC
	else if (title == GameName[9])
	{
		ReadMemory_DDC();
		return true;
	}
	// LoLK
	else if (title == GameName[10])
	{
		ReadMemory_LoLK();
		return true;
	}
	// HSiFS
	else if (title == GameName[11])
	{
		ReadMemory_HSiFS();
		return true;
	}
	else
	{
		return false;
	}
}
