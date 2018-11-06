#include <tchar.h>

#include "ProcessMemory.h"

// Unused code
/*
// Global variables  

// The main window class name.  
static TCHAR szWindowClass[] = _T("MainWin");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Real-time DRC Points Displayer");

// Update rubrics button
HWND hwnd_update_ru;

// Update world records button
HWND hwnd_update_wr;

// enum variable for window action
enum WinACtion
{
	UPDATE_RUBRICS,
	UPDATE_WRS
};

HINSTANCE hInst;

// Forward declarations of functions included in this code module:  
// LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
*/

// int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
int main(int argc, char* args[])
{
	Download_rubrics();
	Download_wrs();
	Load_rubrics();
	Load_wrs();
	while (true)
	{
		while (!GetProcess())
		{
			std::cout << "Game not found. Finding..." << std::endl;
			Sleep(2000);
		}
			
		while (GetProcess())
		{
			ReadMemory(gameProcname);
			Sleep(1000/10);	// 10 FPS
			system("cls");
		}
		system("cls");
	}
	/*
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		// WS_SYSMENU | WS_MINIMIZEBOX,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		480, 360,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
	
	/* Unused code
	// Initialization
	Download_rubrics();
	Read_rubrics();

	Download_wrs();
	Read_wrs();

	// Main loop
	while (true)
	{
		// Find game loop, gamefound is a boolean and set to false until game found
		HWND hGame;
		LPCSTR gamefound_title;
		bool gamefound = true;
		for (int i = 0; i < GAME_AVAILABLE; i++)
		{
			hGame = FindWindow(NULL, GameTitle[i]);
			if (hGame)
			{
				std::cout << "Found game." << std::endl;
				gamefound_title = GameTitle[i];
				gamefound = true;
				break;
			}
		}

		if (gamefound)
		{

			
			// Load game rubrics/ world records

			// detect difficulty, character & shottype

			// when finishing choosing shootype, ingame boolean is created and set to true
			bool ingame = true;

			// calculating DRC Points while in-game
			while (ingame)
			{
				// calculating

				// if not ingame, set ingame boolean to false
				// if ()
				// {
				//	ingame = false;
				// }

				ingame = false;
			}
			
		}
		else
		{
			std::cout << "Finding game..." << std::endl;
		}


		// let CPU rest
		Sleep(3000);
	}
	*/
}


/* Unused code

//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
//  
//  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{
		// Initialize when window is created
		// Should include a button to update rubrics / world records
	case WM_CREATE:

		hwnd_update_ru = CreateWindow(
			"BUTTON",
			"Update rubrics",
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			20, 50, 150, 20,
			hWnd, (HMENU)UPDATE_RUBRICS, NULL, NULL);

		hwnd_update_wr = CreateWindow(
			"BUTTON",
			"Update world records",
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			20, 100, 150, 20,
			hWnd, (HMENU)UPDATE_WRS, NULL, NULL);

		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			// If Update Rubrics is pressed, update rubrics
		case UPDATE_RUBRICS:
			Download_rubrics();
			Read_rubrics();
			break;

			// If Update World Records is pressed, update world records
		case UPDATE_WRS:
			Download_wrs();
			Read_wrs();
			break;
		}

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		// For this introduction, we just print out "Hello, World!"  
		// in the top left corner.  
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.  

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
*/