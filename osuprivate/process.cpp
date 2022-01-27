#include "process.hpp"

DWORD process::getProcessId(const wchar_t* processName) {
	DWORD procId{ 0 };
	HANDLE hSnap{ CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) };
	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 procEntry;
				}

}