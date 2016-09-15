#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
} node_t;

node_t *head;   // an empty list

// ALL INSERT/DELETE MUST BE DONE AT HEAD OF LIST FOR CONSTANT TIME O(1) COMPLEXITY!!!
// CONSTANT TIME COMPLEXITY IS WHY WE USE STACKS
void stack_push(int a)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = a;
    new_node->next = head;
    head = new_node;
}

void stack_pop()
{
    node_t *temp;
    if(head == NULL)
        return; // stack is already empty
    temp = head;
    head = head->next;
    free(temp);
}

int stack_top()
{
    return head->value;
}

int stack_is_empty()
{
    if(head == NULL)
    {
        return 1;
    }
    else
        return 0;
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

