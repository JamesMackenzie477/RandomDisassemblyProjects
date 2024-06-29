// defines the apc object structure
typedef struct _APC
{
	BYTE ByteValue1; // 0x0
	char __PADDING_1__[0x1]; // 0x1
	BYTE ByteValue2; // 0x2
	char __PADDING_2__[0x5]; // 0x3
	QWORD QwordValue1; // 0x8 : pointer to UNKNOWN object
	char __PADDING_3__[0x10]; // 0x10
	QWORD QwordValue2; // 0x20
	QWORD QwordValue3; // 0x28
	QWORD QwordValue4; // 0x30 : could be a pointer like PUNKNOWN
	QWORD QwordValue5; // 0x38 : pointer to UNKNOWN object
	QWORD QwordValue6; // 0x40
	char __PADDING_4__[0x8]; // 0x48
	BYTE ByteValue3; // 0x50
	BYTE ByteValue4; // 0x51 : first 8 bits of pointer to UNKNOWN object
	BYTE ByteValue5; // 0x52
} APC, *PAPC;

typedef struct _UNKNOWN
{
	char __PADDING_1__[0x1F0]; // 0x0
	BYTE ByteValue1; // 0x1F0
} UNKNOWN, *PUNKNOWN;

VOID KeInitializeApc(
	PAPC pApc,			// @rcx : a pointer to the apc object
	PUNKNOWN pUnknown,	// @rdx : seems to be another structure
	__int64 arg2,		// @r8
	__int64 arg3,		// @r9
	APC Apc2)			// @[rsp] : another apc object pushed on to the stack before call
{
	pAcp->ByteValue1 = 0x12;
	pApc->ByteValue2 = 0x58;

	if (arg2 == 2)
	{
		pApc->ByteValue1 = pUnknown->ByteValue1;
	}
	else
	{
		pApc->ByteValue1 = (BYTE)arg2;
	}

	pApc->QwordValue1 = pUnknown;
	pApc->QwordValue3 = Apc2.QwordValue3;
	pApc->QwordValue2 = arg3;
	pApc->QwordValue4 = Apc2.QwordValue4;

	// if the qword value 4 exists in the other structure
	if (Apc2.QwordValue4)
	{
		// set the attributes
		pApc->ByteValue4 = (BYTE)Apc2.QwordValue5;
		pApc->QwordValue5 = Apc2.QwordValue6;
	}
	else
	{
		// null the attributes
		pApc->ByteValue4 = 0x0;
		pApc->QwordValue5 = 0x0;
	}

	pApc->ByteValue5 = 0x0;
}