#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Qucik sort Algorithm (Lomuto scheme)
 *
 * @array: array to sort
 * @size: amount of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursively sorts an array of integers in ascending
 * order using the Quick Sort Algorithm
 *
 * @array: array to sort
 * @lo: index of current lowest positon
 * @hi: pivot point, index highest position
 * @size: size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = quick_sort_partition(array, lo, hi, size);

		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * quick_sort_partition - takes an aarray and two indixes representing a
 * the point of a partition. Wihing these indexes the function will swap
 * values and return the index reference for the next partitions
 *
 * @array: array to evalute and swap in place
 * @lo: index, low bound
 * @hi: index high bound
 * @size: size of the array
 *
 * Return: index to use as partition reference for next use
 */
int quick_sort_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], aux;
	int i = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
			i++;
		}
	}
	aux = array[i];
	array[i] = array[hi];
	array[hi] = aux;
	return (i);
}
