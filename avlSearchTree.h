#ifndef PROJECTDOMWN_AVLSEARCHTREE_H
#define PROJECTDOMWN_AVLSEARCHTREE_H


#include "binarySearchTree.h"

class avlSearchTree {
protected:
    Pair *data;
    avlSearchTree *left, *right;
    long int height;
public:
    avlSearchTree();
    avlSearchTree(Pair*);

    avlSearchTree* addPair(char *token, avlSearchTree*, Pair*);
    char searchTree(char*, avlSearchTree*);

    long int Height(avlSearchTree* );
    long int max(int a, int b);
    long int getBalance(avlSearchTree *);

    void setLeft(avlSearchTree*);
    void setRight(avlSearchTree*);

    Pair* getData();
    avlSearchTree* getLeft();
    avlSearchTree* getRight();
};


#endif //PROJECTDOMWN_AVLSEARCHTREE_H
