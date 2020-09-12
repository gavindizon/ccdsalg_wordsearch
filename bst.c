#include "bst.h"

void create(nodeType *bst)
{
    if (bst == NULL)
    {
        bst = malloc(sizeof(nodeType *));
//        printf("Success");
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
    else{
    	(*BinarySearchTree)->cnt++;
	}
  
}

void inorder(nodeType *bst)
{
	if(bst!=NULL)
	{
		inorder(bst->pLeft);
		printf("%s %d\n", bst->word, bst->cnt);
		inorder(bst->pRight);	
	}	
}

nodeType* searchTree(nodeType *bst, String key){
	if(bst == NULL)
		return bst;
	else{
		if(strcmp(bst->word, key) == 0)
			return bst;
		else if(strcmp(bst->word, key) == 1)
			return searchTree(bst->pLeft, key);
		else
			return searchTree(bst->pRight, key);
	}
}
