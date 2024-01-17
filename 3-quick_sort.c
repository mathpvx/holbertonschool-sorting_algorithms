#include "sort.h"

int partition(int *array, size_t start, size_t end);
void quick_sort_bis(int *array, size_t start, size_t end);
/**
 * quick_sort - calls the quick_sort_bis function with right parameters
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{	
	if (array == NULL || size < 2)
		return;

	quick_sort_bis(array, 0, size - 1);
}
/**
 * partition - segments the array in 2 sub-array
 * @array: the array to sort
 * @start: the first element of the array
 * @end: the last element of the array
 */
int partition(int *array, size_t start, size_t end)
{
	size_t i, j, temp;
	int pivot;

	pivot = array[end];
	i = start - 1;

	for (j = start; j <= end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/**swap*/
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;

	return (i + 1);
}
/**
 * quick_sort_bis - double recursive to sort left and right sub-arrays
 * @start: first element
 * @end: last element
 */
void quick_sort_bis(int *array, size_t start, size_t end)
{
	size_t pi;

	if (start < end)
	{
	pi = partition(array, start, end);

	quick_sort_bis(array, start, pi - 1);
	quick_sort_bis(array, pi + 1, end);
	}
}
