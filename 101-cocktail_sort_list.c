#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *trv;
	int swapped = 0;

	if (!list || !(*list))
		return;

	trv = *list;
	do {
		swapped = 0;
		for (; trv->next != NULL; trv = trv->next)
		{
			if (trv->n > trv->next->n)
			{
				if (trv == *list)
					*list = trv->next;
				swap_node(trv, trv->next);
				trv = trv->prev;
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; trv->prev != NULL; trv = trv->prev)
		{
			if (trv->prev->n > trv->n)
			{
				if (trv->prev == *list)
					*list = trv;
				swap_node(trv->prev, trv);
				trv = trv->next;
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_node - swaps two adjecents nodes of a doubly link list
 * the nodes wont be checked for NULL
 *
 * @node1: first node
 * @node2: second node
 */
void swap_node(listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	node2->prev = node1->prev;
	if (node2->prev)
		node2->prev->next = node2;
	node1->prev = node2;
	if (node1->next)
		node1->next->prev = node1;
	node2->next = node1;
}
