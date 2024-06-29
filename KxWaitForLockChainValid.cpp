VOID KxWaitForLockChainValid(PVOID rcx)
{
	// initalizes the count at zero
	DWORD count = 0;
	// while the qword at rcx is null
	while (*(QWORD*)rcx == 0x0)
	{
		// increments the count
		count++;
		// compares global HvlLongSpinCountMask with the count
		if (*(DWORD*)0xfffff80002f0833c == count)
		{
			// compares global HvlEnlightenments with 0x40
			if (*(BYTE*)0xfffff80002f08068 != 0x40)
			{
				HvlNotifyLongSpinWait(count);
				// continues from the top of the loop
				continue;
			}
		}
		// asm pause
		YieldProcessor();
	}
}