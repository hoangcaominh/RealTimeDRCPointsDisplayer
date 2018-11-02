#pragma once

#include "drc_template.h"

// world record struct, based on shottype / route
struct HRtP_route
{
	ul Jigoku;
	ul Makai;
};

struct SoEW_shottype
{
	ul ReimuA;
	ul ReimuB;
	ul ReimuC;
};

struct PoDD_shottype
{
	ul Reimu;
	ul Mima;
	ul Marisa;
	ul Ellen;
	ul Kotohime;
	ul Kana;
	ul Rikako;
	ul Chiyuri;
	ul Yumemi;
};

struct LLS_shottype
{
	ul ReimuA;
	ul ReimuB;
	ul MarisaA;
	ul MarisaB;
};

struct MS_shottype
{
	ul Reimu;
	ul Marisa;
	ul Mima;
	ul Yuuka;
};

struct EoSD_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
};

struct PCB_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SakuyaA;
	ull SakuyaB;
};

struct IN_shottype
{
	ull BorderTeam;
	ull MagicTeam;
	ull ScarletTeam;
	ull GhostTeam;
	ull Reimu;
	ull Yukari;
	ull Marisa;
	ull Alice;
	ull Sakuya;
	ull Remilia;
	ull Youmu;
	ull Yuyuko;
};

struct PoFV_shottype
{
	ull Reimu;
	ull Marisa;
	ull Sakuya;
	ull Reisen;
	ull Youmu;
	ull Cirno;
	ull Lyrica;
	ull Mystia;
	ull Tewi;
	ull Aya;
	ull Medicine;
	ull Yuuka;
	ull Komachi;
	ull Eiki;	// Shikieiki
};

struct MoF_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull ReimuC;
	ull MarisaA;
	ull MarisaB;
	ull MarisaC;
};

struct SA_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull ReimuC;
	ull MarisaA;
	ull MarisaB;
	ull MarisaC;
};

struct UFO_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SanaeA;
	ull SanaeB;
};

struct GFW_shottype
{
	ull A1;
	ull A2;
	ull B1;
	ull B2;
	ull C1;
	ull C2;
};

struct TD_shottype
{
	ull Reimu;
	ull Marisa;
	ull Sanae;
	ull Youmu;
};

struct DDC_shottype
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SakuyaA;
	ull SakuyaB;
};

struct LoLK_shottype
{
	ull Reimu;
	ull Marisa;
	ull Sanae;
	ull Reisen;
};

// adding season struct for HSiFS (except Extra)
struct HSiFS_season
{
	ull Spring;
	ull Summer;
	ull Autumn;
	ull Winter;
};

// template only for HSiFS shottypes, T = HSiFS_season | ull
template <typename T>
struct HSiFS_shottype
{
	T Reimu;
	T Cirno;
	T Aya;
	T Marisa;
};
