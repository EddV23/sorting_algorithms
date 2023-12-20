#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Suit of a card.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a card.
 * @value: The value of the card (Ace to King).
 * @kind: The suit of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards.
 * @card: Pointer to the card.
 * @prev: Pointer to the previous node in the deck.
 * @next: Pointer to the next node in the deck.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
deck_node_t *init_deck(const card_t cards[52]);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
