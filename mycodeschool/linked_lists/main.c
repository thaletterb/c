#include <stdio.h>
#include <stdlib.h>


typedef struct node_t{
    int value;
    struct node_t *next;
} node_t;

node_t *head=NULL;      // aka an empty list

// traverse to the end of the list. return address of last node
node_t* traverse_list(node_t *head)
{
    node_t *temp_node = head;
    while(temp_node->next != NULL)
    {
        printf("%d, ", temp_node->value);
        temp_node = temp_node->next;
    }
    printf("%d, \n", temp_node->value);
    return temp_node; 
}

// insert node
void insert_node_at_end(node_t *new_node)
{
    node_t *last_node;

    last_node = traverse_list(head);
    last_node->next = new_node;
    
}


int main(void)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = 2;
    new_node->next = NULL;

    head = new_node;

    node_t *new_node_2 = (node_t*)malloc(sizeof(node_t));
    new_node_2->value = 4;
    new_node_2->next = NULL;

    insert_node_at_end(new_node_2);

    node_t *new_node_3 = (node_t*)malloc(sizeof(node_t));
    new_node_3->value = 6;
    new_node_3->next = NULL;
    
    insert_node_at_end(new_node_3);

    node_t *new_node_4 = (node_t*)malloc(sizeof(node_t));
    new_node_4->value = 8;
    new_node_4->next = NULL;
    
    insert_node_at_end(new_node_4);
    traverse_list(head);

    return 0;
}
