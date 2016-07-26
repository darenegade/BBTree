//
// Created by René Zarwel on 25.07.16.
//
#include "BBTree.h"

bool BBTree::Node::search(const int searchKey) const {
    return key == searchKey ||
           ((left != nullptr) ? left->search(searchKey) : false) ||
           ((right != nullptr) ? right->search(searchKey) : false);
}

Node *BBTree::Node::insert(const int insertKey, const double alpha) {
    if (key == insertKey)
        return this;

    Node *ret;
    Node **pptrNode;

    if (insertKey < key) {
        pptrNode = &left;
    } else {
        pptrNode = &right;
    }

    if (*pptrNode == nullptr) {
        *pptrNode = new Node(insertKey);
        ret = *pptrNode;
        weight++;
    } else {
        ret = (*pptrNode)->insert(insertKey, alpha);
        weight = left->weight + right->weight;
    }

    checkBalance(&left, alpha);
    checkBalance(&right, alpha);

    return ret;
}

Node *BBTree::Node::remove(const int removeKey, const double alpha) {
    return nullptr;
}

void BBTree::Node::rotateLeft(Node **node) {
    Node *tmp = (*node)->right;
    (*node)->right = (*node)->right->left;
    tmp->left = *node;
    *node = tmp;
}

void BBTree::Node::rotateRight(Node **node) {
    Node *tmp = (*node)->left;
    (*node)->left = (*node)->left->right;
    tmp->right = *node;
    *node = tmp;
}

void BBTree::Node::rotateLeftRight(Node **node) {
    rotateLeft(&(*node)->left);
    rotateRight(node);
}

void BBTree::Node::rotateRightLeft(Node **node) {
    rotateRight(&(*node)->right);
    rotateLeft(node);
}

double BBTree::Node::balance() {
    return ((double) left->weight) / weight;
}

void BBTree::Node::checkBalance(Node **node, const double alpha) {
    double balance = (*node)->balance();

    //Fall1
    if (alpha > balance) {

        //Fall1.1
        if((*node)->right->balance() < alpha){
            rotateLeft(node);

        //Fall1.2
        } else {
            rotateRightLeft(node);
        }

    //Fall2
    } else if (balance > (1-alpha)){

        //Fall2.1
        if((*node)->left->balance() < alpha){
            rotateRight(node);

        //Fall2.2
        } else {
            rotateLeftRight(node);
        }
    }
}


bool BBTree::search(const int searchKey) const {
    return root->search(searchKey);
}

 BBTree::insert(const int insertKey) {
    root->insert(insertKey, alpha);
}

void BBTree::remove(const int removeKey) {
    root->remove(removeKey, alpha);
}





