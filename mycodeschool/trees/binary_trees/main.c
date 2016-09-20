#include <stdio.h>
#include <stdlib.h>

// Only condition for a binary tree is a node can have no more than 2 children
typedef struct bst_node_t
{
    int value;
    struct bst_node_t *left_child;
    struct bst_node_t *right_child;
} bst_node_t;


bst_node_t* get_new_node(int data)
{
    bst_node_t *new_node = malloc(sizeof(bst_node_t));
    new_node->value=data;
    new_node->left_child=NULL;
    new_node->right_child=NULL;
    
    return new_node;
}
bst_node_t* insert_node(bst_node_t *root, int data)
{
    bst_node_t *temp = root;

    // if the tree is empty
    if(root == NULL)
    {
        root = get_new_node(data);
    }

    else if(data < temp->value)
    {
        root->left_child = insert_node(root->left_child, data);
    }
    else
    {
        root->right_child = insert_node(root->right_child, data);
    }

    return root;
}

bst_node_t *find_min(bst_node_t *root)
{
    bst_node_t *temp = root;

    while(temp->left_child != NULL)
    {
        temp = temp->left_child;
    }
    return temp;
}

bst_node_t* delete(bst_node_t *root, int data)
{
    // 3 cases to worry about:
    //  1) node has 0 children (leaf) - easy delete node and update link of parent to null. 
    //  2) node has 1 child - delete node, and update link of parent to node's child
    //  3) node has 2 children: copy the minimum of the nodes right subtree to the node, and then delete the duplicate value node (the once copied to the target node)
    //       can also use maximum value of the left subtree

   if(root == NULL)     // empty tree
   {
        return root;
   }

    // Recursion!!!
   else if(data < root->value)
   {
        root->left_child = delete(root->left_child, data);
   }
   else if(data > root->value)
   {
        root->right_child = delete(root->right_child, data);
   }
   else
   {
        // case 1 - node has no children
        if(root->right_child == NULL && root->left_child == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // case 2 - one child
        else if(root->left_child == NULL)
        {
            bst_node_t *temp = root;    // store the node to be deleted
            root = root->right_child;         // move the node to the subchild
            free(temp);
            return root;
        }
        else if(root->right_child == NULL)
        {
            bst_node_t *temp = root;
            root = root->left_child;
            free(temp);
            return root;
        }

        // case 3 - two children
        else
        {
            bst_node_t *temp = find_min(root->right_child);
            root->value = temp->value;
            root->right_child = delete(root->right_child, temp->value);
        }
   }

   return root;

}

int search_tree(bst_node_t *root, int data)
{
    if(root == NULL) return 0;
    else if(root->value == data) return 1;
    else if(data <= root->value) return search_tree(root->left_child, data);
    else return search_tree(root->right_child, data);
}

int main(void)
{
    bst_node_t *root;   // empty tree
    root = NULL;
    root = insert_node(root, 15);
    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 25);
    root = insert_node(root, 8);
    root = insert_node(root, 12);

    printf("Search Result: %d\n", search_tree(root, 15));
    delete(root, 15);
    printf("Search Result: %d\n", search_tree(root, 15));
    printf("Search Result: %d\n", search_tree(root, 10));
    printf("Search Result: %d\n", search_tree(root, 20));

    return 0;
}
