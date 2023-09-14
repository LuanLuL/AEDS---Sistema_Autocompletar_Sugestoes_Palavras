#ifndef __AVL_HPP
#define __AVL_HPP

#include <iostream>
#include <cstddef>
#include <unordered_map> 
#include "KnotAVL.hpp"
#include "Word.hpp"
using namespace std;

class AVL {
private:
    KnotAVL *root;
public:
    AVL();
    AVL(unordered_map<string, int> &hash);
    ~AVL();
    KnotAVL *getRoot();
    void setRoot(KnotAVL *newRoot);
    bool isEmpty();
    void insert(KnotAVL newKnot);
    void addKnot(KnotAVL newKnot, KnotAVL *&current, KnotAVL *&dad, bool &grow);
    KnotAVL *search(string item);
    void searchToRemove(Word lookFor, KnotAVL *&current, KnotAVL *&dad, bool &decrease);
    void remove(string item);
    void removeAll();
    Word getNextLeft(KnotAVL *aux);
    Word getNextRight(KnotAVL *aux);
    void deleteKnotAVL(KnotAVL *&current, KnotAVL *&dad, bool &decrease);
    void preOrder(KnotAVL *current, string &output);
    void centralOrder(KnotAVL *current, string &output);
    void posOrder(KnotAVL *current, string &output);
    void leftRotation(KnotAVL *&current, KnotAVL *&dad);
    void rightRotation(KnotAVL *&current, KnotAVL *&dad);
    void doubleLeftRotation(KnotAVL *&current, KnotAVL *&dad);
    void doubleRightRotation(KnotAVL *&current, KnotAVL *&dad);
    void choseRotation(KnotAVL *&current, KnotAVL *&dad, bool &grow);
};

#endif
