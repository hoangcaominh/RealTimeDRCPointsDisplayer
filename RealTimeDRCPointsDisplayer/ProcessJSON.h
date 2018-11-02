#pragma once
// print messages
#include <iostream>

// download preprocessors
#include <urlmon.h>
#include <tchar.h>
#pragma comment (lib, "urlmon.lib")

// reading preprocessors
#include <fstream>
#include "json.hpp"
// for convenience
using json = nlohmann::json;

// games preprocessors
#include "drc_game.h"

// downloading part
bool Download_rubrics()
{
	std::cout << "Downloading rubric file..." << std::endl;

	// result of downloading rubric file
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/hoangcaominh/hoangcaominh.github.io/master/rubrics.json"), _T("rubrics.json"), 0, NULL);

	switch (hResult)
	{
		// successfully downloaded
	case S_OK:
		std::cout << "Successfully downloaded rubric file." << std::endl;
		return true;
		// out of memory
	case E_OUTOFMEMORY:
		std::cout << "Not enough memory to download rubric file." << std::endl;
		break;
		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		std::cout << "Rubric file not valid, or file name not match, download failed." << std::endl;
		break;
		// other errors
	default:
		std::cout << "Failed to download rubric file." << std::endl;
		break;
	}

	return false;
}

bool Download_wrs()
{
	std::cout << "Downloading world record file..." << std::endl;
	
	// result of downloading world record file (temporary url)
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/MaribelHearn/MaribelHearn.github.io/master/json/wrlist.json"), _T("wrlist.json"), 0, NULL);

	switch (hResult)
	{
		// successfully downloaded
	case S_OK:
		std::cout << "Successfully downloaded world record file." << std::endl;
		return true;
		// out of memory
	case E_OUTOFMEMORY:
		std::cout << "Not enough memory to download world record file." << std::endl;
		break;
		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		std::cout << "World record file not valid, or file name not match, download failed." << std::endl;
		break;
		// other errors
	default:
		std::cout << "Failed to download world record file." << std::endl;
		break;
	}

	return false;
}

// reading part
bool Load_rubrics()
{
	std::cout << "Loading saved rubric file..." << std::endl;

	std::ifstream read_rubrics("rubrics.json");
	if (read_rubrics.fail())
	{
		// failed to parse rubrics file
		std::cout << "Failed to load rubric file." << std::endl;
		return false;
	}

	// local variables to free memory when not necessary
	json j;
	// successfully parsed rubrics file
	read_rubrics >> j;

	if (j.empty())
	{
		std::cout << "No element in the rubric file could be found." << std::endl;
		return false;
	}

	// Loading

	std::cout << "Successfully loaded rubric file." << std::endl;
	return true;
}

bool Load_wrs()
{
	std::cout << "Loading saved world record file..." << std::endl;

	std::ifstream read_wrs("wrlist.json");
	if (read_wrs.fail())
	{
		// failed to parse world records file
		std::cout << "Failed to load world record file." << std::endl;
		return false;
	}

	// local variables to free memory when not necessary
	json j;
	// successfully parsed rubrics file
	read_wrs >> j;

	if (j.empty())
	{
		std::cout << "No element in the world record file could be found." << std::endl;
		return false;
	}

	// Loading

	// HRtP world records
	HRtP.wrs.easy.Jigoku = j["HRtP"]["Easy"]["Jigoku"][0].get<ul>();
	HRtP.wrs.easy.Makai = j["HRtP"]["Easy"]["Makai"][0].get<ul>();
	HRtP.wrs.normal.Jigoku = j["HRtP"]["Normal"]["Jigoku"][0].get<ul>();
	HRtP.wrs.normal.Makai = j["HRtP"]["Normal"]["Makai"][0].get<ul>();
	HRtP.wrs.hard.Jigoku = j["HRtP"]["Hard"]["Jigoku"][0].get<ul>();
	HRtP.wrs.hard.Makai = j["HRtP"]["Hard"]["Makai"][0].get<ul>();
	HRtP.wrs.lunatic.Jigoku = j["HRtP"]["Lunatic"]["Jigoku"][0].get<ul>();
	HRtP.wrs.lunatic.Makai = j["HRtP"]["Lunatic"]["Makai"][0].get<ul>();

	// SoEW world records
	SoEW.wrs.easy.ReimuA = j["SoEW"]["Easy"]["ReimuA"][0].get<ul>();
	SoEW.wrs.easy.ReimuB = j["SoEW"]["Easy"]["ReimuB"][0].get<ul>();
	SoEW.wrs.easy.ReimuC = j["SoEW"]["Easy"]["ReimuC"][0].get<ul>();
	SoEW.wrs.normal.ReimuA = j["SoEW"]["Normal"]["ReimuA"][0].get<ul>();
	SoEW.wrs.normal.ReimuB = j["SoEW"]["Normal"]["ReimuB"][0].get<ul>();
	SoEW.wrs.normal.ReimuC = j["SoEW"]["Normal"]["ReimuC"][0].get<ul>();
	SoEW.wrs.hard.ReimuA = j["SoEW"]["Hard"]["ReimuA"][0].get<ul>();
	SoEW.wrs.hard.ReimuB = j["SoEW"]["Hard"]["ReimuB"][0].get<ul>();
	SoEW.wrs.hard.ReimuC = j["SoEW"]["Hard"]["ReimuC"][0].get<ul>();
	SoEW.wrs.lunatic.ReimuA = j["SoEW"]["Lunatic"]["ReimuA"][0].get<ul>();
	SoEW.wrs.lunatic.ReimuB = j["SoEW"]["Lunatic"]["ReimuB"][0].get<ul>();
	SoEW.wrs.lunatic.ReimuC = j["SoEW"]["Lunatic"]["ReimuC"][0].get<ul>();
	SoEW.wrs.extra.ReimuA = j["SoEW"]["Extra"]["ReimuA"][0].get<ul>();
	SoEW.wrs.extra.ReimuB = j["SoEW"]["Extra"]["ReimuB"][0].get<ul>();
	SoEW.wrs.extra.ReimuC = j["SoEW"]["Extra"]["ReimuC"][0].get<ul>();

	// PoDD world records
	PoDD.wrs.easy.Reimu = j["PoDD"]["Easy"]["Reimu"][0].get<ul>();
	PoDD.wrs.easy.Mima = j["PoDD"]["Easy"]["Mima"][0].get<ul>();
	PoDD.wrs.easy.Marisa = j["PoDD"]["Easy"]["Marisa"][0].get<ul>();
	PoDD.wrs.easy.Ellen = j["PoDD"]["Easy"]["Ellen"][0].get<ul>();
	PoDD.wrs.easy.Kotohime = j["PoDD"]["Easy"]["Kotohime"][0].get<ul>();
	PoDD.wrs.easy.Kana = j["PoDD"]["Easy"]["Kana"][0].get<ul>();
	PoDD.wrs.easy.Rikako = j["PoDD"]["Easy"]["Rikako"][0].get<ul>();
	PoDD.wrs.easy.Chiyuri = j["PoDD"]["Easy"]["Chiyuri"][0].get<ul>();
	PoDD.wrs.easy.Yumemi = j["PoDD"]["Easy"]["Yumemi"][0].get<ul>();
	PoDD.wrs.normal.Reimu = j["PoDD"]["Normal"]["Reimu"][0].get<ul>();
	PoDD.wrs.normal.Mima = j["PoDD"]["Normal"]["Mima"][0].get<ul>();
	PoDD.wrs.normal.Marisa = j["PoDD"]["Normal"]["Marisa"][0].get<ul>();
	PoDD.wrs.normal.Ellen = j["PoDD"]["Normal"]["Ellen"][0].get<ul>();
	PoDD.wrs.normal.Kotohime = j["PoDD"]["Normal"]["Kotohime"][0].get<ul>();
	PoDD.wrs.normal.Kana = j["PoDD"]["Normal"]["Kana"][0].get<ul>();
	PoDD.wrs.normal.Rikako = j["PoDD"]["Normal"]["Rikako"][0].get<ul>();
	PoDD.wrs.normal.Chiyuri = j["PoDD"]["Normal"]["Chiyuri"][0].get<ul>();
	PoDD.wrs.normal.Yumemi = j["PoDD"]["Normal"]["Yumemi"][0].get<ul>();
	PoDD.wrs.hard.Reimu = j["PoDD"]["Hard"]["Reimu"][0].get<ul>();
	PoDD.wrs.hard.Mima = j["PoDD"]["Hard"]["Mima"][0].get<ul>();
	PoDD.wrs.hard.Marisa = j["PoDD"]["Hard"]["Marisa"][0].get<ul>();
	PoDD.wrs.hard.Ellen = j["PoDD"]["Hard"]["Ellen"][0].get<ul>();
	PoDD.wrs.hard.Kotohime = j["PoDD"]["Hard"]["Kotohime"][0].get<ul>();
	PoDD.wrs.hard.Kana = j["PoDD"]["Hard"]["Kana"][0].get<ul>();
	PoDD.wrs.hard.Rikako = j["PoDD"]["Hard"]["Rikako"][0].get<ul>();
	PoDD.wrs.hard.Chiyuri = j["PoDD"]["Hard"]["Chiyuri"][0].get<ul>();
	PoDD.wrs.hard.Yumemi = j["PoDD"]["Hard"]["Yumemi"][0].get<ul>();
	PoDD.wrs.lunatic.Reimu = j["PoDD"]["Lunatic"]["Reimu"][0].get<ul>();
	PoDD.wrs.lunatic.Mima = j["PoDD"]["Lunatic"]["Mima"][0].get<ul>();
	PoDD.wrs.lunatic.Marisa = j["PoDD"]["Lunatic"]["Marisa"][0].get<ul>();
	PoDD.wrs.lunatic.Ellen = j["PoDD"]["Lunatic"]["Ellen"][0].get<ul>();
	PoDD.wrs.lunatic.Kotohime = j["PoDD"]["Lunatic"]["Kotohime"][0].get<ul>();
	PoDD.wrs.lunatic.Kana = j["PoDD"]["Lunatic"]["Kana"][0].get<ul>();
	PoDD.wrs.lunatic.Rikako = j["PoDD"]["Lunatic"]["Rikako"][0].get<ul>();
	PoDD.wrs.lunatic.Chiyuri = j["PoDD"]["Lunatic"]["Chiyuri"][0].get<ul>();
	PoDD.wrs.lunatic.Yumemi = j["PoDD"]["Lunatic"]["Yumemi"][0].get<ul>();

	// LLS world records
	LLS.wrs.easy.ReimuA = j["LLS"]["Easy"]["ReimuA"][0].get<ul>();
	LLS.wrs.easy.ReimuB = j["LLS"]["Easy"]["ReimuB"][0].get<ul>();
	LLS.wrs.easy.MarisaA = j["LLS"]["Easy"]["MarisaA"][0].get<ul>();
	LLS.wrs.easy.MarisaB = j["LLS"]["Easy"]["MarisaB"][0].get<ul>();
	LLS.wrs.normal.ReimuA = j["LLS"]["Normal"]["ReimuA"][0].get<ul>();
	LLS.wrs.normal.ReimuB = j["LLS"]["Normal"]["ReimuB"][0].get<ul>();
	LLS.wrs.normal.MarisaA = j["LLS"]["Normal"]["MarisaA"][0].get<ul>();
	LLS.wrs.normal.MarisaB = j["LLS"]["Normal"]["MarisaB"][0].get<ul>();
	LLS.wrs.hard.ReimuA = j["LLS"]["Hard"]["ReimuA"][0].get<ul>();
	LLS.wrs.hard.ReimuB = j["LLS"]["Hard"]["ReimuB"][0].get<ul>();
	LLS.wrs.hard.MarisaA = j["LLS"]["Hard"]["MarisaA"][0].get<ul>();
	LLS.wrs.hard.MarisaB = j["LLS"]["Hard"]["MarisaB"][0].get<ul>();
	LLS.wrs.lunatic.ReimuA = j["LLS"]["Lunatic"]["ReimuA"][0].get<ul>();
	LLS.wrs.lunatic.ReimuB = j["LLS"]["Lunatic"]["ReimuB"][0].get<ul>();
	LLS.wrs.lunatic.MarisaA = j["LLS"]["Lunatic"]["MarisaA"][0].get<ul>();
	LLS.wrs.lunatic.MarisaB = j["LLS"]["Lunatic"]["MarisaB"][0].get<ul>();
	LLS.wrs.extra.ReimuA = j["LLS"]["Extra"]["ReimuA"][0].get<ul>();
	LLS.wrs.extra.ReimuB = j["LLS"]["Extra"]["ReimuB"][0].get<ul>();
	LLS.wrs.extra.MarisaA = j["LLS"]["Extra"]["MarisaA"][0].get<ul>();
	LLS.wrs.extra.MarisaB = j["LLS"]["Extra"]["MarisaB"][0].get<ul>();

	// MS world record
	MS.wrs.easy.Reimu = j["MS"]["Easy"]["Reimu"][0].get<ul>();
	MS.wrs.easy.Marisa = j["MS"]["Easy"]["Marisa"][0].get<ul>();
	MS.wrs.easy.Mima = j["MS"]["Easy"]["Mima"][0].get<ul>();
	MS.wrs.easy.Yuuka = j["MS"]["Easy"]["Yuuka"][0].get<ul>();
	MS.wrs.normal.Reimu = j["MS"]["Normal"]["Reimu"][0].get<ul>();
	MS.wrs.normal.Marisa = j["MS"]["Normal"]["Marisa"][0].get<ul>();
	MS.wrs.normal.Mima = j["MS"]["Normal"]["Mima"][0].get<ul>();
	MS.wrs.normal.Yuuka = j["MS"]["Normal"]["Yuuka"][0].get<ul>();
	MS.wrs.hard.Reimu = j["MS"]["Hard"]["Reimu"][0].get<ul>();
	MS.wrs.hard.Marisa = j["MS"]["Hard"]["Marisa"][0].get<ul>();
	MS.wrs.hard.Mima = j["MS"]["Hard"]["Mima"][0].get<ul>();
	MS.wrs.hard.Yuuka = j["MS"]["Hard"]["Yuuka"][0].get<ul>();
	MS.wrs.lunatic.Reimu = j["MS"]["Lunatic"]["Reimu"][0].get<ul>();
	MS.wrs.lunatic.Marisa = j["MS"]["Lunatic"]["Marisa"][0].get<ul>();
	MS.wrs.lunatic.Mima = j["MS"]["Lunatic"]["Mima"][0].get<ul>();
	MS.wrs.lunatic.Yuuka = j["MS"]["Lunatic"]["Yuuka"][0].get<ul>();
	MS.wrs.extra.Reimu = j["MS"]["Extra"]["Reimu"][0].get<ul>();
	MS.wrs.extra.Marisa = j["MS"]["Extra"]["Marisa"][0].get<ul>();
	MS.wrs.extra.Mima = j["MS"]["Extra"]["Mima"][0].get<ul>();
	MS.wrs.extra.Yuuka = j["MS"]["Extra"]["Yuuka"][0].get<ul>();

	// EoSD world record
	EoSD.wrs.easy.ReimuA = j["EoSD"]["Easy"]["ReimuA"][0].get<ull>();
	EoSD.wrs.easy.ReimuB = j["EoSD"]["Easy"]["ReimuB"][0].get<ull>();
	EoSD.wrs.easy.MarisaA = j["EoSD"]["Easy"]["MarisaA"][0].get<ull>();
	EoSD.wrs.easy.MarisaB = j["EoSD"]["Easy"]["MarisaB"][0].get<ull>();
	EoSD.wrs.normal.ReimuA = j["EoSD"]["Normal"]["ReimuA"][0].get<ull>();
	EoSD.wrs.normal.ReimuB = j["EoSD"]["Normal"]["ReimuB"][0].get<ull>();
	EoSD.wrs.normal.MarisaA = j["EoSD"]["Normal"]["MarisaA"][0].get<ull>();
	EoSD.wrs.normal.MarisaB = j["EoSD"]["Normal"]["MarisaB"][0].get<ull>();
	EoSD.wrs.hard.ReimuA = j["EoSD"]["Hard"]["ReimuA"][0].get<ull>();
	EoSD.wrs.hard.ReimuB = j["EoSD"]["Hard"]["ReimuB"][0].get<ull>();
	EoSD.wrs.hard.MarisaA = j["EoSD"]["Hard"]["MarisaA"][0].get<ull>();
	EoSD.wrs.hard.MarisaB = j["EoSD"]["Hard"]["MarisaB"][0].get<ull>();
	EoSD.wrs.lunatic.ReimuA = j["EoSD"]["Lunatic"]["ReimuA"][0].get<ull>();
	EoSD.wrs.lunatic.ReimuB = j["EoSD"]["Lunatic"]["ReimuB"][0].get<ull>();
	EoSD.wrs.lunatic.MarisaA = j["EoSD"]["Lunatic"]["MarisaA"][0].get<ull>();
	EoSD.wrs.lunatic.MarisaB = j["EoSD"]["Lunatic"]["MarisaB"][0].get<ull>();
	EoSD.wrs.extra.ReimuA = j["EoSD"]["Extra"]["ReimuA"][0].get<ull>();
	EoSD.wrs.extra.ReimuB = j["EoSD"]["Extra"]["ReimuB"][0].get<ull>();
	EoSD.wrs.extra.MarisaA = j["EoSD"]["Extra"]["MarisaA"][0].get<ull>();
	EoSD.wrs.extra.MarisaB = j["EoSD"]["Extra"]["MarisaB"][0].get<ull>();

	// PCB world record
	PCB.wrs.easy.ReimuA = j["PCB"]["Easy"]["ReimuA"][0].get<ull>();
	PCB.wrs.easy.ReimuB = j["PCB"]["Easy"]["ReimuB"][0].get<ull>();
	PCB.wrs.easy.MarisaA = j["PCB"]["Easy"]["MarisaA"][0].get<ull>();
	PCB.wrs.easy.MarisaB = j["PCB"]["Easy"]["MarisaB"][0].get<ull>();
	PCB.wrs.easy.SakuyaA = j["PCB"]["Easy"]["SakuyaA"][0].get<ull>();
	PCB.wrs.easy.SakuyaB = j["PCB"]["Easy"]["SakuyaB"][0].get<ull>();
	PCB.wrs.normal.ReimuA = j["PCB"]["Normal"]["ReimuA"][0].get<ull>();
	PCB.wrs.normal.ReimuB = j["PCB"]["Normal"]["ReimuB"][0].get<ull>();
	PCB.wrs.normal.MarisaA = j["PCB"]["Normal"]["MarisaA"][0].get<ull>();
	PCB.wrs.normal.MarisaB = j["PCB"]["Normal"]["MarisaB"][0].get<ull>();
	PCB.wrs.normal.SakuyaA = j["PCB"]["Normal"]["SakuyaA"][0].get<ull>();
	PCB.wrs.normal.SakuyaB = j["PCB"]["Normal"]["SakuyaB"][0].get<ull>();
	PCB.wrs.hard.ReimuA = j["PCB"]["Hard"]["ReimuA"][0].get<ull>();
	PCB.wrs.hard.ReimuB = j["PCB"]["Hard"]["ReimuB"][0].get<ull>();
	PCB.wrs.hard.MarisaA = j["PCB"]["Hard"]["MarisaA"][0].get<ull>();
	PCB.wrs.hard.MarisaB = j["PCB"]["Hard"]["MarisaB"][0].get<ull>();
	PCB.wrs.hard.SakuyaA = j["PCB"]["Hard"]["SakuyaA"][0].get<ull>();
	PCB.wrs.hard.SakuyaB = j["PCB"]["Hard"]["SakuyaB"][0].get<ull>();
	PCB.wrs.lunatic.ReimuA = j["PCB"]["Lunatic"]["ReimuA"][0].get<ull>();
	PCB.wrs.lunatic.ReimuB = j["PCB"]["Lunatic"]["ReimuB"][0].get<ull>();
	PCB.wrs.lunatic.MarisaA = j["PCB"]["Lunatic"]["MarisaA"][0].get<ull>();
	PCB.wrs.lunatic.MarisaB = j["PCB"]["Lunatic"]["MarisaB"][0].get<ull>();
	PCB.wrs.lunatic.SakuyaA = j["PCB"]["Lunatic"]["SakuyaA"][0].get<ull>();
	PCB.wrs.lunatic.SakuyaB = j["PCB"]["Lunatic"]["SakuyaB"][0].get<ull>();
	PCB.wrs.extra.ReimuA = j["PCB"]["Extra"]["ReimuA"][0].get<ull>();
	PCB.wrs.extra.ReimuB = j["PCB"]["Extra"]["ReimuB"][0].get<ull>();
	PCB.wrs.extra.MarisaA = j["PCB"]["Extra"]["MarisaA"][0].get<ull>();
	PCB.wrs.extra.MarisaB = j["PCB"]["Extra"]["MarisaB"][0].get<ull>();
	PCB.wrs.extra.SakuyaA = j["PCB"]["Extra"]["SakuyaA"][0].get<ull>();
	PCB.wrs.extra.SakuyaB = j["PCB"]["Extra"]["SakuyaB"][0].get<ull>();
	PCB.wrs.phantasm.ReimuA = j["PCB"]["Phantasm"]["ReimuA"][0].get<ull>();
	PCB.wrs.phantasm.ReimuB = j["PCB"]["Phantasm"]["ReimuB"][0].get<ull>();
	PCB.wrs.phantasm.MarisaA = j["PCB"]["Phantasm"]["MarisaA"][0].get<ull>();
	PCB.wrs.phantasm.MarisaB = j["PCB"]["Phantasm"]["MarisaB"][0].get<ull>();
	PCB.wrs.phantasm.SakuyaA = j["PCB"]["Phantasm"]["SakuyaA"][0].get<ull>();
	PCB.wrs.phantasm.SakuyaB = j["PCB"]["Phantasm"]["SakuyaB"][0].get<ull>();

	// IN world record
	INight.wrs.easy.BorderTeam = j["IN"]["Easy"]["BorderTeam"][0].get<ull>();
	INight.wrs.easy.MagicTeam = j["IN"]["Easy"]["MagicTeam"][0].get<ull>();
	INight.wrs.easy.ScarletTeam = j["IN"]["Easy"]["ScarletTeam"][0].get<ull>();
	INight.wrs.easy.GhostTeam = j["IN"]["Easy"]["GhostTeam"][0].get<ull>();
	INight.wrs.easy.Reimu = j["IN"]["Easy"]["Reimu"][0].get<ull>();
	INight.wrs.easy.Yukari = j["IN"]["Easy"]["Yukari"][0].get<ull>();
	INight.wrs.easy.Marisa = j["IN"]["Easy"]["Marisa"][0].get<ull>();
	INight.wrs.easy.Alice = j["IN"]["Easy"]["Alice"][0].get<ull>();
	INight.wrs.easy.Sakuya = j["IN"]["Easy"]["Sakuya"][0].get<ull>();
	INight.wrs.easy.Remilia = j["IN"]["Easy"]["Remilia"][0].get<ull>();
	INight.wrs.easy.Youmu = j["IN"]["Easy"]["Youmu"][0].get<ull>();
	INight.wrs.easy.Yuyuko = j["IN"]["Easy"]["Yuyuko"][0].get<ull>();
	INight.wrs.normal.BorderTeam = j["IN"]["Normal"]["BorderTeam"][0].get<ull>();
	INight.wrs.normal.MagicTeam = j["IN"]["Normal"]["MagicTeam"][0].get<ull>();
	INight.wrs.normal.ScarletTeam = j["IN"]["Normal"]["ScarletTeam"][0].get<ull>();
	INight.wrs.normal.GhostTeam = j["IN"]["Normal"]["GhostTeam"][0].get<ull>();
	INight.wrs.normal.Reimu = j["IN"]["Normal"]["Reimu"][0].get<ull>();
	INight.wrs.normal.Yukari = j["IN"]["Normal"]["Yukari"][0].get<ull>();
	INight.wrs.normal.Marisa = j["IN"]["Normal"]["Marisa"][0].get<ull>();
	INight.wrs.normal.Alice = j["IN"]["Normal"]["Alice"][0].get<ull>();
	INight.wrs.normal.Sakuya = j["IN"]["Normal"]["Sakuya"][0].get<ull>();
	INight.wrs.normal.Remilia = j["IN"]["Normal"]["Remilia"][0].get<ull>();
	INight.wrs.normal.Youmu = j["IN"]["Normal"]["Youmu"][0].get<ull>();
	INight.wrs.normal.Yuyuko = j["IN"]["Normal"]["Yuyuko"][0].get<ull>();
	INight.wrs.hard.BorderTeam = j["IN"]["Hard"]["BorderTeam"][0].get<ull>();
	INight.wrs.hard.MagicTeam = j["IN"]["Hard"]["MagicTeam"][0].get<ull>();
	INight.wrs.hard.ScarletTeam = j["IN"]["Hard"]["ScarletTeam"][0].get<ull>();
	INight.wrs.hard.GhostTeam = j["IN"]["Hard"]["GhostTeam"][0].get<ull>();
	INight.wrs.hard.Reimu = j["IN"]["Hard"]["Reimu"][0].get<ull>();
	INight.wrs.hard.Yukari = j["IN"]["Hard"]["Yukari"][0].get<ull>();
	INight.wrs.hard.Marisa = j["IN"]["Hard"]["Marisa"][0].get<ull>();
	INight.wrs.hard.Alice = j["IN"]["Hard"]["Alice"][0].get<ull>();
	INight.wrs.hard.Sakuya = j["IN"]["Hard"]["Sakuya"][0].get<ull>();
	INight.wrs.hard.Remilia = j["IN"]["Hard"]["Remilia"][0].get<ull>();
	INight.wrs.hard.Youmu = j["IN"]["Hard"]["Youmu"][0].get<ull>();
	INight.wrs.hard.Yuyuko = j["IN"]["Hard"]["Yuyuko"][0].get<ull>();
	INight.wrs.lunatic.BorderTeam = j["IN"]["Lunatic"]["BorderTeam"][0].get<ull>();
	INight.wrs.lunatic.MagicTeam = j["IN"]["Lunatic"]["MagicTeam"][0].get<ull>();
	INight.wrs.lunatic.ScarletTeam = j["IN"]["Lunatic"]["ScarletTeam"][0].get<ull>();
	INight.wrs.lunatic.GhostTeam = j["IN"]["Lunatic"]["GhostTeam"][0].get<ull>();
	INight.wrs.lunatic.Reimu = j["IN"]["Lunatic"]["Reimu"][0].get<ull>();
	INight.wrs.lunatic.Yukari = j["IN"]["Lunatic"]["Yukari"][0].get<ull>();
	INight.wrs.lunatic.Marisa = j["IN"]["Lunatic"]["Marisa"][0].get<ull>();
	INight.wrs.lunatic.Alice = j["IN"]["Lunatic"]["Alice"][0].get<ull>();
	INight.wrs.lunatic.Sakuya = j["IN"]["Lunatic"]["Sakuya"][0].get<ull>();
	INight.wrs.lunatic.Remilia = j["IN"]["Lunatic"]["Remilia"][0].get<ull>();
	INight.wrs.lunatic.Youmu = j["IN"]["Lunatic"]["Youmu"][0].get<ull>();
	INight.wrs.lunatic.Yuyuko = j["IN"]["Lunatic"]["Yuyuko"][0].get<ull>();
	INight.wrs.extra.BorderTeam = j["IN"]["Extra"]["BorderTeam"][0].get<ull>();
	INight.wrs.extra.MagicTeam = j["IN"]["Extra"]["MagicTeam"][0].get<ull>();
	INight.wrs.extra.ScarletTeam = j["IN"]["Extra"]["ScarletTeam"][0].get<ull>();
	INight.wrs.extra.GhostTeam = j["IN"]["Extra"]["GhostTeam"][0].get<ull>();
	INight.wrs.extra.Reimu = j["IN"]["Extra"]["Reimu"][0].get<ull>();
	INight.wrs.extra.Yukari = j["IN"]["Extra"]["Yukari"][0].get<ull>();
	INight.wrs.extra.Marisa = j["IN"]["Extra"]["Marisa"][0].get<ull>();
	INight.wrs.extra.Alice = j["IN"]["Extra"]["Alice"][0].get<ull>();
	INight.wrs.extra.Sakuya = j["IN"]["Extra"]["Sakuya"][0].get<ull>();
	INight.wrs.extra.Remilia = j["IN"]["Extra"]["Remilia"][0].get<ull>();
	INight.wrs.extra.Youmu = j["IN"]["Extra"]["Youmu"][0].get<ull>();
	INight.wrs.extra.Yuyuko = j["IN"]["Extra"]["Yuyuko"][0].get<ull>();

	// PoFV world record
	PoFV.wrs.easy.Reimu = j["PoFV"]["Easy"]["Reimu"][0].get<ull>();
	PoFV.wrs.easy.Marisa = j["PoFV"]["Easy"]["Marisa"][0].get<ull>();
	PoFV.wrs.easy.Sakuya = j["PoFV"]["Easy"]["Sakuya"][0].get<ull>();
	PoFV.wrs.easy.Youmu = j["PoFV"]["Easy"]["Youmu"][0].get<ull>();
	PoFV.wrs.easy.Reisen = j["PoFV"]["Easy"]["Reisen"][0].get<ull>();
	PoFV.wrs.easy.Cirno = j["PoFV"]["Easy"]["Cirno"][0].get<ull>();
	PoFV.wrs.easy.Lyrica = j["PoFV"]["Easy"]["Lyrica"][0].get<ull>();
	PoFV.wrs.easy.Mystia = j["PoFV"]["Easy"]["Mystia"][0].get<ull>();
	PoFV.wrs.easy.Tewi = j["PoFV"]["Easy"]["Tewi"][0].get<ull>();
	PoFV.wrs.easy.Aya = j["PoFV"]["Easy"]["Aya"][0].get<ull>();
	PoFV.wrs.easy.Medicine = j["PoFV"]["Easy"]["Medicine"][0].get<ull>();
	PoFV.wrs.easy.Yuuka = j["PoFV"]["Easy"]["Yuuka"][0].get<ull>();
	PoFV.wrs.easy.Komachi = j["PoFV"]["Easy"]["Komachi"][0].get<ull>();
	PoFV.wrs.easy.Eiki = j["PoFV"]["Easy"]["Eiki"][0].get<ull>();
	PoFV.wrs.normal.Reimu = j["PoFV"]["Normal"]["Reimu"][0].get<ull>();
	PoFV.wrs.normal.Marisa = j["PoFV"]["Normal"]["Marisa"][0].get<ull>();
	PoFV.wrs.normal.Sakuya = j["PoFV"]["Normal"]["Sakuya"][0].get<ull>();
	PoFV.wrs.normal.Youmu = j["PoFV"]["Normal"]["Youmu"][0].get<ull>();
	PoFV.wrs.normal.Reisen = j["PoFV"]["Normal"]["Reisen"][0].get<ull>();
	PoFV.wrs.normal.Cirno = j["PoFV"]["Normal"]["Cirno"][0].get<ull>();
	PoFV.wrs.normal.Lyrica = j["PoFV"]["Normal"]["Lyrica"][0].get<ull>();
	PoFV.wrs.normal.Mystia = j["PoFV"]["Normal"]["Mystia"][0].get<ull>();
	PoFV.wrs.normal.Tewi = j["PoFV"]["Normal"]["Tewi"][0].get<ull>();
	PoFV.wrs.normal.Aya = j["PoFV"]["Normal"]["Aya"][0].get<ull>();
	PoFV.wrs.normal.Medicine = j["PoFV"]["Normal"]["Medicine"][0].get<ull>();
	PoFV.wrs.normal.Yuuka = j["PoFV"]["Normal"]["Yuuka"][0].get<ull>();
	PoFV.wrs.normal.Komachi = j["PoFV"]["Normal"]["Komachi"][0].get<ull>();
	PoFV.wrs.normal.Eiki = j["PoFV"]["Normal"]["Eiki"][0].get<ull>();
	PoFV.wrs.hard.Reimu = j["PoFV"]["Hard"]["Reimu"][0].get<ull>();
	PoFV.wrs.hard.Marisa = j["PoFV"]["Hard"]["Marisa"][0].get<ull>();
	PoFV.wrs.hard.Sakuya = j["PoFV"]["Hard"]["Sakuya"][0].get<ull>();
	PoFV.wrs.hard.Youmu = j["PoFV"]["Hard"]["Youmu"][0].get<ull>();
	PoFV.wrs.hard.Reisen = j["PoFV"]["Hard"]["Reisen"][0].get<ull>();
	PoFV.wrs.hard.Cirno = j["PoFV"]["Hard"]["Cirno"][0].get<ull>();
	PoFV.wrs.hard.Lyrica = j["PoFV"]["Hard"]["Lyrica"][0].get<ull>();
	PoFV.wrs.hard.Mystia = j["PoFV"]["Hard"]["Mystia"][0].get<ull>();
	PoFV.wrs.hard.Tewi = j["PoFV"]["Hard"]["Tewi"][0].get<ull>();
	PoFV.wrs.hard.Aya = j["PoFV"]["Hard"]["Aya"][0].get<ull>();
	PoFV.wrs.hard.Medicine = j["PoFV"]["Hard"]["Medicine"][0].get<ull>();
	PoFV.wrs.hard.Yuuka = j["PoFV"]["Hard"]["Yuuka"][0].get<ull>();
	PoFV.wrs.hard.Komachi = j["PoFV"]["Hard"]["Komachi"][0].get<ull>();
	PoFV.wrs.hard.Eiki = j["PoFV"]["Hard"]["Eiki"][0].get<ull>();
	PoFV.wrs.lunatic.Reimu = j["PoFV"]["Lunatic"]["Reimu"][0].get<ull>();
	PoFV.wrs.lunatic.Marisa = j["PoFV"]["Lunatic"]["Marisa"][0].get<ull>();
	PoFV.wrs.lunatic.Sakuya = j["PoFV"]["Lunatic"]["Sakuya"][0].get<ull>();
	PoFV.wrs.lunatic.Youmu = j["PoFV"]["Lunatic"]["Youmu"][0].get<ull>();
	PoFV.wrs.lunatic.Reisen = j["PoFV"]["Lunatic"]["Reisen"][0].get<ull>();
	PoFV.wrs.lunatic.Cirno = j["PoFV"]["Lunatic"]["Cirno"][0].get<ull>();
	PoFV.wrs.lunatic.Lyrica = j["PoFV"]["Lunatic"]["Lyrica"][0].get<ull>();
	PoFV.wrs.lunatic.Mystia = j["PoFV"]["Lunatic"]["Mystia"][0].get<ull>();
	PoFV.wrs.lunatic.Tewi = j["PoFV"]["Lunatic"]["Tewi"][0].get<ull>();
	PoFV.wrs.lunatic.Aya = j["PoFV"]["Lunatic"]["Aya"][0].get<ull>();
	PoFV.wrs.lunatic.Medicine = j["PoFV"]["Lunatic"]["Medicine"][0].get<ull>();
	PoFV.wrs.lunatic.Yuuka = j["PoFV"]["Lunatic"]["Yuuka"][0].get<ull>();
	PoFV.wrs.lunatic.Komachi = j["PoFV"]["Lunatic"]["Komachi"][0].get<ull>();
	PoFV.wrs.lunatic.Eiki = j["PoFV"]["Lunatic"]["Eiki"][0].get<ull>();
	PoFV.wrs.extra.Reimu = j["PoFV"]["Extra"]["Reimu"][0].get<ull>();
	PoFV.wrs.extra.Marisa = j["PoFV"]["Extra"]["Marisa"][0].get<ull>();
	PoFV.wrs.extra.Sakuya = j["PoFV"]["Extra"]["Sakuya"][0].get<ull>();
	PoFV.wrs.extra.Youmu = j["PoFV"]["Extra"]["Youmu"][0].get<ull>();
	PoFV.wrs.extra.Reisen = j["PoFV"]["Extra"]["Reisen"][0].get<ull>();
	PoFV.wrs.extra.Cirno = j["PoFV"]["Extra"]["Cirno"][0].get<ull>();
	PoFV.wrs.extra.Lyrica = j["PoFV"]["Extra"]["Lyrica"][0].get<ull>();
	PoFV.wrs.extra.Mystia = j["PoFV"]["Extra"]["Mystia"][0].get<ull>();
	PoFV.wrs.extra.Tewi = j["PoFV"]["Extra"]["Tewi"][0].get<ull>();
	PoFV.wrs.extra.Aya = j["PoFV"]["Extra"]["Aya"][0].get<ull>();
	PoFV.wrs.extra.Medicine = j["PoFV"]["Extra"]["Medicine"][0].get<ull>();
	PoFV.wrs.extra.Yuuka = j["PoFV"]["Extra"]["Yuuka"][0].get<ull>();
	PoFV.wrs.extra.Komachi = j["PoFV"]["Extra"]["Komachi"][0].get<ull>();
	PoFV.wrs.extra.Eiki = j["PoFV"]["Extra"]["Eiki"][0].get<ull>();

	// MoF world record
	MoF.wrs.easy.ReimuA = j["MoF"]["Easy"]["ReimuA"][0].get<ull>();
	MoF.wrs.easy.ReimuB = j["MoF"]["Easy"]["ReimuB"][0].get<ull>();
	MoF.wrs.easy.ReimuC = j["MoF"]["Easy"]["ReimuC"][0].get<ull>();
	MoF.wrs.easy.MarisaA = j["MoF"]["Easy"]["MarisaA"][0].get<ull>();
	MoF.wrs.easy.MarisaB = j["MoF"]["Easy"]["MarisaB"][0].get<ull>();
	MoF.wrs.easy.MarisaC = j["MoF"]["Easy"]["MarisaC"][0].get<ull>();
	MoF.wrs.normal.ReimuA = j["MoF"]["Normal"]["ReimuA"][0].get<ull>();
	MoF.wrs.normal.ReimuB = j["MoF"]["Normal"]["ReimuB"][0].get<ull>();
	MoF.wrs.normal.ReimuC = j["MoF"]["Normal"]["ReimuC"][0].get<ull>();
	MoF.wrs.normal.MarisaA = j["MoF"]["Normal"]["MarisaA"][0].get<ull>();
	MoF.wrs.normal.MarisaB = j["MoF"]["Normal"]["MarisaB"][0].get<ull>();
	MoF.wrs.normal.MarisaC = j["MoF"]["Normal"]["MarisaC"][0].get<ull>();
	MoF.wrs.hard.ReimuA = j["MoF"]["Hard"]["ReimuA"][0].get<ull>();
	MoF.wrs.hard.ReimuB = j["MoF"]["Hard"]["ReimuB"][0].get<ull>();
	MoF.wrs.hard.ReimuC = j["MoF"]["Hard"]["ReimuC"][0].get<ull>();
	MoF.wrs.hard.MarisaA = j["MoF"]["Hard"]["MarisaA"][0].get<ull>();
	MoF.wrs.hard.MarisaB = j["MoF"]["Hard"]["MarisaB"][0].get<ull>();
	MoF.wrs.hard.MarisaC = j["MoF"]["Hard"]["MarisaC"][0].get<ull>();
	MoF.wrs.lunatic.ReimuA = j["MoF"]["Lunatic"]["ReimuA"][0].get<ull>();
	MoF.wrs.lunatic.ReimuB = j["MoF"]["Lunatic"]["ReimuB"][0].get<ull>();
	MoF.wrs.lunatic.ReimuC = j["MoF"]["Lunatic"]["ReimuC"][0].get<ull>();
	MoF.wrs.lunatic.MarisaA = j["MoF"]["Lunatic"]["MarisaA"][0].get<ull>();
	MoF.wrs.lunatic.MarisaB = j["MoF"]["Lunatic"]["MarisaB"][0].get<ull>();
	MoF.wrs.lunatic.MarisaC = j["MoF"]["Lunatic"]["MarisaC"][0].get<ull>();
	MoF.wrs.extra.ReimuA = j["MoF"]["Extra"]["ReimuA"][0].get<ull>();
	MoF.wrs.extra.ReimuB = j["MoF"]["Extra"]["ReimuB"][0].get<ull>();
	MoF.wrs.extra.ReimuC = j["MoF"]["Extra"]["ReimuC"][0].get<ull>();
	MoF.wrs.extra.MarisaA = j["MoF"]["Extra"]["MarisaA"][0].get<ull>();
	MoF.wrs.extra.MarisaB = j["MoF"]["Extra"]["MarisaB"][0].get<ull>();
	MoF.wrs.extra.MarisaC = j["MoF"]["Extra"]["MarisaC"][0].get<ull>();

	// SA world record
	SA.wrs.easy.ReimuA = j["SA"]["Easy"]["ReimuA"][0].get<ull>();
	SA.wrs.easy.ReimuB = j["SA"]["Easy"]["ReimuB"][0].get<ull>();
	SA.wrs.easy.ReimuC = j["SA"]["Easy"]["ReimuC"][0].get<ull>();
	SA.wrs.easy.MarisaA = j["SA"]["Easy"]["MarisaA"][0].get<ull>();
	SA.wrs.easy.MarisaB = j["SA"]["Easy"]["MarisaB"][0].get<ull>();
	SA.wrs.easy.MarisaC = j["SA"]["Easy"]["MarisaC"][0].get<ull>();
	SA.wrs.normal.ReimuA = j["SA"]["Normal"]["ReimuA"][0].get<ull>();
	SA.wrs.normal.ReimuB = j["SA"]["Normal"]["ReimuB"][0].get<ull>();
	SA.wrs.normal.ReimuC = j["SA"]["Normal"]["ReimuC"][0].get<ull>();
	SA.wrs.normal.MarisaA = j["SA"]["Normal"]["MarisaA"][0].get<ull>();
	SA.wrs.normal.MarisaB = j["SA"]["Normal"]["MarisaB"][0].get<ull>();
	SA.wrs.normal.MarisaC = j["SA"]["Normal"]["MarisaC"][0].get<ull>();
	SA.wrs.hard.ReimuA = j["SA"]["Hard"]["ReimuA"][0].get<ull>();
	SA.wrs.hard.ReimuB = j["SA"]["Hard"]["ReimuB"][0].get<ull>();
	SA.wrs.hard.ReimuC = j["SA"]["Hard"]["ReimuC"][0].get<ull>();
	SA.wrs.hard.MarisaA = j["SA"]["Hard"]["MarisaA"][0].get<ull>();
	SA.wrs.hard.MarisaB = j["SA"]["Hard"]["MarisaB"][0].get<ull>();
	SA.wrs.hard.MarisaC = j["SA"]["Hard"]["MarisaC"][0].get<ull>();
	SA.wrs.lunatic.ReimuA = j["SA"]["Lunatic"]["ReimuA"][0].get<ull>();
	SA.wrs.lunatic.ReimuB = j["SA"]["Lunatic"]["ReimuB"][0].get<ull>();
	SA.wrs.lunatic.ReimuC = j["SA"]["Lunatic"]["ReimuC"][0].get<ull>();
	SA.wrs.lunatic.MarisaA = j["SA"]["Lunatic"]["MarisaA"][0].get<ull>();
	SA.wrs.lunatic.MarisaB = j["SA"]["Lunatic"]["MarisaB"][0].get<ull>();
	SA.wrs.lunatic.MarisaC = j["SA"]["Lunatic"]["MarisaC"][0].get<ull>();
	SA.wrs.extra.ReimuA = j["SA"]["Extra"]["ReimuA"][0].get<ull>();
	SA.wrs.extra.ReimuB = j["SA"]["Extra"]["ReimuB"][0].get<ull>();
	SA.wrs.extra.ReimuC = j["SA"]["Extra"]["ReimuC"][0].get<ull>();
	SA.wrs.extra.MarisaA = j["SA"]["Extra"]["MarisaA"][0].get<ull>();
	SA.wrs.extra.MarisaB = j["SA"]["Extra"]["MarisaB"][0].get<ull>();
	SA.wrs.extra.MarisaC = j["SA"]["Extra"]["MarisaC"][0].get<ull>();

	// UFO world record
	UFO.wrs.easy.ReimuA = j["UFO"]["Easy"]["ReimuA"][0].get<ull>();
	UFO.wrs.easy.ReimuB = j["UFO"]["Easy"]["ReimuB"][0].get<ull>();
	UFO.wrs.easy.MarisaA = j["UFO"]["Easy"]["MarisaA"][0].get<ull>();
	UFO.wrs.easy.MarisaB = j["UFO"]["Easy"]["MarisaB"][0].get<ull>();
	UFO.wrs.easy.SanaeA = j["UFO"]["Easy"]["SanaeA"][0].get<ull>();
	UFO.wrs.easy.SanaeB = j["UFO"]["Easy"]["SanaeB"][0].get<ull>();
	UFO.wrs.normal.ReimuA = j["UFO"]["Normal"]["ReimuA"][0].get<ull>();
	UFO.wrs.normal.ReimuB = j["UFO"]["Normal"]["ReimuB"][0].get<ull>();
	UFO.wrs.normal.MarisaA = j["UFO"]["Normal"]["MarisaA"][0].get<ull>();
	UFO.wrs.normal.MarisaB = j["UFO"]["Normal"]["MarisaB"][0].get<ull>();
	UFO.wrs.normal.SanaeA = j["UFO"]["Normal"]["SanaeA"][0].get<ull>();
	UFO.wrs.normal.SanaeB = j["UFO"]["Normal"]["SanaeB"][0].get<ull>();
	UFO.wrs.hard.ReimuA = j["UFO"]["Hard"]["ReimuA"][0].get<ull>();
	UFO.wrs.hard.ReimuB = j["UFO"]["Hard"]["ReimuB"][0].get<ull>();
	UFO.wrs.hard.MarisaA = j["UFO"]["Hard"]["MarisaA"][0].get<ull>();
	UFO.wrs.hard.MarisaB = j["UFO"]["Hard"]["MarisaB"][0].get<ull>();
	UFO.wrs.hard.SanaeA = j["UFO"]["Hard"]["SanaeA"][0].get<ull>();
	UFO.wrs.hard.SanaeB = j["UFO"]["Hard"]["SanaeB"][0].get<ull>();
	UFO.wrs.lunatic.ReimuA = j["UFO"]["Lunatic"]["ReimuA"][0].get<ull>();
	UFO.wrs.lunatic.ReimuB = j["UFO"]["Lunatic"]["ReimuB"][0].get<ull>();
	UFO.wrs.lunatic.MarisaA = j["UFO"]["Lunatic"]["MarisaA"][0].get<ull>();
	UFO.wrs.lunatic.MarisaB = j["UFO"]["Lunatic"]["MarisaB"][0].get<ull>();
	UFO.wrs.lunatic.SanaeA = j["UFO"]["Lunatic"]["SanaeA"][0].get<ull>();
	UFO.wrs.lunatic.SanaeB = j["UFO"]["Lunatic"]["SanaeB"][0].get<ull>();
	UFO.wrs.extra.ReimuA = j["UFO"]["Extra"]["ReimuA"][0].get<ull>();
	UFO.wrs.extra.ReimuB = j["UFO"]["Extra"]["ReimuB"][0].get<ull>();
	UFO.wrs.extra.MarisaA = j["UFO"]["Extra"]["MarisaA"][0].get<ull>();
	UFO.wrs.extra.MarisaB = j["UFO"]["Extra"]["MarisaB"][0].get<ull>();
	UFO.wrs.extra.SanaeA = j["UFO"]["Extra"]["SanaeA"][0].get<ull>();
	UFO.wrs.extra.SanaeB = j["UFO"]["Extra"]["SanaeB"][0].get<ull>();

	// TD world record
	TD.wrs.easy.Reimu = j["TD"]["Easy"]["Reimu"][0].get<ull>();
	TD.wrs.easy.Marisa = j["TD"]["Easy"]["Marisa"][0].get<ull>();
	TD.wrs.easy.Sanae = j["TD"]["Easy"]["Sanae"][0].get<ull>();
	TD.wrs.easy.Youmu = j["TD"]["Easy"]["Youmu"][0].get<ull>();
	TD.wrs.normal.Reimu = j["TD"]["Normal"]["Reimu"][0].get<ull>();
	TD.wrs.normal.Marisa = j["TD"]["Normal"]["Marisa"][0].get<ull>();
	TD.wrs.normal.Sanae = j["TD"]["Normal"]["Sanae"][0].get<ull>();
	TD.wrs.normal.Youmu = j["TD"]["Normal"]["Youmu"][0].get<ull>();
	TD.wrs.hard.Reimu = j["TD"]["Hard"]["Reimu"][0].get<ull>();
	TD.wrs.hard.Marisa = j["TD"]["Hard"]["Marisa"][0].get<ull>();
	TD.wrs.hard.Sanae = j["TD"]["Hard"]["Sanae"][0].get<ull>();
	TD.wrs.hard.Youmu = j["TD"]["Hard"]["Youmu"][0].get<ull>();
	TD.wrs.lunatic.Reimu = j["TD"]["Lunatic"]["Reimu"][0].get<ull>();
	TD.wrs.lunatic.Marisa = j["TD"]["Lunatic"]["Marisa"][0].get<ull>();
	TD.wrs.lunatic.Sanae = j["TD"]["Lunatic"]["Sanae"][0].get<ull>();
	TD.wrs.lunatic.Youmu = j["TD"]["Lunatic"]["Youmu"][0].get<ull>();
	TD.wrs.extra.Reimu = j["TD"]["Extra"]["Reimu"][0].get<ull>();
	TD.wrs.extra.Marisa = j["TD"]["Extra"]["Marisa"][0].get<ull>();
	TD.wrs.extra.Sanae = j["TD"]["Extra"]["Sanae"][0].get<ull>();
	TD.wrs.extra.Youmu = j["TD"]["Extra"]["Youmu"][0].get<ull>();

	// DDC world record
	DDC.wrs.easy.ReimuA = j["DDC"]["Easy"]["ReimuA"][0].get<ull>();
	DDC.wrs.easy.ReimuB = j["DDC"]["Easy"]["ReimuB"][0].get<ull>();
	DDC.wrs.easy.MarisaA = j["DDC"]["Easy"]["MarisaA"][0].get<ull>();
	DDC.wrs.easy.MarisaB = j["DDC"]["Easy"]["MarisaB"][0].get<ull>();
	DDC.wrs.easy.SakuyaA = j["DDC"]["Easy"]["SakuyaA"][0].get<ull>();
	DDC.wrs.easy.SakuyaB = j["DDC"]["Easy"]["SakuyaB"][0].get<ull>();
	DDC.wrs.normal.ReimuA = j["DDC"]["Normal"]["ReimuA"][0].get<ull>();
	DDC.wrs.normal.ReimuB = j["DDC"]["Normal"]["ReimuB"][0].get<ull>();
	DDC.wrs.normal.MarisaA = j["DDC"]["Normal"]["MarisaA"][0].get<ull>();
	DDC.wrs.normal.MarisaB = j["DDC"]["Normal"]["MarisaB"][0].get<ull>();
	DDC.wrs.normal.SakuyaA = j["DDC"]["Normal"]["SakuyaA"][0].get<ull>();
	DDC.wrs.normal.SakuyaB = j["DDC"]["Normal"]["SakuyaB"][0].get<ull>();
	DDC.wrs.hard.ReimuA = j["DDC"]["Hard"]["ReimuA"][0].get<ull>();
	DDC.wrs.hard.ReimuB = j["DDC"]["Hard"]["ReimuB"][0].get<ull>();
	DDC.wrs.hard.MarisaA = j["DDC"]["Hard"]["MarisaA"][0].get<ull>();
	DDC.wrs.hard.MarisaB = j["DDC"]["Hard"]["MarisaB"][0].get<ull>();
	DDC.wrs.hard.SakuyaA = j["DDC"]["Hard"]["SakuyaA"][0].get<ull>();
	DDC.wrs.hard.SakuyaB = j["DDC"]["Hard"]["SakuyaB"][0].get<ull>();
	DDC.wrs.lunatic.ReimuA = j["DDC"]["Lunatic"]["ReimuA"][0].get<ull>();
	DDC.wrs.lunatic.ReimuB = j["DDC"]["Lunatic"]["ReimuB"][0].get<ull>();
	DDC.wrs.lunatic.MarisaA = j["DDC"]["Lunatic"]["MarisaA"][0].get<ull>();
	DDC.wrs.lunatic.MarisaB = j["DDC"]["Lunatic"]["MarisaB"][0].get<ull>();
	DDC.wrs.lunatic.SakuyaA = j["DDC"]["Lunatic"]["SakuyaA"][0].get<ull>();
	DDC.wrs.lunatic.SakuyaB = j["DDC"]["Lunatic"]["SakuyaB"][0].get<ull>();
	DDC.wrs.extra.ReimuA = j["DDC"]["Extra"]["ReimuA"][0].get<ull>();
	DDC.wrs.extra.ReimuB = j["DDC"]["Extra"]["ReimuB"][0].get<ull>();
	DDC.wrs.extra.MarisaA = j["DDC"]["Extra"]["MarisaA"][0].get<ull>();
	DDC.wrs.extra.MarisaB = j["DDC"]["Extra"]["MarisaB"][0].get<ull>();
	DDC.wrs.extra.SakuyaA = j["DDC"]["Extra"]["SakuyaA"][0].get<ull>();
	DDC.wrs.extra.SakuyaB = j["DDC"]["Extra"]["SakuyaB"][0].get<ull>();

	// LoLK world record
	LoLK.wrs.easy.Reimu = j["LoLK"]["Easy"]["Reimu"][0].get<ull>();
	LoLK.wrs.easy.Marisa = j["LoLK"]["Easy"]["Marisa"][0].get<ull>();
	LoLK.wrs.easy.Sanae = j["LoLK"]["Easy"]["Sanae"][0].get<ull>();
	LoLK.wrs.easy.Reisen = j["LoLK"]["Easy"]["Reisen"][0].get<ull>();
	LoLK.wrs.normal.Reimu = j["LoLK"]["Normal"]["Reimu"][0].get<ull>();
	LoLK.wrs.normal.Marisa = j["LoLK"]["Normal"]["Marisa"][0].get<ull>();
	LoLK.wrs.normal.Sanae = j["LoLK"]["Normal"]["Sanae"][0].get<ull>();
	LoLK.wrs.normal.Reisen = j["LoLK"]["Normal"]["Reisen"][0].get<ull>();
	LoLK.wrs.hard.Reimu = j["LoLK"]["Hard"]["Reimu"][0].get<ull>();
	LoLK.wrs.hard.Marisa = j["LoLK"]["Hard"]["Marisa"][0].get<ull>();
	LoLK.wrs.hard.Sanae = j["LoLK"]["Hard"]["Sanae"][0].get<ull>();
	LoLK.wrs.hard.Reisen = j["LoLK"]["Hard"]["Reisen"][0].get<ull>();
	LoLK.wrs.lunatic.Reimu = j["LoLK"]["Lunatic"]["Reimu"][0].get<ull>();
	LoLK.wrs.lunatic.Marisa = j["LoLK"]["Lunatic"]["Marisa"][0].get<ull>();
	LoLK.wrs.lunatic.Sanae = j["LoLK"]["Lunatic"]["Sanae"][0].get<ull>();
	LoLK.wrs.lunatic.Reisen = j["LoLK"]["Lunatic"]["Reisen"][0].get<ull>();
	LoLK.wrs.extra.Reimu = j["LoLK"]["Extra"]["Reimu"][0].get<ull>();
	LoLK.wrs.extra.Marisa = j["LoLK"]["Extra"]["Marisa"][0].get<ull>();
	LoLK.wrs.extra.Sanae = j["LoLK"]["Extra"]["Sanae"][0].get<ull>();
	LoLK.wrs.extra.Reisen = j["LoLK"]["Extra"]["Reisen"][0].get<ull>();

	// HSiFS world record
	HSiFS.wrs.easy.Reimu.Spring = j["HSiFS"]["Easy"]["ReimuSpring"][0].get<ull>();
	HSiFS.wrs.easy.Reimu.Summer = j["HSiFS"]["Easy"]["ReimuSummer"][0].get<ull>();
	HSiFS.wrs.easy.Reimu.Autumn = j["HSiFS"]["Easy"]["ReimuAutumn"][0].get<ull>();
	HSiFS.wrs.easy.Reimu.Winter = j["HSiFS"]["Easy"]["ReimuWinter"][0].get<ull>();
	HSiFS.wrs.easy.Cirno.Spring = j["HSiFS"]["Easy"]["CirnoSpring"][0].get<ull>();
	HSiFS.wrs.easy.Cirno.Summer = j["HSiFS"]["Easy"]["CirnoSummer"][0].get<ull>();
	HSiFS.wrs.easy.Cirno.Autumn = j["HSiFS"]["Easy"]["CirnoAutumn"][0].get<ull>();
	HSiFS.wrs.easy.Cirno.Winter = j["HSiFS"]["Easy"]["CirnoWinter"][0].get<ull>();
	HSiFS.wrs.easy.Aya.Spring = j["HSiFS"]["Easy"]["AyaSpring"][0].get<ull>();
	HSiFS.wrs.easy.Aya.Summer = j["HSiFS"]["Easy"]["AyaSummer"][0].get<ull>();
	HSiFS.wrs.easy.Aya.Autumn = j["HSiFS"]["Easy"]["AyaAutumn"][0].get<ull>();
	HSiFS.wrs.easy.Aya.Winter = j["HSiFS"]["Easy"]["AyaWinter"][0].get<ull>();
	HSiFS.wrs.easy.Marisa.Spring = j["HSiFS"]["Easy"]["MarisaSpring"][0].get<ull>();
	HSiFS.wrs.easy.Marisa.Summer = j["HSiFS"]["Easy"]["MarisaSummer"][0].get<ull>();
	HSiFS.wrs.easy.Marisa.Autumn = j["HSiFS"]["Easy"]["MarisaAutumn"][0].get<ull>();
	HSiFS.wrs.easy.Marisa.Winter = j["HSiFS"]["Easy"]["MarisaWinter"][0].get<ull>();
	HSiFS.wrs.normal.Reimu.Spring = j["HSiFS"]["Normal"]["ReimuSpring"][0].get<ull>();
	HSiFS.wrs.normal.Reimu.Summer = j["HSiFS"]["Normal"]["ReimuSummer"][0].get<ull>();
	HSiFS.wrs.normal.Reimu.Autumn = j["HSiFS"]["Normal"]["ReimuAutumn"][0].get<ull>();
	HSiFS.wrs.normal.Reimu.Winter = j["HSiFS"]["Normal"]["ReimuWinter"][0].get<ull>();
	HSiFS.wrs.normal.Cirno.Spring = j["HSiFS"]["Normal"]["CirnoSpring"][0].get<ull>();
	HSiFS.wrs.normal.Cirno.Summer = j["HSiFS"]["Normal"]["CirnoSummer"][0].get<ull>();
	HSiFS.wrs.normal.Cirno.Autumn = j["HSiFS"]["Normal"]["CirnoAutumn"][0].get<ull>();
	HSiFS.wrs.normal.Cirno.Winter = j["HSiFS"]["Normal"]["CirnoWinter"][0].get<ull>();
	HSiFS.wrs.normal.Aya.Spring = j["HSiFS"]["Normal"]["AyaSpring"][0].get<ull>();
	HSiFS.wrs.normal.Aya.Summer = j["HSiFS"]["Normal"]["AyaSummer"][0].get<ull>();
	HSiFS.wrs.normal.Aya.Autumn = j["HSiFS"]["Normal"]["AyaAutumn"][0].get<ull>();
	HSiFS.wrs.normal.Aya.Winter = j["HSiFS"]["Normal"]["AyaWinter"][0].get<ull>();
	HSiFS.wrs.normal.Marisa.Spring = j["HSiFS"]["Normal"]["MarisaSpring"][0].get<ull>();
	HSiFS.wrs.normal.Marisa.Summer = j["HSiFS"]["Normal"]["MarisaSummer"][0].get<ull>();
	HSiFS.wrs.normal.Marisa.Autumn = j["HSiFS"]["Normal"]["MarisaAutumn"][0].get<ull>();
	HSiFS.wrs.normal.Marisa.Winter = j["HSiFS"]["Normal"]["MarisaWinter"][0].get<ull>();
	HSiFS.wrs.hard.Reimu.Spring = j["HSiFS"]["Hard"]["ReimuSpring"][0].get<ull>();
	HSiFS.wrs.hard.Reimu.Summer = j["HSiFS"]["Hard"]["ReimuSummer"][0].get<ull>();
	HSiFS.wrs.hard.Reimu.Autumn = j["HSiFS"]["Hard"]["ReimuAutumn"][0].get<ull>();
	HSiFS.wrs.hard.Reimu.Winter = j["HSiFS"]["Hard"]["ReimuWinter"][0].get<ull>();
	HSiFS.wrs.hard.Cirno.Spring = j["HSiFS"]["Hard"]["CirnoSpring"][0].get<ull>();
	HSiFS.wrs.hard.Cirno.Summer = j["HSiFS"]["Hard"]["CirnoSummer"][0].get<ull>();
	HSiFS.wrs.hard.Cirno.Autumn = j["HSiFS"]["Hard"]["CirnoAutumn"][0].get<ull>();
	HSiFS.wrs.hard.Cirno.Winter = j["HSiFS"]["Hard"]["CirnoWinter"][0].get<ull>();
	HSiFS.wrs.hard.Aya.Spring = j["HSiFS"]["Hard"]["AyaSpring"][0].get<ull>();
	HSiFS.wrs.hard.Aya.Summer = j["HSiFS"]["Hard"]["AyaSummer"][0].get<ull>();
	HSiFS.wrs.hard.Aya.Autumn = j["HSiFS"]["Hard"]["AyaAutumn"][0].get<ull>();
	HSiFS.wrs.hard.Aya.Winter = j["HSiFS"]["Hard"]["AyaWinter"][0].get<ull>();
	HSiFS.wrs.hard.Marisa.Spring = j["HSiFS"]["Hard"]["MarisaSpring"][0].get<ull>();
	HSiFS.wrs.hard.Marisa.Summer = j["HSiFS"]["Hard"]["MarisaSummer"][0].get<ull>();
	HSiFS.wrs.hard.Marisa.Autumn = j["HSiFS"]["Hard"]["MarisaAutumn"][0].get<ull>();
	HSiFS.wrs.hard.Marisa.Winter = j["HSiFS"]["Hard"]["MarisaWinter"][0].get<ull>();
	HSiFS.wrs.lunatic.Reimu.Spring = j["HSiFS"]["Lunatic"]["ReimuSpring"][0].get<ull>();
	HSiFS.wrs.lunatic.Reimu.Summer = j["HSiFS"]["Lunatic"]["ReimuSummer"][0].get<ull>();
	HSiFS.wrs.lunatic.Reimu.Autumn = j["HSiFS"]["Lunatic"]["ReimuAutumn"][0].get<ull>();
	// no iead why Maribel didn't include Reimu Spring world record
	//HSiFS.wrs.lunatic.Reimu.Winter = j["HSiFS"]["Lunatic"]["ReimuWinter"][0].get<ull>();
	HSiFS.wrs.lunatic.Cirno.Spring = j["HSiFS"]["Lunatic"]["CirnoSpring"][0].get<ull>();
	HSiFS.wrs.lunatic.Cirno.Summer = j["HSiFS"]["Lunatic"]["CirnoSummer"][0].get<ull>();
	HSiFS.wrs.lunatic.Cirno.Autumn = j["HSiFS"]["Lunatic"]["CirnoAutumn"][0].get<ull>();
	HSiFS.wrs.lunatic.Cirno.Winter = j["HSiFS"]["Lunatic"]["CirnoWinter"][0].get<ull>();
	HSiFS.wrs.lunatic.Aya.Spring = j["HSiFS"]["Lunatic"]["AyaSpring"][0].get<ull>();
	HSiFS.wrs.lunatic.Aya.Summer = j["HSiFS"]["Lunatic"]["AyaSummer"][0].get<ull>();
	HSiFS.wrs.lunatic.Aya.Autumn = j["HSiFS"]["Lunatic"]["AyaAutumn"][0].get<ull>();
	HSiFS.wrs.lunatic.Aya.Winter = j["HSiFS"]["Lunatic"]["AyaWinter"][0].get<ull>();
	HSiFS.wrs.lunatic.Marisa.Spring = j["HSiFS"]["Lunatic"]["MarisaSpring"][0].get<ull>();
	HSiFS.wrs.lunatic.Marisa.Summer = j["HSiFS"]["Lunatic"]["MarisaSummer"][0].get<ull>();
	HSiFS.wrs.lunatic.Marisa.Autumn = j["HSiFS"]["Lunatic"]["MarisaAutumn"][0].get<ull>();
	HSiFS.wrs.lunatic.Marisa.Winter = j["HSiFS"]["Lunatic"]["MarisaWinter"][0].get<ull>();
	HSiFS.wrs.extra.Reimu = j["HSiFS"]["Extra"]["Reimu"][0].get<ull>();
	HSiFS.wrs.extra.Cirno = j["HSiFS"]["Extra"]["Cirno"][0].get<ull>();
	HSiFS.wrs.extra.Aya = j["HSiFS"]["Extra"]["Aya"][0].get<ull>();
	HSiFS.wrs.extra.Marisa = j["HSiFS"]["Extra"]["Marisa"][0].get<ull>();

	std::cout << "Successfully loaded world record file." << std::endl;
	return true;
}
