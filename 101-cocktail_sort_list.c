#include "sort.h"

void swap_nodes_forward(listint_t **list, listint_t **node1,
			listint_t **node2);
void swap_nodes_backward(listint_t **list, listint_t **node1,
			 listint_t **node2);
void cocktail_sort_list(listint_t **list);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes_forward - Swaps two nodes in a doubly linked list
 *              in a forward direction
 * @list: The doubly linked list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes_forward(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	temp = (*node2)->next;
	if ((*node2)->prev != NULL)
		(*node2)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*node2)->prev;
	(*node2)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *node2;
	else
		*node1 = *node2;
	(*node2)->prev = temp;
	temp->next = *node2;
	*node2 = temp;
}

/**
 * swap_nodes_backward - Swaps two nodes in a doubly linked list
 *              in a backward direction
 * @list: The doubly linked list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes_backward(listint_t **list, listint_t **node1,
			 listint_t **node2)
{
	listint_t *temp;

	temp = (*node2)->prev;
	if ((*node2)->next != NULL)
		(*node2)->next->prev = temp;
	else
		*node1 = temp;

	temp->next = (*node2)->next;
	(*node2)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *node2;
	else
		*list = *node2;
	(*node2)->next = temp;
	temp->prev = *node2;
	*node2 = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (start = *list; start->next != NULL;)
		start = start->next;

	while (swapped == 0)
	{
		swapped = 1;
		for (end = *list; end != start; end = end->next)
		{
			if (end->n > end->next->n)
			{
				swap_nodes_forward(list, &start, &end);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
		for (end = end->prev; end != *list;
		     end = end->prev)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes_backward(list, &start, &end);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
	}
}
