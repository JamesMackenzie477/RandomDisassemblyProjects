// finds the address of a certain character within a string
const char* __cdecl sub_1000CEA0(const char* string, char letter)
{
	// finds the end of the const char array
	for (int i = 0x0FFFFFFFF; i > 0; i--)
	{
		// checks if the string byte is null
		if (*(char*)string == 0x0)
		{
			// break out of the loop
			break;
		}
		// gets the next letter in the string
		string++;
	}
	// finds the character in the string

	return nullptr;
}