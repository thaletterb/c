#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
} node_t;

node_t *head;   // an empty list
int top = -1;   // is this needed?

void stack_push(int a)
{
    node_t *temp = head;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    new_node->value = a;
    new_node->next = NULL;

    if(temp == NULL)    // empty list
    {
        head = new_node;
        return;
    }
    
    while(temp->next != NULL)   // Traverse to end of the list
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void stack_pop()
{
    int count = 0;
    node_t *temp = head;

    while((temp->next)->next != NULL)   // Traverse to end of the list
    {
        temp = temp->next;
    }
    temp->next = NULL;
    
}

int stack_top()
{
    node_t *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->value;   
}

int stack_is_empty()
{
    node_t *temp = head;
    if(temp == NULL)
    {
        return 1;
    }
    else{
        return 0;   // temp
    }
}

void stack_print(void)
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
    printf("Empty: %d\n", stack_is_empty());
    stack_push(1);
    printf("Top: %d\n", stack_top());
    stack_push(2);
    stack_push(3);
    printf("Top: %d\n", stack_top());
    stack_print();
    printf("Empty: %d\n", stack_is_empty());
    stack_pop();
    printf("Top: %d\n", stack_top());
    stack_print();
    return 0;
}

