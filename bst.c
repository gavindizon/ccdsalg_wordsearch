#include "bst.h"

void create(nodeType *bst)
{
	if (bst == NULL)
	{
		bst = malloc(sizeof(nodeType *));
		//        printf("Success");
	}
}

nodeType *create_node(String word)
{
	nodeType *node = (nodeType *)malloc(sizeof(nodeType));
	node->pLeft = NULL;
	node->pRight = NULL;
	node->cnt = 1;
	strcpy(node->word, word);
	return node;
}

void insert(nodeType **BinarySearchTree, String word)
{
	nodeType *node = searchTree(*BinarySearchTree, word);
	if (node == NULL)
	{

		if (*BinarySearchTree == NULL)
		{
			*BinarySearchTree = create_node(word);
		}
		else if (strcmp(word, (*BinarySearchTree)->word) == -1)
		{
			insert(&(*BinarySearchTree)->pLeft, word);
		}
		else if ((strcmp(word, (*BinarySearchTree)->word) == 1))
		{
			insert(&(*BinarySearchTree)->pRight, word);
		}
	}
	else if (strcmp(node->word, word) == 0)
	{
		node->cnt++;
	}
}

void inorder(nodeType *bst, FILE *fp)
{
	if (bst != NULL)
	{
		inorder(bst->pLeft, fp);
		fprintf(fp, "%s %d\n", bst->word, bst->cnt);
		inorder(bst->pRight, fp);
	}
}

nodeType *searchTree(nodeType *bst, String key)
{
	if (bst == NULL)
		return NULL;
	else
	{
		if (strcmp(bst->word, key) == 0)
			return bst;
		else if (strcmp(bst->word, key) == 1)
			return searchTree(bst->pLeft, key);
		else
			return searchTree(bst->pRight, key);
	}
}

void destroy(nodeType *BST)
{
//	struct node *node1 = BST->pLeft;
//	struct node *node2;
//
//	while (node1 != NULL)
//	{
//		node2 = node1->pLeft;
//		free(node1);
//		node1 = node2;
//	}
//
//	node1 = BST->pRight;
//
//	while (node1 != NULL)
//	{
//		node2 = node1->pLeft;
//		free(node1);
//		node1 = node2;
//	}
//
//	memset(BST->word, 0, sizeof(BST->word));

	if (BST == NULL)
		return;
	
	destroy(BST->pLeft);
	
	destroy(BST->pRight);
	
	free(BST);
}
