#include <stdio.h>
#include <stdlib.h>

void merge(int *sorted, int *left, int left_len, int *right, int right_len)            // Merge sorted arrays
{
    int i=0, j=0, k=0;  // i-left array index. j-right array index. k-sorted array index

    while(i<left_len && j<right_len)
    {
        if(left[i] < right[j])
        {
            sorted[k++]=left[i++];
        }
        else
        {
            sorted[k++]=right[j++];
        }
    }
    while(i<left_len)
    {
        sorted[k++] = left[i++];
    }
    while(j<right_len)
    {
        sorted[k++] = right[j++];
    }
}
void merge_sort(int *array, int array_len)       // recursive func
{
    int i=0, j=0, mid=0;
    int *left, *right; 

    if(array_len < 2)
        return; // base case - already sorted 1 element array
    
    mid = array_len/2;
    left = (int*)malloc(mid * sizeof(int));
    right = (int*)malloc((array_len-mid) * sizeof(int));

    for(i=0; i<mid; i++)
    {
        left[i] = array[i];
    }

    for(j=0; j<(array_len-mid); j++)
    {
        right[j] = array[mid+j];
    }
    
    merge_sort(left, mid);
    merge_sort(right, (array_len-mid));
    merge(array, left, mid, right, (array_len-mid));

    free(left);
    free(right);

}
int main(void)
{
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

    printf("\n");
    for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
    printf("\n");
    return 0;
}
