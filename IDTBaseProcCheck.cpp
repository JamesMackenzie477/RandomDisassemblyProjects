// function entry
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	BYTE[6] IDT; // @[ebp-8] = sidt fword ptr
	// gets the last 4 bytes of the 6 byte IDT variable (the IDT base address)
	IDTBaseAddress = *(DWORD*)IDT[2]
	// checks if the base address is between 0x8003F400-0x80047400
	if (IDTBaseAddress > 0x8003F400)
	{
		if (IDTBaseAddress < 0x80047400)
		{
			return FALSE;
		}
	}
	// creates a process entry structure for use with process iteration
	PROCESSENTRY32 lppe; // @[ebp-130h]
	// zeroes out the structure
	// ZeroMemory(&lppe, sizeof(PROCESSENTRY32));
	// takes a snapshot of processes
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL)
	// validates the snapshot
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	// sets the size attribute of the structure
	lppe.dwSize = sizeof(PROCESSENTRY32);
	// gets the first process snapshot
	if (Process32First(hSnapshot, &lppe))
	{
		return FALSE;
	}
	// compares the executable name of the process with a const char*
	if (_stricmp(&lppe.szExeFile, (const char*)0x10007C50))
	{
		// gets the next process snapshot
		while (Process32Next(hSnapshot, &lppe))
		{
			// compares the executable name of the process with a const char*
			if (_stricmp(&lppe.szExeFile, (const char*)0x10007C50) == 0)
			{
				break;
			}
		}
		else
		{
			return FALSE;
		}
	}
	// compares the process id with it's parent
	if (lppe.th32ProcessID == lppe.th32ParentProcessID)
	{
		return FALSE;
	}
	
	fdwReason--;
	if (fdwReason == 0)
	{
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)0x100032D0, NULL, NULL NULL);
	}
	return TRUE;
}