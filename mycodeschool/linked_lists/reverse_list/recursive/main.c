#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
}node_t;

node_t *head;   // NULL - empty list

void print_list(void)
{
    node_t *temp = head;
    while(temp != NULL)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
void insert_end(int value)
{
    node_t *temp = head;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    new_node->value = value;
    new_node->next = NULL;

    if(temp == NULL)
    {
        head = new_node;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->next =  new_node;
}

void recursive_reverse_list(node_t *current)
{
    if(current->next == NULL)
    {
        // base case - update head and return 
        head = current;
        return;
    }

    recursive_reverse_list(current->next);
    node_t *temp = current->next;
    temp->next = current;
    current->next = NULL;
}


int main(void)
{
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    print_list();
    recursive_reverse_list(head);
    print_list();
    return 0;
}

//void recursive_reverse_list(node_t *current)
//{
//    if(current->next == NULL)    // base case - reached end of list
//    {
//        head = current;
//        return;
//    }
//
//    recursive_reverse_list(current->next);
//
//    node_t *temp = current->next;
//    temp->next = current;
//    current->next = NULL;
//}
//
