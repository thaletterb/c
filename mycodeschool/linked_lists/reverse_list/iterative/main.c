#include <stdio.h>
#include <stdlib.h>

typedef struct node_t 
{
    int value;
    struct node_t *next;
} node_t;    

node_t *head;   // NULL - aka empty list

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
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    node_t *temp = head;

    new_node->value = value;
    new_node->next = NULL;

    if(temp == NULL)
    {
        head = new_node;
        return;
    }

    // Traverse to end of the list
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void reverse_list(void)
{
    node_t *temp = head;
    node_t *temp_current_address;
    node_t *temp_next_link;

    /** in the final reversed list current head's ->next field should now point
     *  to null i.e: temp->next = NULL;
     *
     *  But we can't lose the current head's current -> next field
     *  so let's save that first:
     *      temp_next_link = temp->next; 
     *
     *  as well as the address of the current head:
     *      temp_current_address = temp; 
     */
    temp_current_address = temp;
    temp_next_link = temp->next;
    temp->next = NULL;

    while(temp_next_link != NULL)
    {
        temp = temp_next_link;
        temp_next_link = temp->next;

        temp->next = temp_current_address;
        temp_current_address = temp;
    }
    head = temp_current_address;    // update head to be the old tail
}

int main(void)
{
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    insert_end(6);
    print_list();
    reverse_list();
    print_list();
    return 0;
}
