#include <iostream>
#include <Windows.h>
#include <vector>
#include <limits>
#include <TlHelp32.h>
#include <cstdint>
#include "memory.hpp"
#include "process.hpp"
#include "initialize.hpp"
#include "sigs.hpp"
#include "writereadFunc.hpp"
#include "hacks.hpp"
#include <stdlib.h>
int main()
{
	bool isScore{ false }, isTaikoMania{ false };
	init::Initialize();
	bool noErrors{ false };
	const unsigned char subSignature[] = { 0x55, 0x8B,0xEC, 0x57,0x56,0x53,0x83,0xEC,0x00,0x8B,0xF1,0x80,0xBE,0x00,0x00,0x00,0x00,0x00,0x75 };
	const unsigned char taikomaniaSignature[] = { 0xE8, 0x00,0x00,0x00,0x00,0x85,0xC0,0x74,0x00,0xC6,0x05,0x00,0x00,0x00,0x00,0x00,0x8B,0x45 };
	HANDLE hProcess{ 0 };
	uintptr_t moduleBase{ 0 };
	DWORD processId{ process::getProcessId(L"osu!.exe") };

	if (processId) {
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, processId);
		moduleBase = process::getModuleBaseAddress(processId, L"osu!.exe");
		noErrors = true;
	}
	else
	{
		system("CLS");
		std::cout << "Open osu! first!\n";
		getchar();
		return 0;
	}

	if (noErrors) {
		std::cout << "Initializing...\n";
		uintptr_t submitAddress{}, taikomaniaAddress{};
		DWORD dwExit{ 0 };
		submitAddress = sigs::findPattern(hProcess, subSignature, "xxxxxxxx?xxxx?????x", 0x0);
		taikomaniaAddress = sigs::findPattern(hProcess, taikomaniaSignature, "x????xxx?xx?????xx", 0xF);
		if (submitAddress == 0) {
			system("CLS");
			std::cout << "Enter at least 1 map before running cheat!\n";
			getchar();
			return 0;
		}
