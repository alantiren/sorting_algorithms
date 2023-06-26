#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
int pivot = array[right];
int i = left - 1;

for (int j = left; j <= right - 1; j++)
{
if (array[j] <= pivot)
{
i++;
swap_ints(&array[i], &array[j]);
print_array(array, size);
}
}

swap_ints(&array[i + 1], &array[right]);
print_array(array, size);

return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm using the Lomuto partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
if (left < right)
{
int partition = lomuto_partition(array, size, left, right);

lomuto_sort(array, size, left, partition - 1);
lomuto_sort(array, size, partition + 1, right);
}
}

/**
 * quick_sort - Sort an array of integers in ascending order using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
