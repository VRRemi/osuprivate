#include "hacks.hpp"
void hacks::enableScoreSub(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\x55", 1, hProcess);
}

void hacks::disableScoreSub(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\xC3", 1, hProcess);
}

