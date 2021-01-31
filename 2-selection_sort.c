#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, j_swap;
	int aux;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		j_swap = i;
		for (j = i + 1; j < size; j++)
			if (array[j_swap] > array[j])
				j_swap = j;

		if (i != j_swap)
		{
			aux = array[i];
			array[i] = array[j_swap];
			array[j_swap] = aux;
			print_array(array, size);
		}
	}
}
