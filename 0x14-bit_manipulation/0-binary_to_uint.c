#include "main.h"

/**
 * binary_to_unit - Function to convert a binary string to an unsigned integer
 * @b: Pointer to a null-terminated string of '0' and '1' characters
 * Return: The converted integer value, or 0 if the string is invalid
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
	}
	return (dec_val);
}
