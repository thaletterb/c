// Returns the first occurrence or last occurence of an element in a sorted (?) array

#include <stdio.h>
#include <stdlib.h>

/** @brief: returns index of element equal to value
*   
*   @params:    *array - sorted input array
*/
int binary_search(int *array, int start, int end, int value, int find_first)
{
    int result = -1;
    while(start <= end)
    {
        int mid_point = start + (end-start)/2;
        if(array[mid_point] == value)   // value found
        {
            result = mid_point;
            if(find_first)
            {
                end = mid_point-1;
            }
            else
            {
                start = mid_point+1;
            }
        }
        else if(array[mid_point] < value)
        {
            start = mid_point+1;
        }
        else if(array[mid_point] > value)
        {
            end = mid_point-1;
        }
    }

    return result;
    //if(start > end)
    //{
    //    //return NULL;  // Doesn't exits 
    //    return -1;  // Doesn't exits 
    //}
    //
    //int mid_point = start + ((end-start)/2);
    //if(array[mid_point] == value)
    //{
    //    while(array[mid_point] == value)
    //    {
    //        if(find_first)
    //            mid_point--;
    //        else
    //            mid_point++;
    //    }
    //    if(find_first)
    //        mid_point++;
    //    else
    //        mid_point--;
    //    return mid_point;
    //}
    //else if(array[mid_point] < value)
    //{
    //    return binary_search(array, mid_point+1, end, value, find_first);
    //}
    //else
    //{
    //    return binary_search(array, start, mid_point-1, value, find_first);
    //}
}

int main(void)
{
    int array[7] = {2, 10, 10, 10, 10, 10, 20};
    int search_result;

    int find_first = 1;
    int search_value = 10;
    search_result = binary_search(array, 0, 6, search_value, find_first);
    printf("Search Value: %d\nSearch Result: %d\n\n", search_value, search_result);

    return 0;
}
