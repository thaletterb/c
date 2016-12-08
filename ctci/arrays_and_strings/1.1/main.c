//Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures

#include <stdio.h>
#include <stdlib.h>
    
#define NUM_OF_LETTERS  26
#define ASCII_OFFSET_A  65

int hash_char(char c)
{
    return (c - ASCII_OFFSET_A)%NUM_OF_LETTERS;
}

int check_unique(char *input_string)
{
    int char_hash_table[NUM_OF_LETTERS] = {0};      // hash table for each char (26 upper case only)

    if(input_string[0] == '\0')
        return 1;

    for(int i=0; input_string[i] != '\0'; i++)
    {
        int index =  hash_char(input_string[i]);
        if(char_hash_table[index])
        {
            // if we've already seen this char.. return false
            return -1;
        }
        char_hash_table[index]++;
    }

    return 1;
}

int main(void)
{
    char string[] = "HELO";

    int unique_result;
    
    unique_result = check_unique(string);
    printf("Unique: %d\n", unique_result);

    unique_result = check_unique("HELLO");
    printf("Unique: %d\n", unique_result);

    unique_result = check_unique("");
    printf("Unique: %d\n", unique_result);

    return 0;
}
