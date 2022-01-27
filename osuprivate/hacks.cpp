#include "hacks.hpp"
void hacks::enableScoreSub(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\x55", 1, hProcess);
}

