#include "KnotHBT.hpp"

KnotHBT::KnotHBT() {
    this->element = Word();
    this->left = NULL;
    this->right = NULL;
    this->next = NULL;
}

KnotHBT::KnotHBT(int frequency, string value) {
    this->element = Word(frequency, value);
    this->left = NULL;
    this->right = NULL;
    this->next = NULL;
}

KnotHBT::KnotHBT(string value) {
    this->element = Word(value);
    this->left = NULL;
    this->right = NULL;
    this->next = NULL;
}

KnotHBT::~KnotHBT() {/*...*/ }

Word KnotHBT::getElement() {
    return this->element;
}

void KnotHBT::setElement(Word newElement) {
    this->element = newElement;
}

KnotHBT *KnotHBT::getLeft() {
    return this->left;
}

void KnotHBT::setLeft(KnotHBT *newLeft) {
    this->left = newLeft;
}

KnotHBT *KnotHBT::getRight() {
    return this->right;
}

void KnotHBT::setRight(KnotHBT *newRight) {
    this->right = newRight;
}

KnotHBT *KnotHBT::getNext() {
    return this->next;
}

void KnotHBT::setNext(KnotHBT *newNext) {
    this->next = newNext;
}
