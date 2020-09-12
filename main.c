typedef char String[46];

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.c"
#include "tokenizer.c"

int main()
{
	String fileName;
	String words[1024];
	int ctr, wordCount;
	
    nodeType *BinarySearchTree = NULL;
    nodeType* c = NULL;
//    c = malloc(sizeof(char) * 256);
    create(c);
    create(BinarySearchTree);

    String word = "Cenlo";
    String word2 = "Rrk";
    String word3 = "Ark";
    String word4 = "Ass";
    String word5 = "Cam";
    String word6 = "Red";
    
    printf("Input filename: ");
    scanf("%s", fileName);
    
    wordCount = tokenizer(fileName, words);
//	printf("%d", strlen(words));
	for (ctr = 0; ctr < wordCount; ctr++) {
		insert(&BinarySearchTree, words[ctr]);
	}
	inorder(BinarySearchTree);

// 	insert(&BinarySearchTree, word2)
// 	insert(&BinarySearchTree, word3)
// 	insert(&BinarySearchTree, word4)
    return 0;
}
