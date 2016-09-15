#include <stdlib.h>
#include <stdio.h>

int stack[10];
int top = -1;    // index of top empty stack

void push(int x)
{
    top++;
    stack[top] = x;
}

void pop(void)
{
    stack[top] = 0; // ?
    top--;
}

void print_stack()
{
    int stack_size = sizeof(stack)/sizeof(stack[0]);
    for(int i=0; i<stack_size; i++)
    {
        printf("%d, ", stack[i]);
    }
    printf("\n");
}

int main(void)
{
    push(1);
    push(2);
    print_stack();
    pop();
    print_stack();
}
