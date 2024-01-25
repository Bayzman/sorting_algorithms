#include "sort.h"

/**
 * manual_swap - swap the values of a and b
 * @a: pointer to a
 * @b: pointer to b
 * Return: void
 */
void manual_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto - lomuto algorithm for partitioning an array
 * @array: pointer to array
 * @low: index to smaller element
 * @high: index to bigger element
 * @size: size of array
 * Return: int
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			manual_swap(&array[i], &array[j]);
			/*print_array(array, size);*/
		}
	}
	manual_swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort
 * @array: pointer to array
 * @low: index of smaller element
 * @high: index of bigger element
 * @size: size of array
 * Return: void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto(array, low, high, size);
		quick_sort_recursive(array, low, (pivot_idx - 1), size);
		quick_sort_recursive(array, (pivot_idx + 1), high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (size - 1), size);
}
