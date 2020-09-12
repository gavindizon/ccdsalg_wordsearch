typedef struct node
{
    String word;
    struct node *pLeft, *pRight, *pParent;
    int cnt;
} nodeType;

void create(nodeType *BinarySearchTree);
int search(nodeType *BST, char *key);
void insert(nodeType **BinarySearchTree, String word);
void inorder(nodeType *bst, FILE *fp);
void destroy(nodeType *BST);

