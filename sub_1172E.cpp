#include <Windows.h>

struct EAX
{
	DWORD __DWORD_0x8__; // 0x8
	DWORD __DWORD_0x3C__; // 0x3C
};

// appears to pass one argument in eax
void __fastcall sub_1172E(
	PVOID arg1,	// @ecx
	PVOID arg2,	// @edx
	DWORD arg3,	// @[esp]
	EAX* pEax)	// @eax?
{
	// --------------- this could be a switch ---------------
	// decrements the third argument
	arg3--;
	// checks if the value is equal to zero
	if (arg3 == 0)
	{
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x40 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x40;
		// returns from the function
		return;
	}
	// decrements the third argument
	arg3--;
	// checks if the value is equal to zero
	if (arg3 == 0)
	{
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x44 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x44;
		// returns from the function
		return;
	}
	// decrements the third argument
	arg3--;
	// checks if the value is equal to zero
	if (arg3 == 0)
	{
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x44 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x5E;
		// returns from the function
		return;
	}
	// decrements the third argument by 9
	arg3 -= 0x9;
	// checks if the value is not equal to zero
	if (arg3 != 0)
	{
		return;
	}
	// right shifts a value at an offset of eax and stores it at the first pointer
	*(DWORD*)arg1 = pEax->__DWORD_0x8__ >> 1;
	// increments the eax pointer by 0x44 and stores it at the second pointer
	*(DWORD*)arg2 = pEax += 0xC;
	// returns from the function
	return;
}


// uses a custom calling convention
// arguments passed in eax, ecx, edx and stack
void sub_1172E(PVOID arg1, PVOID arg2, DWORD dwValue, EAX* pEax)
{
	// checks the value of the third argument
	switch (dwValue)
	{
	case 0x1:
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x40 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x40;
		// breaks out of the switch
		break;
	case 0x2:
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x44 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x44;
		// breaks out of the switch
		break;
	case 0x3:
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x3C__ >> 1;
		// increments the eax pointer by 0x44 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0x5E;
		// breaks out of the switch
		break;
	case 0xC:
		// right shifts a value at an offset of eax and stores it at the first pointer
		*(DWORD*)arg1 = pEax->__DWORD_0x8__ >> 1;
		// increments the eax pointer by 0x44 and stores it at the second pointer
		*(DWORD*)arg2 = pEax += 0xC;
		// breaks out of the switch
		break;
	}
	// returns from the function
	return;
}