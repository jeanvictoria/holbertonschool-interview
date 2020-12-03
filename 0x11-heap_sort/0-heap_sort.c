#include "sort.h"

/**
 * swap - Function to swap elements
 * @array: array to swap
 * @a: swap element 1
 * @b: swap element 2
 * Return: Nothing (void)
 */

void swap(int *array, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * child - Function to check and assign children in right place
 * @array: array to use
 * @size: size of array
 * @last: last index of heap created
 * @max: current index element of the heap
 * Return: Nothing (void)
 */

void child(int *array, size_t size, size_t last, size_t max)
{
	size_t l_child, r_child, max_child = 0;

	l_child = 2 * max + 1;
	r_child = 2 * max + 2;

	if (l_child > last)
		return;
	if (r_child <= last && array[r_child] > array[l_child])
		max_child = r_child;

	else
		max_child = l_child;

	if (array[max_child] > array[max])
	{
		swap(array, max_child, max);
		print_array(array, size);
		child(array, size, last, max_child);
	}

}

/**
 * heap - Function to recursively sort for heap_sort
 * @array: array to be sorted
 * @size: size of the array
 * @last: last index of the heap
 * Return: Nothing (void)
 */

void heap(int *array, size_t size, size_t last)
{
	if (last == 0)
		return;
	swap(array, 0, last);
	print_array(array, size);
	last--;
	child(array, size, last, 0);
	heap(array, size, last);
}

/**
 * max_heap - Function that build the heap
 * @array: array to use
 * @size: size of the array
 * Return: Nothing (void)
 */
void max_heap(int *array, size_t size)
{
	int max;

	for (max = (size - 1) / 2; max >= 0; max--)
		child(array, size, size - 1, max);
}

/**
* heap_sort - Function that sorts an array of integers in ascending order
* using the Heap sort algorithm
* @array: array of integers to sort
* @size: size of the array
* Return: Nothing (void)
*/

void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	max_heap(array, size);
	heap(array, size, size - 1);
}
