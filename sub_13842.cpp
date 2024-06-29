#include <Windows.h>

// defines the first structure passed into the function sub_13842
typedef struct _FIRST
{
	BYTE __BYTE_0x23__; // 0x23
	DWORD __DWORD_0x60__; // 0x60
} FIRST, *PFIRST;

// defines the second structure passed into the function sub_13842
typedef struct _SECOND
{
	DWORD __DWORD_0x8__; // 0x8
} SECOND, *PSECOND;

// defines the third structure used in the function sub_13842
typedef struct _THIRD
{
	BYTE __BYTE_0x0__; // 0x0
	DWORD __DWORD_0x14__; // 0x14
} THIRD, *PTHIRD;

// defines the function call in sub_13842
typedef int(__stdcall * Function)(PSECOND, PFIRST);

int __fastcall sub_13842(PFIRST pFirst, PSECOND pSecond)
{
	// decrements the byte at the offset of 0x23
	pFirst->__BYTE_0x23__--;
	// gets the address to the third structure
	PTHIRD pThird = pFirst->__DWORD_0x60__ - 0x24;
	// puts the structure address into the original place
	pFirst->__PVOID_0x60__ = pThird;
	// adds the address of the second structure to an attribute of the third
	pThird->__DWORD_0x14__ = pSecond;
	// creates the function that is called
	Function pFunction = (Function)FpSecond->__DWORD_0x8__ + pThird->__BYTE_0x0__ * 4 + 0x38;
	// calls the function and returns the result
	return pFunction(pSecond, pFirst);
}