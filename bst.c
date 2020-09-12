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
    node->cnt = 1;
    strcpy(node->word, word);
    return node;
}

void insert(nodeType **BinarySearchTree, String word)
{
    if (*BinarySearchTree == NULL)
    {
        nodeType *node = create_node(word);
        *BinarySearchTree = (nodeType *)malloc(sizeof(struct node));
        *BinarySearchTree = node;
    }
    else if (strcmp(word, (*BinarySearchTree)->word) == -1)
    {
        insert(&(*BinarySearchTree)->pLeft, word);
    }
    else if ((strcmp(word, (*BinarySearchTree)->word) == 1))
    {
        insert(&(*BinarySearchTree)->pRight, word);
    }
    else
    {
        (*BinarySearchTree)->cnt++;
    }
}

void inorder(nodeType *bst)
{
	if(bst!=NULL)
	{
		inorder(bst->pLeft);
		printf("visited %s\n", bst->word);
		inorder(bst->pRight);	
	}	
}
