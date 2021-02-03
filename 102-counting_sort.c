#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: array to be sorted
 * @size: count of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	size_t s;
	int i, largest = 0, x, *count, *out;

	if (array == NULL || size < 2)
		return;

	for (s = 0; s < size; s++)
		if (largest < array[s])
			largest = array[s];

	count = malloc(sizeof(int) * (largest + 1));
	out = malloc(sizeof(int) * size);
	if (count == NULL || out == NULL)
		return;
	/*Set's the array to ZERO*/
	for (i = 0; i <= largest; i++)
		count[i] = 0;

	for (s = 0; s <  size; s++)
		++count[array[s]];

	for (i = 1; i <= largest; i++)
		count[i] += count[i - 1];

	print_array(count, largest + 1);

	for (s = 0; s < size; s++)
	{
		x = array[s];
		out[count[x] - 1] = x;
		count[x] -= 1;
	}

	for (s = 0; s < size; s++)
		array[s] = out[s];

	free(count);
	free(out);

