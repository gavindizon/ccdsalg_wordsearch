#include "bst.h"

void create(BST *bst)
{
    if (bst == NULL)
    {
        bst = malloc(sizeof(BST));
        printf("Success");
    }
    else
    {
        printf("Memory is already allocated in BST");
    }
}

void insert(BST *BinarySearchTree, nodeType *node)
{
}
void inorder(nodeType *bst)
{

    if (bst != NULL)
    {
        inorder((bst)->pLeft);
        printf("[%s] ", (bst)->S);
        inorder((bst)->pRight);
    }
}
