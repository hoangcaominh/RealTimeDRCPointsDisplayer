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

	// file not available yet, DO NOT USE
	HRESULT hResult = URLDownloadToFile(NULL, _T(""), _T(".json"), 0, NULL);

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
	
	// result of downloading world record file
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

	std::ifstream read_rubrics("rubrics.json");	// file name not available yet
	if (read_rubrics.fail())
	{
		// failed to parse rubrics file
		std::cout << "Failed to load rubric file." << std::endl;
		return false;
	}

	// local variables to free memory when not necessary
	json j_rubrics;
	// successfully parsed rubrics file
	read_rubrics >> j_rubrics;

	if (j_rubrics.empty())
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
	json j_wrs;
	// successfully parsed rubrics file
	read_wrs >> j_wrs;

	if (j_wrs.empty())
	{
		std::cout << "No element in the world record file could be found." << std::endl;
		return false;
	}

	// Loading

	// HRtP world records
	_HRtP.wr.easy.Jigoku = j_wrs["HRtP"]["Easy"]["Jigoku"][0].get<ull>();
	_HRtP.wr.easy.Makai = j_wrs["HRtP"]["Easy"]["Makai"][0].get<ull>();
	_HRtP.wr.normal.Jigoku = j_wrs["HRtP"]["Normal"]["Jigoku"][0].get<ull>();
	_HRtP.wr.normal.Makai = j_wrs["HRtP"]["Normal"]["Makai"][0].get<ull>();
	_HRtP.wr.hard.Jigoku = j_wrs["HRtP"]["Hard"]["Jigoku"][0].get<ull>();
	_HRtP.wr.hard.Makai = j_wrs["HRtP"]["Hard"]["Makai"][0].get<ull>();
	_HRtP.wr.lunatic.Jigoku = j_wrs["HRtP"]["Lunatic"]["Jigoku"][0].get<ull>();
	_HRtP.wr.lunatic.Makai = j_wrs["HRtP"]["Lunatic"]["Makai"][0].get<ull>();

	// SoEW world records
	_SoEW.wr.easy.ReimuA = j_wrs["SoEW"]["Easy"]["ReimuA"][0].get<ull>();
	_SoEW.wr.easy.ReimuB = j_wrs["SoEW"]["Easy"]["ReimuB"][0].get<ull>();
	_SoEW.wr.easy.ReimuC = j_wrs["SoEW"]["Easy"]["ReimuC"][0].get<ull>();
	_SoEW.wr.normal.ReimuA = j_wrs["SoEW"]["Normal"]["ReimuA"][0].get<ull>();
	_SoEW.wr.normal.ReimuB = j_wrs["SoEW"]["Normal"]["ReimuB"][0].get<ull>();
	_SoEW.wr.normal.ReimuC = j_wrs["SoEW"]["Normal"]["ReimuC"][0].get<ull>();
	_SoEW.wr.hard.ReimuA = j_wrs["SoEW"]["Hard"]["ReimuA"][0].get<ull>();
	_SoEW.wr.hard.ReimuB = j_wrs["SoEW"]["Hard"]["ReimuB"][0].get<ull>();
	_SoEW.wr.hard.ReimuC = j_wrs["SoEW"]["Hard"]["ReimuC"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuA = j_wrs["SoEW"]["Lunatic"]["ReimuA"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuB = j_wrs["SoEW"]["Lunatic"]["ReimuB"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuC = j_wrs["SoEW"]["Lunatic"]["ReimuC"][0].get<ull>();
	_SoEW.wr.extra.ReimuA = j_wrs["SoEW"]["Extra"]["ReimuA"][0].get<ull>();
	_SoEW.wr.extra.ReimuB = j_wrs["SoEW"]["Extra"]["ReimuB"][0].get<ull>();
	_SoEW.wr.extra.ReimuC = j_wrs["SoEW"]["Extra"]["ReimuC"][0].get<ull>();

	// PoDD world records
	_PoDD.wr.easy.Reimu = j_wrs["PoDD"]["Easy"]["Reimu"][0].get<ull>();
	_PoDD.wr.easy.Mima = j_wrs["PoDD"]["Easy"]["Mima"][0].get<ull>();
	_PoDD.wr.easy.Marisa = j_wrs["PoDD"]["Easy"]["Marisa"][0].get<ull>();
	_PoDD.wr.easy.Ellen = j_wrs["PoDD"]["Easy"]["Ellen"][0].get<ull>();
	_PoDD.wr.easy.Kotohime = j_wrs["PoDD"]["Easy"]["Kotohime"][0].get<ull>();
	_PoDD.wr.easy.Kana = j_wrs["PoDD"]["Easy"]["Kana"][0].get<ull>();
	_PoDD.wr.easy.Rikako = j_wrs["PoDD"]["Easy"]["Rikako"][0].get<ull>();
	_PoDD.wr.easy.Chiyuri = j_wrs["PoDD"]["Easy"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.easy.Yumemi = j_wrs["PoDD"]["Easy"]["Yumemi"][0].get<ull>();
	_PoDD.wr.normal.Reimu = j_wrs["PoDD"]["Normal"]["Reimu"][0].get<ull>();
	_PoDD.wr.normal.Mima = j_wrs["PoDD"]["Normal"]["Mima"][0].get<ull>();
	_PoDD.wr.normal.Marisa = j_wrs["PoDD"]["Normal"]["Marisa"][0].get<ull>();
	_PoDD.wr.normal.Ellen = j_wrs["PoDD"]["Normal"]["Ellen"][0].get<ull>();
	_PoDD.wr.normal.Kotohime = j_wrs["PoDD"]["Normal"]["Kotohime"][0].get<ull>();
	_PoDD.wr.normal.Kana = j_wrs["PoDD"]["Normal"]["Kana"][0].get<ull>();
	_PoDD.wr.normal.Rikako = j_wrs["PoDD"]["Normal"]["Rikako"][0].get<ull>();
	_PoDD.wr.normal.Chiyuri = j_wrs["PoDD"]["Normal"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.normal.Yumemi = j_wrs["PoDD"]["Normal"]["Yumemi"][0].get<ull>();
	_PoDD.wr.hard.Reimu = j_wrs["PoDD"]["Hard"]["Reimu"][0].get<ull>();
	_PoDD.wr.hard.Mima = j_wrs["PoDD"]["Hard"]["Mima"][0].get<ull>();
	_PoDD.wr.hard.Marisa = j_wrs["PoDD"]["Hard"]["Marisa"][0].get<ull>();
	_PoDD.wr.hard.Ellen = j_wrs["PoDD"]["Hard"]["Ellen"][0].get<ull>();
	_PoDD.wr.hard.Kotohime = j_wrs["PoDD"]["Hard"]["Kotohime"][0].get<ull>();
	_PoDD.wr.hard.Kana = j_wrs["PoDD"]["Hard"]["Kana"][0].get<ull>();
	_PoDD.wr.hard.Rikako = j_wrs["PoDD"]["Hard"]["Rikako"][0].get<ull>();
	_PoDD.wr.hard.Chiyuri = j_wrs["PoDD"]["Hard"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.hard.Yumemi = j_wrs["PoDD"]["Hard"]["Yumemi"][0].get<ull>();
	_PoDD.wr.lunatic.Reimu = j_wrs["PoDD"]["Lunatic"]["Reimu"][0].get<ull>();
	_PoDD.wr.lunatic.Mima = j_wrs["PoDD"]["Lunatic"]["Mima"][0].get<ull>();
	_PoDD.wr.lunatic.Marisa = j_wrs["PoDD"]["Lunatic"]["Marisa"][0].get<ull>();
	_PoDD.wr.lunatic.Ellen = j_wrs["PoDD"]["Lunatic"]["Ellen"][0].get<ull>();
	_PoDD.wr.lunatic.Kotohime = j_wrs["PoDD"]["Lunatic"]["Kotohime"][0].get<ull>();
	_PoDD.wr.lunatic.Kana = j_wrs["PoDD"]["Lunatic"]["Kana"][0].get<ull>();
	_PoDD.wr.lunatic.Rikako = j_wrs["PoDD"]["Lunatic"]["Rikako"][0].get<ull>();
	_PoDD.wr.lunatic.Chiyuri = j_wrs["PoDD"]["Lunatic"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.lunatic.Yumemi = j_wrs["PoDD"]["Lunatic"]["Yumemi"][0].get<ull>();

	// LLS world records
	_LLS.wr.easy.ReimuA = j_wrs["LLS"]["Easy"]["ReimuA"][0].get<ull>();
	_LLS.wr.easy.ReimuB = j_wrs["LLS"]["Easy"]["ReimuB"][0].get<ull>();
	_LLS.wr.easy.MarisaA = j_wrs["LLS"]["Easy"]["MarisaA"][0].get<ull>();
	_LLS.wr.easy.MarisaB = j_wrs["LLS"]["Easy"]["MarisaB"][0].get<ull>();
	_LLS.wr.normal.ReimuA = j_wrs["LLS"]["Normal"]["ReimuA"][0].get<ull>();
	_LLS.wr.normal.ReimuB = j_wrs["LLS"]["Normal"]["ReimuB"][0].get<ull>();
	_LLS.wr.normal.MarisaA = j_wrs["LLS"]["Normal"]["MarisaA"][0].get<ull>();
	_LLS.wr.normal.MarisaB = j_wrs["LLS"]["Normal"]["MarisaB"][0].get<ull>();
	_LLS.wr.hard.ReimuA = j_wrs["LLS"]["Hard"]["ReimuA"][0].get<ull>();
	_LLS.wr.hard.ReimuB = j_wrs["LLS"]["Hard"]["ReimuB"][0].get<ull>();
	_LLS.wr.hard.MarisaA = j_wrs["LLS"]["Hard"]["MarisaA"][0].get<ull>();
	_LLS.wr.hard.MarisaB = j_wrs["LLS"]["Hard"]["MarisaB"][0].get<ull>();
	_LLS.wr.lunatic.ReimuA = j_wrs["LLS"]["Lunatic"]["ReimuA"][0].get<ull>();
	_LLS.wr.lunatic.ReimuB = j_wrs["LLS"]["Lunatic"]["ReimuB"][0].get<ull>();
	_LLS.wr.lunatic.MarisaA = j_wrs["LLS"]["Lunatic"]["MarisaA"][0].get<ull>();
	_LLS.wr.lunatic.MarisaB = j_wrs["LLS"]["Lunatic"]["MarisaB"][0].get<ull>();
	_LLS.wr.extra.ReimuA = j_wrs["LLS"]["Extra"]["ReimuA"][0].get<ull>();
	_LLS.wr.extra.ReimuB = j_wrs["LLS"]["Extra"]["ReimuB"][0].get<ull>();
	_LLS.wr.extra.MarisaA = j_wrs["LLS"]["Extra"]["MarisaA"][0].get<ull>();
	_LLS.wr.extra.MarisaB = j_wrs["LLS"]["Extra"]["MarisaB"][0].get<ull>();

	// MS world record
	_MS.wr.easy.Reimu = j_wrs["MS"]["Easy"]["Reimu"][0].get<ull>();
	_MS.wr.easy.Marisa = j_wrs["MS"]["Easy"]["Marisa"][0].get<ull>();
	_MS.wr.easy.Mima = j_wrs["MS"]["Easy"]["Mima"][0].get<ull>();
	_MS.wr.easy.Yuuka = j_wrs["MS"]["Easy"]["Yuuka"][0].get<ull>();
	_MS.wr.normal.Reimu = j_wrs["MS"]["Normal"]["Reimu"][0].get<ull>();
	_MS.wr.normal.Marisa = j_wrs["MS"]["Normal"]["Marisa"][0].get<ull>();
	_MS.wr.normal.Mima = j_wrs["MS"]["Normal"]["Mima"][0].get<ull>();
	_MS.wr.normal.Yuuka = j_wrs["MS"]["Normal"]["Yuuka"][0].get<ull>();
	_MS.wr.hard.Reimu = j_wrs["MS"]["Hard"]["Reimu"][0].get<ull>();
	_MS.wr.hard.Marisa = j_wrs["MS"]["Hard"]["Marisa"][0].get<ull>();
	_MS.wr.hard.Mima = j_wrs["MS"]["Hard"]["Mima"][0].get<ull>();
	_MS.wr.hard.Yuuka = j_wrs["MS"]["Hard"]["Yuuka"][0].get<ull>();
	_MS.wr.lunatic.Reimu = j_wrs["MS"]["Lunatic"]["Reimu"][0].get<ull>();
	_MS.wr.lunatic.Marisa = j_wrs["MS"]["Lunatic"]["Marisa"][0].get<ull>();
	_MS.wr.lunatic.Mima = j_wrs["MS"]["Lunatic"]["Mima"][0].get<ull>();
	_MS.wr.lunatic.Yuuka = j_wrs["MS"]["Lunatic"]["Yuuka"][0].get<ull>();
	_MS.wr.extra.Reimu = j_wrs["MS"]["Extra"]["Reimu"][0].get<ull>();
	_MS.wr.extra.Marisa = j_wrs["MS"]["Extra"]["Marisa"][0].get<ull>();
	_MS.wr.extra.Mima = j_wrs["MS"]["Extra"]["Mima"][0].get<ull>();
	_MS.wr.extra.Yuuka = j_wrs["MS"]["Extra"]["Yuuka"][0].get<ull>();

	// EoSD world record
	_EoSD.wr.easy.ReimuA = j_wrs["EoSD"]["Easy"]["ReimuA"][0].get<int>();
	_EoSD.wr.easy.ReimuB = j_wrs["EoSD"]["Easy"]["ReimuB"][0].get<int>();
	_EoSD.wr.easy.MarisaA = j_wrs["EoSD"]["Easy"]["MarisaA"][0].get<int>();
	_EoSD.wr.easy.MarisaB = j_wrs["EoSD"]["Easy"]["MarisaB"][0].get<int>();
	_EoSD.wr.normal.ReimuA = j_wrs["EoSD"]["Normal"]["ReimuA"][0].get<int>();
	_EoSD.wr.normal.ReimuB = j_wrs["EoSD"]["Normal"]["ReimuB"][0].get<int>();
	_EoSD.wr.normal.MarisaA = j_wrs["EoSD"]["Normal"]["MarisaA"][0].get<int>();
	_EoSD.wr.normal.MarisaB = j_wrs["EoSD"]["Normal"]["MarisaB"][0].get<int>();
	_EoSD.wr.hard.ReimuA = j_wrs["EoSD"]["Hard"]["ReimuA"][0].get<int>();
	_EoSD.wr.hard.ReimuB = j_wrs["EoSD"]["Hard"]["ReimuB"][0].get<int>();
	_EoSD.wr.hard.MarisaA = j_wrs["EoSD"]["Hard"]["MarisaA"][0].get<int>();
	_EoSD.wr.hard.MarisaB = j_wrs["EoSD"]["Hard"]["MarisaB"][0].get<int>();
	_EoSD.wr.lunatic.ReimuA = j_wrs["EoSD"]["Lunatic"]["ReimuA"][0].get<int>();
	_EoSD.wr.lunatic.ReimuB = j_wrs["EoSD"]["Lunatic"]["ReimuB"][0].get<int>();
	_EoSD.wr.lunatic.MarisaA = j_wrs["EoSD"]["Lunatic"]["MarisaA"][0].get<int>();
	_EoSD.wr.lunatic.MarisaB = j_wrs["EoSD"]["Lunatic"]["MarisaB"][0].get<int>();
	_EoSD.wr.extra.ReimuA = j_wrs["EoSD"]["Extra"]["ReimuA"][0].get<int>();
	_EoSD.wr.extra.ReimuB = j_wrs["EoSD"]["Extra"]["ReimuB"][0].get<int>();
	_EoSD.wr.extra.MarisaA = j_wrs["EoSD"]["Extra"]["MarisaA"][0].get<int>();
	_EoSD.wr.extra.MarisaB = j_wrs["EoSD"]["Extra"]["MarisaB"][0].get<int>();

	// PCB world record
	_PCB.wr.easy.ReimuA = j_wrs["PCB"]["Easy"]["ReimuA"][0].get<ull>();
	_PCB.wr.easy.ReimuB = j_wrs["PCB"]["Easy"]["ReimuB"][0].get<ull>();
	_PCB.wr.easy.MarisaA = j_wrs["PCB"]["Easy"]["MarisaA"][0].get<ull>();
	_PCB.wr.easy.MarisaB = j_wrs["PCB"]["Easy"]["MarisaB"][0].get<ull>();
	_PCB.wr.easy.SakuyaA = j_wrs["PCB"]["Easy"]["SakuyaA"][0].get<ull>();
	_PCB.wr.easy.SakuyaB = j_wrs["PCB"]["Easy"]["SakuyaB"][0].get<ull>();
	_PCB.wr.normal.ReimuA = j_wrs["PCB"]["Normal"]["ReimuA"][0].get<ull>();
	_PCB.wr.normal.ReimuB = j_wrs["PCB"]["Normal"]["ReimuB"][0].get<ull>();
	_PCB.wr.normal.MarisaA = j_wrs["PCB"]["Normal"]["MarisaA"][0].get<ull>();
	_PCB.wr.normal.MarisaB = j_wrs["PCB"]["Normal"]["MarisaB"][0].get<ull>();
	_PCB.wr.normal.SakuyaA = j_wrs["PCB"]["Normal"]["SakuyaA"][0].get<ull>();
	_PCB.wr.normal.SakuyaB = j_wrs["PCB"]["Normal"]["SakuyaB"][0].get<ull>();
	_PCB.wr.hard.ReimuA = j_wrs["PCB"]["Hard"]["ReimuA"][0].get<ull>();
	_PCB.wr.hard.ReimuB = j_wrs["PCB"]["Hard"]["ReimuB"][0].get<ull>();
	_PCB.wr.hard.MarisaA = j_wrs["PCB"]["Hard"]["MarisaA"][0].get<ull>();
	_PCB.wr.hard.MarisaB = j_wrs["PCB"]["Hard"]["MarisaB"][0].get<ull>();
	_PCB.wr.hard.SakuyaA = j_wrs["PCB"]["Hard"]["SakuyaA"][0].get<ull>();
	_PCB.wr.hard.SakuyaB = j_wrs["PCB"]["Hard"]["SakuyaB"][0].get<ull>();
	_PCB.wr.lunatic.ReimuA = j_wrs["PCB"]["Lunatic"]["ReimuA"][0].get<ull>();
	_PCB.wr.lunatic.ReimuB = j_wrs["PCB"]["Lunatic"]["ReimuB"][0].get<ull>();
	_PCB.wr.lunatic.MarisaA = j_wrs["PCB"]["Lunatic"]["MarisaA"][0].get<ull>();
	_PCB.wr.lunatic.MarisaB = j_wrs["PCB"]["Lunatic"]["MarisaB"][0].get<ull>();
	_PCB.wr.lunatic.SakuyaA = j_wrs["PCB"]["Lunatic"]["SakuyaA"][0].get<ull>();
	_PCB.wr.lunatic.SakuyaB = j_wrs["PCB"]["Lunatic"]["SakuyaB"][0].get<ull>();
	_PCB.wr.extra.ReimuA = j_wrs["PCB"]["Extra"]["ReimuA"][0].get<ull>();
	_PCB.wr.extra.ReimuB = j_wrs["PCB"]["Extra"]["ReimuB"][0].get<ull>();
	_PCB.wr.extra.MarisaA = j_wrs["PCB"]["Extra"]["MarisaA"][0].get<ull>();
	_PCB.wr.extra.MarisaB = j_wrs["PCB"]["Extra"]["MarisaB"][0].get<ull>();
	_PCB.wr.extra.SakuyaA = j_wrs["PCB"]["Extra"]["SakuyaA"][0].get<ull>();
	_PCB.wr.extra.SakuyaB = j_wrs["PCB"]["Extra"]["SakuyaB"][0].get<ull>();
	_PCB.wr.phantasm.ReimuA = j_wrs["PCB"]["Phantasm"]["ReimuA"][0].get<ull>();
	_PCB.wr.phantasm.ReimuB = j_wrs["PCB"]["Phantasm"]["ReimuB"][0].get<ull>();
	_PCB.wr.phantasm.MarisaA = j_wrs["PCB"]["Phantasm"]["MarisaA"][0].get<ull>();
	_PCB.wr.phantasm.MarisaB = j_wrs["PCB"]["Phantasm"]["MarisaB"][0].get<ull>();
	_PCB.wr.phantasm.SakuyaA = j_wrs["PCB"]["Phantasm"]["SakuyaA"][0].get<ull>();
	_PCB.wr.phantasm.SakuyaB = j_wrs["PCB"]["Phantasm"]["SakuyaB"][0].get<ull>();

	// IN world record
	_IN.wr.easy.BorderTeam = j_wrs["IN"]["Easy"]["BorderTeam"][0].get<ull>();
	_IN.wr.easy.MagicTeam = j_wrs["IN"]["Easy"]["MagicTeam"][0].get<ull>();
	_IN.wr.easy.ScarletTeam = j_wrs["IN"]["Easy"]["ScarletTeam"][0].get<ull>();
	_IN.wr.easy.GhostTeam = j_wrs["IN"]["Easy"]["GhostTeam"][0].get<ull>();
	_IN.wr.easy.Reimu = j_wrs["IN"]["Easy"]["Reimu"][0].get<ull>();
	_IN.wr.easy.Yukari = j_wrs["IN"]["Easy"]["Yukari"][0].get<ull>();
	_IN.wr.easy.Marisa = j_wrs["IN"]["Easy"]["Marisa"][0].get<ull>();
	_IN.wr.easy.Alice = j_wrs["IN"]["Easy"]["Alice"][0].get<ull>();
	_IN.wr.easy.Sakuya = j_wrs["IN"]["Easy"]["Sakuya"][0].get<ull>();
	_IN.wr.easy.Remilia = j_wrs["IN"]["Easy"]["Remilia"][0].get<ull>();
	_IN.wr.easy.Youmu = j_wrs["IN"]["Easy"]["Youmu"][0].get<ull>();
	_IN.wr.easy.Yuyuko = j_wrs["IN"]["Easy"]["Yuyuko"][0].get<ull>();
	_IN.wr.normal.BorderTeam = j_wrs["IN"]["Normal"]["BorderTeam"][0].get<ull>();
	_IN.wr.normal.MagicTeam = j_wrs["IN"]["Normal"]["MagicTeam"][0].get<ull>();
	_IN.wr.normal.ScarletTeam = j_wrs["IN"]["Normal"]["ScarletTeam"][0].get<ull>();
	_IN.wr.normal.GhostTeam = j_wrs["IN"]["Normal"]["GhostTeam"][0].get<ull>();
	_IN.wr.normal.Reimu = j_wrs["IN"]["Normal"]["Reimu"][0].get<ull>();
	_IN.wr.normal.Yukari = j_wrs["IN"]["Normal"]["Yukari"][0].get<ull>();
	_IN.wr.normal.Marisa = j_wrs["IN"]["Normal"]["Marisa"][0].get<ull>();
	_IN.wr.normal.Alice = j_wrs["IN"]["Normal"]["Alice"][0].get<ull>();
	_IN.wr.normal.Sakuya = j_wrs["IN"]["Normal"]["Sakuya"][0].get<ull>();
	_IN.wr.normal.Remilia = j_wrs["IN"]["Normal"]["Remilia"][0].get<ull>();
	_IN.wr.normal.Youmu = j_wrs["IN"]["Normal"]["Youmu"][0].get<ull>();
	_IN.wr.normal.Yuyuko = j_wrs["IN"]["Normal"]["Yuyuko"][0].get<ull>();
	_IN.wr.hard.BorderTeam = j_wrs["IN"]["Hard"]["BorderTeam"][0].get<ull>();
	_IN.wr.hard.MagicTeam = j_wrs["IN"]["Hard"]["MagicTeam"][0].get<ull>();
	_IN.wr.hard.ScarletTeam = j_wrs["IN"]["Hard"]["ScarletTeam"][0].get<ull>();
	_IN.wr.hard.GhostTeam = j_wrs["IN"]["Hard"]["GhostTeam"][0].get<ull>();
	_IN.wr.hard.Reimu = j_wrs["IN"]["Hard"]["Reimu"][0].get<ull>();
	_IN.wr.hard.Yukari = j_wrs["IN"]["Hard"]["Yukari"][0].get<ull>();
	_IN.wr.hard.Marisa = j_wrs["IN"]["Hard"]["Marisa"][0].get<ull>();
	_IN.wr.hard.Alice = j_wrs["IN"]["Hard"]["Alice"][0].get<ull>();
	_IN.wr.hard.Sakuya = j_wrs["IN"]["Hard"]["Sakuya"][0].get<ull>();
	_IN.wr.hard.Remilia = j_wrs["IN"]["Hard"]["Remilia"][0].get<ull>();
	_IN.wr.hard.Youmu = j_wrs["IN"]["Hard"]["Youmu"][0].get<ull>();
	_IN.wr.hard.Yuyuko = j_wrs["IN"]["Hard"]["Yuyuko"][0].get<ull>();
	_IN.wr.lunatic.BorderTeam = j_wrs["IN"]["Lunatic"]["BorderTeam"][0].get<ull>();
	_IN.wr.lunatic.MagicTeam = j_wrs["IN"]["Lunatic"]["MagicTeam"][0].get<ull>();
	_IN.wr.lunatic.ScarletTeam = j_wrs["IN"]["Lunatic"]["ScarletTeam"][0].get<ull>();
	_IN.wr.lunatic.GhostTeam = j_wrs["IN"]["Lunatic"]["GhostTeam"][0].get<ull>();
	_IN.wr.lunatic.Reimu = j_wrs["IN"]["Lunatic"]["Reimu"][0].get<ull>();
	_IN.wr.lunatic.Yukari = j_wrs["IN"]["Lunatic"]["Yukari"][0].get<ull>();
	_IN.wr.lunatic.Marisa = j_wrs["IN"]["Lunatic"]["Marisa"][0].get<ull>();
	_IN.wr.lunatic.Alice = j_wrs["IN"]["Lunatic"]["Alice"][0].get<ull>();
	_IN.wr.lunatic.Sakuya = j_wrs["IN"]["Lunatic"]["Sakuya"][0].get<ull>();
	_IN.wr.lunatic.Remilia = j_wrs["IN"]["Lunatic"]["Remilia"][0].get<ull>();
	_IN.wr.lunatic.Youmu = j_wrs["IN"]["Lunatic"]["Youmu"][0].get<ull>();
	_IN.wr.lunatic.Yuyuko = j_wrs["IN"]["Lunatic"]["Yuyuko"][0].get<ull>();
	_IN.wr.extra.BorderTeam = j_wrs["IN"]["Extra"]["BorderTeam"][0].get<ull>();
	_IN.wr.extra.MagicTeam = j_wrs["IN"]["Extra"]["MagicTeam"][0].get<ull>();
	_IN.wr.extra.ScarletTeam = j_wrs["IN"]["Extra"]["ScarletTeam"][0].get<ull>();
	_IN.wr.extra.GhostTeam = j_wrs["IN"]["Extra"]["GhostTeam"][0].get<ull>();
	_IN.wr.extra.Reimu = j_wrs["IN"]["Extra"]["Reimu"][0].get<ull>();
	_IN.wr.extra.Yukari = j_wrs["IN"]["Extra"]["Yukari"][0].get<ull>();
	_IN.wr.extra.Marisa = j_wrs["IN"]["Extra"]["Marisa"][0].get<ull>();
	_IN.wr.extra.Alice = j_wrs["IN"]["Extra"]["Alice"][0].get<ull>();
	_IN.wr.extra.Sakuya = j_wrs["IN"]["Extra"]["Sakuya"][0].get<ull>();
	_IN.wr.extra.Remilia = j_wrs["IN"]["Extra"]["Remilia"][0].get<ull>();
	_IN.wr.extra.Youmu = j_wrs["IN"]["Extra"]["Youmu"][0].get<ull>();
	_IN.wr.extra.Yuyuko = j_wrs["IN"]["Extra"]["Yuyuko"][0].get<ull>();

	// PoFV world record
	_PoFV.wr.easy.Reimu = j_wrs["PoFV"]["Easy"]["Reimu"][0].get<ull>();
	_PoFV.wr.easy.Marisa = j_wrs["PoFV"]["Easy"]["Marisa"][0].get<ull>();
	_PoFV.wr.easy.Sakuya = j_wrs["PoFV"]["Easy"]["Sakuya"][0].get<ull>();
	_PoFV.wr.easy.Youmu = j_wrs["PoFV"]["Easy"]["Youmu"][0].get<ull>();
	_PoFV.wr.easy.Reisen = j_wrs["PoFV"]["Easy"]["Reisen"][0].get<ull>();
	_PoFV.wr.easy.Cirno = j_wrs["PoFV"]["Easy"]["Cirno"][0].get<ull>();
	_PoFV.wr.easy.Lyrica = j_wrs["PoFV"]["Easy"]["Lyrica"][0].get<ull>();
	_PoFV.wr.easy.Mystia = j_wrs["PoFV"]["Easy"]["Mystia"][0].get<ull>();
	_PoFV.wr.easy.Tewi = j_wrs["PoFV"]["Easy"]["Tewi"][0].get<ull>();
	_PoFV.wr.easy.Aya = j_wrs["PoFV"]["Easy"]["Aya"][0].get<ull>();
	_PoFV.wr.easy.Medicine = j_wrs["PoFV"]["Easy"]["Medicine"][0].get<ull>();
	_PoFV.wr.easy.Yuuka = j_wrs["PoFV"]["Easy"]["Yuuka"][0].get<ull>();
	_PoFV.wr.easy.Komachi = j_wrs["PoFV"]["Easy"]["Komachi"][0].get<ull>();
	_PoFV.wr.easy.Eiki = j_wrs["PoFV"]["Easy"]["Eiki"][0].get<ull>();
	_PoFV.wr.normal.Reimu = j_wrs["PoFV"]["Normal"]["Reimu"][0].get<ull>();
	_PoFV.wr.normal.Marisa = j_wrs["PoFV"]["Normal"]["Marisa"][0].get<ull>();
	_PoFV.wr.normal.Sakuya = j_wrs["PoFV"]["Normal"]["Sakuya"][0].get<ull>();
	_PoFV.wr.normal.Youmu = j_wrs["PoFV"]["Normal"]["Youmu"][0].get<ull>();
	_PoFV.wr.normal.Reisen = j_wrs["PoFV"]["Normal"]["Reisen"][0].get<ull>();
	_PoFV.wr.normal.Cirno = j_wrs["PoFV"]["Normal"]["Cirno"][0].get<ull>();
	_PoFV.wr.normal.Lyrica = j_wrs["PoFV"]["Normal"]["Lyrica"][0].get<ull>();
	_PoFV.wr.normal.Mystia = j_wrs["PoFV"]["Normal"]["Mystia"][0].get<ull>();
	_PoFV.wr.normal.Tewi = j_wrs["PoFV"]["Normal"]["Tewi"][0].get<ull>();
	_PoFV.wr.normal.Aya = j_wrs["PoFV"]["Normal"]["Aya"][0].get<ull>();
	_PoFV.wr.normal.Medicine = j_wrs["PoFV"]["Normal"]["Medicine"][0].get<ull>();
	_PoFV.wr.normal.Yuuka = j_wrs["PoFV"]["Normal"]["Yuuka"][0].get<ull>();
	_PoFV.wr.normal.Komachi = j_wrs["PoFV"]["Normal"]["Komachi"][0].get<ull>();
	_PoFV.wr.normal.Eiki = j_wrs["PoFV"]["Normal"]["Eiki"][0].get<ull>();
	_PoFV.wr.hard.Reimu = j_wrs["PoFV"]["Hard"]["Reimu"][0].get<ull>();
	_PoFV.wr.hard.Marisa = j_wrs["PoFV"]["Hard"]["Marisa"][0].get<ull>();
	_PoFV.wr.hard.Sakuya = j_wrs["PoFV"]["Hard"]["Sakuya"][0].get<ull>();
	_PoFV.wr.hard.Youmu = j_wrs["PoFV"]["Hard"]["Youmu"][0].get<ull>();
	_PoFV.wr.hard.Reisen = j_wrs["PoFV"]["Hard"]["Reisen"][0].get<ull>();
	_PoFV.wr.hard.Cirno = j_wrs["PoFV"]["Hard"]["Cirno"][0].get<ull>();
	_PoFV.wr.hard.Lyrica = j_wrs["PoFV"]["Hard"]["Lyrica"][0].get<ull>();
	_PoFV.wr.hard.Mystia = j_wrs["PoFV"]["Hard"]["Mystia"][0].get<ull>();
	_PoFV.wr.hard.Tewi = j_wrs["PoFV"]["Hard"]["Tewi"][0].get<ull>();
	_PoFV.wr.hard.Aya = j_wrs["PoFV"]["Hard"]["Aya"][0].get<ull>();
	_PoFV.wr.hard.Medicine = j_wrs["PoFV"]["Hard"]["Medicine"][0].get<ull>();
	_PoFV.wr.hard.Yuuka = j_wrs["PoFV"]["Hard"]["Yuuka"][0].get<ull>();
	_PoFV.wr.hard.Komachi = j_wrs["PoFV"]["Hard"]["Komachi"][0].get<ull>();
	_PoFV.wr.hard.Eiki = j_wrs["PoFV"]["Hard"]["Eiki"][0].get<ull>();
	_PoFV.wr.lunatic.Reimu = j_wrs["PoFV"]["Lunatic"]["Reimu"][0].get<ull>();
	_PoFV.wr.lunatic.Marisa = j_wrs["PoFV"]["Lunatic"]["Marisa"][0].get<ull>();
	_PoFV.wr.lunatic.Sakuya = j_wrs["PoFV"]["Lunatic"]["Sakuya"][0].get<ull>();
	_PoFV.wr.lunatic.Youmu = j_wrs["PoFV"]["Lunatic"]["Youmu"][0].get<ull>();
	_PoFV.wr.lunatic.Reisen = j_wrs["PoFV"]["Lunatic"]["Reisen"][0].get<ull>();
	_PoFV.wr.lunatic.Cirno = j_wrs["PoFV"]["Lunatic"]["Cirno"][0].get<ull>();
	_PoFV.wr.lunatic.Lyrica = j_wrs["PoFV"]["Lunatic"]["Lyrica"][0].get<ull>();
	_PoFV.wr.lunatic.Mystia = j_wrs["PoFV"]["Lunatic"]["Mystia"][0].get<ull>();
	_PoFV.wr.lunatic.Tewi = j_wrs["PoFV"]["Lunatic"]["Tewi"][0].get<ull>();
	_PoFV.wr.lunatic.Aya = j_wrs["PoFV"]["Lunatic"]["Aya"][0].get<ull>();
	_PoFV.wr.lunatic.Medicine = j_wrs["PoFV"]["Lunatic"]["Medicine"][0].get<ull>();
	_PoFV.wr.lunatic.Yuuka = j_wrs["PoFV"]["Lunatic"]["Yuuka"][0].get<ull>();
	_PoFV.wr.lunatic.Komachi = j_wrs["PoFV"]["Lunatic"]["Komachi"][0].get<ull>();
	_PoFV.wr.lunatic.Eiki = j_wrs["PoFV"]["Lunatic"]["Eiki"][0].get<ull>();
	_PoFV.wr.extra.Reimu = j_wrs["PoFV"]["Extra"]["Reimu"][0].get<ull>();
	_PoFV.wr.extra.Marisa = j_wrs["PoFV"]["Extra"]["Marisa"][0].get<ull>();
	_PoFV.wr.extra.Sakuya = j_wrs["PoFV"]["Extra"]["Sakuya"][0].get<ull>();
	_PoFV.wr.extra.Youmu = j_wrs["PoFV"]["Extra"]["Youmu"][0].get<ull>();
	_PoFV.wr.extra.Reisen = j_wrs["PoFV"]["Extra"]["Reisen"][0].get<ull>();
	_PoFV.wr.extra.Cirno = j_wrs["PoFV"]["Extra"]["Cirno"][0].get<ull>();
	_PoFV.wr.extra.Lyrica = j_wrs["PoFV"]["Extra"]["Lyrica"][0].get<ull>();
	_PoFV.wr.extra.Mystia = j_wrs["PoFV"]["Extra"]["Mystia"][0].get<ull>();
	_PoFV.wr.extra.Tewi = j_wrs["PoFV"]["Extra"]["Tewi"][0].get<ull>();
	_PoFV.wr.extra.Aya = j_wrs["PoFV"]["Extra"]["Aya"][0].get<ull>();
	_PoFV.wr.extra.Medicine = j_wrs["PoFV"]["Extra"]["Medicine"][0].get<ull>();
	_PoFV.wr.extra.Yuuka = j_wrs["PoFV"]["Extra"]["Yuuka"][0].get<ull>();
	_PoFV.wr.extra.Komachi = j_wrs["PoFV"]["Extra"]["Komachi"][0].get<ull>();
	_PoFV.wr.extra.Eiki = j_wrs["PoFV"]["Extra"]["Eiki"][0].get<ull>();

	// MoF world record
	_MoF.wr.easy.ReimuA = j_wrs["MoF"]["Easy"]["ReimuA"][0].get<ull>();
	_MoF.wr.easy.ReimuB = j_wrs["MoF"]["Easy"]["ReimuB"][0].get<ull>();
	_MoF.wr.easy.ReimuC = j_wrs["MoF"]["Easy"]["ReimuC"][0].get<ull>();
	_MoF.wr.easy.MarisaA = j_wrs["MoF"]["Easy"]["MarisaA"][0].get<ull>();
	_MoF.wr.easy.MarisaB = j_wrs["MoF"]["Easy"]["MarisaB"][0].get<ull>();
	_MoF.wr.easy.MarisaC = j_wrs["MoF"]["Easy"]["MarisaC"][0].get<ull>();
	_MoF.wr.normal.ReimuA = j_wrs["MoF"]["Normal"]["ReimuA"][0].get<ull>();
	_MoF.wr.normal.ReimuB = j_wrs["MoF"]["Normal"]["ReimuB"][0].get<ull>();
	_MoF.wr.normal.ReimuC = j_wrs["MoF"]["Normal"]["ReimuC"][0].get<ull>();
	_MoF.wr.normal.MarisaA = j_wrs["MoF"]["Normal"]["MarisaA"][0].get<ull>();
	_MoF.wr.normal.MarisaB = j_wrs["MoF"]["Normal"]["MarisaB"][0].get<ull>();
	_MoF.wr.normal.MarisaC = j_wrs["MoF"]["Normal"]["MarisaC"][0].get<ull>();
	_MoF.wr.hard.ReimuA = j_wrs["MoF"]["Hard"]["ReimuA"][0].get<ull>();
	_MoF.wr.hard.ReimuB = j_wrs["MoF"]["Hard"]["ReimuB"][0].get<ull>();
	_MoF.wr.hard.ReimuC = j_wrs["MoF"]["Hard"]["ReimuC"][0].get<ull>();
	_MoF.wr.hard.MarisaA = j_wrs["MoF"]["Hard"]["MarisaA"][0].get<ull>();
	_MoF.wr.hard.MarisaB = j_wrs["MoF"]["Hard"]["MarisaB"][0].get<ull>();
	_MoF.wr.hard.MarisaC = j_wrs["MoF"]["Hard"]["MarisaC"][0].get<ull>();
	_MoF.wr.lunatic.ReimuA = j_wrs["MoF"]["Lunatic"]["ReimuA"][0].get<ull>();
	_MoF.wr.lunatic.ReimuB = j_wrs["MoF"]["Lunatic"]["ReimuB"][0].get<ull>();
	_MoF.wr.lunatic.ReimuC = j_wrs["MoF"]["Lunatic"]["ReimuC"][0].get<ull>();
	_MoF.wr.lunatic.MarisaA = j_wrs["MoF"]["Lunatic"]["MarisaA"][0].get<ull>();
	_MoF.wr.lunatic.MarisaB = j_wrs["MoF"]["Lunatic"]["MarisaB"][0].get<ull>();
	_MoF.wr.lunatic.MarisaC = j_wrs["MoF"]["Lunatic"]["MarisaC"][0].get<ull>();
	_MoF.wr.extra.ReimuA = j_wrs["MoF"]["Extra"]["ReimuA"][0].get<ull>();
	_MoF.wr.extra.ReimuB = j_wrs["MoF"]["Extra"]["ReimuB"][0].get<ull>();
	_MoF.wr.extra.ReimuC = j_wrs["MoF"]["Extra"]["ReimuC"][0].get<ull>();
	_MoF.wr.extra.MarisaA = j_wrs["MoF"]["Extra"]["MarisaA"][0].get<ull>();
	_MoF.wr.extra.MarisaB = j_wrs["MoF"]["Extra"]["MarisaB"][0].get<ull>();
	_MoF.wr.extra.MarisaC = j_wrs["MoF"]["Extra"]["MarisaC"][0].get<ull>();

	// SA world record
	_SA.wr.easy.ReimuA = j_wrs["SA"]["Easy"]["ReimuA"][0].get<ull>();
	_SA.wr.easy.ReimuB = j_wrs["SA"]["Easy"]["ReimuB"][0].get<ull>();
	_SA.wr.easy.ReimuC = j_wrs["SA"]["Easy"]["ReimuC"][0].get<ull>();
	_SA.wr.easy.MarisaA = j_wrs["SA"]["Easy"]["MarisaA"][0].get<ull>();
	_SA.wr.easy.MarisaB = j_wrs["SA"]["Easy"]["MarisaB"][0].get<ull>();
	_SA.wr.easy.MarisaC = j_wrs["SA"]["Easy"]["MarisaC"][0].get<ull>();
	_SA.wr.normal.ReimuA = j_wrs["SA"]["Normal"]["ReimuA"][0].get<ull>();
	_SA.wr.normal.ReimuB = j_wrs["SA"]["Normal"]["ReimuB"][0].get<ull>();
	_SA.wr.normal.ReimuC = j_wrs["SA"]["Normal"]["ReimuC"][0].get<ull>();
	_SA.wr.normal.MarisaA = j_wrs["SA"]["Normal"]["MarisaA"][0].get<ull>();
	_SA.wr.normal.MarisaB = j_wrs["SA"]["Normal"]["MarisaB"][0].get<ull>();
	_SA.wr.normal.MarisaC = j_wrs["SA"]["Normal"]["MarisaC"][0].get<ull>();
	_SA.wr.hard.ReimuA = j_wrs["SA"]["Hard"]["ReimuA"][0].get<ull>();
	_SA.wr.hard.ReimuB = j_wrs["SA"]["Hard"]["ReimuB"][0].get<ull>();
	_SA.wr.hard.ReimuC = j_wrs["SA"]["Hard"]["ReimuC"][0].get<ull>();
	_SA.wr.hard.MarisaA = j_wrs["SA"]["Hard"]["MarisaA"][0].get<ull>();
	_SA.wr.hard.MarisaB = j_wrs["SA"]["Hard"]["MarisaB"][0].get<ull>();
	_SA.wr.hard.MarisaC = j_wrs["SA"]["Hard"]["MarisaC"][0].get<ull>();
	_SA.wr.lunatic.ReimuA = j_wrs["SA"]["Lunatic"]["ReimuA"][0].get<ull>();
	_SA.wr.lunatic.ReimuB = j_wrs["SA"]["Lunatic"]["ReimuB"][0].get<ull>();
	_SA.wr.lunatic.ReimuC = j_wrs["SA"]["Lunatic"]["ReimuC"][0].get<ull>();
	_SA.wr.lunatic.MarisaA = j_wrs["SA"]["Lunatic"]["MarisaA"][0].get<ull>();
	_SA.wr.lunatic.MarisaB = j_wrs["SA"]["Lunatic"]["MarisaB"][0].get<ull>();
	_SA.wr.lunatic.MarisaC = j_wrs["SA"]["Lunatic"]["MarisaC"][0].get<ull>();
	_SA.wr.extra.ReimuA = j_wrs["SA"]["Extra"]["ReimuA"][0].get<ull>();
	_SA.wr.extra.ReimuB = j_wrs["SA"]["Extra"]["ReimuB"][0].get<ull>();
	_SA.wr.extra.ReimuC = j_wrs["SA"]["Extra"]["ReimuC"][0].get<ull>();
	_SA.wr.extra.MarisaA = j_wrs["SA"]["Extra"]["MarisaA"][0].get<ull>();
	_SA.wr.extra.MarisaB = j_wrs["SA"]["Extra"]["MarisaB"][0].get<ull>();
	_SA.wr.extra.MarisaC = j_wrs["SA"]["Extra"]["MarisaC"][0].get<ull>();

	// UFO world record
	_UFO.wr.easy.ReimuA = j_wrs["UFO"]["Easy"]["ReimuA"][0].get<ull>();
	_UFO.wr.easy.ReimuB = j_wrs["UFO"]["Easy"]["ReimuB"][0].get<ull>();
	_UFO.wr.easy.MarisaA = j_wrs["UFO"]["Easy"]["MarisaA"][0].get<ull>();
	_UFO.wr.easy.MarisaB = j_wrs["UFO"]["Easy"]["MarisaB"][0].get<ull>();
	_UFO.wr.easy.SanaeA = j_wrs["UFO"]["Easy"]["SanaeA"][0].get<ull>();
	_UFO.wr.easy.SanaeB = j_wrs["UFO"]["Easy"]["SanaeB"][0].get<ull>();
	_UFO.wr.normal.ReimuA = j_wrs["UFO"]["Normal"]["ReimuA"][0].get<ull>();
	_UFO.wr.normal.ReimuB = j_wrs["UFO"]["Normal"]["ReimuB"][0].get<ull>();
	_UFO.wr.normal.MarisaA = j_wrs["UFO"]["Normal"]["MarisaA"][0].get<ull>();
	_UFO.wr.normal.MarisaB = j_wrs["UFO"]["Normal"]["MarisaB"][0].get<ull>();
	_UFO.wr.normal.SanaeA = j_wrs["UFO"]["Normal"]["SanaeA"][0].get<ull>();
	_UFO.wr.normal.SanaeB = j_wrs["UFO"]["Normal"]["SanaeB"][0].get<ull>();
	_UFO.wr.hard.ReimuA = j_wrs["UFO"]["Hard"]["ReimuA"][0].get<ull>();
	_UFO.wr.hard.ReimuB = j_wrs["UFO"]["Hard"]["ReimuB"][0].get<ull>();
	_UFO.wr.hard.MarisaA = j_wrs["UFO"]["Hard"]["MarisaA"][0].get<ull>();
	_UFO.wr.hard.MarisaB = j_wrs["UFO"]["Hard"]["MarisaB"][0].get<ull>();
	_UFO.wr.hard.SanaeA = j_wrs["UFO"]["Hard"]["SanaeA"][0].get<ull>();
	_UFO.wr.hard.SanaeB = j_wrs["UFO"]["Hard"]["SanaeB"][0].get<ull>();
	_UFO.wr.lunatic.ReimuA = j_wrs["UFO"]["Lunatic"]["ReimuA"][0].get<ull>();
	_UFO.wr.lunatic.ReimuB = j_wrs["UFO"]["Lunatic"]["ReimuB"][0].get<ull>();
	_UFO.wr.lunatic.MarisaA = j_wrs["UFO"]["Lunatic"]["MarisaA"][0].get<ull>();
	_UFO.wr.lunatic.MarisaB = j_wrs["UFO"]["Lunatic"]["MarisaB"][0].get<ull>();
	_UFO.wr.lunatic.SanaeA = j_wrs["UFO"]["Lunatic"]["SanaeA"][0].get<ull>();
	_UFO.wr.lunatic.SanaeB = j_wrs["UFO"]["Lunatic"]["SanaeB"][0].get<ull>();
	_UFO.wr.extra.ReimuA = j_wrs["UFO"]["Extra"]["ReimuA"][0].get<ull>();
	_UFO.wr.extra.ReimuB = j_wrs["UFO"]["Extra"]["ReimuB"][0].get<ull>();
	_UFO.wr.extra.MarisaA = j_wrs["UFO"]["Extra"]["MarisaA"][0].get<ull>();
	_UFO.wr.extra.MarisaB = j_wrs["UFO"]["Extra"]["MarisaB"][0].get<ull>();
	_UFO.wr.extra.SanaeA = j_wrs["UFO"]["Extra"]["SanaeA"][0].get<ull>();
	_UFO.wr.extra.SanaeB = j_wrs["UFO"]["Extra"]["SanaeB"][0].get<ull>();

	// TD world record
	_TD.wr.easy.Reimu = j_wrs["TD"]["Easy"]["Reimu"][0].get<ull>();
	_TD.wr.easy.Marisa = j_wrs["TD"]["Easy"]["Marisa"][0].get<ull>();
	_TD.wr.easy.Sanae = j_wrs["TD"]["Easy"]["Sanae"][0].get<ull>();
	_TD.wr.easy.Youmu = j_wrs["TD"]["Easy"]["Youmu"][0].get<ull>();
	_TD.wr.normal.Reimu = j_wrs["TD"]["Normal"]["Reimu"][0].get<ull>();
	_TD.wr.normal.Marisa = j_wrs["TD"]["Normal"]["Marisa"][0].get<ull>();
	_TD.wr.normal.Sanae = j_wrs["TD"]["Normal"]["Sanae"][0].get<ull>();
	_TD.wr.normal.Youmu = j_wrs["TD"]["Normal"]["Youmu"][0].get<ull>();
	_TD.wr.hard.Reimu = j_wrs["TD"]["Hard"]["Reimu"][0].get<ull>();
	_TD.wr.hard.Marisa = j_wrs["TD"]["Hard"]["Marisa"][0].get<ull>();
	_TD.wr.hard.Sanae = j_wrs["TD"]["Hard"]["Sanae"][0].get<ull>();
	_TD.wr.hard.Youmu = j_wrs["TD"]["Hard"]["Youmu"][0].get<ull>();
	_TD.wr.lunatic.Reimu = j_wrs["TD"]["Lunatic"]["Reimu"][0].get<ull>();
	_TD.wr.lunatic.Marisa = j_wrs["TD"]["Lunatic"]["Marisa"][0].get<ull>();
	_TD.wr.lunatic.Sanae = j_wrs["TD"]["Lunatic"]["Sanae"][0].get<ull>();
	_TD.wr.lunatic.Youmu = j_wrs["TD"]["Lunatic"]["Youmu"][0].get<ull>();
	_TD.wr.extra.Reimu = j_wrs["TD"]["Extra"]["Reimu"][0].get<ull>();
	_TD.wr.extra.Marisa = j_wrs["TD"]["Extra"]["Marisa"][0].get<ull>();
	_TD.wr.extra.Sanae = j_wrs["TD"]["Extra"]["Sanae"][0].get<ull>();
	_TD.wr.extra.Youmu = j_wrs["TD"]["Extra"]["Youmu"][0].get<ull>();

	// DDC world record
	_DDC.wr.easy.ReimuA = j_wrs["DDC"]["Easy"]["ReimuA"][0].get<ull>();
	_DDC.wr.easy.ReimuB = j_wrs["DDC"]["Easy"]["ReimuB"][0].get<ull>();
	_DDC.wr.easy.MarisaA = j_wrs["DDC"]["Easy"]["MarisaA"][0].get<ull>();
	_DDC.wr.easy.MarisaB = j_wrs["DDC"]["Easy"]["MarisaB"][0].get<ull>();
	_DDC.wr.easy.SakuyaA = j_wrs["DDC"]["Easy"]["SakuyaA"][0].get<ull>();
	_DDC.wr.easy.SakuyaB = j_wrs["DDC"]["Easy"]["SakuyaB"][0].get<ull>();
	_DDC.wr.normal.ReimuA = j_wrs["DDC"]["Normal"]["ReimuA"][0].get<ull>();
	_DDC.wr.normal.ReimuB = j_wrs["DDC"]["Normal"]["ReimuB"][0].get<ull>();
	_DDC.wr.normal.MarisaA = j_wrs["DDC"]["Normal"]["MarisaA"][0].get<ull>();
	_DDC.wr.normal.MarisaB = j_wrs["DDC"]["Normal"]["MarisaB"][0].get<ull>();
	_DDC.wr.normal.SakuyaA = j_wrs["DDC"]["Normal"]["SakuyaA"][0].get<ull>();
	_DDC.wr.normal.SakuyaB = j_wrs["DDC"]["Normal"]["SakuyaB"][0].get<ull>();
	_DDC.wr.hard.ReimuA = j_wrs["DDC"]["Hard"]["ReimuA"][0].get<ull>();
	_DDC.wr.hard.ReimuB = j_wrs["DDC"]["Hard"]["ReimuB"][0].get<ull>();
	_DDC.wr.hard.MarisaA = j_wrs["DDC"]["Hard"]["MarisaA"][0].get<ull>();
	_DDC.wr.hard.MarisaB = j_wrs["DDC"]["Hard"]["MarisaB"][0].get<ull>();
	_DDC.wr.hard.SakuyaA = j_wrs["DDC"]["Hard"]["SakuyaA"][0].get<ull>();
	_DDC.wr.hard.SakuyaB = j_wrs["DDC"]["Hard"]["SakuyaB"][0].get<ull>();
	_DDC.wr.lunatic.ReimuA = j_wrs["DDC"]["Lunatic"]["ReimuA"][0].get<ull>();
	_DDC.wr.lunatic.ReimuB = j_wrs["DDC"]["Lunatic"]["ReimuB"][0].get<ull>();
	_DDC.wr.lunatic.MarisaA = j_wrs["DDC"]["Lunatic"]["MarisaA"][0].get<ull>();
	_DDC.wr.lunatic.MarisaB = j_wrs["DDC"]["Lunatic"]["MarisaB"][0].get<ull>();
	_DDC.wr.lunatic.SakuyaA = j_wrs["DDC"]["Lunatic"]["SakuyaA"][0].get<ull>();
	_DDC.wr.lunatic.SakuyaB = j_wrs["DDC"]["Lunatic"]["SakuyaB"][0].get<ull>();
	_DDC.wr.extra.ReimuA = j_wrs["DDC"]["Extra"]["ReimuA"][0].get<ull>();
	_DDC.wr.extra.ReimuB = j_wrs["DDC"]["Extra"]["ReimuB"][0].get<ull>();
	_DDC.wr.extra.MarisaA = j_wrs["DDC"]["Extra"]["MarisaA"][0].get<ull>();
	_DDC.wr.extra.MarisaB = j_wrs["DDC"]["Extra"]["MarisaB"][0].get<ull>();
	_DDC.wr.extra.SakuyaA = j_wrs["DDC"]["Extra"]["SakuyaA"][0].get<ull>();
	_DDC.wr.extra.SakuyaB = j_wrs["DDC"]["Extra"]["SakuyaB"][0].get<ull>();

	// LoLK world record
	_LoLK.wr.easy.Reimu = j_wrs["LoLK"]["Easy"]["Reimu"][0].get<ull>();
	_LoLK.wr.easy.Marisa = j_wrs["LoLK"]["Easy"]["Marisa"][0].get<ull>();
	_LoLK.wr.easy.Sanae = j_wrs["LoLK"]["Easy"]["Sanae"][0].get<ull>();
	_LoLK.wr.easy.Reisen = j_wrs["LoLK"]["Easy"]["Reisen"][0].get<ull>();
	_LoLK.wr.normal.Reimu = j_wrs["LoLK"]["Normal"]["Reimu"][0].get<ull>();
	_LoLK.wr.normal.Marisa = j_wrs["LoLK"]["Normal"]["Marisa"][0].get<ull>();
	_LoLK.wr.normal.Sanae = j_wrs["LoLK"]["Normal"]["Sanae"][0].get<ull>();
	_LoLK.wr.normal.Reisen = j_wrs["LoLK"]["Normal"]["Reisen"][0].get<ull>();
	_LoLK.wr.hard.Reimu = j_wrs["LoLK"]["Hard"]["Reimu"][0].get<ull>();
	_LoLK.wr.hard.Marisa = j_wrs["LoLK"]["Hard"]["Marisa"][0].get<ull>();
	_LoLK.wr.hard.Sanae = j_wrs["LoLK"]["Hard"]["Sanae"][0].get<ull>();
	_LoLK.wr.hard.Reisen = j_wrs["LoLK"]["Hard"]["Reisen"][0].get<ull>();
	_LoLK.wr.lunatic.Reimu = j_wrs["LoLK"]["Lunatic"]["Reimu"][0].get<ull>();
	_LoLK.wr.lunatic.Marisa = j_wrs["LoLK"]["Lunatic"]["Marisa"][0].get<ull>();
	_LoLK.wr.lunatic.Sanae = j_wrs["LoLK"]["Lunatic"]["Sanae"][0].get<ull>();
	_LoLK.wr.lunatic.Reisen = j_wrs["LoLK"]["Lunatic"]["Reisen"][0].get<ull>();
	_LoLK.wr.extra.Reimu = j_wrs["LoLK"]["Extra"]["Reimu"][0].get<ull>();
	_LoLK.wr.extra.Marisa = j_wrs["LoLK"]["Extra"]["Marisa"][0].get<ull>();
	_LoLK.wr.extra.Sanae = j_wrs["LoLK"]["Extra"]["Sanae"][0].get<ull>();
	_LoLK.wr.extra.Reisen = j_wrs["LoLK"]["Extra"]["Reisen"][0].get<ull>();

	// HSiFS world record
	_HSiFS.wr.easy.Reimu.Spring = j_wrs["HSiFS"]["Easy"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Summer = j_wrs["HSiFS"]["Easy"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Autumn = j_wrs["HSiFS"]["Easy"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Winter = j_wrs["HSiFS"]["Easy"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Spring = j_wrs["HSiFS"]["Easy"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Summer = j_wrs["HSiFS"]["Easy"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Autumn = j_wrs["HSiFS"]["Easy"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Winter = j_wrs["HSiFS"]["Easy"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Spring = j_wrs["HSiFS"]["Easy"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Summer = j_wrs["HSiFS"]["Easy"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Autumn = j_wrs["HSiFS"]["Easy"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Winter = j_wrs["HSiFS"]["Easy"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Spring = j_wrs["HSiFS"]["Easy"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Summer = j_wrs["HSiFS"]["Easy"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Autumn = j_wrs["HSiFS"]["Easy"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Winter = j_wrs["HSiFS"]["Easy"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Spring = j_wrs["HSiFS"]["Normal"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Summer = j_wrs["HSiFS"]["Normal"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Autumn = j_wrs["HSiFS"]["Normal"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Winter = j_wrs["HSiFS"]["Normal"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Spring = j_wrs["HSiFS"]["Normal"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Summer = j_wrs["HSiFS"]["Normal"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Autumn = j_wrs["HSiFS"]["Normal"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Winter = j_wrs["HSiFS"]["Normal"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Spring = j_wrs["HSiFS"]["Normal"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Summer = j_wrs["HSiFS"]["Normal"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Autumn = j_wrs["HSiFS"]["Normal"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Winter = j_wrs["HSiFS"]["Normal"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Spring = j_wrs["HSiFS"]["Normal"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Summer = j_wrs["HSiFS"]["Normal"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Autumn = j_wrs["HSiFS"]["Normal"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Winter = j_wrs["HSiFS"]["Normal"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Spring = j_wrs["HSiFS"]["Hard"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Summer = j_wrs["HSiFS"]["Hard"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Autumn = j_wrs["HSiFS"]["Hard"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Winter = j_wrs["HSiFS"]["Hard"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Spring = j_wrs["HSiFS"]["Hard"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Summer = j_wrs["HSiFS"]["Hard"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Autumn = j_wrs["HSiFS"]["Hard"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Winter = j_wrs["HSiFS"]["Hard"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Spring = j_wrs["HSiFS"]["Hard"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Summer = j_wrs["HSiFS"]["Hard"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Autumn = j_wrs["HSiFS"]["Hard"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Winter = j_wrs["HSiFS"]["Hard"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Spring = j_wrs["HSiFS"]["Hard"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Summer = j_wrs["HSiFS"]["Hard"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Autumn = j_wrs["HSiFS"]["Hard"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Winter = j_wrs["HSiFS"]["Hard"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Spring = j_wrs["HSiFS"]["Lunatic"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Summer = j_wrs["HSiFS"]["Lunatic"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Autumn = j_wrs["HSiFS"]["Lunatic"]["ReimuAutumn"][0].get<ull>();
	// no iead why Maribel didn't include Reimu Spring world record
	//_HSiFS.wr.lunatic.Reimu.Winter = j_wrs["HSiFS"]["Lunatic"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Spring = j_wrs["HSiFS"]["Lunatic"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Summer = j_wrs["HSiFS"]["Lunatic"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Autumn = j_wrs["HSiFS"]["Lunatic"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Winter = j_wrs["HSiFS"]["Lunatic"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Spring = j_wrs["HSiFS"]["Lunatic"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Summer = j_wrs["HSiFS"]["Lunatic"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Autumn = j_wrs["HSiFS"]["Lunatic"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Winter = j_wrs["HSiFS"]["Lunatic"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Spring = j_wrs["HSiFS"]["Lunatic"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Summer = j_wrs["HSiFS"]["Lunatic"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Autumn = j_wrs["HSiFS"]["Lunatic"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Winter = j_wrs["HSiFS"]["Lunatic"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.extra.Reimu = j_wrs["HSiFS"]["Extra"]["Reimu"][0].get<ull>();
	_HSiFS.wr.extra.Cirno = j_wrs["HSiFS"]["Extra"]["Cirno"][0].get<ull>();
	_HSiFS.wr.extra.Aya = j_wrs["HSiFS"]["Extra"]["Aya"][0].get<ull>();
	_HSiFS.wr.extra.Marisa = j_wrs["HSiFS"]["Extra"]["Marisa"][0].get<ull>();

	std::cout << "Successfully loaded world record file." << std::endl;
	return true;
}
