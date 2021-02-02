#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 *
 * @array: array of ints to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int aux;

	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = aux;
		}
		gap /= 3;
		print_array(array, size);
	}
}
