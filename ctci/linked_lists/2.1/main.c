#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
}node_t;

node_t *g_root;   // pointer to the head of my empty linked list

uint32_t hash_node(node_t *node)
{
    return (node->value)*2654435761 % 2^32;
}
void insert_node(node_t *root, int value)
{
    node_t *temp = root;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;

    if(temp == NULL)
    {
        g_root = new_node;
        return;
    }

    while(temp->next != NULL)
    {   
        temp = temp->next;
    }

    temp->next = new_node;

}

void print_list(node_t *root)
{
    node_t *temp = root;

    while(temp != NULL)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void remove_duplicates(node_t *root)
{
    node_t *current, *look_ahead, *previous;

    current = root;
    previous = root;
    look_ahead = current->next;

    while(current != NULL)
    {
        look_ahead = current;
        while(look_ahead->next != NULL)
        {
            if(look_ahead->next->value == current->value)
            {
                look_ahead->next = look_ahead->next->next;
            }
            else
            {
                look_ahead = look_ahead->next;
            }
        }
        current = current->next;
    }

}

int main(void)
{
    int hash_value = 0;

    insert_node(g_root, 1);    
    insert_node(g_root, 1);    
    insert_node(g_root, 2);    
    insert_node(g_root, 2);    
    insert_node(g_root, 1);    
    insert_node(g_root, 3);    
    insert_node(g_root, 4);    
    insert_node(g_root, 4);    

    print_list(g_root);
     
    remove_duplicates(g_root);
    print_list(g_root);
    return 0;
}
