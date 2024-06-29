typedef struct _LIST_ENTRY
{
	PLIST_ENTRY Flink; // 0x0
	PLIST_ENTRY Blink; // 0x8
} LIST_ENTRY, *PLIST_ENTRY;

typedef struct _QUEUE
{
	BYTE __0x0__; // 0x0
	BYTE __0x1__; // 0x1
	BYTE __0x2__; // 0x2
	char __PADDING__0x1__; // 0x3
	DWORD __0x4__; // 0x4
	LIST_ENTRY __0x8__; // 0x8
	LIST_ENTRY __0x18__; // 0x18
	DWORD __0x28__; // 0x28
	DWORD __0x2C__; // 0x2C
	LIST_ENTRY __0x30__; // 0x30
} QUEUE, *PQUEUE;

VOID KeInitializeQueue(PQUEUE pQueue, DWORD arg2)
{
	pQueue->__0x0__ = 0x4;
	pQueue->__0x2__ = 0x10;
	pQueue->__0x1__ = 0x0;
	pQueue->__0x4__ = 0x0;

	// initalizes the linked list head
	pQueue->__0x8__->Blink = &pQueue->__0x8__;
	pQueue->__0x8__->Flink = &pQueue->__0x8__;

	// initalizes the linked list head
	pQueue->__0x18__->Blink = &pQueue->__0x18__;
	pQueue->__0x18__->Flink = &pQueue->__0x18__;

	// initalizes the linked list head
	pQueue->__0x30__->Blink = &pQueue->__0x30__;
	pQueue->__0x30__->Flink = &pQueue->__0x30__;

	pQueue->__0x28__ = 0x0;

	if (arg2)
	{
		pQueue->__0x2C__ = arg2;
	}
	else
	{
		pQueue->__0x2C__ = *(DWORD*)0xfffff80002f0800c; // nt!KeNumberProcessors
	}
}