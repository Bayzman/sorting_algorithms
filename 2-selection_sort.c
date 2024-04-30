#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *  using the Selection sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j;
    int min, temp, temp2;

    for (i = 0; i < size; i++)
    {
        min  = array[i];

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                temp = j;
            }
        }
        if (min != array[i])
        {
            temp2 = array[i];
            array[i] = min;
            array[temp] = temp2;
            print_array(array, size);
        }
    }
}
