//
// Created by René Zarwel on 26.07.16.
//

#include "DirectLinkedHashList.h"
#include <iostream>

using namespace std;

void DirectLinkedHashList::remove(const int key) {
    int hash = this->hash(key);

    if(data[hash] == nullptr){
        return;
    } else if (data[hash]->key == key) {
        data[hash] = data[hash]->next;
    } else {
        data[hash]->remove(key);
    }
}

void DirectLinkedHashList::insert(const int key) {
    int hash = this->hash(key);

    if(data[hash] == nullptr){
        data[hash] = new Node(key);
    } else {
        data[hash]->insert(key);
    }
}

bool DirectLinkedHashList::search(const int key) const {
    int hash = this->hash(key);

    Node *current;
    do{
        current = data[hash];
    } while (current != nullptr && current->key != key);

    return current != nullptr;

}

int DirectLinkedHashList::hash(int key) const {
    return key % m;
}


void DirectLinkedHashList::Node::insert(const int key) {
    if(next == nullptr){
        next = new Node(key);
    } else {
        next->insert(key);
    }
}

void DirectLinkedHashList::Node::remove(const int key) {
    if(next == nullptr){
        return;
    } else if (next->key == key) {
        next = next->next;
    } else {
        next->remove(key);
    }
}

void DirectLinkedHashList::print() {

    for (int i = 0; i < m; ++i) {
        if(data[i] != nullptr){
            data[i]->print();
        }
    }
}

void DirectLinkedHashList::Node::print() {
    cout<<key<< " ";

    if(next != nullptr){
        next->print();
    } else {
        cout<<endl;
    }
}



