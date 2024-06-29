#define CRT_ADDR(X, Y, Z) ((X + (Y * Z)))

struct STRUCT_ONE
{
	unsigned short short_0xC; // 0xC
	unsigned short short_0x12; // 0x12
	unsigned int int_0x20; // 0x20
	unsigned int int_0x28; // 0x28
	unsigned short short_0x34; // 0x34
	unsigned short short_0x36; // 0x36
	unsigned short short_0x3A; // 0x3A
	unsigned int int_0x40; // 0x40
	// possibly array size?
	signed short short_0x5A; // 0x5A
}

struct STRUCT_TWO
{
	unsigned int int_0x84; // 0x84
}

struct STRUCT_THREE
{
	unsigned short short_0x5C; // 0x5C
}

DWORD __stdcall mystery11(STRUCT_ONE* pStructOne, PVOID pBuffer, DWORD arg2)
{
	// gets struct two by offsetting struct one
	STRUCT_TWO* pStructTwo = pStructOne + (pStructOne->short_0x5A * 4);
	// checks if a member is zero
	if (pStructOne->short_0x3A == 0)
	{
		// gets the third structure
		STRUCT_THREE* pStructThree = pStructOne + (pStructOne->short_0x5A * 2);
		// gets a byte array by offsetting and address stored in the first array
		PBYTE pChar = pStructOne->int_0x40 + (pStructOne->short_0xC + (pStructThree->short_0x5C * 2));
		// gets the memory region size
		DWORD dwSize = pStructTwo->int_0x84;
		// gets the output buffer address
		PVOID pBuffer = pStructOne->int_0x40 + (pStructOne->short_0x12 & (pChar[1] | (pChar[0] * 256)));
		// gets the data address to copy to the new buffer 
		PVOID pData = &pStructOne->int_0x20;
		// calls the function with the defined arguments
		// could this be memcpy?
		sub_101651C(dwSize, pBuffer, pData);
	}
	// gets the value
	DWORD value = 0;
	// if an attribute of a structure within the second structure is null
	if (*(BYTE*)(pStructTwo->int_0x84 + 2) == 0)
		// sets the value
		value = pStructOne->int_0x20;
	// stores the result
	DWORD result = (pStructOne->short_0x34 + pStructOne->int_0x28);

	DWORD r3 = pStructOne->short_0x36;
	// checks if arg2 exists
	if (arg2 != 0)
	{
		result += value;
		r3 -= value; 
	}
	// stores r3 in the buffer
	*(DWORD*)pBuffer = r3;
	// returns the result
	return result;
}