#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "eosd.h"
#include "in.h"

constexpr auto GAME_AVAILABLE = 12;

using string = std::string;

// a handle for found game
HANDLE gameProc;
string gameProcname;

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

void ReadMemory_PCB()
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
	/*
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
	*/
	/*
0x004A57B4: difficulty value (0 = easy, 4 = extra)
0x004A57F4: number of lives
0x004A5800: number of bombs
0x004A5808: number of release petal (each 190 petals = 1 level, LV6 = 1140 max)
	*/
}

bool GetProcess()
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
					gameProcname = GameName[i];
					gameProc = OpenProcess(PROCESS_VM_READ, false, pe32.th32ProcessID);

					if (!gameProc)
					{
						std::cout << "Failed to open game process." << std::endl;
						CloseHandle(hProcessSnap);
						return false;
					}

					// Found game, return game name

					CloseHandle(hProcessSnap);
					return true;
				}
			}
		}
	}

	CloseHandle(hProcessSnap);
	return false;
}

void ReadMemory(string title)
{
	// EoSD
	if (title == GameName[0])
		ns_eosd::ReadMemory(gameProc);

	// PCB
	else if (title == GameName[1])
		ReadMemory_PCB();

		// IN
	else if (title == GameName[2])
		ns_in::ReadMemory(gameProc);

		// PoFV
	else if (title == GameName[3])
		ReadMemory_PoFV();

		// MoF
	else if (title == GameName[4])
		ReadMemory_MoF();

		// SA
	else if (title == GameName[5])
		ReadMemory_SA();

		// UFO
	else if (title == GameName[6])
		ReadMemory_UFO();

		// GFW
	else if (title == GameName[7])
		ReadMemory_GFW();

		// TD
	else if (title == GameName[8])
		ReadMemory_TD();

		// DDC
	else if (title == GameName[9])
		ReadMemory_DDC();

		// LoLK
	else if (title == GameName[10])
		ReadMemory_LoLK();

		// HSiFS
	else if (title == GameName[11])
		ReadMemory_HSiFS();

	else
		return;
}
