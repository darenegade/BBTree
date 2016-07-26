//
// Created by René Zarwel on 26.07.16.
//
#include "DirectLinkedHashList.cpp"
#include <iostream>

using namespace std;

int main(){

    cout<< "Started:\n" << endl;

    DirectLinkedHashList *hashList = new DirectLinkedHashList();

    hashList->insert(15);
    hashList->insert(43);
    hashList->insert(2);
    hashList->insert(53);
    hashList->insert(12);
    hashList->insert(5);
    hashList->insert(19);

    hashList->print();

    cout << endl << "-------------" << endl << endl;

    hashList->remove(19);
    hashList->print();

}
