#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the top-down Merge sort algorithm
 *
 * @array: array to sort
 * @size: count of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	TopDownSplitMerge(array, 0, size, copy);

	free(copy);
}

/**
 * TopDownSplitMerge - hlper function ofr merge sort, takes care of spliting
 * the array
 *
 * @array: array getting sorted
 * @s_idx: starting index
 * @f_idx: finishing index
 * @aux: array of same size that @array to be used as a tool
 */
void TopDownSplitMerge(int *aux, int s_idx, int f_idx, int *array)
{
	int mid_idx;

	if (f_idx - s_idx <= 1)
		return;

	mid_idx = (s_idx + f_idx) / 2;

	TopDownSplitMerge(array, s_idx, mid_idx, aux);
	TopDownSplitMerge(array, mid_idx, f_idx, aux);

	TopDownMerge(array, s_idx, mid_idx, f_idx, aux);
}

/**
 * TopDownMerge - merges arrays splits during the TopDown Merge sort
 *
 * @arr1: array to merge TO
 * @s_idx: starting index
 * @mid_idx: midlle index
 * @f_idx: finishing index
 * @arr2: array to merge FROM
 */
void TopDownMerge(int *arr1, int s_idx, int mid_idx, int f_idx, int *arr2)
{
	int i = s_idx, j = mid_idx, k;

	printf("Merging...\n");
	print_split_merge(arr1, "[left]", s_idx, mid_idx);
	print_split_merge(arr1, "[right]", mid_idx, f_idx);


	for (k = s_idx; k < f_idx; k++)
	{
		if (i < mid_idx && (j >= f_idx || arr1[i] <= arr1[j]))
		{
			arr2[k] = arr1[i];
			i++;
		}
		else
		{
			arr2[k] = arr1[j];
			j++;
		}
	}

	print_split_merge(arr2, "[Done]", s_idx, f_idx);
}

/**
 * print_split_merge - prints a section of an array, preceded by
 * an specifed string
 *
 * @arr: array to print from
 * @str: message to print before the elements
 * @s_idx: starting index
 * @f_idx: finishind index
 */
void print_split_merge(int *arr, char *str, int s_idx, int f_idx)
{
	printf("%s: ", str);

	for (; s_idx < f_idx; s_idx++)
	{
		printf("%d", arr[s_idx]);
		if (s_idx + 1 < f_idx)
			printf(", ");
	}
	printf("\n");
}
