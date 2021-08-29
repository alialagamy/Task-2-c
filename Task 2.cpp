//processing part.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
#define size_array 100000 
// declare a "Global array"
int value[size_array];
// Function make random value of array.
void rand(int value[])
 {
	srand(time(NULL));
	for (int i = 0; i < size_array; i++)
	 {
		value[i] = rand() % 100000 + 1;
	}
}

// Insertion sort.
void insertion_sort(int* array, int len)
 {
	for (int i = 1; i < len; i++)
	 {
		int x = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > x)
		 {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = x;
	}
}

// Swap function 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 	Quick sort function.
void quick_sort(int start, int end)
 {
	if (start >= end)
	    return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && value[i] <= value[key])
			i++;
		while (j > start && value[j] >= value[key])
		    j--;
		if (i > j)  
			swap(&value[key], &value[j]);
		else 
		    swap(&value[i], &value[j]);
	}
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
}

int main() 
{
	int arr[size_array];
	srand(time(NULL));
	for (int i = 0; i < size_array; i++) 
	{
		arr[i] = rand() % 100000 + 1;
	}
	printf("\tArray of 100000 Random Numbers is initialized\n");
	rand(value);
	quick_sort(0, size_array - 1);
	printf("The Array is sorted using quick sort in %u seconds\n", clock());
	insertion_sort(arr, size_array);
	printf("The Array is sorted using insertion sort in %u seconds\n", clock());
	return 0;
}
