#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

listint_t *current = NULL, *key = NULL;
for (current = (*list)->next; current != NULL; current = current->next)
{
key = current;
while (key->prev != NULL && key->n < key->prev->n)
{
listint_t *prev = key->prev;
listint_t *next = key->next;

if (prev->prev != NULL)
prev->prev->next = key;
else
*list = key;

key->prev = prev->prev;
key->next = prev;
prev->prev = key;
prev->next = next;

if (next != NULL)
next->prev = prev;

print_list((const listint_t *)*list);
}
}
}
