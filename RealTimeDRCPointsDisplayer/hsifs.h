#pragma once

#include "color.h"
#include "drc_assets.h"

namespace ns_hsifs
{
	// Global variables
	bool reset;
	char character, season, difficulty, misses, bombs;
	// new variables for recording key pressed
	DWORD p_is_bomb;
	bool is_bomb, x_reset;
	std::string shottype;
	// for final spell
	DWORD p_spellID;
	char spellID;
	ull score;
	// variables for HSiFS
	unsigned short release_petals, _release_petals, releases;
	// variables with suffix _s are for scoring
	unsigned short base, base_s;
	float exp, exp_s;
	char firstBomb, bomb, firstRelease;

	// character index
	const char* idx_character[] = { "Reimu", "Cirno", "Aya", "Marisa" };
	const char* idx_season[] = { "Spring", "Summer", "Autumn", "Winter" };

	void getShottype()
	{
		shottype = idx_character[character];

		if (idx_difficulty[difficulty] != "Extra")
		{
			shottype += idx_season[season];
		}

		std::cout << "Shottype: " << shottype << std::endl;
	}

	void getRubrics()
	{
		std::cout << "Difficulty: " << idx_difficulty[difficulty] << std::endl;
		getSurvRubrics("HSiFS", idx_difficulty[difficulty], base, exp, firstBomb, bomb, firstRelease);
		getScoreRubrics("HSiFS", idx_difficulty[difficulty], base_s, exp_s);
	}

	void countBombs()
	{
		if (is_bomb && x_reset)	// player is bombing
		{
			bombs++;
			x_reset = false;
		}
		else if (!is_bomb)	// player is not bombing
		{
			x_reset = true;
		}
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
		float decrement = 0;
		float n = 0;
		// make a copy if bombs used
		char _bombs = bombs;

		n += misses * 2;	// default is 2
		if (bombs > 0)
		{
			n += firstBomb;
			_bombs--;
		}
		n += _bombs * 1;	// default is 1

		// make a copy of release variable
		unsigned short _releases = releases;

		if (_releases > 0)
		{
			n += firstRelease;
			_releases--;
		}
		while (_releases > 0)
		{
			for (int i = 0; i < 10; i++)
			{
				n += 0.5f - decrement;
				_releases--;
				if (_releases == 0)
					break;
			}
			decrement += (decrement == 0.4f) ? 0 : 0.1f;
		}

		drcpoints_survival = base * pow(exp, -n) * getMultiplier("HSiFS", shottype.c_str());

		ull wr;
		// catch ReimuWinter Lunatic world record exception
		if (idx_difficulty[difficulty] == "Lunatic" && shottype == "ReimuWinter")
			wr = 0;
		else
			wr = getWR<ull>("HSiFS", idx_difficulty[difficulty], shottype.c_str());

		if (wr == 0)
		{
			std::cout << "This difficulty with this shottype hasn't had a world record yet." << std::endl;
		}

		drcpoints_score = (score >= wr) ? roundf(base_s) : roundf(base_s * (float)pow((long double)score / wr, exp_s));
	}

	void ReadMemory(HANDLE gameProc)
	{
		enum address
		{
			SCORE = 0x004A57B0,
			CHARACTER = 0x004A57A4,
			SEASON = 0x004A57AC,
			DIFFICULTY = 0x004A57B4,
			MISSES = 0x004A57CC,
			P_IS_BOMB = 0x004A6DA8,
			RELEASE_PETALS = 0x004A5808,	// 190 petals = 1 level / level 6 = 1140 petals
			P_SPELLID = 0x004A6DB0
		};

		ReadProcessMemory(gameProc, (void*)SCORE, &score, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)CHARACTER, &character, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)SEASON, &season, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)DIFFICULTY, &difficulty, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)MISSES, &misses, sizeof(char), 0);
		ReadProcessMemory(gameProc, (void*)P_IS_BOMB, &p_is_bomb, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)(p_is_bomb + 0x30), &is_bomb, sizeof(bool), 0);
		ReadProcessMemory(gameProc, (void*)RELEASE_PETALS, &release_petals, sizeof(unsigned short), 0);
		ReadProcessMemory(gameProc, (void*)P_SPELLID, &p_spellID, sizeof(int), 0);
		ReadProcessMemory(gameProc, (void*)(p_spellID + 0x74), &spellID, sizeof(char), 0);

		score *= 10;
		if (score == 0 && reset)
		{
			// reset / initialize
			misses = 0;
			bombs = 0;
			releases = 0;
			_release_petals = 0;
			spellID = 0;

			reset = false;	// reset once
		}
		if (score > 0)
			reset = true;

		getShottype();
		getRubrics();

		countBombs();
		countReleases();

		setcolor(LIGHTRED);
		std::cout << "Misses: " << int(misses) << std::endl;
		setcolor(LIGHTGREEN);
		std::cout << "Bombs: " << int(bombs) << std::endl;
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
