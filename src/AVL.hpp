#ifndef __AVL_HPP
#define __AVL_HPP

#include <iostream>
#include <cstddef>
#include "KnotAVL.hpp"
#include "Word.hpp"
using namespace std;

class AVL {
private:
    KnotAVL *root;
public:
    AVL();
    ~AVL();
    KnotAVL *getRoot();
    void setRoot(KnotAVL *newRoot);
    void deleteBTS(KnotAVL *current);
    bool isEmpty();
    bool isFull();
    void insert(KnotAVL newKnot);
    void addKnot(KnotAVL newKnot, KnotAVL *&current, bool &grow);
    KnotAVL *search(string item);
    void searchToRemove(Word lookFor, KnotAVL *&current, KnotAVL *&dad, bool &decrease);
    void remove(string item);
    Word getNextKnotAVL(KnotAVL *aux);
    void deleteKnotAVL(KnotAVL *&current, KnotAVL *&dad, bool &decrease);
    void preOrder(KnotAVL *current);
    void centralOrder(KnotAVL *current);
    void posOrder(KnotAVL *current);
    void leftRotation(KnotAVL *&current);
    void rightRotation(KnotAVL *&current);
    void doubleLeftRotation(KnotAVL *&current);
    void doubleRightRotation(KnotAVL *&current);
    void choseRotation(KnotAVL *&current);
};

#endif
