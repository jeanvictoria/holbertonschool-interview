#include "search_algos.h"

/**
 * advanced_binary - search the value into the array
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located, otherwise -1 on failure
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t i, half, idx = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}

	if (size == 1 && array[0] != value)
		return (-1);

	half = (size - 1) / 2;

	if (array[half] == value)
	{
		if (array[half - 1] < value)
			return (half);
	}

	if (array[half] < value)
	{
		idx += half + 1;
		array += half + 1;
		if (size % 2 != 0)
			half--;
	}

	half++;
	tmp = advanced_binary(array, half, value);
	if (tmp != -1)
		return (tmp + idx);

	return (-1);
}
