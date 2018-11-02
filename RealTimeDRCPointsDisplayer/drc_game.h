#pragma once
#include "drc_survival.h"
#include "drc_score.h"
#include "drc_wr.h"

// Global drc points for both categories
float drcpoints_survival, drcpoints_score;

struct HRtP
{
	// survival
	drc_diff_survival_noextra survival;
    // scoring
    drc_diff_score score;
	// world record
	HRtP_wr wr;
} _HRtP;

struct SoEW
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	SoEW_wr wr;
} _SoEW;

struct PoDD
{
    // phantasmagoria
    drc_diff_phantasmagoria phantasmagoria;
    // scoring
    drc_diff_score score;
	// world record
	PoDD_wr wr;
} _PoDD;

struct LLS
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	LLS_wr wr;
} _LLS;

struct MS
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	MS_wr wr;
} _MS;

struct EoSD
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	EoSD_wr wr;
} _EoSD;

struct PCB
{
    // survival + phantasm difficulty, exclusive for PCB
    drc_diff_survival survival;
    drc_survival phantasm_survival;
    // scoringing + phantasm difficulty, exclusive for PCB
    drc_diff_score score;
    drc_score phantasm_score;
	// world record
	PCB_wr wr;
} _PCB;

struct INight
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	IN_wr wr;
} _IN;

struct PoFV
{
    // survival
    drc_diff_phantasmagoria phantasmagoria;
    // phantasmagoria extra, exclusive for PoFV
    drc_phantasmagoria extra;
    // scoring
    drc_diff_score score;
	// world record
	PoFV_wr wr;
} _PoFV;

struct MoF
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	MoF_wr wr;
} _MoF;

struct SA
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	SA_wr wr;
} _SA;

struct UFO
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	UFO_wr wr;
} _UFO;

struct GFW
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	GFW_wr wr;
} _GFW;

struct TD
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	TD_wr wr;
} _TD;

struct DDC
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	DDC_wr wr;
} _DDC;

struct LoLK
{
    // survival
    drc_diff_survival survival;
    // scoring
    drc_diff_score score;
	// world record
	LoLK_wr wr;
} _LoLK;

struct HSiFS
{
    // survival
    drc_diff_survival_hsifs survival_hsifs;
    // scoring
    drc_diff_score score;
	// world record
	HSiFS_wr wr;
} _HSiFS;
