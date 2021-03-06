#ifndef _SORT_H_
#define _SORT_H_
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Task 0. Bubble Sort*/
void bubble_sort(int *array, size_t size);
/*Task 1. Insertion Sort*/
void insertion_sort_list(listint_t **list);
void swap_node(listint_t *node1, listint_t *node2);
/*Task 2. Selection Sort*/
void selection_sort(int *array, size_t size);
/*Task 3. Quick Sort*/
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int lo, int hi, size_t size);
int quick_sort_partition(int *array, int lo, int hi, size_t size);
void swap_in_array(int *array, int idx1, int idx2, size_t size);

/*Task 4. Shell sort (AKA #100)*/
void shell_sort(int *array, size_t size);
/*Task 5. Cocktail shaker sort (AKA 101)*/
void cocktail_sort_list(listint_t **list);
/*====Task 5 reuses the prototype swap_node(..) from task 1=====*/
/*Task 6. Counting sort (AKA 102)*/
void counting_sort(int *array, size_t size);
/*Task 7. Merge sort (AKA 103)*/
void merge_sort(int *array, size_t size);
void TopDownSplitMerge(int *aux, int s_idx, int f_idx, int *array);
void TopDownMerge(int *arr1, int s_idx, int mid_idx, int f_idx, int *arr2);
void print_split_merge(int *arr, char *str, int s_idx, int f_idx);
/*Task 8. Heap sort (AKA 104)*/
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void shift_down(int *array, size_t root, size_t f_idx, size_t size);
/*Task 9. Radix sort*/
void radix_sort(int *array, size_t size);
void countSort(int *arr, size_t n, int exp);
/*Task 10 Quick sort *Hoare scheme* (AKA 107)*/
void quick_sort_hoare(int *array, size_t size);
#endif
