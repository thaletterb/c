#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node_t
{
    int value;
    struct bst_node_t *left_child, *right_child;
} bst_node_t;

bst_node_t *root;

void create_node(bst_node_t **node, int value)
{
    bst_node_t *new_node = malloc(sizeof(bst_node_t));
    new_node->value = value;
    new_node->right_child = NULL;
    new_node->left_child = NULL;

    *node = new_node;
}

void insert_node(bst_node_t **head, int value)
{
    if(*head == NULL)
    {
        create_node(head, value);
    }
    if(value < (*head)->value)
    {
        insert_node(&(*head)->left_child, value);
    }
    else if(value > (*head)->value)
    {
        insert_node(&(*head)->right_child, value);
    }
}

int main(void)
{
    insert_node(&root, 2);
    printf("root val: %d\n", root->value); 
    insert_node(&root, 1);
    printf("root->left val: %d\n", root->left_child->value); 
    insert_node(&root, 0);
    printf("root->left val: %d\n", (root->left_child)->left_child->value); 
    return 0;
}
