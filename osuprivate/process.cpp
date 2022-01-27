#include "process.hpp"

DWORD process::getProcessId(const wchar_t* processName) {
	DWORD procId{ 0 };
	HANDLE hSnap{ CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) };
	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		if (Process32First(hSnap, &procEntry)) {
			do {
				if (!_wcsicmp(procEntry.szExeFile, processName)) {
					procId = procEntry.th32ProcessID;
					break;
				}

			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procId;
}

uintptr_t process::getModuleBaseAddress(DWORD processId, const wchar_t* moduleName) {
	uintptr_t addr{ 0 };
	HANDLE hSnap{ CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId) };
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do {
				addr = (uintptr_t)modEntry.modBaseAddr;
				break;
}