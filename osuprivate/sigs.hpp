#pragma once
#include <Windows.h>
namespace sigs {
	uintptr_t findPattern(HANDLE hProcess, const unsigned char pattern[], const char* mask, const int offset);
}