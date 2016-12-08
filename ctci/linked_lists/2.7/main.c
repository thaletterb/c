/** 
*   Implement a function to check if a linked list is a palindrome
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
}node_t;

node_t *g_root;

void insert_node(node_t *root, int value)
{
    node_t *temp = root;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;

    if(temp == NULL)
    {
        g_root = new_node;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;

}

void print_list(node_t *root)
{
    node_t *temp = root;

    while(temp != NULL)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int is_palindrome(node_t *list_head)
{
    if(list_head == NULL)
    {
        return 1;   // list is empty 
    }

    // reverse original list and compare if reversed list is the same as the original list 
    node_t *list_original_head = list_head;
    node_t *reversed_list;  // 'tail' of the reversed list
    node_t *reversed_list_head = NULL;
    
    while(list_head != NULL)
    {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->value = list_head->value;
        new_node->next = reversed_list_head; 
        reversed_list_head = new_node;
        list_head = list_head->next;
    }
    print_list(reversed_list_head);

    list_head = list_original_head;
    
    while(list_head != NULL)
    {
        if(list_head->value != reversed_list_head->value)
        {
            return 0;
        }
        list_head = list_head->next; 
        reversed_list_head = reversed_list_head->next;
    }
    return 1;
}

int main(void)
{
    insert_node(g_root, 1);
    insert_node(g_root, 2);
    insert_node(g_root, 3);
    insert_node(g_root, 4);
    insert_node(g_root, 5);
    insert_node(g_root, 4);
    insert_node(g_root, 3);
    insert_node(g_root, 2);
    insert_node(g_root, 1);

    print_list(g_root);

    int palindrome = 0;
    palindrome = is_palindrome(g_root);
    printf("Palindrome: %d\n", palindrome);
    return 0;
}
