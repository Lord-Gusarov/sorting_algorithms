#ifndef _SORT_H_
#define _SORT_H_
#include <stdlib.h>

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
#endif
