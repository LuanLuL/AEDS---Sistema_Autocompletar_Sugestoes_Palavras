#include "KnotBST.hpp"

KnotBST::KnotBST() {
    this->element = Word();
    this->left = NULL;
    this->right = NULL;
}

KnotBST::KnotBST(int frequency, string value) {
    this->element = Word(frequency, value);
    this->left = NULL;
    this->right = NULL;
}

KnotBST::KnotBST(string value) {
    this->element = Word(value);
    this->left = NULL;
    this->right = NULL;
}

KnotBST::~KnotBST() {/*...*/ }

Word KnotBST::getElement() {
    return this->element;
}

void KnotBST::setElement(Word newElement) {
    this->element = newElement;
}

KnotBST *KnotBST::getLeft() {
    return this->left;
}

void KnotBST::setLeft(KnotBST *newLeft) {
    this->left = newLeft;
}

KnotBST *KnotBST::getRight() {
    return this->right;
}

void KnotBST::setRight(KnotBST *newRight) {
    this->right = newRight;
}