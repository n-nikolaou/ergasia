#ifndef PROJECTDOMWN_BINARYSEARCHTREE_H
#define PROJECTDOMWN_BINARYSEARCHTREE_H

#include "Pair.h"
#include "unorderedTable.h"

/* EXPLANATION FOR EACH FUNCTION CAN BE FOUND
 * AT THE IMPLEMENTATION (binarySearchTree.cpp) */

/* the search tree is constructed recursively
 * each node is represented as a root having
 * only two children */
class binarySearchTree {
protected:
    /* the actual node which contains the data
     * of the Pair. actually a pointer to a Pair */
    Pair *data;
    /* the children of the node */
    binarySearchTree *left, *right;

public:
    binarySearchTree();
    binarySearchTree(Pair*);

    binarySearchTree* addPair(binarySearchTree*, Pair*);
    char searchTree(char*, binarySearchTree*);

    void setLeft(binarySearchTree*);
    void setRight(binarySearchTree*);

    Pair* getData();
    binarySearchTree* getLeft();
    binarySearchTree* getRight();
};


#endif //PROJECTDOMWN_BINARYSEARCHTREE_H
