#include "deck.h"
#define DECK_SIZE 52
/**
 * sort_deck - sorts a deck of cards, The deck must be ordered::
 * From Ace to King & From Spades to Diamonds
 * @deck: head of a doubly linked list of cards
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *arr_deck[DECK_SIZE], *trv;
	int i;

	trv = *deck;

	for (i = 0; i < DECK_SIZE; i++, trv = trv->next)
		arr_deck[i] = trv;

	qsort(arr_deck, DECK_SIZE, sizeof(deck_node_t *), card_cmp);

	*deck = arr_deck[0];
	(*deck)->prev = NULL;
	(arr_deck[DECK_SIZE - 1])->next = NULL;
	for (trv = *deck, i = 1; i < DECK_SIZE; i++)
	{
		trv->next = arr_deck[i];
		(arr_deck[i])->prev = trv;
		trv = trv->next;
	}
}

/**
 * card_cmp - compares two cards according to their type first
 * and then to their value
 *
 * @c1: fisrt card to compare
 * @c2: second card to compare
 *
 * Return: -1 if c1 < c2, 0 if c1 == c2 and 1 otherwise
 */
int card_cmp(const void *c1, const void *c2)
{
	static const char *order = "A234567891JQK";
	int val1, val2, kind_cmp;

	const card_t *cd1 = (*(deck_node_t **)c1)->card,
				 *cd2 = (*(deck_node_t **)c2)->card;

	kind_cmp = cd1->kind - cd2->kind;
	if (kind_cmp != 0)
		return (kind_cmp);
	for (val1 = 0; order[val1] != cd1->value[0]; val1++)
		;
	for (val2 = 0; order[val2] != cd2->value[0]; val2++)
		;

	return (val1 - val2);
}
