#pragma once

// unsigned long long for convenience
typedef unsigned long long ull;
// unsigned int for convenience (pc-98 only)
typedef unsigned long ul;

// world record struct, base on shottype / route
struct HRtP_s
{
	ul Makai;
	ul Jigoku;
};

struct HRtP_wr
{
	HRtP_s easy;
	HRtP_s normal;
	HRtP_s hard;
	HRtP_s lunatic;
};

struct SoEW_s
{
	ul ReimuA;
	ul ReimuB;
	ul ReimuC;
};

struct SoEW_wr
{
	SoEW_s easy;
	SoEW_s normal;
	SoEW_s hard;
	SoEW_s lunatic;
	SoEW_s extra;
};

struct PoDD_s
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

struct PoDD_wr
{
	PoDD_s easy;
	PoDD_s normal;
	PoDD_s hard;
	PoDD_s lunatic;
};

struct LLS_s
{
	ul ReimuA;
	ul ReimuB;
	ul MarisaA;
	ul MarisaB;
};

struct LLS_wr
{
	LLS_s easy;
	LLS_s normal;
	LLS_s hard;
	LLS_s lunatic;
	LLS_s extra;
};

struct MS_s
{
	ul Reimu;
	ul Marisa;
	ul Mima;
	ul Yuuka;
};

struct MS_wr
{
	MS_s easy;
	MS_s normal;
	MS_s hard;
	MS_s lunatic;
	MS_s extra;
};

struct EoSD_s
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
};

struct EoSD_wr
{
	EoSD_s easy;
	EoSD_s normal;
	EoSD_s hard;
	EoSD_s lunatic;
	EoSD_s extra;
};

struct PCB_s
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SakuyaA;
	ull SakuyaB;
};

struct PCB_wr
{
	PCB_s easy;
	PCB_s normal;
	PCB_s hard;
	PCB_s lunatic;
	PCB_s extra;
	PCB_s phantasm;
};

struct IN_s
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

struct IN_wr
{
	IN_s easy;
	IN_s normal;
	IN_s hard;
	IN_s lunatic;
	IN_s extra;
};

struct PoFV_s
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

struct PoFV_wr
{
	PoFV_s easy;
	PoFV_s normal;
	PoFV_s hard;
	PoFV_s lunatic;
	PoFV_s extra;
};

struct MoF_s
{
	ull ReimuA;
	ull ReimuB;
	ull ReimuC;
	ull MarisaA;
	ull MarisaB;
	ull MarisaC;
};

struct MoF_wr
{
	MoF_s easy;
	MoF_s normal;
	MoF_s hard;
	MoF_s lunatic;
	MoF_s extra;
};

struct SA_s
{
	ull ReimuA;
	ull ReimuB;
	ull ReimuC;
	ull MarisaA;
	ull MarisaB;
	ull MarisaC;
};

struct SA_wr
{
	SA_s easy;
	SA_s normal;
	SA_s hard;
	SA_s lunatic;
	SA_s extra;
};

struct UFO_s
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SanaeA;
	ull SanaeB;
};

struct UFO_wr
{
	UFO_s easy;
	UFO_s normal;
	UFO_s hard;
	UFO_s lunatic;
	UFO_s extra;
};

struct GFW_s
{
	ull A1;
	ull A2;
	ull B1;
	ull B2;
	ull C1;
	ull C2;
};

struct GFW_wr
{
	GFW_s easy;
	GFW_s normal;
	GFW_s hard;
	GFW_s lunatic;
	GFW_s extra;
};

struct TD_s
{
	ull Reimu;
	ull Marisa;
	ull Sanae;
	ull Youmu;
};

struct TD_wr
{
	TD_s easy;
	TD_s normal;
	TD_s hard;
	TD_s lunatic;
	TD_s extra;
};

struct DDC_s
{
	ull ReimuA;
	ull ReimuB;
	ull MarisaA;
	ull MarisaB;
	ull SakuyaA;
	ull SakuyaB;
};

struct DDC_wr
{
	DDC_s easy;
	DDC_s normal;
	DDC_s hard;
	DDC_s lunatic;
	DDC_s extra;
};

struct LoLK_s
{
	ull Reimu;
	ull Marisa;
	ull Sanae;
	ull Reisen;
};

struct LoLK_wr
{
	LoLK_s easy;
	LoLK_s normal;
	LoLK_s hard;
	LoLK_s lunatic;
	LoLK_s extra;
};

// adding season struct for HSiFS (except Extra)
struct HSiFS_season
{
	ull Spring;
	ull Summer;
	ull Autumn;
	ull Winter;
};

struct HSiFS_s
{
	HSiFS_season Reimu;
	HSiFS_season Cirno;
	HSiFS_season Aya;
	HSiFS_season Marisa;
};

// normal struct for Extra
struct HSiFS_s_Ex
{
	ull Reimu;
	ull Cirno;
	ull Aya;
	ull Marisa;
};

struct HSiFS_wr
{
	HSiFS_s easy;
	HSiFS_s normal;
	HSiFS_s hard;
	HSiFS_s lunatic;
	HSiFS_s_Ex extra;
};

