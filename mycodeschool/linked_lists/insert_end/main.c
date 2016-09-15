#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
}node_t;

node_t *head; 

void insert_end(int value)
{
    node_t *temp_head = head;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    new_node->value = value;
    new_node->next = NULL;

    // If empty list
    if(temp_head == NULL)
    {   
        head = new_node; 
        return;
    }

    // if not empty - traverse to end of list
    while(temp_head->next != NULL)
        temp_head = temp_head->next;

    temp_head->next = new_node;
}

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

int main(void)
{
    head = NULL;
    insert_end(5);
    insert_end(7);
    insert_end(2);
    insert_end(9);
    insert_end(1);
    insert_end(6);
    print_list();
    return 0;
}

