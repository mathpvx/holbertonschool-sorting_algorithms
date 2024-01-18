#include "sort.h"

/**
 * partition - parts an array in two subarrays
 * @array: array to partition
 * @size: size of the array
 * @start: index at the beginning of the array
 * @end: index at the end of the array
 *
 * Return: the pivot's position
 */

int partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = (start - 1);
	int j, temp = 0;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	if (end != (i + 1))
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - recursively sort the subarrays
 * @array: array to partition and sort
 * @size: size of the array
 * @start: index at the start of the array
 * @end: index at the end of the array
 *
 * Return: void
 */

void quick_sort_recursive(int *array, size_t size, int start, int end)
{
	int pivot_index;

	if (end <= start)
		return;
	pivot_index = partition(array, size, start, end);
	quick_sort_recursive(array, size, start, pivot_index - 1);
	quick_sort_recursive(array, size, pivot_index + 1, end);
}

/**
 * quick_sort - sorts an array of integer in ascending order
 * @array: array of int to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, start, end);
}
