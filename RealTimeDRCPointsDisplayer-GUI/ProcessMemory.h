#pragma once

// #include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Windows.h>
#include <TlHelp32.h>
#include "sha256.h"

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
#include "wbawc.h"

constexpr auto GAME_AVAILABLE = 18;

// a handle for found game
HANDLE gameProc;
DWORD procStatus, GetExitCodeReturn, updateDataFailed;

std::string filehash;

std::wstring gameList[GAME_AVAILABLE] = {
	L"(HRtP)",
	L"(SoEW)",
	L"(PoDD)",
	L"(LLS)",
	L"(MS)",
	L"th06.exe",
	L"th07.exe",
	L"th08.exe",
	L"th09.exe",
	L"th10.exe",
	L"th11.exe",
	L"th12.exe",
	L"th128.exe",
	L"th13.exe",
	L"th14.exe",
	L"th15.exe",
	L"th16.exe",
	L"th17.exe"
};

// SHA256
const char* gamehash_supported[GAME_AVAILABLE] = {
	"",
	"",
	"",
	"",
	"",
	"9f76483c46256804792399296619c1274363c31cd8f1775fafb55106fb852245",
	"35467eaf8dc7fc85f024f16fb2037255f151cefda33cf4867bc9122aaa2e80ca",
	"330fbdbf58a710829d65277b4f312cfbb38d5448b3df523e79350b879213d924",
	"10350095bcf95edb59e03bee9849a2dc8a7714b4927ad5909c569c550fce6822",
	"2f14760b6fbbf57549541583283badb9a19a4222b90f0a146d5aa17f01dc9040",
	"2978b17f6184d100d249d4311348dd30c5c32ec75c014b667a525b797d3d8813",
	"d8d644d2e64957a3031b1a1399d0502e1ddaa5252d2c4e492770ad6717827628",
	"ba515750ece845b56640fe440592fc39ebb7bdd1ed87c541b67a19b148e767d4",
	"422f40aa176c9aab7d0178ce6033802b4143921a5e0e463ef99259ef6d100a58",
	"f08e885e28d2e0fc8c579e88034dd7de8f2a648d8f08ce781cf08eadc9ffe353",
	"67a642357c8777089f468aab9c7a0ae346ebdb62849d842a7b7b18d1e6910364",
	"c11776019f083978e66027e7394dafb1fb9543afca986f28049a49417e341929",
	"85cb011e2e43b316c8fa42a3c402565ecdf2f4379f3bab66d86bcb7beef8255f"
};

std::unordered_map<std::string, std::pair<std::string, std::string>> gamehash[GAME_AVAILABLE] = {
	{},
	{},
	{},
	{},
	{},
	{
		{ "21cddb2b5a7dfaf38e542b707873a35b3fbfd38c1aa21d5b969e1a49a1855f4b", { "v0.13",  "Original" } },
		{ "7152c0ce2667ff10bd5bbe9c3a2052302dec7d326798eb2e70f106e933831a9d", { "v1.00",  "Original" } },
		{ "0adcf7ad5b451d77b5fb86771c3718d242fc7b27dc5940477d289a797e51785f", { "v1.02f", "Original" } },
		{ "9f76483c46256804792399296619c1274363c31cd8f1775fafb55106fb852245", { "v1.02h", "Original" } },
		{ "7f38496b31b8625196900a69cd1bfed243cab1f9612073e7881dc354b876fd39", { "v1.02h", "Original with Kanji name removed" } },
		{ "0883c6433b77af87054d9d05731649c79926a55037840c72d33e50635d64d506", { "v1.02h", "English patch" } },
		{ "fa6562ddfd81f3010d7d87792a69aaa950e0f60b00e42885ef2c30577d8dbe45", { "v1.02h", "English patch with .cfg removed" } },
		{ "8a509709650a83db6850c3498e1e1051dddc6cd46791911c0d78438be8968195", { "v1.02h", "Russian patch" } }
	},
	{
		{ "a44d2581d5a51c5ac93ec2331045e7b29e7386a2414f700097dfab7cd789a34c", { "v0.01",   "Original" } },
		{ "4e0d82301a3dcad4d8cde64aeaf0fdad85bb12941fc4381b744ed8c1be1cdedc", { "v0.02",   "Original" } },
		{ "6c07a9f90ff2a60fe2c1d4f04573aae440baa040c7d87a335d9aa4ff6483b4de", { "v0.03",   "Original" } },
		{ "5d38b33e6bcb1c968b95cdf9bb751ca5116c36b14378690e40743bb3cd8473ae", { "v0.04a",  "Original" } },
		{ "8ee7fb3fb0f38e1c1144d95cfecb13120d6ee6ebc01992e28f6891f579771f5c", { "v0.04a2", "Original" } },
		{ "8bf865803ee88f2765f1def53a3a4872871d8e5478fe93c5df77cfc1663caadc", { "v0.04b",  "Original" } },
		{ "7bfaf12cdf6bfd4444e2c3f63a4ad07c2a10aa88aa7113c90d48f3f479726e97", { "v0.06",   "Original" } },
		{ "2ca6b41ce2b07fb2b8a119f9683fc497dd724edcbc130b5076f8d86323b9091f", { "v0.11",   "Original" } },
		{ "1251458d0564c565610b28bc94a434f5d4e8aee5d0882fa278b19277c7ac4cf7", { "v1.00",   "Original" } },
		{ "8198b75faf42ad4ab7e509a089bfbb3a4ffb03927350b70926227a6e26255914", { "v1.00a",  "Original" } },
		{ "35467eaf8dc7fc85f024f16fb2037255f151cefda33cf4867bc9122aaa2e80ca", { "v1.00b",  "Original" } },
		{ "275cfdcab6ad463be4d3d646ddc21811dc65cb1c7e88c7b18bb8a89f25316655", { "v1.00b",  "English patch" } }
	},
	{
		{ "a0e04caa9e51f305009aa434ce5bd787424224b972ad72470a77827d36ac8081", { "v0.03",  "Original" } },
		{ "e287dbb4d19781f2da9c161ac0010df7e52e8c8a238c339838a631cfc3b02682", { "v1.00",  "Original" } },
		{ "f271a1cadfefb9586e0b7a6ed71855f839f7cfbbce2dbdba62c064087467da9c", { "v1.00a", "Original" } },
		{ "0b94bf89ed9d0011305fba5256af6ec9219b0c9da97735022fd1e5ee0f2aff17", { "v1.00b", "Original" } },
		{ "f1a7c5941358b83fa11a9f3619ba3b2e2ef4674a4dca1cfcc423ca21d9889acf", { "v1.00c", "Original" } },
		{ "330fbdbf58a710829d65277b4f312cfbb38d5448b3df523e79350b879213d924", { "v1.00d", "Original" } },
		{ "467085c3c85ceed4b6f5be410e14cd56f1af0b5afa4e0c752270b56ecbc470cf", { "v1.00d", "English patch" } }
	},
	{
		{ "de2076269ed3747cdbec840dd3eb7b155407f5e536b8caa83d26fc716e9a67cc", { "v0.02a", "Original" } },
		{ "234195e017548c2114c664a6f5592be64720dad5d445a24602e8fa2e792f97ef", { "v1.00",  "Original" } },
		{ "10350095bcf95edb59e03bee9849a2dc8a7714b4927ad5909c569c550fce6822", { "v1.50a", "Original" } },
		{ "f402287326bcee15b6eda743f1edb7882294257d65c8d828d849110cb0c53bb6", { "v1.50a", "English patch" } }
	},
	{
		{ "5430fac601d645798ccf794362ec7d4cd753814f09d160247dc628b7c6943fd8", { "v0.02a", "Original" } },
		{ "2f14760b6fbbf57549541583283badb9a19a4222b90f0a146d5aa17f01dc9040", { "v1.00a", "Original" } },
		{ "d28e36a6596a4c64b441c148d65a8c12b68e4a683f1d14e7df83d43f92c57d71", { "v1.00a", "English patch" } },
		{ "3bdb72cf3d7c33c183359d368c801490dbcf54e6b3b2f060b95d72250b6866a3", { "v1.00a", "Steam release" } }
	},
	{
		{ "360f542349a08707de5c788ef5a950d5d3ad0fd727a23e74b6813db40dfe77a9", { "v0.02a", "Original" } },
		{ "2978b17f6184d100d249d4311348dd30c5c32ec75c014b667a525b797d3d8813", { "v1.00a", "Original" } },
		{ "18555e5055909570dbf46ca2a7cb796c50174fcdffb863a83357110d7f3f770b", { "v1.00a", "English patch" } },
		{ "f42c5d3540489e8c99ac81d88293ef7a830ad3a402d67dcd83f575816775dbd7", { "v1.00a", "Korean patch (Gungsuh font)" } },
		{ "5cc754c4ddd52ee788910a479372330645969fffaade5b3a7a42c8b099e8dbbe", { "v1.00a", "Korean patch (Nanum Gothic font)" } },
		{ "47cbcfdba984e32ba2887bc0a8c35e21aa8a039c1d87675da8493544d86e2a42", { "v1.00a", "Steam release" } },
	},
	{
		{ "c6d15044394a33d6116c09eac44b33fdec814541c78518e29f60d54f49bdbd3a", { "v0.02a", "Original" } },
		{ "e2939ba3f92e427216a619191a682a8197cc59a64eab99302a7b98811d6120a9", { "v1.00a", "Original" } },
		{ "d8d644d2e64957a3031b1a1399d0502e1ddaa5252d2c4e492770ad6717827628", { "v1.00b", "Original" } },
		{ "0c9ac1c756eaef681f7538af72b297877ac13f06c2ca2df743e8a29d96672d08", { "v1.00b", "Score counter bugfix" } },
		{ "9bcc0675792a057d97a5f560c3d0cf21d07cb02f01d47a9207dcbe1c5efffee5", { "v1.00b", "English patch" } },
		{ "d116fed3eef093607f8c4b55fd0ec45dfc99139a7e1913f88570db0968341ba2", { "v1.00b", "English patch, score counter bugfix" } },
		{ "eb275a8c285fd8450fa5ac79fa730a759aeca8b2904aeb16d30e65859372a459", { "v1.00b", "Steam release" } },
	},
	{
		{ "ba515750ece845b56640fe440592fc39ebb7bdd1ed87c541b67a19b148e767d4", { "v1.00a", "Original" } },
		{ "f26586b24673d0e1477ebbb698c82470803730e11f950caa428c7d25d6e0a415", { "v1.00a", "English patch" } },
		{ "73781a26417b823c3b1efe7065bb0c93337e9d50634347a1347c5359457f3ae0", { "v1.00a", "Steam release" } },
	},
	{
		{ "09818929cceea76ff4c65630e649bbccdb85d92b2e28bb4dfe6526749e6f4fb6", { "v0.01a", "Original" } },
		{ "6e95052ca552330659fdc1afa7042926573b4133087bb802a745fa68efd7ac74", { "v1.00a", "Original" } },
		{ "3fce325a063439c2e78fd0f95db519f1c83df7c3cf7b6c36e5ca46f7993f97ff", { "v1.00a", "Aero patch" } },
		{ "ac0f9d9d0dc92739b52661c5e9f5bf4bab13349bedec1cc87b2330d00f776a2d", { "v1.00b", "Original" } },
		{ "422f40aa176c9aab7d0178ce6033802b4143921a5e0e463ef99259ef6d100a58", { "v1.00c", "Original" } },
		{ "2368f892d2d15ce96e546de33290501bccd03188b875649012d43616314d21c3", { "v1.00c", "English patch" } },
		{ "1a6e3eb3b65238a739d7250606e9cb233d16b505c3340a11c4584b583388930d", { "v1.00c", "Steam release" } },
	},
	{
		{ "72a7e52d978fb7fcfc0a3a2ced1096305b9161279a029bbf9df2f0b8cb0fe84a", { "v0.01a",  "Original, Reitaisai trial" } },
		{ "6c62bff1e6be644086c5811c36eb938818f14012f94ad5fce784ca7889c66d48", { "v0.01b",  "Original, web trial" } },
		{ "5cbb053091eca055f850d316f818d10c47450b1198b8136bf096bab94fe53da3", { "v0.01bp", "Original, Playism trial" } },
		{ "498b3c186387dbcebbae86263bb1144d8fc4f17c8957197eaa7169d90a73eeb6", { "v1.00a",  "Original" } },
		{ "f08e885e28d2e0fc8c579e88034dd7de8f2a648d8f08ce781cf08eadc9ffe353", { "v1.00b",  "Original" } },
		{ "147b2b36582465638783c9431a1cc9940c85f6025116832992bdb8594e396a52", { "v1.00bp", "Original, Playism release" } },
		{ "4609e701b677b8317e43be92041f0c7075a292182848a7c11215c3a226034f90", { "v1.00b",  "Steam release" } },
	},
	{
		{ "24447efbfef5c4dc2f987fff5a66e88c107a7e235fe67f4d01642001abe6136b", { "v0.01a", "Original, Reitaisai trial" } },
		{ "2e5b3969cea763e6caf26cd926bc1f8b4f60f900971a695cee99925bb5955d2c", { "v0.01b", "Original, web trial" } },
		{ "a9048c3bd922b9bc21b0b760c925b55129aebe7950927026c75ae04a32183562", { "v1.00a", "Original" } },
		{ "67a642357c8777089f468aab9c7a0ae346ebdb62849d842a7b7b18d1e6910364", { "v1.00b", "Original" } },
	},
	{
		{ "6dd1c7ac48be083a8c3b90434245186a3a6e6293a46359ebc96a43fcf98e1486", { "v0.01a", "Original" } },
		{ "c11776019f083978e66027e7394dafb1fb9543afca986f28049a49417e341929", { "v1.00a", "Original" } },
		{ "aee27f70c2b9f7e7acba15b3b35449c79e4d707e404646362b8edf961a574731", { "v1.00a", "Steam release" } },
		{ "28706073602c95bccafd86ee535b54e8ab9312cf6d211343c7ceab5bad7968da", { "v1.00a", "Unpacked Steam release)" } },
	},
	{
		{ "3ffa3963003cce6dc02b1dae5adeb4411138772834efdb195a05b9081027aaba", { "v0.01a", "Original" } },
		{ "41304c38acc014787df29604e6f4b35ce6ae74938999eb11b9381f5232d5ff9b", { "v0.01a", "Steam release" } },
		{ "bbfdd8d76e5a806738256bb4efe053954bf666a0c2755d8e5458873f70de754a", { "v1.00a", "Original" } },
		{ "85cb011e2e43b316c8fa42a3c402565ecdf2f4379f3bab66d86bcb7beef8255f", { "v1.00b", "Original" } },
		{ "470769ddfbac9404b3fdacbb05893fae387943c22605935ea5ec6caee8388d4d", { "v1.00b", "Steam release" } },
	}
};

BOOL VerifyVersion(wchar_t* filename, int gameindex)
{
	unsigned char* buffer = 0;
	long filesize;
	FILE* f;

	_wfopen_s(&f, filename, L"rb");
	if (f)
	{
		// determine size of file
		fseek(f, 0, SEEK_END);
		filesize = ftell(f);
		fseek(f, 0, SEEK_SET);

		// read file content
		buffer = (unsigned char*)malloc(filesize + 1);
		if (buffer)
		{
			fread(buffer, 1, filesize, f);
		}
		fclose(f);
		buffer[filesize] = '\0';

		// hash
		SHA256_CTX ctx;
		BYTE hash[32];
		char hash_str[65];

		sha256_init(&ctx);
		sha256_update(&ctx, buffer, filesize);
		sha256_final(&ctx, hash);
		free(buffer);

		hash_str[64] = '\0';
		for (int i = 0; i < 32; i++)
		{
			sprintf(hash_str + (i * 2), "%02x", hash[i]);
		}
		filehash = hash_str;

		// verify
		if (strcmp(hash_str, gamehash_supported[gameindex]) == 0)
			return 0;
		else if (gamehash[gameindex].find(hash_str) != gamehash[gameindex].end())
			return 1;
		else
			return 2;
	}
	return -1;
}

BOOL GetProcessFullPath(DWORD procid, wchar_t* fullpath)
{
	HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32 | TH32CS_SNAPMODULE, procid);
	if (hModuleSnap == INVALID_HANDLE_VALUE)
	{
		return 2;
	}

	MODULEENTRY32 me32;
	me32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hModuleSnap, &me32))
	{
		wcscpy_s(fullpath, wcslen(me32.szExePath) + 1, me32.szExePath);
		CloseHandle(hModuleSnap);
		return 0;
	}

	CloseHandle(hModuleSnap);
	return -1;
}

BOOL GetProcess()
{
	HANDLE hProcessSnap;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		// Failed to snap process
		return -4;
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
			std::wstring processName = pe32.szExeFile;
			// lowercase all letters
			std::transform(processName.begin(), processName.end(), processName.begin(), ::tolower);
			std::wstring *found = std::find(gameList, gameList + GAME_AVAILABLE, processName);
			if (found == gameList + GAME_AVAILABLE && processName == L"東方紅魔郷.exe")	// EoSD exception
				found = gameList + 5;

			if (found != gameList + GAME_AVAILABLE)
			{
				// mark game
				game = found - gameList;
				
				wchar_t fullpath[260];
				GetProcessFullPath(pe32.th32ProcessID, fullpath);

				BOOL verify = VerifyVersion(fullpath, game);
				if (verify >= 0)
				{
					// Open game process
					gameProc = OpenProcess(PROCESS_ALL_ACCESS, false, pe32.th32ProcessID);

					if (!gameProc)
					{
						// Failed to open process
						CloseHandle(hProcessSnap);
						return -2;
					}
				}
				// Found game, return game name
				CloseHandle(hProcessSnap);
				return verify;
			}
		}
	}

	CloseHandle(hProcessSnap);
	return -3;
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
	case 17:	// WBaWC
		ns_wbawc::ReadMemory(gameProc);
		break;
	}
	return;
}
