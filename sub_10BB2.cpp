#include <Windows.h>

// defines the map section function
typedef bool __cdecl MapSection(PIMAGE_SECTION_HEADER pSectionHeader, DWORD arg2);

// decompilation of sub_10BB2
// only one argument that is passed on the stack
// function doesn't seem to clean stack before returning
PVOID __stdcall MapImageSections(PIMAGE_DOS_HEADER pImageBase, DWORD arg2)
{
	// gets the nt headers of the image
	PIMAGE_NT_HEADERS pNtHeaders = (LPBYTE)pImageBase + pImageBase->e_lfanew;
	// gets the section headers array
	PIMAGE_SECTION_HEADER pSectionHeader = (LPBYTE)&pNtHeaders->OptionalHeader + pNtHeaders->FileHeader.SizeOfOptionalHeader;
	// verifies sections exist
	if (pNtHeaders->NumberOfSections > 0)
	{
		// loop counter
		DWORD dwCounter = 0;
		// iterates through the sections
		do
		{
			// maps the section? dword_169A4
			if (MapSection(pSectionHeader, arg2))
			{
				// gets the next section header
				PIMAGE_SECTION_HEADER pSectionHeader = (PIMAGE_SECTION_HEADER)((LPBYTE)pSectionHeader + 0x28);
				// increments the counter
				dwCounter++;
			}
			else
			{
				// returns the pointer to the section header
				return pSectionHeader;
			}
		} while (pNtHeaders->NumberOfSections < dwCounter);
	}
	// function failed?
	return 0;
}