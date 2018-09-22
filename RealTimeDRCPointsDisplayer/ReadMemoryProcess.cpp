#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <math.h>
using namespace std;

int main()
{
    HANDLE handle;
    HWND hwnd;
    DWORD address = 0x004AEBD0;
    uint8_t buffer[4];

    hwnd = FindWindow(0, "“Œ•û¯˜@‘D@` Undefined Fantastic Object. ver 1.00b");

    if (!hwnd)
    {
        cout << "Window not found" << endl;
        return 0;
    }

    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    handle = OpenProcess(PROCESS_VM_READ, 0, pid);
    if (!handle)
    {
        cout << "Could not get handle!" << endl;
        return 0;
    }

    while (true)
    {
        ReadProcessMemory(handle, (void*)address, buffer, 1, 0);
        switch (buffer[0])
        {
        case 0:
            cout << "Easy" << endl;
            break;
        case 1:
            cout << "Normal" << endl;
            break;
        case 2:
            cout << "Hard" << endl;
            break;
        case 3:
            cout << "Lunatic" << endl;
            break;
        case 4:
            cout << "Extra" << endl;
            break;
        default:
            cout << "Not selected" << endl;
        }

        // 0x004B0CDC: graze
        // 0x0749CD98: miss
        // 0x0749CD9C: bomb
        // 0x004B0C58: the current number of UFO vaults
        // 0x02D49CD8: temp playcount
        uint8_t score[4];
        DWORD paddress = 0x004B0C44;
        int readScore = ReadProcessMemory(handle, (void*)paddress, score, 4, 0);
        if (!readScore)
            cout << "Cannot read score!" << endl;
        else
            cout << int(score[0]) + int(score[1]) * pow(16, 2) + int(score[2]) * pow(16, 4) + int(score[3]) * pow(16, 6) << endl;

        Sleep(1000);
    }
    return 0;
}

