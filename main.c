#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.c"

int main()
{

    BST *bst = NULL;
    create(bst);

    nodeType *node = malloc(sizeof(node));
    strcpy(node->S, "A");
    node->pLeft = NULL;
    node->pParent = NULL;
    node->pRight = NULL;

    insert(bst, node);
    inorder(*bst);

    return 0;
}