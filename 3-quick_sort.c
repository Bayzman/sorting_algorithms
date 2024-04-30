#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
/**
 * quick_sort - sorts an array of integers in ascending order
 *  using the Quick sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (size < 2)
		return;
	quick_sort_recursive(array, low, high, size);
}

/**
 * quick_sort_recursive - sorts an array of integers in ascending order
 *  using the Quick sort algorithm
 *
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low >= high || low < 0 || high < 0 || low >= (int)size ||
		high >= (int)size)
		return;

	pivot = partition(array, low, high, size);
	quick_sort_recursive(array, low, pivot - 1, size);
	quick_sort_recursive(array, pivot + 1, high, size);
}
/**
 * partition - partitions the array and selects a pivot element
 *
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;

			if (i - 1 != j)
				print_array(array, size);
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (i != high)
		print_array(array, size);
	return (i);
}
