#include <stdlib.h>
#include <stdio.h>

typedef struct node_t{
    int data;
    struct node_t *next;
} node_t;

node_t *head;

void print_list(void){
    node_t *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(int data, int position)
{
    node_t *temp1 = (node_t*)malloc(sizeof(node_t));

    temp1->data = data;
    temp1->next = NULL;

    // Adding at beginning of list
    if(position == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    // Go to (n-1)th node
    node_t *temp2 = (node_t*)malloc(sizeof(node_t));
    temp2 = head;
    for(int i=0; i<position-2; i++)
        temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
    
}

int main(void){
    head = NULL;        // empty list
    insert_node(2, 1);
    insert_node(3, 2);
    insert_node(4, 1);
    insert_node(5, 2);
    print_list();
    return 0;
}
