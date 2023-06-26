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
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
int *count, *output;
int max_value = 0, i;

if (array == NULL || size < 2)
return;

for (i = 0; i < size; i++) {
if (array[i] > max_value)
max_value = array[i];
}

count = malloc(sizeof(int) * (max_value + 1));
output = malloc(sizeof(int) * size);
if (count == NULL || output == NULL) {
free(count);
free(output);
return;
}

for (i = 0; i <= max_value; i++) {
count[i] = 0;
}

for (i = 0; i < size; i++) {
count[array[i]]++;
}

for (i = 1; i <= max_value; i++) {
count[i] += count[i - 1];
}

for (i = size - 1; i >= 0; i--) {
output[count[array[i]] - 1] = array[i];
count[array[i]]--;
}

for (i = 0; i < size; i++) {
array[i] = output[i];
}

printf("%d", count[0]);
for (i = 1; i <= max_value; i++)
{
printf(", %d", count[i]);
}
printf("\n");

free(count);
free(output);
}
