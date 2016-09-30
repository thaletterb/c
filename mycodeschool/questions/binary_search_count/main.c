#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int start, int end, int value, int find_first)
{
    int count = 0;
    int result = -1;

    while(start <= end)
    {
        int mid_point = start + (end-start)/2;
        if(array[mid_point] == value)
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
        else    // array[mid_point] > value
        {
            end = mid_point-1;
        }
    }

    return result;
}

int main(void)
{
    int sorted_array[12] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11}; 
    int first_index = 0;
    int last_index = 0;
    int total_num = 0;

    first_index = binary_search(sorted_array, 0, 11, 0, 1);
    printf("First: %d\n", first_index);
    last_index = binary_search(sorted_array, 0, 11, 0, 0);
    printf("Last: %d\n", last_index);

    if(last_index > 0 && first_index > 0)
        total_num = last_index - first_index + 1;   // in case there's only one occurance
    else
        total_num = 0;
    printf("Total Occurrences: %d\n", total_num); 
}
