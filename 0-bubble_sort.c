#include "sort.h"

/**
 * bubble_sort - sorst and array of integers in ascending order using the
 * bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, j_limit;
	int aux;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		for (j = 0, j_limit = size - i - 1; j < j_limit; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				print_array(array, size);
			}
		}
}
