#ifndef __KNOTAVL_HPP
#define __KNOTAVL_HPP

#include <iostream>
#include <string>
#include "Word.hpp"
using namespace std;

class KnotAVL {
private:
    Word element;
    short int balance;
    KnotAVL *left, *right;
public:
    KnotAVL();
    KnotAVL(int frequency, string value);
    KnotAVL(string value);
    ~KnotAVL();
    Word getElement();
    void setElement(Word newElement);
    short int getBalance();
    void setBalance(short int newBalance);
    KnotAVL *getLeft();
    void setLeft(KnotAVL *newLeft);
    KnotAVL *getRight();
    void setRight(KnotAVL *newRight);
    void clearBalance();
};

#endif