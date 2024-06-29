// the function takes three arguments
// first argument is passed in ecx
// the second is passed in eax
// the rest are passed on the stack
// this indicates a custom calling convention
// could be __fastcall or __thiscall but edx is not used
// potentially checks if the given player is an enemy or an ally
DWORD CheckPlayer(
	DWORD dwUnknown,	// @ecx an unknown dword
	PVOID pPlayer,		// @eax a pointer to the player structure
	LPCSTR lpType,		// @[esp] the type to test the player for
	LPCSTR lpUnknown)	// @[esp+4] an unknown string
{

}

// NetworkManager seems to be a class for managing the network packets
// could be used to hijack the player location
// look into cfg reading
// look into wpg file opening