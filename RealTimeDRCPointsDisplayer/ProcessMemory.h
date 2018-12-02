#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "eosd.h"
#include "in.h"
#include "lolk.h"
#include "hsifs.h"

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
		ns_lolk::ReadMemory(gameProc);

	// HSiFS
	else if (title == GameName[11])
		ns_hsifs::ReadMemory(gameProc);

	else
		return;
}
