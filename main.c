typedef char String[46];

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.c"

int main()
{

    nodeType *BinarySearchTree = NULL;
    create(BinarySearchTree);

    String word = "Cenlo";
    String word2 = "Rrk";
    String word3 = "Ark";
    String word4 = "Ass";
    String word5 = "Cam";
    String word6 = "Red";

    insert(&BinarySearchTree, word);
    printf("\n1. [%s] [%d]\n", (BinarySearchTree)->word, (BinarySearchTree)->cnt);
    insert(&BinarySearchTree, word2);
    printf("2. [%s] [%d]\n", (BinarySearchTree)->pRight->word, (BinarySearchTree)->pRight->cnt);
    insert(&BinarySearchTree, word3);
    printf("3. [%s] [%d]\n", (BinarySearchTree)->pLeft->word, (BinarySearchTree)->pLeft->cnt);
    insert(&BinarySearchTree, word4);
    printf("4. [%s] [%d]\n", (BinarySearchTree)->pLeft->pRight->word, (BinarySearchTree)->pLeft->cnt);
    insert(&BinarySearchTree, word5);
    printf("5. [%s] [%d]\n", (BinarySearchTree)->pLeft->pRight->pRight->word, (BinarySearchTree)->pLeft->pRight->pRight->cnt);
    insert(&BinarySearchTree, word6);
    printf("6. [%s] [%d]\n", (BinarySearchTree)->pRight->pLeft->word, (BinarySearchTree)->pRight->pLeft->cnt);
    //   printf("7. [%s] [%d]\n", (BinarySearchTree)->pRight->pRight->word, (BinarySearchTree)->pRight->pRight->cnt);
    insert(&BinarySearchTree, word);
    insert(&BinarySearchTree, word);
    printf("\n1. [%s] [%d]\n", (BinarySearchTree)->word, (BinarySearchTree)->cnt);
    //printf("7. [%s] [%d]\n", (BinarySearchTree)->pRight->pRight->word, (BinarySearchTree)->pRight->pRight->cnt);

    /*    
    String word3 = "Gavin";
    String word4 = "B";


    //    inorder(bst);
    bst = insert(bst, word2);
    bst = insert(bst, word3);
       inorder(*bst);
*/
    return 0;
}