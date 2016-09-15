#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN   8

int array[ARRAY_LEN] = {7, 6, 5, 4, 3, 2, 1, 0};

void swap(int *array, int element_1, int element_2)
{
    int temp;
    temp = array[element_2];
    array[element_2] = array[element_1];
    array[element_1] = temp;
}

void print_array(int *array)
{
    for(int i=0; i<ARRAY_LEN; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int partition(int *array, int start, int end)
{
    int pivot=array[end];       // Always take the last for now
    int p_index = start;
    for(int i=start; i<end; i++)
    {
        if(array[i] <= pivot)
        {
            int temp = array[i];
            array[i] = array[p_index];
            array[p_index] = temp;
            p_index++;
        }
    }
    int temp = array[p_index];
    array[p_index] = array[end];
    array[end] = temp;
    return p_index; 
}

void quicksort(int *array, int start, int end)
{
    if(start<end)
    {
        int pivot = partition(array, start, end);   // partition
        quicksort(array, start, pivot-1);           // Left
        quicksort(array, pivot+1, end);             // Right
    }
}


int main(void)
{
    print_array(array);
    swap(array, 1, 4);
    swap(array, 0, 7);
    print_array(array);
    quicksort(array, 0, ARRAY_LEN - 1);
    print_array(array);
    return 0;
}
