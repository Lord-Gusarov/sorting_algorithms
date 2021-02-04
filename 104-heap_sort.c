#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 *
 * @array: array to sort
 * @size: count of element sin the array
 */
void heap_sort(int *array, size_t size)
{
	size_t f_idx;
	int temp;

	if (array == NULL || size < 2)
		return;
	heapify(array, size);
	f_idx = size - 1;
	while (f_idx > 0)
	{
		temp = array[f_idx];
		array[f_idx] = array[0];
		array[0] = temp;
		print_array(array, size);
		f_idx--;
		shift_down(array, 0, f_idx, size);
	}
}

/**
 * heapify - helper method, creates a heap from an array
 * @array: array to turn into a heap
 * @size: amount of elements in the array
 */
void heapify(int *array, size_t size)
{
	size_t h;

	for (h = ((size - 1) - 1) / 2; 1; h--)
	{
		shift_down(array, h, size - 1, size);
		if (h == 0)
			break;
	}
}

/**
 * shift_down - Repairs the heap whose root element is at index 'root'
 *
 * @array: heaped array
 * @root: the root of the heap
 * @f_idx: the last index of the heap
 * @size: cnt of elemets in the array
 */
void shift_down(int *array, size_t root, size_t f_idx, size_t size)
{
	size_t l_child, r_child, swap;
	int temp;

	while ((l_child = (2 * root) + 1) <= f_idx)
	{
		swap = root;
		r_child = l_child + 1;
		if (array[swap] < array[l_child])
			swap = l_child;
		if (r_child <= f_idx && array[swap] < array[r_child])
			swap = r_child;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}
