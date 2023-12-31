#include "BST.hpp"

BST::BST() {
  this->root = NULL;
}

BST::BST(unordered_map<string, int> &hash) {
  this->root = NULL;
  for (const auto &element : hash) {
    KnotBST newElement(element.second, element.first);
    insert(newElement);
  }
}

BST::~BST() {
  removeTree();
}

KnotBST *BST::getRoot() {
  return this->root;
}

void BST::setRoot(KnotBST *newRoot) {
  this->root = newRoot;
}

bool BST::isEmpty() {
  return this->root == NULL;
}

void BST::insert(KnotBST item) {
  KnotBST *newKnotBST = new KnotBST(item.getElement().getFrequency(), item.getElement().getValue());
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
      }
    }
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

void BST::removeAll(KnotBST *current) {
  if (current != NULL) {
    removeAll(current->getLeft());
    removeAll(current->getRight());
    delete(current);
    current = NULL;
  }
}

void BST::removeTree() {
  removeAll(this->root);
  this->root = NULL;
}

Word BST::getNextLeft(KnotBST *aux) {
  aux = aux->getLeft();
  while (aux->getRight() != NULL) {
    aux = aux->getRight();
  }
  return aux->getElement();
}

Word BST::getNextRight(KnotBST *aux) {
  aux = aux->getRight();
  while (aux->getLeft() != NULL) {
    aux = aux->getLeft();
  }
  return aux->getElement();
}

void BST::deleteKnotBST(KnotBST *&current, KnotBST *&dad) {
  if (dad == NULL) {
    KnotBST *temporary;
    if (current->getLeft() == NULL && current->getRight() == NULL) {
      delete(this->root);
      this->root = NULL;
    } else if (current->getLeft() == NULL) {
      current->setElement(getNextRight(current));
      temporary = current->getRight();
      searchToRemove(current->getElement(), temporary, this->root);
    } else {
      current->setElement(getNextLeft(current));
      temporary = current->getLeft();
      searchToRemove(current->getElement(), temporary, this->root);
    }
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
    current->setElement(getNextLeft(current));
    KnotBST *temporary = current->getLeft();
    searchToRemove(current->getElement(), temporary, current);
  }
}

void BST::preOrder(KnotBST *current, string &output) {
  if (current != NULL) {
    output = output + current->getElement().getValue() + ", ";
    preOrder(current->getLeft(), output);
    preOrder(current->getRight(), output);
  }
}

void BST::centralOrder(KnotBST *current, string &output) {
  if (current != NULL) {
    centralOrder(current->getLeft(), output);
    output = output + current->getElement().getValue() + ", ";
    centralOrder(current->getRight(), output);
  }
}

void BST::posOrder(KnotBST *current, string &output) {
  if (current != NULL) {
    posOrder(current->getLeft(), output);
    posOrder(current->getRight(), output);
    output = output + current->getElement().getValue() + ", ";
  }
}
