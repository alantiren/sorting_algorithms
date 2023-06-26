#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The original array.
 * @size: The size of the array.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
size_t i = 0, j = 0, k = 0;
int *temp_array;

temp_array = malloc(sizeof(int) * size);
if (temp_array == NULL)
return;

printf("Merging...\n[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

while (i < left_size && j < right_size) {
if (left[i] <= right[j]) {
temp_array[k] = left[i];
i++;
} else
{
temp_array[k] = right[j];
j++;
}
k++;
}

while (i < left_size) {
temp_array[k] = left[i];
i++;
k++;
}

while (j < right_size) {
temp_array[k] = right[j];
j++;
k++;
}

for (i = 0; i < size; i++) {
array[i] = temp_array[i];
}
printf("[Done]: ");
print_array(array, size);

free(temp_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
size_t mid, i;
int *left, *right;

if (array == NULL || size < 2)
return;

if (size > 1)
{
mid = size / 2;
left = array;
right = array + mid;

merge_sort(left, mid);
merge_sort(right, size - mid);

printf("Merging...\n[left]: ");
print_array(left, mid);
printf("[right]: ");
print_array(right, size - mid);

merge(array, size, left, mid, right, size - mid);
}

printf("[Done]: ");
print_array(array, size);
}
