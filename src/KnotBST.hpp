#ifndef __KNOTBST_HPP
#define __KNOTBST_HPP

#include <iostream>
#include <string>
#include "Word.hpp"
using namespace std;

class KnotBST {
private:
    Word element;
    KnotBST *left, *right;
public:
    KnotBST();
    KnotBST(int frequency, string value);
    KnotBST(string value);
    ~KnotBST();
    Word getElement();
    void setElement(Word newElement);
    KnotBST *getLeft();
    void setLeft(KnotBST *newLeft);
    KnotBST *getRight();
    void setRight(KnotBST *newRight);
};

#endif