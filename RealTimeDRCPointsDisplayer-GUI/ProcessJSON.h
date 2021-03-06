/*
MIT License

Copyright (c) 2019 Maribel Hearn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://maribelhearn.com/assets/json/rubrics.json"), _T("rubrics.json"), 0, NULL);

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
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://maribelhearn.com/assets/json/wrlist.json"), _T("wrlist.json"), 0, NULL);

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
/*
BOOL Download_config()
{
	HRESULT hResult = URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/hoangcaominh/RealTimeDRCPointsDisplayer/master/RealTimeDRCPointsDisplayer-GUI/config.json"), _T("_config.json"), 0, NULL);

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
*/
bool Load_config()
{
	std::ifstream read("config.json");
	if (read.fail())
	{
		return false;
	}

	// successfully parsed config file
	read >> config;

	return true;
}

bool Save_config()
{
	std::ofstream write("config.json");
	if (write.fail())
	{
		return false;
	}

	// successfully saved config file
	write << config;
	return true;
}
