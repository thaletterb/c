#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t* next;
} node_t;

node_t *head;

void insert_position(int value, int position)
{
    node_t *temp = head;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    
    new_node->value = value;
    new_node->next = NULL;

    if(temp == NULL)    // empty list
    {
        head = new_node;
        return;
    }

    if(position == 1)   // insert at head of list
    {
        new_node->next = head;
        head = new_node;
        return;
    }
    // Iterate to the (position-1)th node. aka the node before
    for(int i=0; i<(position-2); i++)
    {
        temp = temp->next;
    }

    node_t *temp2 = malloc(sizeof(node_t));

    temp2->next = temp->next;   // Save the old link
    temp->next = new_node;
    new_node->next = temp2->next;

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
    insert_position(1, 1);
    insert_position(2, 1);
    insert_position(0, 1);
    insert_position(0, 1);
    insert_position(6, 3);
    insert_position(5, 3);
    insert_position(5, 2);
    print_list();
    return 0;
}
