#include "memory.hpp"

void memory::PatchMemory(BYTE* destination, BYTE* source, unsigned int size, HANDLE hProcess) {
	DWORD oldProtect;
	VirtualProtectEx(hProcess, destination, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(hProcess, destination, source, size, nullptr);
	VirtualProtectEx(hProcess, destination, size, oldProtect, &oldProtect);
}

void memory::NopMemory(BYTE* destination, unsigned int size, HANDLE hProcess) {
	BYTE* nopArr{ new BYTE[size] };
	memset(nopArr, 0x90, size);
	PatchMemory(destination, nopArr, size, hProcess);
	delete[] nopArr;
}

void memory::enable_debug_privilege()
{
	HANDLE h_token{};
	TOKEN_PRIVILEGES token_privileges{};
	LUID uid_debug;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &h_token) != FALSE)
	{
		if (LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &uid_debug) != FALSE)
		{
			token_privileges.PrivilegeCount = 1;
			token_privileges.Privileges[0].Luid = uid_debug;
			token_privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			AdjustTokenPrivileges(h_token, FALSE, &token_privileges, 0, nullptr, nullptr);
		}
	}
	CloseHandle(h_token);
}
