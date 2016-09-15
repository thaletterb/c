#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
} node_t;

node_t *head;

void insert_start(int value)
{
    node_t *temp = head;

    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    new_node->value = value;
    new_node->next = temp;

    head = new_node;
}

void print_list()
{
    node_t* temp = head;
    while(temp != NULL)
    {
        printf("%d, ",temp->value); 
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    head = NULL;    // start with an empty list

    insert_start(5);
    insert_start(4);
    insert_start(3);
    insert_start(2);
    insert_start(1);
    print_list();
    return 0;
}
