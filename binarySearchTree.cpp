#include "binarySearchTree.h"
#include <string.h>
#include <cstdio>

/* the default constructor of the class
 * initializing every element with null pointer.
 * there is an overloaded constructor */
binarySearchTree::binarySearchTree() {
    data = nullptr;
    left = right = nullptr;
}

/* the constructor of the class initializing the data
 * of the root with the given Pair and its children
 * with null pointer */
binarySearchTree::binarySearchTree(Pair *newPair) {
    data = newPair;
    left = right = nullptr;
}

/* comparing the token of the given Pair with the
 * token of the Pair saved in the data and saving
 * either in the left or in the right child if the
 * token either greater or lesser than the token */
binarySearchTree* binarySearchTree::addPair(binarySearchTree *root, Pair *newPair) {
    if (root == nullptr) {
        printf("%s\n", newPair->getToken());
        return new binarySearchTree(newPair);
    }
    if (strcmp(data->getToken(), newPair->getToken()) < 0) root->setRight(addPair(root->getRight(), newPair));
    else root->setLeft(addPair(root->getLeft(), newPair));

    return root;
}

/* searching the tree recursively based on the token
 * string given and returning true or false if the token exists*/
char binarySearchTree::searchTree(char *token, binarySearchTree *node) {
    /* if node is pointing to null pointer then we return a value
     * different from 0 or 1 */
    if (node == nullptr) return 3;

    /* first recur on left child */
    if (searchTree(token, node->getLeft()) == 1) return 1;

    if (!strcmp(node->getData()->getToken(), token)) return 1;

    /* now recur on right child */
    if (searchTree(token, node->getRight()) == 1) return 1;

    return 0;
}

/* SETTERS */
void binarySearchTree::setLeft(binarySearchTree *left) { this->left = left;}
void binarySearchTree::setRight(binarySearchTree *right) { this->right = right;}

/* GETTERS */
Pair* binarySearchTree::getData() {return data;}
binarySearchTree* binarySearchTree::getLeft() {return left;}
binarySearchTree* binarySearchTree::getRight() {return right;}