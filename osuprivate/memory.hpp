#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
namespace memory {
	void PatchMemory(BYTE* destination, BYTE* source, unsigned int size, HANDLE hProcess);
	void NopMemory(BYTE* destination, unsigned int size, HANDLE hProcess);
	void enable_debug_privilege();
}
