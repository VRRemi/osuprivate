#include "sigs.hpp"
uintptr_t sigs::findPattern(HANDLE hProcess, const unsigned char pattern[], const char* mask, const int offset) {
	const size_t signature_size = strlen(mask);
	const size_t read_size = 4096;
	const size_t beginAddress = 0x04000000;
	bool isFound = false;

	unsigned char chunk[read_size]{};

	for (size_t i = beginAddress; i < 0x7F000000; i += read_size - signature_size) {
		ReadProcessMemory(hProcess, LPCVOID(i), &chunk, read_size, nullptr);

		for (size_t a = 0; a < read_size; a++) {
			isFound = true;

			for (size_t j = 0; j < signature_size && isFound; j++) {
				if (mask[j] != '?' && chunk[a + j] != pattern[j]) {
					isFound = false;
				}
			}

