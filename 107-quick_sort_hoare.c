#include "sort.h"
size_t hoare_partition(int *array, size_t low, size_t high);
void quick_sort_hoare_recursive(int *array, size_t low, size_t high);

/**
 * quick_sort_hoare - an array of inters is sorted
 * @array: array to be sorted
 * @size: total no of elements in an array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1);
}

/**
 * hoare_partition - array is partitioned
 * @array: array to partition
 * @low: first element of the partitioned array
 * @high: last element of the partitioned array
 * Return: index of pivot element after partitioning
 */
size_t hoare_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i = low - 1, j = high + 1;
	int temp;

	while (1)
	{
		do {
			i++;
		} while (i < high && array[i] < pivot);

		do {
			j--;
		} while (j > low && array[j] > pivot);

		if (i >= j)
			return j;

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		print_array(array, high + 1);
	}
}

/**
 * quick_sort_hoare_recursive - recursively sorts
 * @array: array to be sorted
 * @low: subarray first element index
 * @high: subarray last element index
 */

void quick_sort_hoare_recursive(int *array, size_t low, size_t high)
{
	size_t pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high);

		if (pivot > 0)
			quick_sort_hoare_recursive(array, low, pivot);
		quick_sort_hoare_recursive(array, pivot + 1, high);
	}
}
