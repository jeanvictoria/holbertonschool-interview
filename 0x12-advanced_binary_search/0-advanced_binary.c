#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"


/**
 * search - Entry point
 * @array: pointer to first element of array
 * @size: num of elements im array
 * @value: value to search for
 *
 * Return: Always EXIT_SUCCESS
 */
int search_list(int *array, size_t size, int value)
{
	size_t iter;
	size_t left;
	size_t right;

	left = (size / 2);
	right = (size / 2 - 1);


	if (size == 1 && array[0] == value)
		return (array[0]);
	printf("Searching in array: %d", array[0]);
	/* print loop */
	for (iter = 1; iter < size; iter++)
		printf(", %d", array[iter]);
	printf("\n");

	if (right >= left)
		{
		if (array[right] >= value)
			return (advanced_binary(array, left + size % 2, value));
		else
			return (advanced_binary(array + left + size % 2, left, value));
		}
	return (-1);
}


/**
 * advanced_binary - Entry point
 * @array: pointer to first element of array
 * @size: num of elements im array
 * @value: value to search for
 *
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{

	/*int *val_address;*/


	if (array == 0)
		return (-1);
	if (size <= 0)
		return (-1);

	/*val_address = search_list(array, size, value);*/
	/* if element not present in the array*/
	/*if (val_address == NULL)*/
		/*return (-1);*/
	return (search_list(array, size, value));
}
