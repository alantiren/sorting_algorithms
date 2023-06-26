#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array.
 * @array: An array of integers.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *array, size_t i, size_t j)
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
}

/**
 * bitonic_merge - Merge two halves of a bitonic sequence in the specified order.
 * @array: An array of integers.
 * @low: Starting index of the first half.
 * @count: The number of elements to merge.
 * @up: Flag to specify the merging order (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int up)
{
if (count > 1)
{
size_t k = count / 2;
size_t i;

for (i = low; i < low + k; i++)
{
if ((array[i] > array[i + k]) == up)
swap(array, i, i + k);
}

bitonic_merge(array, low, k, up);
bitonic_merge(array, low + k, k, up);
}
}

/**
 * bitonic_sort_recursive - Recursive function to perform the Bitonic sort.
 * @array: An array of integers.
 * @low: Starting index of the sequence to sort.
 * @count: The number of elements in the sequence.
 * @up: Flag to specify the sorting order (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int up)
{
if (count > 1)
{
size_t k = count / 2;

bitonic_sort_recursive(array, low, k, 1);
bitonic_sort_recursive(array, low + k, k, 0);
bitonic_merge(array, low, count, up);
}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
int up = 1; // 1 for ascending, 0 for descending
size_t i, j, k;

if (array == NULL || size < 2)
return;
for (k = 2; k <= size; k *= 2)
{
for (j = k >> 1; j > 0; j = j >> 1)
{
for (i = 0; i < size; i++)
{
int xor = i ^ j;
if ((xor & j) == 0)
{
if ((i & k) == 0 && array[i] > array[i + j])
swap(array, i, i + j);
if ((i & k) != 0 && array[i] < array[i + j])
swap(array, i, i + j);
}
}
print_array(array, size);
}
}
}
