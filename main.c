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
//	FILE *fp;
    nodeType *BinarySearchTree = NULL;

    create(BinarySearchTree);    
    printf("Input filename: ");
    scanf("%s", fileName);
//    fgets(fileName, 46, stdin);
//    fileName[strlen(fileName)-1] = '\0';
    printf("%s\n", fileName);
    
    wordCount = tokenizer(fileName, words);
	printf("%d\n", wordCount);
	
	for (ctr = 0; ctr < wordCount; ctr++) {
		insert(&BinarySearchTree, words[ctr]);
		printf("[%s]\n", words[ctr]);
	}
//	fp = fopen("WORDS.txt", "w");
//	inorder(BinarySearchTree, fp);
//	fclose(fp);

    return 0;
}
