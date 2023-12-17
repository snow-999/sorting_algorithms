#include "sort.h"

/**
 * bubble_sort - sorting algerothim
 * @array: an array will be sorted
 * @size: the size of an array
 * Return: void
 *
*/
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t j, i = 0;

	while (i < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
