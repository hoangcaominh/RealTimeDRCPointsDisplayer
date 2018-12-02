#pragma once
// print messages
#include <iostream>
#include "color.h"

// download preprocessors
#include <urlmon.h>
#include <tchar.h>
#pragma comment (lib, "urlmon.lib")

// reading preprocessors
#include <fstream>
#include "json.hpp"
// for convenience
using json = nlohmann::json;

// json objects
json WRs, Rubrics;

// check if a key exists
bool keyExist(json outer_object, const char* key)
{
	return outer_object.find(key) != outer_object.end();
}

// downloading part
bool Download_rubrics()
{
	std::cout << "Downloading rubric file..." << std::endl;

	// result of downloading rubric file
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/MaribelHearn/MaribelHearn.github.io/master/json/rubrics.json"), _T("rubrics.json"), 0, NULL);

	switch (hResult)
	{
		// successfully downloaded
	case S_OK:
		setcolor(LIGHTGRAY);
		std::cout << "Successfully downloaded rubric file." << std::endl;
		return true;
		// out of memory
	case E_OUTOFMEMORY:
		setcolor(LIGHTRED);
		std::cout << "Not enough memory to download rubric file." << std::endl;
		break;
		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		setcolor(LIGHTRED);
		std::cout << "Rubric file not valid, or file name not match, download failed." << std::endl;
		break;
		// other errors
	default:
		setcolor(LIGHTRED);
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
		setcolor(LIGHTGRAY);
		std::cout << "Successfully downloaded world record file." << std::endl;
		return true;
		// out of memory
	case E_OUTOFMEMORY:
		setcolor(LIGHTRED);
		std::cout << "Not enough memory to download world record file." << std::endl;
		break;
		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		setcolor(LIGHTRED);
		std::cout << "World record file not valid, or file name not match, download failed." << std::endl;
		break;
		// other errors
	default:
		setcolor(LIGHTRED);
		std::cout << "Failed to download world record file." << std::endl;
		break;
	}

	return false;
}

// reading part
bool Load_rubrics()
{
	setcolor(LIGHTGRAY);
	std::cout << "Loading saved rubric file..." << std::endl;

	std::ifstream read("rubrics.json");
	if (read.fail())
	{
		// failed to parse rubrics file
		setcolor(LIGHTRED);
		std::cout << "Failed to load rubric file." << std::endl;
		return false;
	}

	// successfully parsed rubrics file
	read >> Rubrics;

	if (Rubrics.empty())
	{
		setcolor(LIGHTRED);
		std::cout << "No element in the rubric file could be found." << std::endl;
		return false;
	}

	std::cout << "Successfully loaded rubric file." << std::endl;
	return true;
}

bool Load_wrs()
{
	setcolor(LIGHTGRAY);
	std::cout << "Loading saved world record file..." << std::endl;

	std::ifstream read("wrlist.json");
	if (read.fail())
	{
		// failed to parse world records file
		setcolor(LIGHTRED);
		std::cout << "Failed to load world record file." << std::endl;
		return false;
	}

	// successfully parsed rubrics file
	read >> WRs;

	if (WRs.empty())
	{
		setcolor(LIGHTRED);
		std::cout << "No element in the world record file could be found." << std::endl;
		return false;
	}

	std::cout << "Successfully loaded world record file." << std::endl;
	return true;
}
