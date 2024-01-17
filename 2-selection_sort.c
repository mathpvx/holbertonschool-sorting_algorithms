#include "sort.h"
/**
 * selection_sort - sorts an array of int using selection sort
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	/**outer loop*/
	for (i = 0; i < size - 1; i++)
	{
		/**store index into min so it starts at the unsorted part*/
		min = i;
		/**inner loop that initializes j */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			/**SWAP*/
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
	}
}
