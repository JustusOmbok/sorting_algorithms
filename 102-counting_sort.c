#include "sort.h"
/**
 * counting_sort - uses counting sort technique to sort integers
 * @array: array to sorted pointer
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	ssize_t j;
	int *sorted_array;
	int *counting_array;

	if (array == NULL || size <= 1)
		return;

	for (i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	printf("%d", counting_array[0]);
	for (i = 1; i <= (size_t)max; i++)
		printf(", %d", counting_array[i]);
	printf("\n");

	for (i = 1; i <= (size_t)max; i++)
		counting_array[i] += counting_array[i - 1];

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL) {
		free(counting_array);
		return;
	}

	for (j = size - 1; j >= 0; j--) {
		int index = counting_array[array[j]] - 1;
		sorted_array[index] = array[j];
		counting_array[array[j]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(counting_array);
}
