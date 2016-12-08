#include <stdio.h>
#include <stdlib.h>

char *reverse_string(char *input_string)
{
    // determine input string length
    int string_length = 0;
    for(int i=0; input_string[i] != '\0'; i++)
    {
        string_length++;
    }

    char *reversed_string = malloc(string_length * sizeof(char));
    //reversed_string = "abc";

    int j=0;
    for(int i=string_length-1; i>=0; i--)
    {
       reversed_string[j++] = input_string[i]; 
    }
    return reversed_string;
}

int main(void)
{
    printf("%s\n", reverse_string("hello"));
    return 0;
}
