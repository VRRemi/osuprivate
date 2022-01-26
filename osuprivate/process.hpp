#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

namespace process {
	DWORD getProcessId(const wchar_t* processName);
	uintptr_t getModuleBaseAddress(DWORD processId, const wchar_t* moduleName);
	uintptr_t getPointer(HANDLE hProcess, uintptr_t pointer, std::vector<unsigned int> offsets);
}