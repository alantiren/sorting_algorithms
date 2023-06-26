#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @a: The first element.
 * @b: The second element.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a heap to maintain the heap property.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @start: The index of the parent node to sift down from.
 * @end: The index where the sift-down operation should stop.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
size_t root = start;
size_t child, swap_idx;

while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap_idx = root;

if (array[swap_idx] < array[child])
swap_idx = child;

if (child + 1 <= end && array[swap_idx] < array[child + 1])
swap_idx = child + 1;

if (swap_idx == root)
return;

swap(&array[root], &array[swap_idx]);
print_array(array, size);

root = swap_idx;
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
size_t i;

if (array == NULL || size < 2)
return;
for (i = size / 2; i > 0; i--) {
sift_down(array, size, i - 1, size - 1);
}

for (i = size - 1; i > 0; i--) {
swap(&array[0], &array[i]);
print_array(array, size);
sift_down(array, size, 0, i - 1);
}
}
