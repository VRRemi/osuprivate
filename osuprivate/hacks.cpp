#include "hacks.hpp"
void hacks::enableScoreSub(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\x55", 1, hProcess);
}

void hacks::disableScoreSub(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\xC3", 1, hProcess);
}

void hacks::enableTaikoManiaBypass(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\x00", 1, hProcess);
}

/*void hacks::disableTaikoManiaBypass(uintptr_t address, HANDLE hProcess) {
	memory::PatchMemory((BYTE*)address, (BYTE*)"\x01", 1, hProcess);
}*/