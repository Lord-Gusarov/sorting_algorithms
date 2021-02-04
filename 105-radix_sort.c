#include "sort.h"

/**
 * countSort - A function to do counting sort of arr[] according to
 * the digit represented by exp
 *
 * @arr: array to be sorted
 * @n: number of elements in the array
 * @exp: a multiple of 10 represenmting the decimal place being
 * evaluated
 */
void countSort(int *arr, size_t n, int exp)
{
	int count[10] = {0}, *out = malloc(sizeof(int) * n);
	size_t i;

	if (out == NULL)
		return;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n; i > 0;)
	{
		i--;
		out[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = out[i];

	free(out);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int mx, exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (mx = array[0], i = 1; i < size; i++)
		if (array[i] > mx)
			mx = array[i];

	for (exp = 1; mx / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
