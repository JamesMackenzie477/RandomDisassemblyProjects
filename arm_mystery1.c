#include <Windows.h>

// defines the ascii codes
#define ASCII_MINUS 0x2D
#define ASCII_PLUS 0x2B
#define ASCII_ZERO 0x30

// defines a few constant functions
#define VALID(I) (((I >= 0 && I <= 0x9)))
#define TO_INT(I) (((I - 0x30)))

// function definition for mystery1
// two arguments passed in the 32 bit registers r0 and r1
// first argument is a const char array
bool mystery1(const char* string, PVOID pStore)
{
	// is the number negative
	bool minus;
	// compares the first character to the ascii minus code
	if (string[0] == ASCII_MINUS)
	{
		// increments the char pointer by one byte
		string++;
		// sets minus to true
		minus = true;
	}
	else
	{
		// sets minus to false
		minus = false;
		// compares the first character to the ascii plus code
		if (string[0] == ASCII_PLUS)
			// increments the char pointer by one byte
			string++;
	}
	// iterates through the characters while the ascii code is zero
	// this gets to the end of the zeros in the string
	while (string[0] == ASCII_ZERO)
		// increments the char pointer by one byte
		string++;
	// stores the result
	unsigned long long result = 0;
	// stores an index for the char array
	unsigned int index = 0;
	// converts the ascii code into the integer value it represents
	unsigned int value = TO_INT(string[index]);
	// enters a while loop and checks if it's a valid integer value
	while (VALID(value))
	{
		// checks if the counter is not equal to 0xB
		if (index != 0xB)
			// adds the integer value to the result
			result = (result * 0xA) + value;
			// increments the char index
			index++;
			// converts the ascii code into the integer value it represents
			value = TO_INT(string[index]);
		else
			// function failed
			return false;
	}

	if (value - minus >= 0)
		// function failed
		return false;
	// if the input value was negative
	if (minus != 0)
		// subtracts the value from zero
		value = 0 - value;
	// stores the result in the second argument pointer
	*(int*)pStore = result;
	// function succeeded
	return true;
}