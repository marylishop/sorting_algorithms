#include "sort.h"
#include <stdlib>

/**
 * counting_sort - sorts an array of integers in ascending order using a
 * counting sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void counting_sort(int *array, size_t size) 
{
    if (size <= 1)
        return;

    int max_value = array[0];
	for (size_t i = 1; i < size; i++) 
{
	if (array[i] > max_value) 
{
		max_value = array[i];
		}
	}

	int *counting_array = (int *)malloc((max_value + 1) * sizeof(int));
	if (counting_array == NULL)

	return;

	for (int i = 0; i <= max_value; i++) 
{
		counting_array[i] = 0;
    }

		for (size_t i = 0; i < size; i++) 
{
		counting_array[array[i]]++;
	}

		size_t index = 0;
	for (int i = 0; i <= max_value; i++) 
{
	while (counting_array[i] > 0) 
{
		array[index] = i;
	counting_array[i]--;
	index++;
	}
}

free(counting_array);
}

/* Printing array elements */
void print_array(const int *array, size_t size) 
{
	for (size_t i = 0; i < size; i++) {
	printf("%d", array[i]);
	if (i != size - 1) {
	printf(", ");
		}
	}
	printf("\n");
}

int main(void) 
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
    counting_sort(array, n);
	print_array(array, n);
	return (0);
}
