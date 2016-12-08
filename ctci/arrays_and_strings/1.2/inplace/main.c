#include <stdio.h>

void reverse_in_place(char *input_string)
{
    int string_length = 0;
    for(int i=0; input_string[i] != '\0'; i++)
    {
        string_length++;
    }

    int string_mid = string_length / 2;
    // swap in place
    for(int i=0; i<string_mid; i++)
    {
        char temp = input_string[i];
        input_string[i] = input_string[string_length-1-i];
        input_string[string_length-1-i] = temp;
    }

    printf("%s\n", input_string);
}

int main(void)
{
    char test_string[] = "hello";
    reverse_in_place(test_string);
    return 0;
}
