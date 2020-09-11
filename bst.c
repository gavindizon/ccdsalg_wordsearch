#include "bst.h"

void create(nodeType *bst)
{
    if (bst == NULL)
    {
        bst = malloc(sizeof(nodeType *));
        printf("Success");
    }
    else
    {
        printf("Memory is already allocated in BST");
    }
}

nodeType *create_node(String word)
{
    nodeType *node = malloc(sizeof(nodeType *));
    node->pLeft = NULL;
    node->pParent = NULL;
    node->pRight = NULL;
    strcpy(node->word, word);
    return node;
}

nodeType *insert(nodeType *bst, String word)
{
    nodeType *node = create_node(word);
    nodeType *parent = NULL;
    nodeType *x = bst;

    while (x != NULL)
    {
        parent = x;
        printf("TestA");
        if (strcmp(node->word, x->word) == -1)
        {
            printf("TestC");
            x = x->pLeft;
        }
        else
        {
            printf("TestB");
            x = x->pRight;
        }
    }

    node->pParent = parent;

    if (parent == NULL)
        bst = node;
    else if (strcmp(node->word, parent->word) == -1)
        parent->pLeft = node;
    else
        parent->pRight = node;
    printf("TestX");
    return bst;
}
