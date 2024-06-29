#include <Windows.h>

// Program is to be run on the arm processor.
// All pointers are 32 bit.

typedef __int32 __fastcall foo(__int32);

// defines the first structure
typedef struct _ONE
{
	__int32 offset_0x0; // 0x0
	__int32 offset_0x8; // 0x8 same type as TWO.offset_0x18
	__int32 offset_0xC; // 0xC
	__int16 offset_0x10; // 0x10
	__int64 offset_0x18; // 0x18
} ONE, *PONE;

// defines the second structure
typedef struct _TWO
{
	PTHREE offset_0xC; // 0xC
	__int32 offset_0x18; // 0x18 same type as ONE.offset_0x8
} TWO, *PTWO;

// defines the third structure
typedef struct _THREE
{
	PFOUR offset_0xC; // 0xC = array of structure four
} THREE, *PTHREE;

// defines the fourth structure
// sizeof() = 0x18
typedef struct _FOUR
{
	__int8 offset_0x16; // 0x16
	__int8 offset_0x17; // 0x17
} FOUR, *PFOUR;

// ARM standard calling convention is to pass the first 4 arguments in the registers r0-r3 and the rest on the stack. Same at the x64 calling convention __fastcall.
// Uses BL to call function, branches to function, saves return address in the LR (r14) register.
bool __fastcall unk_function(PONE pOne, PTWO pTwo, __int64 arg3)
{
	// LDR R5, [R0, #8]
	// LDR R4, [R1, #0x18]
	// CMP R5, R4
	if (pOne->offset_0x8 == pTwo->offset_0x18)
	{
		// LDRH R3, [R0, #0x10]
		// CMP R3, #2
		if (pOne->offset_0x10 == 2)
		{
			// LDR R3, [R0, #0x18]
			// ANDS R2, R3
			// LDR R3, [R0, #0x1C]
			// ANDS R3, R6
			// ORRS R3, R2
			// arg3 and arg4 is actually a 64 bit integer split into two registers
			// This is a common pattern used to access 64-bit constants on 32-bit architectures
			if ((pOne->offset_0x18 & arg3) == 0)
			{
				// LDR R3, [R0,#0xC]
				// ADD.W R2, R3, R3,LSL#1
				// LDR R3, [R1, #0xC]
				// LDR R3, [R3, #0xC]
				// ADD.W R3, R3, R2, LSL#3
				// LDRSB.W  R4, [R3, #0x16]
				// pOne->offset_0xC = array index aligned to 24 bytes
				__int8 r4 = pTwo->offset_0xC->offset_0xC[pOne->offset_0xC].offset_0x16;
				// LDR R0, [R0]
				// BL foo
				__int32 result = foo(pOne->offset_0x0);
				// CMP R0, #0x61
				if (result == 0x61)
				{
					// CMP R4, #0x61
					if (r4 == 0x61)
					{
						// function success
						return true;
					}
				}
				// CMP R0, #0x62
				else if (result == 0x62)
				{
					// function success
					return true;
				}
				// CMP R4, #0x63
				else if (r4 >= 0x63)
				{
					// function success
					return true;
				}
			}
		}
	}
	// function failed
	return false;
}