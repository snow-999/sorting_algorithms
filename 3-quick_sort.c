#include "sort.h"
/**
 * swap - swap the elements
 * @x: an array
 * @y: an array
 * @array: an array will be sorted
 * @size: size of the array
 *
 *
*/
void swap(int *array, size_t size, int *x, int *y)
{
	int tmp;

	if (*x != *y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
		print_array((const int *)array, size);
	}
}
/**
 * partition - seprate the array that will be sorted
 * @array: an array will be sorted
 * @size: the size of attay
 * @low: the lowest number
 * @high: the highest number
 * Return: the address of the pivot
 *
*/
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot_indx = array[high];

	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_indx)
		{
			swap(array, size, &array[j], &array[i]);
			i++;
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}
/**
 * quickSort_recurction - sort the array
 * @array: an array will be sorted
 * @size: the size of attay
 * @low: the lowest number
 * @high: the highest number
 *
*/
void quickSort_recurction(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot_value = partition(array, size, low, high);

		quickSort_recurction(array, size, low, pivot_value - 1);
		quickSort_recurction(array, size, pivot_value + 1, high);
	}
}

/**
 * quick_sort - the main function
 * @array: an array will be sorted
 * @size: size of the array
 *
*/
void quick_sort(int *array, size_t size)
{
	if (!size || !array)
	{
		return;
	}
	quickSort_recurction(array, size, 0, size - 1);
}
