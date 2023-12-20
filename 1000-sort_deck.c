#include "deck.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_nodes(deck_node_t *a, deck_node_t *b, deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 * @deck: Pointer to the head of the deck
 */
void swap_nodes(deck_node_t *a, deck_node_t *b, deck_node_t **deck)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sorts a deck of cards by kind and value
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL)
		return;

	do {
		swapped = 0;
		current = *deck;

		while (current->next != NULL)
		{
			if (current->card->kind > current->next->card->kind ||
			    (current->card->kind == current->next->card->kind &&
			     strcmp(current->card->value, current->next->card->
				    value) > 0))
			{
				swap_nodes(current, current->next, deck);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
	} while (swapped);
}
