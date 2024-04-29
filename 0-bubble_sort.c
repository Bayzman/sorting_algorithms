#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
	}
}
