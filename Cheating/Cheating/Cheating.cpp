// Cheating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define BASE_HEALTH 0x50F4F4 
#define BASE_GUN 0x027EA54C
int main()
{
	int addHealVal = 0;
	int healVal = 0;
	HWND hwnd = FindWindowA(NULL, "AssaultCube");
	if (hwnd == NULL)
	{
		printf("This app not variable");
	}
	else
	{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		if (procID != NULL)
		{
			int addGum;
			int numGum=100;
			ReadProcessMemory(handle, (PBYTE*)BASE_HEALTH, &addHealVal, sizeof(int), 0);
			ReadProcessMemory(handle, (PBYTE*)BASE_GUN, &addGum, sizeof(int), 0);
			printf(" dia chi la %x", addHealVal);
			addHealVal += 0xF8;
			ReadProcessMemory(handle, (PBYTE*)addHealVal, &healVal, sizeof(int), 0);
			WriteProcessMemory(handle, (PBYTE*)addGum, &numGum, sizeof(int), 0);
			printf(" \nso mau la %d", healVal);
			while (1)
			{
				ReadProcessMemory(handle, (PBYTE*)addHealVal, &healVal, sizeof(int), 0);
				ReadProcessMemory(handle, (PBYTE*)addGum, &numGum, sizeof(int), 0);
				if (healVal < 70)
				{
					healVal = 1000;
					WriteProcessMemory(handle, (PBYTE*)addHealVal, &healVal, sizeof(int), 0);
				}
				if (numGum < 5)
				{
					numGum = 1000;
					WriteProcessMemory(handle, (PBYTE*)addGum, &numGum, sizeof(int), 0);
				}
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
