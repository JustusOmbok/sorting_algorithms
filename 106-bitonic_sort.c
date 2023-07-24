#include "sort.h"
void bitonic_merge(int *array, size_t low, size_t size, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t size, int dir);

/**
 * bitonic_merge - two halves of a bitonic sequence are merged
 * @array: array to be merged pointer
 * @low: first element of the left halve
 * @size: size of subarray
 * @dir: merge direction
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir)
{
	size_t mid;
	int temp;
	size_t i;

	if (size > 1)
	{
		mid = size / 2;
		printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array + low, size);

		for (i = low; i < low + mid; i++)
		{
			if ((array[i] > array[i + mid]) == dir)
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}
		bitonic_merge(array, low, mid, dir);
		bitonic_merge(array, low + mid, mid, dir);
	}
}

/**
 * bitonic_sort_recursive - divides the array recursively
 * @array: array to sort
 * @low: first element of subarray
 * @size: size of subarray
 * @dir: sorting direction
 */
void bitonic_sort_recursive(int *array, size_t low, size_t size, int dir)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;
		bitonic_sort_recursive(array, low, mid, !dir);
		bitonic_sort_recursive(array, low + mid, mid, dir);
		bitonic_merge(array, low, size, dir);
	}
}

/**
 * bitonic_sort - sorts an array
 * @array: array to be sorted
 * @size: total number of elements
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
