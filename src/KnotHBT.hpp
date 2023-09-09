#ifndef __KNOTHBT_HPP
#define __KNOTHBT_HPP

#include <iostream>
#include <string>
#include "Word.hpp"
using namespace std;

class KnotHBT {
private:
    Word element;
    KnotHBT *left, *right, *next;
public:
    KnotHBT();
    KnotHBT(int frequency, string value);
    KnotHBT(string value);
    ~KnotHBT();
    Word getElement();
    void setElement(Word newElement);
    KnotHBT *getLeft();
    void setLeft(KnotHBT *newLeft);
    KnotHBT *getRight();
    void setRight(KnotHBT *newRight);
    KnotHBT *getNext();
    void setNext(KnotHBT *newNext);
};

#endif