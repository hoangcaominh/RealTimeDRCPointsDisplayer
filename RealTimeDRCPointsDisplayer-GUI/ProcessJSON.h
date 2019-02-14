#pragma once

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
json WRs, Rubrics, config;

// check if a key exists
bool keyExist(json outer_object, const char* key)
{
	return outer_object.find(key) != outer_object.end();
}

// downloading part
BOOL Download_rubrics()
{
	// result of downloading rubric file
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/MaribelHearn/MaribelHearn.github.io/master/json/rubrics.json"), _T("rubrics.json"), 0, NULL);

	switch (hResult)
	{
	// successfully downloaded
	case S_OK:
		return 0;

	// out of memory
	case E_OUTOFMEMORY:
		return 2;

	// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		return 3;

	// other errors
	default:
		return 1;
	}

	return 1;
}

BOOL Download_wrs()
{
	// result of downloading world record file (temporary url)
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/MaribelHearn/MaribelHearn.github.io/master/json/wrlist.json"), _T("wrlist.json"), 0, NULL);

	switch (hResult)
	{
		// successfully downloaded
	case S_OK:
		return 0;

		// out of memory
	case E_OUTOFMEMORY:
		return 2;

		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		return 3;

		// other errors
	default:
		return 1;
	}

	return 1;
}

// reading part
bool Load_rubrics()
{
	std::ifstream read("rubrics.json");
	if (read.fail())
	{
		// failed to parse rubrics file
		return true;
	}

	// successfully parsed rubrics file
	read >> Rubrics;

	return false;
}

bool Load_wrs()
{
	std::ifstream read("wrlist.json");
	if (read.fail())
	{
		return true;
	}

	// successfully parsed rubrics file
	read >> WRs;
	
	return false;
}

// check new version

BOOL Download_config()
{
	// result of downloading world record file (temporary url)
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/hoangcaominh/RealTimeDRCPointsDisplayer/master/RealTimeDRCPointsDisplayer/config.json"), _T("_config.json"), 0, NULL);

	switch (hResult)
	{
		// successfully downloaded
	case S_OK:
		return 0;

		// out of memory
	case E_OUTOFMEMORY:
		return 2;

		// file not valid
	case INET_E_DOWNLOAD_FAILURE:
		return 3;

		// other errors
	default:
		return 1;
	}

	return 1;
}

bool Load_config()
{
	std::ifstream read("config.json");
	if (read.fail())
	{
		return false;
	}

	// successfully parsed rubrics file
	read >> config;

	return true;
}
