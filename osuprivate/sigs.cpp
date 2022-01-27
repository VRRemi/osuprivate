#include "sigs.hpp"
uintptr_t sigs::findPattern(HANDLE hProcess, const unsigned char pattern[], const char* mask, const int offset) {
	const size_t signature_size = strlen(mask);
	const size_t read_size = 4096;
	const size_t beginAddress = 0x04000000;
	bool isFound = false;
