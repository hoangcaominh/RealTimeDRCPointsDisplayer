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
	_HRtP.wr.easy.Jigoku = j["HRtP"]["Easy"]["Jigoku"][0].get<ull>();
	_HRtP.wr.easy.Makai = j["HRtP"]["Easy"]["Makai"][0].get<ull>();
	_HRtP.wr.normal.Jigoku = j["HRtP"]["Normal"]["Jigoku"][0].get<ull>();
	_HRtP.wr.normal.Makai = j["HRtP"]["Normal"]["Makai"][0].get<ull>();
	_HRtP.wr.hard.Jigoku = j["HRtP"]["Hard"]["Jigoku"][0].get<ull>();
	_HRtP.wr.hard.Makai = j["HRtP"]["Hard"]["Makai"][0].get<ull>();
	_HRtP.wr.lunatic.Jigoku = j["HRtP"]["Lunatic"]["Jigoku"][0].get<ull>();
	_HRtP.wr.lunatic.Makai = j["HRtP"]["Lunatic"]["Makai"][0].get<ull>();

	// SoEW world records
	_SoEW.wr.easy.ReimuA = j["SoEW"]["Easy"]["ReimuA"][0].get<ull>();
	_SoEW.wr.easy.ReimuB = j["SoEW"]["Easy"]["ReimuB"][0].get<ull>();
	_SoEW.wr.easy.ReimuC = j["SoEW"]["Easy"]["ReimuC"][0].get<ull>();
	_SoEW.wr.normal.ReimuA = j["SoEW"]["Normal"]["ReimuA"][0].get<ull>();
	_SoEW.wr.normal.ReimuB = j["SoEW"]["Normal"]["ReimuB"][0].get<ull>();
	_SoEW.wr.normal.ReimuC = j["SoEW"]["Normal"]["ReimuC"][0].get<ull>();
	_SoEW.wr.hard.ReimuA = j["SoEW"]["Hard"]["ReimuA"][0].get<ull>();
	_SoEW.wr.hard.ReimuB = j["SoEW"]["Hard"]["ReimuB"][0].get<ull>();
	_SoEW.wr.hard.ReimuC = j["SoEW"]["Hard"]["ReimuC"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuA = j["SoEW"]["Lunatic"]["ReimuA"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuB = j["SoEW"]["Lunatic"]["ReimuB"][0].get<ull>();
	_SoEW.wr.lunatic.ReimuC = j["SoEW"]["Lunatic"]["ReimuC"][0].get<ull>();
	_SoEW.wr.extra.ReimuA = j["SoEW"]["Extra"]["ReimuA"][0].get<ull>();
	_SoEW.wr.extra.ReimuB = j["SoEW"]["Extra"]["ReimuB"][0].get<ull>();
	_SoEW.wr.extra.ReimuC = j["SoEW"]["Extra"]["ReimuC"][0].get<ull>();

	// PoDD world records
	_PoDD.wr.easy.Reimu = j["PoDD"]["Easy"]["Reimu"][0].get<ull>();
	_PoDD.wr.easy.Mima = j["PoDD"]["Easy"]["Mima"][0].get<ull>();
	_PoDD.wr.easy.Marisa = j["PoDD"]["Easy"]["Marisa"][0].get<ull>();
	_PoDD.wr.easy.Ellen = j["PoDD"]["Easy"]["Ellen"][0].get<ull>();
	_PoDD.wr.easy.Kotohime = j["PoDD"]["Easy"]["Kotohime"][0].get<ull>();
	_PoDD.wr.easy.Kana = j["PoDD"]["Easy"]["Kana"][0].get<ull>();
	_PoDD.wr.easy.Rikako = j["PoDD"]["Easy"]["Rikako"][0].get<ull>();
	_PoDD.wr.easy.Chiyuri = j["PoDD"]["Easy"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.easy.Yumemi = j["PoDD"]["Easy"]["Yumemi"][0].get<ull>();
	_PoDD.wr.normal.Reimu = j["PoDD"]["Normal"]["Reimu"][0].get<ull>();
	_PoDD.wr.normal.Mima = j["PoDD"]["Normal"]["Mima"][0].get<ull>();
	_PoDD.wr.normal.Marisa = j["PoDD"]["Normal"]["Marisa"][0].get<ull>();
	_PoDD.wr.normal.Ellen = j["PoDD"]["Normal"]["Ellen"][0].get<ull>();
	_PoDD.wr.normal.Kotohime = j["PoDD"]["Normal"]["Kotohime"][0].get<ull>();
	_PoDD.wr.normal.Kana = j["PoDD"]["Normal"]["Kana"][0].get<ull>();
	_PoDD.wr.normal.Rikako = j["PoDD"]["Normal"]["Rikako"][0].get<ull>();
	_PoDD.wr.normal.Chiyuri = j["PoDD"]["Normal"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.normal.Yumemi = j["PoDD"]["Normal"]["Yumemi"][0].get<ull>();
	_PoDD.wr.hard.Reimu = j["PoDD"]["Hard"]["Reimu"][0].get<ull>();
	_PoDD.wr.hard.Mima = j["PoDD"]["Hard"]["Mima"][0].get<ull>();
	_PoDD.wr.hard.Marisa = j["PoDD"]["Hard"]["Marisa"][0].get<ull>();
	_PoDD.wr.hard.Ellen = j["PoDD"]["Hard"]["Ellen"][0].get<ull>();
	_PoDD.wr.hard.Kotohime = j["PoDD"]["Hard"]["Kotohime"][0].get<ull>();
	_PoDD.wr.hard.Kana = j["PoDD"]["Hard"]["Kana"][0].get<ull>();
	_PoDD.wr.hard.Rikako = j["PoDD"]["Hard"]["Rikako"][0].get<ull>();
	_PoDD.wr.hard.Chiyuri = j["PoDD"]["Hard"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.hard.Yumemi = j["PoDD"]["Hard"]["Yumemi"][0].get<ull>();
	_PoDD.wr.lunatic.Reimu = j["PoDD"]["Lunatic"]["Reimu"][0].get<ull>();
	_PoDD.wr.lunatic.Mima = j["PoDD"]["Lunatic"]["Mima"][0].get<ull>();
	_PoDD.wr.lunatic.Marisa = j["PoDD"]["Lunatic"]["Marisa"][0].get<ull>();
	_PoDD.wr.lunatic.Ellen = j["PoDD"]["Lunatic"]["Ellen"][0].get<ull>();
	_PoDD.wr.lunatic.Kotohime = j["PoDD"]["Lunatic"]["Kotohime"][0].get<ull>();
	_PoDD.wr.lunatic.Kana = j["PoDD"]["Lunatic"]["Kana"][0].get<ull>();
	_PoDD.wr.lunatic.Rikako = j["PoDD"]["Lunatic"]["Rikako"][0].get<ull>();
	_PoDD.wr.lunatic.Chiyuri = j["PoDD"]["Lunatic"]["Chiyuri"][0].get<ull>();
	_PoDD.wr.lunatic.Yumemi = j["PoDD"]["Lunatic"]["Yumemi"][0].get<ull>();

	// LLS world records
	_LLS.wr.easy.ReimuA = j["LLS"]["Easy"]["ReimuA"][0].get<ull>();
	_LLS.wr.easy.ReimuB = j["LLS"]["Easy"]["ReimuB"][0].get<ull>();
	_LLS.wr.easy.MarisaA = j["LLS"]["Easy"]["MarisaA"][0].get<ull>();
	_LLS.wr.easy.MarisaB = j["LLS"]["Easy"]["MarisaB"][0].get<ull>();
	_LLS.wr.normal.ReimuA = j["LLS"]["Normal"]["ReimuA"][0].get<ull>();
	_LLS.wr.normal.ReimuB = j["LLS"]["Normal"]["ReimuB"][0].get<ull>();
	_LLS.wr.normal.MarisaA = j["LLS"]["Normal"]["MarisaA"][0].get<ull>();
	_LLS.wr.normal.MarisaB = j["LLS"]["Normal"]["MarisaB"][0].get<ull>();
	_LLS.wr.hard.ReimuA = j["LLS"]["Hard"]["ReimuA"][0].get<ull>();
	_LLS.wr.hard.ReimuB = j["LLS"]["Hard"]["ReimuB"][0].get<ull>();
	_LLS.wr.hard.MarisaA = j["LLS"]["Hard"]["MarisaA"][0].get<ull>();
	_LLS.wr.hard.MarisaB = j["LLS"]["Hard"]["MarisaB"][0].get<ull>();
	_LLS.wr.lunatic.ReimuA = j["LLS"]["Lunatic"]["ReimuA"][0].get<ull>();
	_LLS.wr.lunatic.ReimuB = j["LLS"]["Lunatic"]["ReimuB"][0].get<ull>();
	_LLS.wr.lunatic.MarisaA = j["LLS"]["Lunatic"]["MarisaA"][0].get<ull>();
	_LLS.wr.lunatic.MarisaB = j["LLS"]["Lunatic"]["MarisaB"][0].get<ull>();
	_LLS.wr.extra.ReimuA = j["LLS"]["Extra"]["ReimuA"][0].get<ull>();
	_LLS.wr.extra.ReimuB = j["LLS"]["Extra"]["ReimuB"][0].get<ull>();
	_LLS.wr.extra.MarisaA = j["LLS"]["Extra"]["MarisaA"][0].get<ull>();
	_LLS.wr.extra.MarisaB = j["LLS"]["Extra"]["MarisaB"][0].get<ull>();

	// MS world record
	_MS.wr.easy.Reimu = j["MS"]["Easy"]["Reimu"][0].get<ull>();
	_MS.wr.easy.Marisa = j["MS"]["Easy"]["Marisa"][0].get<ull>();
	_MS.wr.easy.Mima = j["MS"]["Easy"]["Mima"][0].get<ull>();
	_MS.wr.easy.Yuuka = j["MS"]["Easy"]["Yuuka"][0].get<ull>();
	_MS.wr.normal.Reimu = j["MS"]["Normal"]["Reimu"][0].get<ull>();
	_MS.wr.normal.Marisa = j["MS"]["Normal"]["Marisa"][0].get<ull>();
	_MS.wr.normal.Mima = j["MS"]["Normal"]["Mima"][0].get<ull>();
	_MS.wr.normal.Yuuka = j["MS"]["Normal"]["Yuuka"][0].get<ull>();
	_MS.wr.hard.Reimu = j["MS"]["Hard"]["Reimu"][0].get<ull>();
	_MS.wr.hard.Marisa = j["MS"]["Hard"]["Marisa"][0].get<ull>();
	_MS.wr.hard.Mima = j["MS"]["Hard"]["Mima"][0].get<ull>();
	_MS.wr.hard.Yuuka = j["MS"]["Hard"]["Yuuka"][0].get<ull>();
	_MS.wr.lunatic.Reimu = j["MS"]["Lunatic"]["Reimu"][0].get<ull>();
	_MS.wr.lunatic.Marisa = j["MS"]["Lunatic"]["Marisa"][0].get<ull>();
	_MS.wr.lunatic.Mima = j["MS"]["Lunatic"]["Mima"][0].get<ull>();
	_MS.wr.lunatic.Yuuka = j["MS"]["Lunatic"]["Yuuka"][0].get<ull>();
	_MS.wr.extra.Reimu = j["MS"]["Extra"]["Reimu"][0].get<ull>();
	_MS.wr.extra.Marisa = j["MS"]["Extra"]["Marisa"][0].get<ull>();
	_MS.wr.extra.Mima = j["MS"]["Extra"]["Mima"][0].get<ull>();
	_MS.wr.extra.Yuuka = j["MS"]["Extra"]["Yuuka"][0].get<ull>();

	// EoSD world record
	_EoSD.wr.easy.ReimuA = j["EoSD"]["Easy"]["ReimuA"][0].get<int>();
	_EoSD.wr.easy.ReimuB = j["EoSD"]["Easy"]["ReimuB"][0].get<int>();
	_EoSD.wr.easy.MarisaA = j["EoSD"]["Easy"]["MarisaA"][0].get<int>();
	_EoSD.wr.easy.MarisaB = j["EoSD"]["Easy"]["MarisaB"][0].get<int>();
	_EoSD.wr.normal.ReimuA = j["EoSD"]["Normal"]["ReimuA"][0].get<int>();
	_EoSD.wr.normal.ReimuB = j["EoSD"]["Normal"]["ReimuB"][0].get<int>();
	_EoSD.wr.normal.MarisaA = j["EoSD"]["Normal"]["MarisaA"][0].get<int>();
	_EoSD.wr.normal.MarisaB = j["EoSD"]["Normal"]["MarisaB"][0].get<int>();
	_EoSD.wr.hard.ReimuA = j["EoSD"]["Hard"]["ReimuA"][0].get<int>();
	_EoSD.wr.hard.ReimuB = j["EoSD"]["Hard"]["ReimuB"][0].get<int>();
	_EoSD.wr.hard.MarisaA = j["EoSD"]["Hard"]["MarisaA"][0].get<int>();
	_EoSD.wr.hard.MarisaB = j["EoSD"]["Hard"]["MarisaB"][0].get<int>();
	_EoSD.wr.lunatic.ReimuA = j["EoSD"]["Lunatic"]["ReimuA"][0].get<int>();
	_EoSD.wr.lunatic.ReimuB = j["EoSD"]["Lunatic"]["ReimuB"][0].get<int>();
	_EoSD.wr.lunatic.MarisaA = j["EoSD"]["Lunatic"]["MarisaA"][0].get<int>();
	_EoSD.wr.lunatic.MarisaB = j["EoSD"]["Lunatic"]["MarisaB"][0].get<int>();
	_EoSD.wr.extra.ReimuA = j["EoSD"]["Extra"]["ReimuA"][0].get<int>();
	_EoSD.wr.extra.ReimuB = j["EoSD"]["Extra"]["ReimuB"][0].get<int>();
	_EoSD.wr.extra.MarisaA = j["EoSD"]["Extra"]["MarisaA"][0].get<int>();
	_EoSD.wr.extra.MarisaB = j["EoSD"]["Extra"]["MarisaB"][0].get<int>();

	// PCB world record
	_PCB.wr.easy.ReimuA = j["PCB"]["Easy"]["ReimuA"][0].get<ull>();
	_PCB.wr.easy.ReimuB = j["PCB"]["Easy"]["ReimuB"][0].get<ull>();
	_PCB.wr.easy.MarisaA = j["PCB"]["Easy"]["MarisaA"][0].get<ull>();
	_PCB.wr.easy.MarisaB = j["PCB"]["Easy"]["MarisaB"][0].get<ull>();
	_PCB.wr.easy.SakuyaA = j["PCB"]["Easy"]["SakuyaA"][0].get<ull>();
	_PCB.wr.easy.SakuyaB = j["PCB"]["Easy"]["SakuyaB"][0].get<ull>();
	_PCB.wr.normal.ReimuA = j["PCB"]["Normal"]["ReimuA"][0].get<ull>();
	_PCB.wr.normal.ReimuB = j["PCB"]["Normal"]["ReimuB"][0].get<ull>();
	_PCB.wr.normal.MarisaA = j["PCB"]["Normal"]["MarisaA"][0].get<ull>();
	_PCB.wr.normal.MarisaB = j["PCB"]["Normal"]["MarisaB"][0].get<ull>();
	_PCB.wr.normal.SakuyaA = j["PCB"]["Normal"]["SakuyaA"][0].get<ull>();
	_PCB.wr.normal.SakuyaB = j["PCB"]["Normal"]["SakuyaB"][0].get<ull>();
	_PCB.wr.hard.ReimuA = j["PCB"]["Hard"]["ReimuA"][0].get<ull>();
	_PCB.wr.hard.ReimuB = j["PCB"]["Hard"]["ReimuB"][0].get<ull>();
	_PCB.wr.hard.MarisaA = j["PCB"]["Hard"]["MarisaA"][0].get<ull>();
	_PCB.wr.hard.MarisaB = j["PCB"]["Hard"]["MarisaB"][0].get<ull>();
	_PCB.wr.hard.SakuyaA = j["PCB"]["Hard"]["SakuyaA"][0].get<ull>();
	_PCB.wr.hard.SakuyaB = j["PCB"]["Hard"]["SakuyaB"][0].get<ull>();
	_PCB.wr.lunatic.ReimuA = j["PCB"]["Lunatic"]["ReimuA"][0].get<ull>();
	_PCB.wr.lunatic.ReimuB = j["PCB"]["Lunatic"]["ReimuB"][0].get<ull>();
	_PCB.wr.lunatic.MarisaA = j["PCB"]["Lunatic"]["MarisaA"][0].get<ull>();
	_PCB.wr.lunatic.MarisaB = j["PCB"]["Lunatic"]["MarisaB"][0].get<ull>();
	_PCB.wr.lunatic.SakuyaA = j["PCB"]["Lunatic"]["SakuyaA"][0].get<ull>();
	_PCB.wr.lunatic.SakuyaB = j["PCB"]["Lunatic"]["SakuyaB"][0].get<ull>();
	_PCB.wr.extra.ReimuA = j["PCB"]["Extra"]["ReimuA"][0].get<ull>();
	_PCB.wr.extra.ReimuB = j["PCB"]["Extra"]["ReimuB"][0].get<ull>();
	_PCB.wr.extra.MarisaA = j["PCB"]["Extra"]["MarisaA"][0].get<ull>();
	_PCB.wr.extra.MarisaB = j["PCB"]["Extra"]["MarisaB"][0].get<ull>();
	_PCB.wr.extra.SakuyaA = j["PCB"]["Extra"]["SakuyaA"][0].get<ull>();
	_PCB.wr.extra.SakuyaB = j["PCB"]["Extra"]["SakuyaB"][0].get<ull>();
	_PCB.wr.phantasm.ReimuA = j["PCB"]["Phantasm"]["ReimuA"][0].get<ull>();
	_PCB.wr.phantasm.ReimuB = j["PCB"]["Phantasm"]["ReimuB"][0].get<ull>();
	_PCB.wr.phantasm.MarisaA = j["PCB"]["Phantasm"]["MarisaA"][0].get<ull>();
	_PCB.wr.phantasm.MarisaB = j["PCB"]["Phantasm"]["MarisaB"][0].get<ull>();
	_PCB.wr.phantasm.SakuyaA = j["PCB"]["Phantasm"]["SakuyaA"][0].get<ull>();
	_PCB.wr.phantasm.SakuyaB = j["PCB"]["Phantasm"]["SakuyaB"][0].get<ull>();

	// IN world record
	_IN.wr.easy.BorderTeam = j["IN"]["Easy"]["BorderTeam"][0].get<ull>();
	_IN.wr.easy.MagicTeam = j["IN"]["Easy"]["MagicTeam"][0].get<ull>();
	_IN.wr.easy.ScarletTeam = j["IN"]["Easy"]["ScarletTeam"][0].get<ull>();
	_IN.wr.easy.GhostTeam = j["IN"]["Easy"]["GhostTeam"][0].get<ull>();
	_IN.wr.easy.Reimu = j["IN"]["Easy"]["Reimu"][0].get<ull>();
	_IN.wr.easy.Yukari = j["IN"]["Easy"]["Yukari"][0].get<ull>();
	_IN.wr.easy.Marisa = j["IN"]["Easy"]["Marisa"][0].get<ull>();
	_IN.wr.easy.Alice = j["IN"]["Easy"]["Alice"][0].get<ull>();
	_IN.wr.easy.Sakuya = j["IN"]["Easy"]["Sakuya"][0].get<ull>();
	_IN.wr.easy.Remilia = j["IN"]["Easy"]["Remilia"][0].get<ull>();
	_IN.wr.easy.Youmu = j["IN"]["Easy"]["Youmu"][0].get<ull>();
	_IN.wr.easy.Yuyuko = j["IN"]["Easy"]["Yuyuko"][0].get<ull>();
	_IN.wr.normal.BorderTeam = j["IN"]["Normal"]["BorderTeam"][0].get<ull>();
	_IN.wr.normal.MagicTeam = j["IN"]["Normal"]["MagicTeam"][0].get<ull>();
	_IN.wr.normal.ScarletTeam = j["IN"]["Normal"]["ScarletTeam"][0].get<ull>();
	_IN.wr.normal.GhostTeam = j["IN"]["Normal"]["GhostTeam"][0].get<ull>();
	_IN.wr.normal.Reimu = j["IN"]["Normal"]["Reimu"][0].get<ull>();
	_IN.wr.normal.Yukari = j["IN"]["Normal"]["Yukari"][0].get<ull>();
	_IN.wr.normal.Marisa = j["IN"]["Normal"]["Marisa"][0].get<ull>();
	_IN.wr.normal.Alice = j["IN"]["Normal"]["Alice"][0].get<ull>();
	_IN.wr.normal.Sakuya = j["IN"]["Normal"]["Sakuya"][0].get<ull>();
	_IN.wr.normal.Remilia = j["IN"]["Normal"]["Remilia"][0].get<ull>();
	_IN.wr.normal.Youmu = j["IN"]["Normal"]["Youmu"][0].get<ull>();
	_IN.wr.normal.Yuyuko = j["IN"]["Normal"]["Yuyuko"][0].get<ull>();
	_IN.wr.hard.BorderTeam = j["IN"]["Hard"]["BorderTeam"][0].get<ull>();
	_IN.wr.hard.MagicTeam = j["IN"]["Hard"]["MagicTeam"][0].get<ull>();
	_IN.wr.hard.ScarletTeam = j["IN"]["Hard"]["ScarletTeam"][0].get<ull>();
	_IN.wr.hard.GhostTeam = j["IN"]["Hard"]["GhostTeam"][0].get<ull>();
	_IN.wr.hard.Reimu = j["IN"]["Hard"]["Reimu"][0].get<ull>();
	_IN.wr.hard.Yukari = j["IN"]["Hard"]["Yukari"][0].get<ull>();
	_IN.wr.hard.Marisa = j["IN"]["Hard"]["Marisa"][0].get<ull>();
	_IN.wr.hard.Alice = j["IN"]["Hard"]["Alice"][0].get<ull>();
	_IN.wr.hard.Sakuya = j["IN"]["Hard"]["Sakuya"][0].get<ull>();
	_IN.wr.hard.Remilia = j["IN"]["Hard"]["Remilia"][0].get<ull>();
	_IN.wr.hard.Youmu = j["IN"]["Hard"]["Youmu"][0].get<ull>();
	_IN.wr.hard.Yuyuko = j["IN"]["Hard"]["Yuyuko"][0].get<ull>();
	_IN.wr.lunatic.BorderTeam = j["IN"]["Lunatic"]["BorderTeam"][0].get<ull>();
	_IN.wr.lunatic.MagicTeam = j["IN"]["Lunatic"]["MagicTeam"][0].get<ull>();
	_IN.wr.lunatic.ScarletTeam = j["IN"]["Lunatic"]["ScarletTeam"][0].get<ull>();
	_IN.wr.lunatic.GhostTeam = j["IN"]["Lunatic"]["GhostTeam"][0].get<ull>();
	_IN.wr.lunatic.Reimu = j["IN"]["Lunatic"]["Reimu"][0].get<ull>();
	_IN.wr.lunatic.Yukari = j["IN"]["Lunatic"]["Yukari"][0].get<ull>();
	_IN.wr.lunatic.Marisa = j["IN"]["Lunatic"]["Marisa"][0].get<ull>();
	_IN.wr.lunatic.Alice = j["IN"]["Lunatic"]["Alice"][0].get<ull>();
	_IN.wr.lunatic.Sakuya = j["IN"]["Lunatic"]["Sakuya"][0].get<ull>();
	_IN.wr.lunatic.Remilia = j["IN"]["Lunatic"]["Remilia"][0].get<ull>();
	_IN.wr.lunatic.Youmu = j["IN"]["Lunatic"]["Youmu"][0].get<ull>();
	_IN.wr.lunatic.Yuyuko = j["IN"]["Lunatic"]["Yuyuko"][0].get<ull>();
	_IN.wr.extra.BorderTeam = j["IN"]["Extra"]["BorderTeam"][0].get<ull>();
	_IN.wr.extra.MagicTeam = j["IN"]["Extra"]["MagicTeam"][0].get<ull>();
	_IN.wr.extra.ScarletTeam = j["IN"]["Extra"]["ScarletTeam"][0].get<ull>();
	_IN.wr.extra.GhostTeam = j["IN"]["Extra"]["GhostTeam"][0].get<ull>();
	_IN.wr.extra.Reimu = j["IN"]["Extra"]["Reimu"][0].get<ull>();
	_IN.wr.extra.Yukari = j["IN"]["Extra"]["Yukari"][0].get<ull>();
	_IN.wr.extra.Marisa = j["IN"]["Extra"]["Marisa"][0].get<ull>();
	_IN.wr.extra.Alice = j["IN"]["Extra"]["Alice"][0].get<ull>();
	_IN.wr.extra.Sakuya = j["IN"]["Extra"]["Sakuya"][0].get<ull>();
	_IN.wr.extra.Remilia = j["IN"]["Extra"]["Remilia"][0].get<ull>();
	_IN.wr.extra.Youmu = j["IN"]["Extra"]["Youmu"][0].get<ull>();
	_IN.wr.extra.Yuyuko = j["IN"]["Extra"]["Yuyuko"][0].get<ull>();

	// PoFV world record
	_PoFV.wr.easy.Reimu = j["PoFV"]["Easy"]["Reimu"][0].get<ull>();
	_PoFV.wr.easy.Marisa = j["PoFV"]["Easy"]["Marisa"][0].get<ull>();
	_PoFV.wr.easy.Sakuya = j["PoFV"]["Easy"]["Sakuya"][0].get<ull>();
	_PoFV.wr.easy.Youmu = j["PoFV"]["Easy"]["Youmu"][0].get<ull>();
	_PoFV.wr.easy.Reisen = j["PoFV"]["Easy"]["Reisen"][0].get<ull>();
	_PoFV.wr.easy.Cirno = j["PoFV"]["Easy"]["Cirno"][0].get<ull>();
	_PoFV.wr.easy.Lyrica = j["PoFV"]["Easy"]["Lyrica"][0].get<ull>();
	_PoFV.wr.easy.Mystia = j["PoFV"]["Easy"]["Mystia"][0].get<ull>();
	_PoFV.wr.easy.Tewi = j["PoFV"]["Easy"]["Tewi"][0].get<ull>();
	_PoFV.wr.easy.Aya = j["PoFV"]["Easy"]["Aya"][0].get<ull>();
	_PoFV.wr.easy.Medicine = j["PoFV"]["Easy"]["Medicine"][0].get<ull>();
	_PoFV.wr.easy.Yuuka = j["PoFV"]["Easy"]["Yuuka"][0].get<ull>();
	_PoFV.wr.easy.Komachi = j["PoFV"]["Easy"]["Komachi"][0].get<ull>();
	_PoFV.wr.easy.Eiki = j["PoFV"]["Easy"]["Eiki"][0].get<ull>();
	_PoFV.wr.normal.Reimu = j["PoFV"]["Normal"]["Reimu"][0].get<ull>();
	_PoFV.wr.normal.Marisa = j["PoFV"]["Normal"]["Marisa"][0].get<ull>();
	_PoFV.wr.normal.Sakuya = j["PoFV"]["Normal"]["Sakuya"][0].get<ull>();
	_PoFV.wr.normal.Youmu = j["PoFV"]["Normal"]["Youmu"][0].get<ull>();
	_PoFV.wr.normal.Reisen = j["PoFV"]["Normal"]["Reisen"][0].get<ull>();
	_PoFV.wr.normal.Cirno = j["PoFV"]["Normal"]["Cirno"][0].get<ull>();
	_PoFV.wr.normal.Lyrica = j["PoFV"]["Normal"]["Lyrica"][0].get<ull>();
	_PoFV.wr.normal.Mystia = j["PoFV"]["Normal"]["Mystia"][0].get<ull>();
	_PoFV.wr.normal.Tewi = j["PoFV"]["Normal"]["Tewi"][0].get<ull>();
	_PoFV.wr.normal.Aya = j["PoFV"]["Normal"]["Aya"][0].get<ull>();
	_PoFV.wr.normal.Medicine = j["PoFV"]["Normal"]["Medicine"][0].get<ull>();
	_PoFV.wr.normal.Yuuka = j["PoFV"]["Normal"]["Yuuka"][0].get<ull>();
	_PoFV.wr.normal.Komachi = j["PoFV"]["Normal"]["Komachi"][0].get<ull>();
	_PoFV.wr.normal.Eiki = j["PoFV"]["Normal"]["Eiki"][0].get<ull>();
	_PoFV.wr.hard.Reimu = j["PoFV"]["Hard"]["Reimu"][0].get<ull>();
	_PoFV.wr.hard.Marisa = j["PoFV"]["Hard"]["Marisa"][0].get<ull>();
	_PoFV.wr.hard.Sakuya = j["PoFV"]["Hard"]["Sakuya"][0].get<ull>();
	_PoFV.wr.hard.Youmu = j["PoFV"]["Hard"]["Youmu"][0].get<ull>();
	_PoFV.wr.hard.Reisen = j["PoFV"]["Hard"]["Reisen"][0].get<ull>();
	_PoFV.wr.hard.Cirno = j["PoFV"]["Hard"]["Cirno"][0].get<ull>();
	_PoFV.wr.hard.Lyrica = j["PoFV"]["Hard"]["Lyrica"][0].get<ull>();
	_PoFV.wr.hard.Mystia = j["PoFV"]["Hard"]["Mystia"][0].get<ull>();
	_PoFV.wr.hard.Tewi = j["PoFV"]["Hard"]["Tewi"][0].get<ull>();
	_PoFV.wr.hard.Aya = j["PoFV"]["Hard"]["Aya"][0].get<ull>();
	_PoFV.wr.hard.Medicine = j["PoFV"]["Hard"]["Medicine"][0].get<ull>();
	_PoFV.wr.hard.Yuuka = j["PoFV"]["Hard"]["Yuuka"][0].get<ull>();
	_PoFV.wr.hard.Komachi = j["PoFV"]["Hard"]["Komachi"][0].get<ull>();
	_PoFV.wr.hard.Eiki = j["PoFV"]["Hard"]["Eiki"][0].get<ull>();
	_PoFV.wr.lunatic.Reimu = j["PoFV"]["Lunatic"]["Reimu"][0].get<ull>();
	_PoFV.wr.lunatic.Marisa = j["PoFV"]["Lunatic"]["Marisa"][0].get<ull>();
	_PoFV.wr.lunatic.Sakuya = j["PoFV"]["Lunatic"]["Sakuya"][0].get<ull>();
	_PoFV.wr.lunatic.Youmu = j["PoFV"]["Lunatic"]["Youmu"][0].get<ull>();
	_PoFV.wr.lunatic.Reisen = j["PoFV"]["Lunatic"]["Reisen"][0].get<ull>();
	_PoFV.wr.lunatic.Cirno = j["PoFV"]["Lunatic"]["Cirno"][0].get<ull>();
	_PoFV.wr.lunatic.Lyrica = j["PoFV"]["Lunatic"]["Lyrica"][0].get<ull>();
	_PoFV.wr.lunatic.Mystia = j["PoFV"]["Lunatic"]["Mystia"][0].get<ull>();
	_PoFV.wr.lunatic.Tewi = j["PoFV"]["Lunatic"]["Tewi"][0].get<ull>();
	_PoFV.wr.lunatic.Aya = j["PoFV"]["Lunatic"]["Aya"][0].get<ull>();
	_PoFV.wr.lunatic.Medicine = j["PoFV"]["Lunatic"]["Medicine"][0].get<ull>();
	_PoFV.wr.lunatic.Yuuka = j["PoFV"]["Lunatic"]["Yuuka"][0].get<ull>();
	_PoFV.wr.lunatic.Komachi = j["PoFV"]["Lunatic"]["Komachi"][0].get<ull>();
	_PoFV.wr.lunatic.Eiki = j["PoFV"]["Lunatic"]["Eiki"][0].get<ull>();
	_PoFV.wr.extra.Reimu = j["PoFV"]["Extra"]["Reimu"][0].get<ull>();
	_PoFV.wr.extra.Marisa = j["PoFV"]["Extra"]["Marisa"][0].get<ull>();
	_PoFV.wr.extra.Sakuya = j["PoFV"]["Extra"]["Sakuya"][0].get<ull>();
	_PoFV.wr.extra.Youmu = j["PoFV"]["Extra"]["Youmu"][0].get<ull>();
	_PoFV.wr.extra.Reisen = j["PoFV"]["Extra"]["Reisen"][0].get<ull>();
	_PoFV.wr.extra.Cirno = j["PoFV"]["Extra"]["Cirno"][0].get<ull>();
	_PoFV.wr.extra.Lyrica = j["PoFV"]["Extra"]["Lyrica"][0].get<ull>();
	_PoFV.wr.extra.Mystia = j["PoFV"]["Extra"]["Mystia"][0].get<ull>();
	_PoFV.wr.extra.Tewi = j["PoFV"]["Extra"]["Tewi"][0].get<ull>();
	_PoFV.wr.extra.Aya = j["PoFV"]["Extra"]["Aya"][0].get<ull>();
	_PoFV.wr.extra.Medicine = j["PoFV"]["Extra"]["Medicine"][0].get<ull>();
	_PoFV.wr.extra.Yuuka = j["PoFV"]["Extra"]["Yuuka"][0].get<ull>();
	_PoFV.wr.extra.Komachi = j["PoFV"]["Extra"]["Komachi"][0].get<ull>();
	_PoFV.wr.extra.Eiki = j["PoFV"]["Extra"]["Eiki"][0].get<ull>();

	// MoF world record
	_MoF.wr.easy.ReimuA = j["MoF"]["Easy"]["ReimuA"][0].get<ull>();
	_MoF.wr.easy.ReimuB = j["MoF"]["Easy"]["ReimuB"][0].get<ull>();
	_MoF.wr.easy.ReimuC = j["MoF"]["Easy"]["ReimuC"][0].get<ull>();
	_MoF.wr.easy.MarisaA = j["MoF"]["Easy"]["MarisaA"][0].get<ull>();
	_MoF.wr.easy.MarisaB = j["MoF"]["Easy"]["MarisaB"][0].get<ull>();
	_MoF.wr.easy.MarisaC = j["MoF"]["Easy"]["MarisaC"][0].get<ull>();
	_MoF.wr.normal.ReimuA = j["MoF"]["Normal"]["ReimuA"][0].get<ull>();
	_MoF.wr.normal.ReimuB = j["MoF"]["Normal"]["ReimuB"][0].get<ull>();
	_MoF.wr.normal.ReimuC = j["MoF"]["Normal"]["ReimuC"][0].get<ull>();
	_MoF.wr.normal.MarisaA = j["MoF"]["Normal"]["MarisaA"][0].get<ull>();
	_MoF.wr.normal.MarisaB = j["MoF"]["Normal"]["MarisaB"][0].get<ull>();
	_MoF.wr.normal.MarisaC = j["MoF"]["Normal"]["MarisaC"][0].get<ull>();
	_MoF.wr.hard.ReimuA = j["MoF"]["Hard"]["ReimuA"][0].get<ull>();
	_MoF.wr.hard.ReimuB = j["MoF"]["Hard"]["ReimuB"][0].get<ull>();
	_MoF.wr.hard.ReimuC = j["MoF"]["Hard"]["ReimuC"][0].get<ull>();
	_MoF.wr.hard.MarisaA = j["MoF"]["Hard"]["MarisaA"][0].get<ull>();
	_MoF.wr.hard.MarisaB = j["MoF"]["Hard"]["MarisaB"][0].get<ull>();
	_MoF.wr.hard.MarisaC = j["MoF"]["Hard"]["MarisaC"][0].get<ull>();
	_MoF.wr.lunatic.ReimuA = j["MoF"]["Lunatic"]["ReimuA"][0].get<ull>();
	_MoF.wr.lunatic.ReimuB = j["MoF"]["Lunatic"]["ReimuB"][0].get<ull>();
	_MoF.wr.lunatic.ReimuC = j["MoF"]["Lunatic"]["ReimuC"][0].get<ull>();
	_MoF.wr.lunatic.MarisaA = j["MoF"]["Lunatic"]["MarisaA"][0].get<ull>();
	_MoF.wr.lunatic.MarisaB = j["MoF"]["Lunatic"]["MarisaB"][0].get<ull>();
	_MoF.wr.lunatic.MarisaC = j["MoF"]["Lunatic"]["MarisaC"][0].get<ull>();
	_MoF.wr.extra.ReimuA = j["MoF"]["Extra"]["ReimuA"][0].get<ull>();
	_MoF.wr.extra.ReimuB = j["MoF"]["Extra"]["ReimuB"][0].get<ull>();
	_MoF.wr.extra.ReimuC = j["MoF"]["Extra"]["ReimuC"][0].get<ull>();
	_MoF.wr.extra.MarisaA = j["MoF"]["Extra"]["MarisaA"][0].get<ull>();
	_MoF.wr.extra.MarisaB = j["MoF"]["Extra"]["MarisaB"][0].get<ull>();
	_MoF.wr.extra.MarisaC = j["MoF"]["Extra"]["MarisaC"][0].get<ull>();

	// SA world record
	_SA.wr.easy.ReimuA = j["SA"]["Easy"]["ReimuA"][0].get<ull>();
	_SA.wr.easy.ReimuB = j["SA"]["Easy"]["ReimuB"][0].get<ull>();
	_SA.wr.easy.ReimuC = j["SA"]["Easy"]["ReimuC"][0].get<ull>();
	_SA.wr.easy.MarisaA = j["SA"]["Easy"]["MarisaA"][0].get<ull>();
	_SA.wr.easy.MarisaB = j["SA"]["Easy"]["MarisaB"][0].get<ull>();
	_SA.wr.easy.MarisaC = j["SA"]["Easy"]["MarisaC"][0].get<ull>();
	_SA.wr.normal.ReimuA = j["SA"]["Normal"]["ReimuA"][0].get<ull>();
	_SA.wr.normal.ReimuB = j["SA"]["Normal"]["ReimuB"][0].get<ull>();
	_SA.wr.normal.ReimuC = j["SA"]["Normal"]["ReimuC"][0].get<ull>();
	_SA.wr.normal.MarisaA = j["SA"]["Normal"]["MarisaA"][0].get<ull>();
	_SA.wr.normal.MarisaB = j["SA"]["Normal"]["MarisaB"][0].get<ull>();
	_SA.wr.normal.MarisaC = j["SA"]["Normal"]["MarisaC"][0].get<ull>();
	_SA.wr.hard.ReimuA = j["SA"]["Hard"]["ReimuA"][0].get<ull>();
	_SA.wr.hard.ReimuB = j["SA"]["Hard"]["ReimuB"][0].get<ull>();
	_SA.wr.hard.ReimuC = j["SA"]["Hard"]["ReimuC"][0].get<ull>();
	_SA.wr.hard.MarisaA = j["SA"]["Hard"]["MarisaA"][0].get<ull>();
	_SA.wr.hard.MarisaB = j["SA"]["Hard"]["MarisaB"][0].get<ull>();
	_SA.wr.hard.MarisaC = j["SA"]["Hard"]["MarisaC"][0].get<ull>();
	_SA.wr.lunatic.ReimuA = j["SA"]["Lunatic"]["ReimuA"][0].get<ull>();
	_SA.wr.lunatic.ReimuB = j["SA"]["Lunatic"]["ReimuB"][0].get<ull>();
	_SA.wr.lunatic.ReimuC = j["SA"]["Lunatic"]["ReimuC"][0].get<ull>();
	_SA.wr.lunatic.MarisaA = j["SA"]["Lunatic"]["MarisaA"][0].get<ull>();
	_SA.wr.lunatic.MarisaB = j["SA"]["Lunatic"]["MarisaB"][0].get<ull>();
	_SA.wr.lunatic.MarisaC = j["SA"]["Lunatic"]["MarisaC"][0].get<ull>();
	_SA.wr.extra.ReimuA = j["SA"]["Extra"]["ReimuA"][0].get<ull>();
	_SA.wr.extra.ReimuB = j["SA"]["Extra"]["ReimuB"][0].get<ull>();
	_SA.wr.extra.ReimuC = j["SA"]["Extra"]["ReimuC"][0].get<ull>();
	_SA.wr.extra.MarisaA = j["SA"]["Extra"]["MarisaA"][0].get<ull>();
	_SA.wr.extra.MarisaB = j["SA"]["Extra"]["MarisaB"][0].get<ull>();
	_SA.wr.extra.MarisaC = j["SA"]["Extra"]["MarisaC"][0].get<ull>();

	// UFO world record
	_UFO.wr.easy.ReimuA = j["UFO"]["Easy"]["ReimuA"][0].get<ull>();
	_UFO.wr.easy.ReimuB = j["UFO"]["Easy"]["ReimuB"][0].get<ull>();
	_UFO.wr.easy.MarisaA = j["UFO"]["Easy"]["MarisaA"][0].get<ull>();
	_UFO.wr.easy.MarisaB = j["UFO"]["Easy"]["MarisaB"][0].get<ull>();
	_UFO.wr.easy.SanaeA = j["UFO"]["Easy"]["SanaeA"][0].get<ull>();
	_UFO.wr.easy.SanaeB = j["UFO"]["Easy"]["SanaeB"][0].get<ull>();
	_UFO.wr.normal.ReimuA = j["UFO"]["Normal"]["ReimuA"][0].get<ull>();
	_UFO.wr.normal.ReimuB = j["UFO"]["Normal"]["ReimuB"][0].get<ull>();
	_UFO.wr.normal.MarisaA = j["UFO"]["Normal"]["MarisaA"][0].get<ull>();
	_UFO.wr.normal.MarisaB = j["UFO"]["Normal"]["MarisaB"][0].get<ull>();
	_UFO.wr.normal.SanaeA = j["UFO"]["Normal"]["SanaeA"][0].get<ull>();
	_UFO.wr.normal.SanaeB = j["UFO"]["Normal"]["SanaeB"][0].get<ull>();
	_UFO.wr.hard.ReimuA = j["UFO"]["Hard"]["ReimuA"][0].get<ull>();
	_UFO.wr.hard.ReimuB = j["UFO"]["Hard"]["ReimuB"][0].get<ull>();
	_UFO.wr.hard.MarisaA = j["UFO"]["Hard"]["MarisaA"][0].get<ull>();
	_UFO.wr.hard.MarisaB = j["UFO"]["Hard"]["MarisaB"][0].get<ull>();
	_UFO.wr.hard.SanaeA = j["UFO"]["Hard"]["SanaeA"][0].get<ull>();
	_UFO.wr.hard.SanaeB = j["UFO"]["Hard"]["SanaeB"][0].get<ull>();
	_UFO.wr.lunatic.ReimuA = j["UFO"]["Lunatic"]["ReimuA"][0].get<ull>();
	_UFO.wr.lunatic.ReimuB = j["UFO"]["Lunatic"]["ReimuB"][0].get<ull>();
	_UFO.wr.lunatic.MarisaA = j["UFO"]["Lunatic"]["MarisaA"][0].get<ull>();
	_UFO.wr.lunatic.MarisaB = j["UFO"]["Lunatic"]["MarisaB"][0].get<ull>();
	_UFO.wr.lunatic.SanaeA = j["UFO"]["Lunatic"]["SanaeA"][0].get<ull>();
	_UFO.wr.lunatic.SanaeB = j["UFO"]["Lunatic"]["SanaeB"][0].get<ull>();
	_UFO.wr.extra.ReimuA = j["UFO"]["Extra"]["ReimuA"][0].get<ull>();
	_UFO.wr.extra.ReimuB = j["UFO"]["Extra"]["ReimuB"][0].get<ull>();
	_UFO.wr.extra.MarisaA = j["UFO"]["Extra"]["MarisaA"][0].get<ull>();
	_UFO.wr.extra.MarisaB = j["UFO"]["Extra"]["MarisaB"][0].get<ull>();
	_UFO.wr.extra.SanaeA = j["UFO"]["Extra"]["SanaeA"][0].get<ull>();
	_UFO.wr.extra.SanaeB = j["UFO"]["Extra"]["SanaeB"][0].get<ull>();

	// TD world record
	_TD.wr.easy.Reimu = j["TD"]["Easy"]["Reimu"][0].get<ull>();
	_TD.wr.easy.Marisa = j["TD"]["Easy"]["Marisa"][0].get<ull>();
	_TD.wr.easy.Sanae = j["TD"]["Easy"]["Sanae"][0].get<ull>();
	_TD.wr.easy.Youmu = j["TD"]["Easy"]["Youmu"][0].get<ull>();
	_TD.wr.normal.Reimu = j["TD"]["Normal"]["Reimu"][0].get<ull>();
	_TD.wr.normal.Marisa = j["TD"]["Normal"]["Marisa"][0].get<ull>();
	_TD.wr.normal.Sanae = j["TD"]["Normal"]["Sanae"][0].get<ull>();
	_TD.wr.normal.Youmu = j["TD"]["Normal"]["Youmu"][0].get<ull>();
	_TD.wr.hard.Reimu = j["TD"]["Hard"]["Reimu"][0].get<ull>();
	_TD.wr.hard.Marisa = j["TD"]["Hard"]["Marisa"][0].get<ull>();
	_TD.wr.hard.Sanae = j["TD"]["Hard"]["Sanae"][0].get<ull>();
	_TD.wr.hard.Youmu = j["TD"]["Hard"]["Youmu"][0].get<ull>();
	_TD.wr.lunatic.Reimu = j["TD"]["Lunatic"]["Reimu"][0].get<ull>();
	_TD.wr.lunatic.Marisa = j["TD"]["Lunatic"]["Marisa"][0].get<ull>();
	_TD.wr.lunatic.Sanae = j["TD"]["Lunatic"]["Sanae"][0].get<ull>();
	_TD.wr.lunatic.Youmu = j["TD"]["Lunatic"]["Youmu"][0].get<ull>();
	_TD.wr.extra.Reimu = j["TD"]["Extra"]["Reimu"][0].get<ull>();
	_TD.wr.extra.Marisa = j["TD"]["Extra"]["Marisa"][0].get<ull>();
	_TD.wr.extra.Sanae = j["TD"]["Extra"]["Sanae"][0].get<ull>();
	_TD.wr.extra.Youmu = j["TD"]["Extra"]["Youmu"][0].get<ull>();

	// DDC world record
	_DDC.wr.easy.ReimuA = j["DDC"]["Easy"]["ReimuA"][0].get<ull>();
	_DDC.wr.easy.ReimuB = j["DDC"]["Easy"]["ReimuB"][0].get<ull>();
	_DDC.wr.easy.MarisaA = j["DDC"]["Easy"]["MarisaA"][0].get<ull>();
	_DDC.wr.easy.MarisaB = j["DDC"]["Easy"]["MarisaB"][0].get<ull>();
	_DDC.wr.easy.SakuyaA = j["DDC"]["Easy"]["SakuyaA"][0].get<ull>();
	_DDC.wr.easy.SakuyaB = j["DDC"]["Easy"]["SakuyaB"][0].get<ull>();
	_DDC.wr.normal.ReimuA = j["DDC"]["Normal"]["ReimuA"][0].get<ull>();
	_DDC.wr.normal.ReimuB = j["DDC"]["Normal"]["ReimuB"][0].get<ull>();
	_DDC.wr.normal.MarisaA = j["DDC"]["Normal"]["MarisaA"][0].get<ull>();
	_DDC.wr.normal.MarisaB = j["DDC"]["Normal"]["MarisaB"][0].get<ull>();
	_DDC.wr.normal.SakuyaA = j["DDC"]["Normal"]["SakuyaA"][0].get<ull>();
	_DDC.wr.normal.SakuyaB = j["DDC"]["Normal"]["SakuyaB"][0].get<ull>();
	_DDC.wr.hard.ReimuA = j["DDC"]["Hard"]["ReimuA"][0].get<ull>();
	_DDC.wr.hard.ReimuB = j["DDC"]["Hard"]["ReimuB"][0].get<ull>();
	_DDC.wr.hard.MarisaA = j["DDC"]["Hard"]["MarisaA"][0].get<ull>();
	_DDC.wr.hard.MarisaB = j["DDC"]["Hard"]["MarisaB"][0].get<ull>();
	_DDC.wr.hard.SakuyaA = j["DDC"]["Hard"]["SakuyaA"][0].get<ull>();
	_DDC.wr.hard.SakuyaB = j["DDC"]["Hard"]["SakuyaB"][0].get<ull>();
	_DDC.wr.lunatic.ReimuA = j["DDC"]["Lunatic"]["ReimuA"][0].get<ull>();
	_DDC.wr.lunatic.ReimuB = j["DDC"]["Lunatic"]["ReimuB"][0].get<ull>();
	_DDC.wr.lunatic.MarisaA = j["DDC"]["Lunatic"]["MarisaA"][0].get<ull>();
	_DDC.wr.lunatic.MarisaB = j["DDC"]["Lunatic"]["MarisaB"][0].get<ull>();
	_DDC.wr.lunatic.SakuyaA = j["DDC"]["Lunatic"]["SakuyaA"][0].get<ull>();
	_DDC.wr.lunatic.SakuyaB = j["DDC"]["Lunatic"]["SakuyaB"][0].get<ull>();
	_DDC.wr.extra.ReimuA = j["DDC"]["Extra"]["ReimuA"][0].get<ull>();
	_DDC.wr.extra.ReimuB = j["DDC"]["Extra"]["ReimuB"][0].get<ull>();
	_DDC.wr.extra.MarisaA = j["DDC"]["Extra"]["MarisaA"][0].get<ull>();
	_DDC.wr.extra.MarisaB = j["DDC"]["Extra"]["MarisaB"][0].get<ull>();
	_DDC.wr.extra.SakuyaA = j["DDC"]["Extra"]["SakuyaA"][0].get<ull>();
	_DDC.wr.extra.SakuyaB = j["DDC"]["Extra"]["SakuyaB"][0].get<ull>();

	// LoLK world record
	_LoLK.wr.easy.Reimu = j["LoLK"]["Easy"]["Reimu"][0].get<ull>();
	_LoLK.wr.easy.Marisa = j["LoLK"]["Easy"]["Marisa"][0].get<ull>();
	_LoLK.wr.easy.Sanae = j["LoLK"]["Easy"]["Sanae"][0].get<ull>();
	_LoLK.wr.easy.Reisen = j["LoLK"]["Easy"]["Reisen"][0].get<ull>();
	_LoLK.wr.normal.Reimu = j["LoLK"]["Normal"]["Reimu"][0].get<ull>();
	_LoLK.wr.normal.Marisa = j["LoLK"]["Normal"]["Marisa"][0].get<ull>();
	_LoLK.wr.normal.Sanae = j["LoLK"]["Normal"]["Sanae"][0].get<ull>();
	_LoLK.wr.normal.Reisen = j["LoLK"]["Normal"]["Reisen"][0].get<ull>();
	_LoLK.wr.hard.Reimu = j["LoLK"]["Hard"]["Reimu"][0].get<ull>();
	_LoLK.wr.hard.Marisa = j["LoLK"]["Hard"]["Marisa"][0].get<ull>();
	_LoLK.wr.hard.Sanae = j["LoLK"]["Hard"]["Sanae"][0].get<ull>();
	_LoLK.wr.hard.Reisen = j["LoLK"]["Hard"]["Reisen"][0].get<ull>();
	_LoLK.wr.lunatic.Reimu = j["LoLK"]["Lunatic"]["Reimu"][0].get<ull>();
	_LoLK.wr.lunatic.Marisa = j["LoLK"]["Lunatic"]["Marisa"][0].get<ull>();
	_LoLK.wr.lunatic.Sanae = j["LoLK"]["Lunatic"]["Sanae"][0].get<ull>();
	_LoLK.wr.lunatic.Reisen = j["LoLK"]["Lunatic"]["Reisen"][0].get<ull>();
	_LoLK.wr.extra.Reimu = j["LoLK"]["Extra"]["Reimu"][0].get<ull>();
	_LoLK.wr.extra.Marisa = j["LoLK"]["Extra"]["Marisa"][0].get<ull>();
	_LoLK.wr.extra.Sanae = j["LoLK"]["Extra"]["Sanae"][0].get<ull>();
	_LoLK.wr.extra.Reisen = j["LoLK"]["Extra"]["Reisen"][0].get<ull>();

	// HSiFS world record
	_HSiFS.wr.easy.Reimu.Spring = j["HSiFS"]["Easy"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Summer = j["HSiFS"]["Easy"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Autumn = j["HSiFS"]["Easy"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Reimu.Winter = j["HSiFS"]["Easy"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Spring = j["HSiFS"]["Easy"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Summer = j["HSiFS"]["Easy"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Autumn = j["HSiFS"]["Easy"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Cirno.Winter = j["HSiFS"]["Easy"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Spring = j["HSiFS"]["Easy"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Summer = j["HSiFS"]["Easy"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Autumn = j["HSiFS"]["Easy"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Aya.Winter = j["HSiFS"]["Easy"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Spring = j["HSiFS"]["Easy"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Summer = j["HSiFS"]["Easy"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Autumn = j["HSiFS"]["Easy"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.easy.Marisa.Winter = j["HSiFS"]["Easy"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Spring = j["HSiFS"]["Normal"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Summer = j["HSiFS"]["Normal"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Autumn = j["HSiFS"]["Normal"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Reimu.Winter = j["HSiFS"]["Normal"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Spring = j["HSiFS"]["Normal"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Summer = j["HSiFS"]["Normal"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Autumn = j["HSiFS"]["Normal"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Cirno.Winter = j["HSiFS"]["Normal"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Spring = j["HSiFS"]["Normal"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Summer = j["HSiFS"]["Normal"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Autumn = j["HSiFS"]["Normal"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Aya.Winter = j["HSiFS"]["Normal"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Spring = j["HSiFS"]["Normal"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Summer = j["HSiFS"]["Normal"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Autumn = j["HSiFS"]["Normal"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.normal.Marisa.Winter = j["HSiFS"]["Normal"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Spring = j["HSiFS"]["Hard"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Summer = j["HSiFS"]["Hard"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Autumn = j["HSiFS"]["Hard"]["ReimuAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Reimu.Winter = j["HSiFS"]["Hard"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Spring = j["HSiFS"]["Hard"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Summer = j["HSiFS"]["Hard"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Autumn = j["HSiFS"]["Hard"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Cirno.Winter = j["HSiFS"]["Hard"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Spring = j["HSiFS"]["Hard"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Summer = j["HSiFS"]["Hard"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Autumn = j["HSiFS"]["Hard"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Aya.Winter = j["HSiFS"]["Hard"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Spring = j["HSiFS"]["Hard"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Summer = j["HSiFS"]["Hard"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Autumn = j["HSiFS"]["Hard"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.hard.Marisa.Winter = j["HSiFS"]["Hard"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Spring = j["HSiFS"]["Lunatic"]["ReimuSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Summer = j["HSiFS"]["Lunatic"]["ReimuSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Reimu.Autumn = j["HSiFS"]["Lunatic"]["ReimuAutumn"][0].get<ull>();
	// no iead why Maribel didn't include Reimu Spring world record
	//_HSiFS.wr.lunatic.Reimu.Winter = j["HSiFS"]["Lunatic"]["ReimuWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Spring = j["HSiFS"]["Lunatic"]["CirnoSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Summer = j["HSiFS"]["Lunatic"]["CirnoSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Autumn = j["HSiFS"]["Lunatic"]["CirnoAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Cirno.Winter = j["HSiFS"]["Lunatic"]["CirnoWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Spring = j["HSiFS"]["Lunatic"]["AyaSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Summer = j["HSiFS"]["Lunatic"]["AyaSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Autumn = j["HSiFS"]["Lunatic"]["AyaAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Aya.Winter = j["HSiFS"]["Lunatic"]["AyaWinter"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Spring = j["HSiFS"]["Lunatic"]["MarisaSpring"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Summer = j["HSiFS"]["Lunatic"]["MarisaSummer"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Autumn = j["HSiFS"]["Lunatic"]["MarisaAutumn"][0].get<ull>();
	_HSiFS.wr.lunatic.Marisa.Winter = j["HSiFS"]["Lunatic"]["MarisaWinter"][0].get<ull>();
	_HSiFS.wr.extra.Reimu = j["HSiFS"]["Extra"]["Reimu"][0].get<ull>();
	_HSiFS.wr.extra.Cirno = j["HSiFS"]["Extra"]["Cirno"][0].get<ull>();
	_HSiFS.wr.extra.Aya = j["HSiFS"]["Extra"]["Aya"][0].get<ull>();
	_HSiFS.wr.extra.Marisa = j["HSiFS"]["Extra"]["Marisa"][0].get<ull>();

	std::cout << "Successfully loaded world record file." << std::endl;
	return true;
}
