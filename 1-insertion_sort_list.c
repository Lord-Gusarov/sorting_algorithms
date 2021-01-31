#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list in ascesding order
 * using the Insertion sort algorithm
 *
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *trv, *trv2, *aux_1, *aux_2;

	if (list == NULL || (*list)->next == NULL)
		return;
	trv = *list;
	trv2 = trv->next;

	while (trv2)
	{
		if (trv->n > trv2->n)
		{
			swap_node(trv, trv2);
			if (*list == trv)
				*list = trv2;
			trv2 = trv2->next;
			trv = trv2->prev;
			print_list(*list);
			aux_2 = trv;
			aux_1 = aux_2->prev;
			while (aux_1 && aux_1->n > aux_2->n)
			{
				swap_node(aux_1, aux_2);
				if (aux_1 == *list)
					*list = aux_2;
				print_list(*list);
				aux_1 = aux_2->prev;
			}
		}
		trv = trv2;
		trv2 = trv2->next;
	}
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
