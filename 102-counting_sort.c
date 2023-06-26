#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
int max, i;
for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @list: pointer to the header
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (tail = *list; tail->next != NULL;)
tail = tail->next;

while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
