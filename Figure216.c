// fills a buffer with various system information
// probably a class method since the first argument is not used
DWORD __stdcall GetSystemInfo(DWORD dwUnknown, DWORD dwSize, LPVOID lpBuffer)
{
	// sets the buffer offset
	DWORD offset = 0;
	// checks the buffer size
	if (dwSize > sizeof(SYSTEMTIME))
	{
		// gets the system time
		GetSystemTime((LPSYSTEMTIME)lpBuffer);
		// sets the buffer offset
		offset += sizeof(SYSTEMTIME);
	}
	// checks if the remaining buffer size can store a dword
	if ((dwSize - offset) > sizeof(DWORD))
	{
		// gets the current process id
		*(DWORD*)((LPBYTE)lpBuffer + offset) = GetCurrentProcessId();
		// increments the buffer offset
		offset += sizeof(DWORD);
	}
	// checks if the remaining buffer size can store a dword
	if ((dwSize - offset) > sizeof(DWORD))
	{
		// gets the tick count
		*(DWORD*)((LPBYTE)lpBuffer + offset) = GetTickCount();
		// increments the buffer offset
		offset += sizeof(DWORD);
	}
	// checks if the remaining buffer size can store a qword
	if ((dwSize - offset) > sizeof(LARGE_INTEGER))
	{
		// queries the performance counter
		QueryPerformanceCounter((LARGE_INTEGER*)((LPBYTE)lpBuffer + offset))
		// increments the buffer offset
		offset += sizeof(LARGE_INTEGER);
	}
	// returns the amount of data stored in bytes
	return offset;
}