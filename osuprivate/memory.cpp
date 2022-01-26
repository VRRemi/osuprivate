#include "memory.hpp"

void memory::PatchMemory(BYTE* destination, BYTE* source, unsigned int size, HANDLE hProcess) {
	DWORD oldProtect;
	VirtualProtectEx(hProcess, destination, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(hProcess, destination, source, size, nullptr);
	VirtualProtectEx(hProcess, destination, size, oldProtect, &oldProtect);
}