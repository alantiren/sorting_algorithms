#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              algorithm with the Knuth sequence.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
size_t interval = 1, i, j;
int temp;

if (array == NULL || size < 2)
return;

while (interval < size / 3)
interval = interval * 3 + 1;

while (interval > 0)
{
printf("Interval %lu:\n", interval);
print_array(array, size);

for (i = interval; i < size; i++)
{
temp = array[i];

for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
array[j] = array[j - interval];

array[j] = temp;
}

interval = (interval - 1) / 3;
}

printf("Interval 1:\n");
print_array(array, size);
}
