#pragma once
#include "memory.hpp"
namespace hacks {
	void enableScoreSub(uintptr_t address, HANDLE hProcess);
	void disableScoreSub(uintptr_t address, HANDLE hProcess);
	void enableTaikoManiaBypass(uintptr_t address, HANDLE hProcess);
	//void disableTaikoManiaBypass(uintptr_t address,  HANDLE hProcess);
}
