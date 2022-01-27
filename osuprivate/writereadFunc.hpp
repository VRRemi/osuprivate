#pragma once
#include "memory.hpp"

template <typename T>
bool writeMem(uintptr_t address, T value, HANDLE hProcess) {
	return WriteProcessMemory(hProcess, (LPVOID)(address), &value, sizeof(value), nullptr);
}

template <typename T>
T readMem(uintptr_t address, HANDLE hProcess) {
	T value{};
	ReadProcessMemory(hProcess, (LPVOID)(address), &value, sizeof(value), nullptr);
	return value;
}