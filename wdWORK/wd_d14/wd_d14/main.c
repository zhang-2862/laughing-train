#include"BST.h"

int main(void) {
    BST* bst = bst_create();
    bst_insert(bst, 1);
    bst_insert(bst, 4);
    bst_insert(bst, 7);
    bst_insert(bst, 9);
    bst_insert(bst, 3);
    bst_insert(bst, 5);

    bst_preorder(bst);

    bst_postorder(bst);
    
    bst_destroy(bst);

    //bst_levelorder2(bst);
    return 0;
}