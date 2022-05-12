#include "avlSearchTree.h"
#include <string.h>

avlSearchTree::avlSearchTree() {
    data = nullptr;
    left = right = nullptr;
    height = 0;
}

avlSearchTree::avlSearchTree(Pair *newPair) {
    data = newPair;
    left = right = nullptr;
    height = 1;
}

long int avlSearchTree::Height(avlSearchTree *root) {
    //calculates the height of tree
    {
        if (root == NULL)
            return 0;
        return root->height;
    }
}

long int avlSearchTree::max(int a, int b){
    return (a > b)? a : b;
}

avlSearchTree* avlSearchTree::addPair(avlSearchTree *root, Pair *newPair) {
    if (root == nullptr) return new avlSearchTree(newPair);
    if (strcmp(data->getToken(), newPair->getToken()) < 0) root->setRight(addPair(root->getRight(), newPair));
    else root->setLeft(addPair(root->getLeft(), newPair));

    root->height = 1 + max(Height(root->left),Height(root->right));

    long int balance = getBalance(root);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && newPair->getToken() < root->left->data->getToken())
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && newPair->getToken() > node->right->
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && newPair->getToken() > node->left->newPair->getToken())
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && newPair->getToken() < node->right->newPair->getToken())
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return root;
}

// Get Balance factor
long int avlSearchTree::getBalance(avlSearchTree *root)
{
    if (root == NULL)
        return 0;
    return Height(root->left) - Height(root->right);
}



char avlSearchTree::searchTree(char *token, avlSearchTree *node) {
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

void avlSearchTree::setLeft(avlSearchTree *left) { this->left = left;}
void avlSearchTree::setRight(avlSearchTree *right) { this->right = right;}

Pair* avlSearchTree::getData() {return data;}
avlSearchTree* avlSearchTree::getLeft() {return left;}
avlSearchTree* avlSearchTree::getRight() {return right;}