#pragma once
#include "drc_survival.h"
#include "drc_score.h"
#include "drc_wr.h"

struct HRtP
{
    // survival struct is not available

    // score
    drc_diff_score score;

	// world record
	HRtP_wr wr;

} _HRtP;
//_HRtP {300, 11, 325, 11, 350, 11, 400, 10, 0, 0};

struct SoEW
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuC = 1.05;
	*/
	// world record
	SoEW_wr wr;

} _SoEW;
/*_SoEW {40, 1.05, 2, 2, 1,
        80, 1.05, 2, 3, 1,
        120, 1.05, 2, 3, 1,
        250, 1.05, 2, 5, 1,
        100, 1.1, 2, 3, 1,
        300, 4, 300, 4, 350, 3, 375, 2, 325, 5};
		*/

struct PoDD
{
    // phantasmagoria
    drc_diff_phantasmagoria phantasmagoria;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float Mima = 1.1;
    float Marisa = 1.1;
    float Ellen = 1.2;
    float Kotohime = 1.1;
    float Kana = 1.15;
    float Chiyuri = 1.2;
	*/
	// world record
	PoDD_wr wr;
} _PoDD;
/*_PoDD{ 50, 15, 5, 10,
        90, 25, 5, 20,
        130, 40, 5, 30,
        260, 50, 5, 50,
        300, 4, 350, 3, 400, 3, 450, 2};
		*/

struct LLS
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuA = 1.05;
    float ReimuB = 1.05;
    float MarisaB = 1.1;
	*/
	// world record
	LLS_wr wr;
} _LLS;
/*_LLS{ 40, 1.05, 2, 2, 1,
        90, 1.05, 2, 2, 1,
        140, 1.05, 2, 2, 1,
        290, 1.07, 2, 3, 1,
        90, 1.07, 2, 3, 1,
        300, 4, 350, 3, 375, 3, 400, 2.5, 350, 9};
		*/

struct MS
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float Reimu = 1.05;
    float Marisa = 1.05;
    float Yuuka = 1.1;
	*/
	// world record
	MS_wr wr;
} _MS;
/*_MS{ 60, 1.05, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        150, 1.05, 2, 3, 1,
        300, 1.07, 2, 5, 1,
        100, 1.08, 2, 3, 1,
        300, 4, 350, 3, 400, 3, 450, 2, 375, 4};
		*/

struct EoSD
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuA = 1.05;
    float MairsaA = 1.1;
	*/
	// world record
	EoSD_wr wr;
} _EoSD;
/*_EoSD{ 50, 1.05, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        150, 1.05, 2, 3, 1,
        320, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        350, 4, 400, 3, 450, 2.5, 500, 2, 450, 2.5};
		*/

struct PCB
{
    // survival + phantasm difficulty, exclusive for PCB
    drc_diff_survival survival;
    drc_survival phantasm_survival;
    // score + phantasm difficulty, exclusive for PCB
    drc_diff_score score;
    drc_score phantasm_score;
	/*
    // multiplier
    float ReimuA = 1.05;
    float MairsaA = 1.05;
    float MarisaB = 1.05;
	*/
	// world record
	PCB_wr wr;
} _PCB;
/*_PCB{ 60, 1.05, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        150, 1.05, 2, 5, 1,
        280, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 1.5, 450, 2.5, 450, 2.5};
		*/

struct IN
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float MagicTeam = 1.05;
    float ScarletTeam = 1.05;
    float Reimu = 1.1;
    float Yukari = 1.05;
    float Marisa = 1.05;
    float Alice = 1.2;
    float Sakuya = 1.2;
    float Remilia = 1.1;
    float Yuyuko = 1.1;
	*/
	// world record
	IN_wr wr;
} _IN;
/*_IN{ 45, 1.05, 2, 2, 1,
        90, 1.05, 2, 3, 1,
        140, 1.05, 2, 3, 1,
        290, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 2.1, 450, 3};
		*/

struct PoFV
{
    // survival
    drc_diff_phantasmagoria phantasmagoria;
    // phantasmagoria extra, exclusive for PoFV
    drc_phantasmagoria extra;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float Reisen = 1.05;
    float Lyrica = 1.05;
    float Tewi = 1.05;
    float Aya = 0.5;
    float Medicine = 0.5;
    float Yuuka = 1.05;
	*/
	// world record
	PoFV_wr wr;
} _PoFV;
/*_PoFV{ 40, 10, 7, 10,
        70, 15, 7, 20,
        100, 20, 7, 30,
        210, 30, 7, 50,
        85, 15, 8, 25,
        375, 4, 400, 3, 450, 2.5, 500, 2, 450, 2.5};
		*/

struct MoF
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuA = 1.05;
    float ReimuC = 1.15;
    float MarisaA = 1.15;
    float MarisaB = 1.05;
	*/
	// world record
	MoF_wr wr;
} _MoF;
/*_MoF{ 60, 1.05, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        150, 1.05, 2, 4, 1,
        290, 1.05, 2, 5, 1,
        105, 1.08, 2, 3, 1,
        };
		*/

struct SA
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuB = 1.05;
    float ReimuC = 1.1;
    float MarisaA = 1.05;
    float MarisaC = 1.15;
	*/
	// world record
	SA_wr wr;
} _SA;
/*_SA{ 50, 1.05, 2, 2, 1,
        110, 1.05, 2, 3, 1,
        150, 1.05, 2, 3, 1,
        300, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 2.2, 450, 6.5};
		*/

struct UFO
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuB = 1.05;
    float MarisaA = 1.05;
    float MarisaB = 1.15;
    float SanaeA = 1.05;
	*/
	// world record
	UFO_wr wr;
} _UFO;
/*_UFO{ 50, 1.05, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        160, 1.05, 2, 4, 1,
        315, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 2, 450, 3};
		*/

struct GFW
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float B1 = 1.15;
    float B2 = 1.05;
    float C1 = 1.15;
	*/
	// world record
	GFW_wr wr;
} _GFW;
/*_GFW{ 50, 1.09, 2, 2, 1,
        90, 1.08, 2, 3, 1,
        130, 1.06, 2, 3, 1,
        260, 1.06, 2, 4, 1,
        130, 1.07, 2, 3, 1,
        375, 8.5, 400, 7.5, 450, 7, 500, 6.5, 450, 7};
		*/

struct TD
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float Sanae = 1.1;
	*/
	// world record
	TD_wr wr;
} _TD;
/*_TD{ 50, 1.05, 2, 2, 1,
        90, 1.05, 2, 3, 1,
        140, 1.05, 2, 4, 1,
        280, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 2.2, 450, 2.5};
		*/

struct DDC
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuB = 1.1;
    float MarisaA = 1.2;
    float MarisaB = 1.05;
    float SakuyaB = 1.2;
	*/
	// world record
	DDC_wr wr;
} _DDC;
/*_DDC{ 50, 1.07, 2, 2, 1,
        100, 1.05, 2, 3, 1,
        150, 1.05, 2, 4, 1,
        290, 1.05, 2, 5, 1,
        110, 1.08, 2, 3, 1,
        375, 4, 400, 3, 450, 2.5, 500, 2, 450, 2.5};
		*/

struct LoLK
{
    // survival
    drc_diff_survival survival;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float Marisa = 1.15;
    float Sanae = 1.05;
    float Reisen = 1.05;
	*/
	// world record
	LoLK_wr wr;
} _LoLK;
/*_LoLK{ 60, 1.05, 2, 2, 1,
        120, 1.05, 2, 3, 1,
        160, 1.05, 2, 4, 1,
        320, 1.05, 2, 5, 1,
        130, 1.08, 2, 3, 1,
        375, 4, 400, 3.5, 450, 3, 500, 3, 450, 3.5};
		*/

struct HSiFS
{
    // survival
    drc_diff_survival_hsifs survival_hsifs;
    // score
    drc_diff_score score;
	/*
    // multiplier
    float ReimuSpring = 1.15;
    float ReimuSummer = 1.15;
    float CirnoSpring = 1.2;
    float CirnoSummer = 1.2;
    float CirnoAutumn = 1.1;
    float CirnoWinter = 1.1;
    float AyaSpring = 1.15;
    float AyaSummer = 1.15;
    float AyaAutumn = 1.05;
    float AyaWinter = 1.05;
    float MarisaSpring = 1.15;
    float MarisaSummer = 1.15;
	*/
	// world record
	HSiFS_wr wr;
} _HSiFS;
/*_HSiFS{ 50, 1.06, 2, 2, 1, 2, 0.5,
            100, 1.05, 2, 3, 1, 2, 0.5,
            150, 1.05, 2, 3, 1, 2, 0.5,
            300, 1.05, 2, 3, 1, 2, 0.5,
            105, 1.07, 2, 3, 1, 2, 0.5,
            375, 3, 400, 3, 450, 2.5, 500, 2, 450, 2.5};
			*/
