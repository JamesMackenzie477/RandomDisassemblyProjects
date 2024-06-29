// disassembly of ObFastDereferenceObject

VOID ObFastDereferenceObject(PVOID Uno, QWORD Dos)
{
	// stores the byte at the address in the cache
	_m_prefetchw(Uno);

	if ((*(QWORD*)Uno ^ Dos) >= 0x0F)
	{
		ObfDereferenceObject(Dos);
	}

	if (*(QWORD*)Uno == *(QWORD*)Uno)
	{
		*(QWORD*)Uno = ((QWORD)Uno + 1)
		return 0;
	}

	if ((*(QWORD*)Uno ^ Dos) >= 0x0F)
	{
		ObfDereferenceObject(Dos)
	}

	goto ObfDereferenceObject + 0x15;
}