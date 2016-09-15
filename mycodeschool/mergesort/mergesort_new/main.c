#include <stdio.h>
#include <stdlib.h>

void merge(int *left, int left_size, int *right, int right_size, int *array)
{
    int i=0, j=0, k = 0;    // i = left index, j = right index, k = merge index
    while(i < left_size && j < right_size)
    {
        if(left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
   while((i<left_size))
   {
       array[k] = left[i];
       k++;
       i++;
   }
    while(j<right_size)
   {
       array[k] = right[j];
       k++;
       j++;
   }
}

void merge_sort(int *array, int array_len)
{
    int pivot = 0;
    int *left, *right;

    if(array_len < 2){   // Base case - array of size 1 is always sorted
        return; 
    }
    pivot = array_len / 2;

    left = (int*)malloc(pivot * sizeof(int));
    right = (int*)malloc((array_len - pivot) * sizeof(int));
    for(int i = 0; i<pivot; i++){
        left[i] = array[i];
    }

    for(int j= 0; j < array_len-pivot; j++){
        right[j] = array[j+pivot];
    }
        
    merge_sort(left, pivot);
    merge_sort(right, array_len - pivot);
    //Merge(array, left, pivot, right, array_len - pivot);
    merge(left, pivot, right, array_len - pivot, array);
    
    free(left);
    free(right);
}

int main() {
    /* Code to test the MergeSort function. */
    
    int A[] = {6,2,3,1,9,10,15,13,12,17, 22, 11, 27, 18}; // creating an array of integers. 
    int i,numberOfElements;

    // finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
    // This won't work if array is passed to the function because array
    // is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
    // Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g  
    numberOfElements = sizeof(A)/sizeof(A[0]); 

    // Calling merge sort to sort the array. 
    //MergeSort(A,numberOfElements);
    merge_sort(A,numberOfElements);

    //printing all elements in the array once its sorted.
    for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
    printf("\n");
    return 0;
}
