/** Implement a function void reverse(char *str) in C which reverses
*   a NULL terminated string
*/

#include <stdio.h>
#include <stdlib.h>

void reverse(char *str)
{
    int array_len = 0;
    int mid_index = 0;

    for(int i=0; str[i] != '\0'; i++)
    {
        array_len++;
    }

    char reverse_str[array_len];

    for(int i=0; i<array_len; i++)
    {
        reverse_str[i] = str[array_len-1-i];
    }


    printf("%s\n", reverse_str);
}

int main(void)
{
    reverse("Hello");
    return 0;
}
