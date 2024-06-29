typedef struct _DPC
{
	BYTE Uno; // 0x0
	BYTE Dos; // 0x1
	WORD Tres; // 0x2
	BYTE __PADDING_14__[0x14]; // 0x4
	QWORD Quatro; // 0x18
	QWORD Cinco; // 0x20
	BYTE __PADDING_10__[0x10]; // 0x28
	QWORD Siete; // 0x38
} DPC, *PDPC;

VOID KeInitializeDpc(PDPC pDpcStructure, __int64 arg1, __int64 arg2)
{
	pDpcStructure->Uno = 0x13;
	pDpcStructure->Dos = 0x1;
	pDpcStructure->Quatro = arg1;
	pDpcStructure->Cinco = arg2;
	pDpcStructure->Tres = 0x0;
	pDpcStructure->Siete = 0x0;
}