#include "BST.hpp"

BST::BST() {
  this->root = NULL;
}

BST::~BST() {
  deleteBTS(this->root);
}

KnotBST *BST::getRoot() {
  return this->root;
}

void BST::setRoot(KnotBST *newRoot) {
  this->root = newRoot;
}

void BST::deleteBTS(KnotBST *current) {
  if (current != NULL) {
    deleteBTS(current->getLeft());
    deleteBTS(current->getRight());
    current = nullptr;
    delete(current);
  }
}

bool BST::isEmpty() {
  return this->root == NULL;
}

bool BST::isFull() {
  try {
    KnotBST *ponteiro = new KnotBST;
    delete(ponteiro);
    return false;
  }
  catch (bad_alloc exception) {
    return true;
  }
}

void BST::insert(KnotBST item) {
  try {
    if (isFull()) {
      throw "./BST::insert(int frequency, string item) !ERROR! => System doesn't has enough memory";
    }
    KnotBST *newKnotBST = &item;
    if (isEmpty()) {
      this->root = newKnotBST;
    } else {
      KnotBST *aux = this->root;
      while (aux != NULL) {
        if (newKnotBST->getElement().getKey() < aux->getElement().getKey()) {
          if (aux->getLeft() == NULL) {
            aux->setLeft(newKnotBST);
            break;
          } else {
            aux = aux->getLeft();
          }
        } else if (newKnotBST->getElement().getKey() > aux->getElement().getKey()) {
          if (aux->getRight() == NULL) {
            aux->setRight(newKnotBST);
            break;
          } else {
            aux = aux->getRight();
          }
        } else {
          throw "./BST::insert(int frequency, string item) !ERROR! => KnotBST's key already inserts in the BST";
        }
      }
    }
  }
  catch (const char *msg) {
    cerr << msg << endl;
  }
}

KnotBST *BST::search(string item) {
  KnotBST *lookFor = new KnotBST(item);
  KnotBST *aux = this->root;
  while (aux != NULL) {
    if (lookFor->getElement().getKey() < aux->getElement().getKey()) {
      aux = aux->getLeft();
    } else if (lookFor->getElement().getKey() > aux->getElement().getKey()) {
      aux = aux->getRight();
    } else {
      return aux;
    }
  }
  return NULL;
}

void BST::searchToRemove(Word lookFor, KnotBST *&current, KnotBST *&dad) {
  if (current != NULL) {
    if (lookFor.getKey() < current->getElement().getKey()) {
      KnotBST *temporary = current->getLeft();
      searchToRemove(lookFor, temporary, current);
    } else if (lookFor.getKey() > current->getElement().getKey()) {
      KnotBST *temporary = current->getRight();
      searchToRemove(lookFor, temporary, current);
    } else {
      deleteKnotBST(current, dad);
    }
  }
}

void BST::remove(string item) {
  Word lookFor(item);
  KnotBST *dad = NULL;
  searchToRemove(lookFor, this->root, dad);
}

Word BST::getNextKnotBST(KnotBST *aux) {
  aux = aux->getLeft();
  while (aux->getRight() != NULL) {
    aux = aux->getRight();
  }
  return aux->getElement();
}

void BST::deleteKnotBST(KnotBST *&current, KnotBST *&dad) {
  if (dad == NULL) {
    current->setElement(getNextKnotBST(current));
    KnotBST *temporary = current->getLeft();
    searchToRemove(current->getElement(), temporary, this->root);
  } else if (current->getLeft() == NULL) {
    if (current == dad->getLeft()) {
      dad->setLeft(current->getRight());
      delete(current);
    } else {
      dad->setRight(current->getRight());
      delete(current);
    }
  } else if (current->getRight() == NULL) {
    if (current == dad->getLeft()) {
      dad->setLeft(current->getLeft());
      delete(current);
    } else {
      dad->setRight(current->getLeft());
      delete(current);
    }
  } else {
    current->setElement(getNextKnotBST(current));
    KnotBST *temporary = current->getLeft();
    searchToRemove(current->getElement(), temporary, current);
  }
}

void BST::preOrder(KnotBST *current) {
  if (current != NULL) {
    cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
    preOrder(current->getLeft());
    preOrder(current->getRight());
  }
}

void BST::centralOrder(KnotBST *current) {
  if (current != NULL) {
    centralOrder(current->getLeft());
    cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
    centralOrder(current->getRight());
  }
}

void BST::posOrder(KnotBST *current) {
  if (current != NULL) {
    posOrder(current->getLeft());
    posOrder(current->getRight());
    cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
  }
}
