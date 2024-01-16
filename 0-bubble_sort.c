#include "sort.h"
/**
 * bubble_sort - sorts the array with bubble sorting
 * @array: array of numbers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/**swap*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
