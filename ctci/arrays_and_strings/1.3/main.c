/**
*   Given two strings, write a method to determine if one is a permutation of the other
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_CHARS    26 
#define ASCII_A_OFFSET  65

int hash_char(char c)
{
    return (c - ASCII_A_OFFSET) % NUM_OF_CHARS;
}

int is_permutation(char *str1, char *str2)
{
    if(!str1 || !str2)  // if one of the strings does not exist
        return 0;

    char char_hash_table[NUM_OF_CHARS] = {0};

    // hash and add all values to the table for 1st string
    for(int i=0; str1[i] != '\0'; i++)
    {
        int hash_index = hash_char(str1[i]);
        char_hash_table[hash_index]++;
    }

    // hash and subtract all values to the table for the 2nd string
    for(int i=0; str2[i] != '\0'; i++)
    {
        int hash_index = hash_char(str2[i]);
        char_hash_table[hash_index]--;
    }

    // if hash table is completely empty.. then strings are permutations of each other
    for(int i=0; i<NUM_OF_CHARS; i++)
    {
        if(char_hash_table[i])
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int permutation = 0;

    permutation = is_permutation("Hello", "eHllo");

    printf("Is Permutation: %d\n", permutation);
    return 0;

}

