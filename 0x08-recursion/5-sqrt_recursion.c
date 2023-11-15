#include "main.h"

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number, or -1 if it does not exist.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (sqrt_recursive(n, 1, n));
}

/**
 * sqrt_recursive - Helper function for recursive calculation of square root.
 * @n: The number to calculate the square root of.
 * @start: The starting point for the search.
 * @end: The ending point for the search.
 *
 * Return: The natural square root of the number, or -1 if it does not exist.
 */
int sqrt_recursive(int n, int start, int end)
{
	int mid = (start + end) / 2;

	if (start <= end)
	{
		if (mid * mid == n)
			return (mid);
		if (mid * mid < n)
			return (sqrt_recursive(n, mid + 1, end));

		return (sqrt_recursive(n, start, mid - 1));
	}
	return (end);
}
