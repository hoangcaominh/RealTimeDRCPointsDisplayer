#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "eosd.h"
#include "pcb.h"
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

constexpr auto GAME_AVAILABLE = 17;

// a handle for found game
HANDLE gameProc;

std::wstring gameList[GAME_AVAILABLE] = {
	L"(HRtP)",
	L"(SoEW)",
	L"(PoDD)",
	L"(LLS)",
	L"(MS)",
	L"東方紅魔郷.exe",
	L"Th07.exe",
	L"th08.exe",
	L"th09.exe",
	L"th10.exe",
	L"th11.exe",
	L"th12.exe",
	L"th128.exe",
	L"th13.exe",
	L"th14.exe",
	L"th15.exe",
	L"th16.exe"
};

BOOL GetProcess()
{
	HANDLE hProcessSnap;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		// Failed to snap process
		return 2;
	}

	PROCESSENTRY32 pe32;

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Now walk the snapshot of processes, and
	// find the process name which matches gameList
	if (Process32First(hProcessSnap, &pe32))
	{
		while (Process32Next(hProcessSnap, &pe32))
		{
			std::wstring *found = std::find(gameList, gameList + GAME_AVAILABLE, pe32.szExeFile);
			if (found != gameList + GAME_AVAILABLE)
			{
				// Open game process
				gameProc = OpenProcess(PROCESS_ALL_ACCESS, false, pe32.th32ProcessID);

				if (!gameProc)
				{
					// Failed to open process
					CloseHandle(hProcessSnap);
					return 3;
				}

				// mark game
				game = found - gameList;

				// Found game, return game name
				CloseHandle(hProcessSnap);
				return 0;
			}
			
		}
	}

	CloseHandle(hProcessSnap);
	return 1;
}

void ReadMemory()
{
	switch (game)
	{
	/* This is juat a copy paste
	case 0:	// HRtP
		ns_eosd::ReadMemory(gameProc);
		break;
	case 1:	// SoEW
		ns_eosd::ReadMemory(gameProc);
		break;
	case 2:	// PoDD
		ns_eosd::ReadMemory(gameProc);
		break;
	case 3:	// LLS
		ns_eosd::ReadMemory(gameProc);
		break;
	case 4:	// MS
		ns_eosd::ReadMemory(gameProc);
		break;
	*/
	case 5:	// EoSD
		ns_eosd::ReadMemory(gameProc);
		break;
	case 6:	// PCB
		ns_pcb::ReadMemory(gameProc);
		break;
	case 7:	// IN
		ns_in::ReadMemory(gameProc);
		break;
	case 8:	// PoFV
		ns_pofv::ReadMemory(gameProc);
		break;
	case 9:	// MoF
		ns_mof::ReadMemory(gameProc);
		break;
	case 10:	// SA
		ns_sa::ReadMemory(gameProc);
		break;
	case 11:	// UFO
		ns_ufo::ReadMemory(gameProc);
		break;
	case 12:	// GFW
		ns_gfw::ReadMemory(gameProc);
		break;
	case 13:	// TD
		ns_td::ReadMemory(gameProc);
		break;
	case 14:	// DDC
		ns_ddc::ReadMemory(gameProc);
		break;
	case 15:	// LoLK
		ns_lolk::ReadMemory(gameProc);
		break;
	case 16:	// HSiFS
		ns_hsifs::ReadMemory(gameProc);
		break;
	}
	return;
}
