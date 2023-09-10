#ifndef __HBT_HPP
#define __HBT_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include "KnotHBT.hpp"
#include "Word.hpp"
using namespace std;

class HBT {
private:
    KnotHBT *root;
    int size;
public:
    HBT();
    HBT(unordered_map<string, int> &hash);
    ~HBT();
    KnotHBT *getRoot();
    void setRoot(KnotHBT *newRoot);
    int getSize();
    void setSize(int newSize);
    bool isEmpty();
    bool isLeaf(KnotHBT *current);
    void createList(unordered_map<string, int> &hash);
    void printList();
    void insertList(KnotHBT *&item);
    KnotHBT *removeList();
    void makeTree();
    void preOrder(KnotHBT *current, string &output);
    void centralOrder(KnotHBT *current, string &output);
    void posOrder(KnotHBT *current, string &output);
};

#endif