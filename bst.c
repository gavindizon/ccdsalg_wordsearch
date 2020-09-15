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
	nodeType *node = (nodeType *)malloc(sizeof(nodeType));
	node->pLeft = NULL;
	node->pRight = NULL;
	node->cnt = 1;
	strcpy(node->word, word);
	return node;
}

void insert(nodeType **BinarySearchTree, String word)
{
	/*
	nodeType *node = create_node(word);

	nodeType *copy = BinarySearchTree;

	nodeType *trail = NULL;

	while (copy != NULL)
	{
		trail = copy;
		if (strcmp(word, copy->word) == -1)
		{
			printf("Test");
			copy = copy->pLeft;
		}
		else
			copy = copy->pRight;
	}
	printf("FInished Loop");
	printf("Comparing, given word %s to %s", word, trail->word);
	if (trail == NULL) // tree is empty
		trail = node;
	else if (strcmp(word, trail->word) == -1)
	{
		printf("Test");
		trail->pLeft = node;
		printf("Test22");
	}

	else if (strcmp(word, trail->word) == 1)
		trail->pRight = node;
	else
		trail->cnt++;

	return trail;
*/
	nodeType *node = searchTree(*BinarySearchTree, word);
	// *BinarySearchTree = node;
	if (node == NULL)
	{
		// printf("node: %s\n bst: %s\n", node->word, (*BinarySearchTree)->word);

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
		// printf("")
		// printf("not null: \nnode: %s\n bst: %s\n", node->word, (*BinarySearchTree)->word);

		// (*BinarySearchTree)->cnt++;
		node->cnt++;
		// printf("%s: %d\n", node->word, node->cnt);
	}
	//return BinarySearchTree;
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
	struct node *node1 = BST->pLeft;
	struct node *node2;

	while (node1 != NULL)
	{
		node2 = node1->pLeft;
		free(node1);
		node1 = node2;
	}

	printf("\nSUCCess\n");

	node1 = BST->pRight;

	while (node1 != NULL)
	{
		node2 = node1->pLeft;
		free(node1);
		node1 = node2;
	}

	printf("\nsuccESS\n");

	memset(BST->word, 0, sizeof(BST->word));
}
