//
// Created by René Zarwel on 26.07.16.
//

#ifndef ALGDAT2_DIRECTLINKEDHASHLIST_H
#define ALGDAT2_DIRECTLINKEDHASHLIST_H


class DirectLinkedHashList {

private:
    struct Node {
        const int key;
        Node *next = nullptr;

        Node(const int k) : key(k) {}
        void insert(const int key);
        void remove(const int key);

        void print();
    };

    static const int m = 7;
    Node *data[m];

    int hash(int key) const;

public:
    bool search(const int key) const;
    void insert(const int key);
    void remove(const int key);

    void print();

};


#endif //ALGDAT2_DIRECTLINKEDHASHLIST_H
