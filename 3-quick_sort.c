#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int low, int high)
{
int *pivot, above, below;

pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap_ints(array + below, array + above);
print_array(array, size);
}
above++;
}
}
if (array[above] > *pivot)
{
swap_ints(array + above, pivot);
print_array(array, size);
}

return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm using
 * the Lomuto partition scheme.
 * @array: An array of integers to sort.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, int low, int high)
{
if (low < high)
{
int partition = lomuto_partition(array, low, high);

lomuto_sort(array, low, partition - 1);
lomuto_sort(array, partition + 1, high);
}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, 0, size - 1);
}
