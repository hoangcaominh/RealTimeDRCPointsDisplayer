#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "eosd.h"
#include "in.h"
#include "pofv.h"
#include "mof.h"
#include "sa.h"
#include "ufo.h"
#include "gfw.h"
#include "td.h"
#include "ddc.h"
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
	{
		game = 5;
		ns_eosd::ReadMemory(gameProc);
	}

	// PCB
	else if (title == GameName[1])
		std::cout << "This game is currently unsupported. Please wait warmly." << std::endl;

	// IN
	else if (title == GameName[2])
	{
		game = 7;
		ns_in::ReadMemory(gameProc);
	}

	// PoFV
	else if (title == GameName[3])
	{
		game = 8;
		ns_pofv::ReadMemory(gameProc);
	}

	// MoF
	else if (title == GameName[4])
	{
		game = 9;
		ns_mof::ReadMemory(gameProc);
	}

	// SA
	else if (title == GameName[5])
	{
		game = 10;
		ns_sa::ReadMemory(gameProc);
	}

	// UFO
	else if (title == GameName[6])
	{
		game = 11;
		ns_ufo::ReadMemory(gameProc);
	}

	// GFW
	else if (title == GameName[7])
	{
		game = 12;
		ns_gfw::ReadMemory(gameProc);
	}

	// TD
	else if (title == GameName[8])
	{
		game = 13;
		ns_td::ReadMemory(gameProc);
	}

	// DDC
	else if (title == GameName[9])
	{
		game = 14;
		ns_ddc::ReadMemory(gameProc);
	}

	// LoLK
	else if (title == GameName[10])
	{
		game = 15;
		ns_lolk::ReadMemory(gameProc);
	}

	// HSiFS
	else if (title == GameName[11])
	{
		game = 16;
		ns_hsifs::ReadMemory(gameProc);
	}

	else
		return;
}
