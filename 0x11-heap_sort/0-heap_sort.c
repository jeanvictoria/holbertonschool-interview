
#include "sort.h"

/**
 * sift_down - sorts an array of integers in ascending order
 * @array: list to be sorted
 * @size: length of array
 * @root: num
 *
 *
 * Return: Always 0
 */
void sift_down(int *array,  size_t size, size_t root, size_t last)
{
	int interim = 0;
	int key;

	size_t bignum = root * 2;

	if ((bignum <= size) && (array[root - 1] < array[bignum - 1]))
		interim = bignum - 1;
	if (bignum + 1 <= size && array[root - 1] < array[bignum]
		&& array[bignum - 1] < array[bignum])
		interim = bignum;
	/* swap algorithm */
	if (interim)
	{
		key = array[interim];
		array[interim] = array[root - 1];
		array[root - 1] = key;
		/* print after each swap */
		print_array(array, size);
		sift_down(array, size, 1, last);

	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: list of int to sort
 * @size: length of array
 *
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{
	size_t idx;
	int temp;
	size_t hlast = size;
	/*size_t root = 0;*/

	/*for (idx = (size - 2) / 2; idx > 0; idx--)*/
	for (idx = (size / 2); idx >= 1; idx--)
	{
		sift_down(array, size, idx, hlast);
	}
	for (idx = 0; idx < size; idx++)
	{
		temp = array[size - idx - 1];
		array[size - idx - 1] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, size, 1, hlast);
	}
}
