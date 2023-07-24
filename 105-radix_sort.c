#include "sort.h"
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);

/**
 * get_max - finds maximum int
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

/**
 * count_sort - performs counting based on significant digits
 */
void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] -1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - sorts array of ints
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
