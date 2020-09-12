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

int isCharacter (char c) {
	int ctr;
	char notAllowed[19] = {' ', '.', ',', '?', ';', '!', ':', '\'', '(', ')', '[', ']', '\"', '-', '/', '@', '{', '}', '\0'};
	
	for (ctr = 0; ctr < 19; ctr++) {
		if (c == notAllowed[ctr])
			return 0;
	}
	
	return 1;
}

void tokenizer (String fileName, String words[]) {
	int ctr = 0, wordCount = 0;
	char c;
	String word;
	FILE *fp;
	
	fp = fopen(fileName, "r");
		while (fscanf(fp, "%c", &c) == 1) {
			if (c >= 65 && c <= 90)
				c = tolower(c);
			
			if (isCharacter(c)) {
				word[ctr] = c;
				ctr++;
			} 
			
			else if (isCharacter(c) == 0) {
				word[ctr] = '\0';
				ctr = 0;
				
				if (strlen(word) >= 3) {
					strcpy(words[wordCount], word);
					wordCount++;
					
					memset(word, 0, sizeof(word));
				}
			}
		}
		
		if (strlen(word) >= 3) {
			strcpy(words[wordCount], word);
			wordCount++;
			
			memset(word, 0, sizeof(word));
		}
	
	for (ctr = 0; ctr < wordCount; ctr++) {
		printf("%s ", words[ctr]);
	}
	
	fclose(fp);
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
