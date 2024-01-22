#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble Sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i;
	int temp;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
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
