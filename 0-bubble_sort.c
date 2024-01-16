#include "sort.h"

/**
* bubble_sort - sort an array of integers in ascending order
* @array: pointer to an array of int to sort
* @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp = 0;
	int swap_counter = -1;

	while (swap_counter != 0)
	{
		swap_counter = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap_counter++;
				print_array(array, size);
			}
		}
	}
}
