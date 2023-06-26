#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * print_array - Print an array of integers.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(const int *array, size_t size)
{
size_t i;

for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i != size - 1)
printf(", ");
}
printf("\n");
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
int driver, up, down;

driver = array[right];
for (up = left - 1, down = right + 1; up < down;)
{
do
{
up++;
} while (array[up] < driver);
do
{
down--;
} while (array[down] > driver);

if (up < down)
{
swap_ints(array + up, array + down);
print_array(array, size);
}
}

return up;
}

/**
 * hoare_sort - Implement the QuickSort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
int belong;

if (right - left > 0)
{
belong = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, belong - 1);
hoare_sort(array, size, belong, right);
}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the QuickSort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}
