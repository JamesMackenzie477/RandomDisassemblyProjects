#define STATUS_SUCCESS 0x0
#define STATUS_INVALID_PARAMETER 0xC000000D

typedef struct _UNICODE_STRING
{
	BYTE __BYTE__0x0__; // 0x0
	char __PADDING__0x1__[0x1]; // 0x1
	WORD __WORD__0x2__; // 0x2
	char __PADDING__0x3__[0x6];
	QWORD __QWORD__0x8__; // 0x8
} UNICODE_STRING, *PUNICODE_STRING;


NTSTATUS RtlUnicodeStringValidateEx(PUNICODE_STRING pUnicodeString, DWORD arg2)
{
	// overwrites the second argument?
	arg2 = 0x7FFF;
	// validates the unicode string pointer
	if (pUnicodeString)
	{
		if (*(BYTE*)pUnicodeString == 0x1)
		{
			if (*(WORD*)(pUnicodeString + 0x2) == 1)
			{
				if (*(WORD*)(pUnicodeString + 0x2) >= *(WORD*)pUnicodeString)
				{
					if (arg2 <= 0xFFFE)
					{
						if (*(QWORD*)(pUnicodeString + 0x8) == 0)
						{
							if (*(WORD*)pUnicodeString == 0)
							{
								if ((WORD)arg2 == 0x0)
								{
									return STATUS_SUCCESS;
								}
							}
						}
						else
						{
							return STATUS_SUCCESS;
						}
					}
				}
			}
		}
	}
	else
	{
		return STATUS_SUCCESS;
	}
	return STATUS_INVALID_PARAMETER;
}

NTSTATUS RtlValidateUnicodeString(DWORD arg1, PUNICODE_STRING pUnicodeString)
{
	if (arg1 == 0)
	{
		return RtlUnicodeStringValidateEx(arg2, 0x100);
	}
	else
	{
		return STATUS_INVALID_PARAMETER;
	}
}