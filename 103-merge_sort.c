#include "sort.h"
void merge_sort_recursive(int *array, size_t left, size_t right);
void merge_sort(int *array, size_t size);
/**
 * merge - two subarrays are merged
 * @array: array to be sorted
 * @left: left subarray starting index
 * @mid: left subarray ending index
 * @right: right subarray ending index
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t left_size = mid - left + 1;
	size_t right_size = right - mid;
	int *left_array = malloc(left_size * sizeof(int));
	int *right_array = malloc(right_size * sizeof(int));

	if (left_array == NULL || right_array == NULL)
	{
		free(left_array);
		free(right_array);
		return;
	}

	for (i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < right_size; j++)
		right_array[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array + left, right - left + 1);

	free(left_array);
	free(right_array);
}

/**
 * merge_sort_recursive - recurse func
 * @array: array to be sorted
 * @left: starting index of current subarray
 * @right: ending index of current sub-array
 */

void merge_sort_recursive(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + left, mid - left + 1);
		printf("[right]: ");
		print_array(array + mid + 1, right - mid);

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - array of integers is sorted
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
