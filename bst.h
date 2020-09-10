typedef struct node
{
    char *S;
    struct node *pLeft, *pRight, *pParent;
} nodeType;

typedef nodeType *BST;

void create(BST *BinarySearchTree);
int search(nodeType *BST, char *key);
void insert(BST *BinarySearchTree, nodeType *node);
void inorder(nodeType *bst);
void destroy(nodeType *BST);