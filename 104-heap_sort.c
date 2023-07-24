#include "sort.h"
void heapify(int *array, size_t size, size_t index, size_t len);
/**
 * heapify - an array is converted to max heap
 * @array: the array
 * @size: array size
 * @index: current element index
 */

void heapify(int *array, size_t size, size_t index, size_t len)
{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;
	int temp;

	if (left < len && array[left] > array[largest])
		largest = left;

	if (right < len && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, size, largest, len);
	}
}

/**
 * heap_sort - an array of integers is sorted
 * @array: array
 * @size: array size
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0, i);
	}
}
