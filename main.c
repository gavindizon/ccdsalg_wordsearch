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
    String word2 = "Ark";
    String word3 = "Ate";

    BinarySearchTree = insert(BinarySearchTree, word);

    printf("[%s]", (BinarySearchTree)->word);
    BinarySearchTree = insert(BinarySearchTree, word2);
    printf("[%s]", (BinarySearchTree)->pLeft->word);
    BinarySearchTree = insert(BinarySearchTree, word3);
    printf("[%s]", (BinarySearchTree)->pLeft->pLeft->word);

    /*    
    String word3 = "Gavin";
    String word4 = "B";


    //    inorder(bst);
    bst = insert(bst, word2);
    bst = insert(bst, word3);
    /*   inorder(*bst);
*/
    return 0;
}