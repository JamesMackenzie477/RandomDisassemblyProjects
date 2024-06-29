typedef struct _THREAD
{
	char __PADDING_0x0__[0x70]; // 0x0
	PSYSTEM __0x70__; // 0x70
} THREAD, *PTHREAD;

typedef struct _SYSTEM
{
	char __PADDING_0x0__[0xDC]; // 0x0
	DWORD __0xDC__; // 0xDC
} SYSTEM, *PSYSTEM;

VOID KeReadyThread(PTHREAD pThread) // @rcx
{
	if ((BYTE)pThread->__0x70__->__0xDC__ != 0x7)
	{
		if (!(BYTE)KiInSwapSingleProcess())
		{
			return;
		}
	}
	KiFastReadyThread(pThread);
}