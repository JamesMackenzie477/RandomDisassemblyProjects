NTSTATUS WINAPI PsOpenProcess(_Out_ PHANDLE ProcessHandle, _In_ ACCESS_MASK DesiredAccess, _In_ POBJECT_ATTRIBUTES ObjectAttributes, _In_ PCLIENT_ID ClientId, _In_ BYTE PreviousMode, _In_ BYTE PreviousMode)
{
	DWORD Attributes; // @[rsp+0x44]
	QWORD Var1 = 0; // @[rsp+0x50]
	QWORD Var2 = 0; // @[rsp+0x58]
	// true if an object name exists
	bool ObjectName;
	// if the previous mode was the kernel
	if (PreviousMode == 0)
	{

	}
	else
	{
		// cmp qword ptr [r8+10h], rax
		// setne cl
		// checks an object name is set
		if (ObjectAttributes->ObjectName) ObjectName = true;
		else ObjectName = false;
		// mov dil, byte ptr [rsp+248h]
		// test dil, dil
		// if the previous mode was the kernel
		if (PreviousMode == 0)
			// and eax, 10FF2h
			// mov dword ptr [rsp+44h], eax
			// applies a mask to the attributes
			Attributes = (ObjectAttributes->Attributes & 0x10FF2)
		else
			// and eax, 0DF2h
			// mov dword ptr [rsp+44h], eax
			// applies a mask to the attributes
			Attributes = (ObjectAttributes->Attributes & 0x0DF2)
	}
}

NTSTATUS WINAPI NtOpenProcess(_Out_ PHANDLE ProcessHandle, _In_ ACCESS_MASK DesiredAccess, _In_ POBJECT_ATTRIBUTES ObjectAttributes, _In_ PCLIENT_ID ClientId)
{
	// reads the ethread address from the gs register
	PETHREAD pThread = __readgsqword(0x188);
	// reads the previous mode from the ethread structure
	BYTE PreviousMode = pThread->PreviousMode;
	// returns the result of open process
	return PsOpenProcess();
}


HANDLE WINAPI OpenProcess(_In_ DWORD dwDesiredAccess, _In_ BOOL bInheritHandle, _In_ DWORD dwProcessId)
{
	// recieves the process handle
	HANDLE hProcess;
	// stores the object attributes
	OBJECT_ATTRIBUTES ObjectAttributes;
	// zeroes out the object attributes
	memset(&ObjectAttributes, 0, sizeof(OBJECT_ATTRIBUTES))
	// sets the length of the object attributes
	ObjectAttributes.Length = 0x30;
	// checks the inherit handle argument
	if (bInheritHandle)
		// sets the object attributes to inherit handle
		ObjectAttributes.Attributes = OBJ_INHERIT;
	// traps to the kernel to open the process
	if (NT_SUCCESS(ZwOpenProcess(&hProcess, dwDesiredAccess, &ObjectAttributes, &dwProcessId)))
		// returns the handle
		return hProcess;
	// function failed
	return NULL;
}