#include "sort.h"
void quick_sort_recursive(int *array, int low, int high);
int lomuto_partition(int *array, int low, int high);

/**
 * swap - two integers are swapped
 * @a: first int pointer
 * @b: second int pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort - uses quick sort to sort an array of integers
 * @array: array to sort
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - helper recursive function
 * @array: array to be sorted
 * @low: starting index of partition
 * @high: end endex of partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	
	if (low < high)
	{
		int partition = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, partition - 1);
		quick_sort_recursive(array, partition + 1, high);
	}
}

/**
 * lomuto_partition - partition scheme for quick sort
 * @array: array to be partitioned
 * @low: start index of partition
 * @end: end index of partition
 * Return: index of pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}

	return (i + 1);
}
