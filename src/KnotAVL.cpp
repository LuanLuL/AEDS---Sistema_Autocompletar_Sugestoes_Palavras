#include "KnotAVL.hpp"

KnotAVL::KnotAVL() {
    this->element = Word();
    this->left = NULL;
    this->right = NULL;
    this->balance = 0;
}

KnotAVL::KnotAVL(int frequency, string value) {
    this->element = Word(frequency, value);
    this->left = NULL;
    this->right = NULL;
    this->balance = 0;
}

KnotAVL::KnotAVL(string value) {
    this->element = Word(value);
    this->left = NULL;
    this->right = NULL;
    this->balance = 0;
}

KnotAVL::~KnotAVL() {/*...*/ }

Word KnotAVL::getElement() {
    return this->element;
}

void KnotAVL::setElement(Word newElement) {
    this->element = newElement;
}

short int KnotAVL::getBalance() {
    return this->balance;
}

void KnotAVL::setBalance(short int newBalance) {
    this->balance = this->balance + newBalance;
}

KnotAVL *KnotAVL::getLeft() {
    return this->left;
}

void KnotAVL::setLeft(KnotAVL *newLeft) {
    this->left = newLeft;
}

KnotAVL *KnotAVL::getRight() {
    return this->right;
}

void KnotAVL::setRight(KnotAVL *newRight) {
    this->right = newRight;
}