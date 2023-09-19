#include "HBT.hpp"

HBT::HBT() {
    this->root = NULL;
    this->size = 0;
}

HBT::HBT(unordered_map<string, int> &hash) {
    this->root = NULL;
    this->size = 0;
    createList(hash);
    hash.clear();
    makeTree();
}

HBT::~HBT() {
    removeTree();
}

KnotHBT *HBT::getRoot() {
    return this->root;
}

void HBT::setRoot(KnotHBT *newRoot) {
    this->root = newRoot;
}

int HBT::getSize() {
    return this->size;
}

void HBT::setSize(int newSize) {
    this->size = newSize;
}

bool HBT::isEmpty() {
    return (this->root == NULL && this->size == 0);
}

bool HBT::isLeaf(KnotHBT *current) {
    return (current->getLeft() == NULL && current->getRight() == NULL && current->getNext() == 0);
}

void HBT::createList(unordered_map<string, int> &hash) {
    for (const auto &elemento : hash) {
        KnotHBT *newElement = new KnotHBT(elemento.second, elemento.first);
        insertList(newElement);
    }
}

void HBT::printList() {
    KnotHBT *aux = this->root;
    cout << "\n\n";
    while (aux != NULL) {
        cout << aux->getElement().getValue() << " - " << aux->getElement().getFrequency() << endl;
        aux = aux->getNext();
    }
    cout << "\n\n";
}

void HBT::insertList(KnotHBT *&item) {
    if (isEmpty()) {
        this->root = item;
    } else if (item->getElement().getFrequency() < this->root->getElement().getFrequency()) {
        item->setNext(this->root);
        this->root = item;
    } else {
        KnotHBT *aux = this->root;
        while (aux->getNext() && aux->getNext()->getElement().getFrequency() <= item->getElement().getFrequency()) {
            aux = aux->getNext();
        }
        item->setNext(aux->getNext());
        aux->setNext(item);
    }
    this->size++;
}

KnotHBT *HBT::removeList() {
    KnotHBT *aux = NULL;
    if (!(isEmpty())) {
        aux = this->root;
        this->root = aux->getNext();
        this->size--;
        aux->setNext(NULL);
    }
    return aux;
}

void HBT::makeTree() {
    KnotHBT *first, *second;
    while (this->size > 1) {
        first = removeList();
        second = removeList();
        KnotHBT *newELement = new KnotHBT((first->getElement().getFrequency() + second->getElement().getFrequency()), "+");
        newELement->setLeft(first);
        newELement->setRight(second);
        insertList(newELement);
    }
}

void HBT::removeAll(KnotHBT *current) {
    if (current != NULL) {
        removeAll(current->getLeft());
        removeAll(current->getRight());
        delete(current);
        current = NULL;
    }
}

void HBT::removeTree() {
    removeAll(this->root);
    this->size = 0;
    this->root = NULL;
}

void HBT::preOrder(KnotHBT *current, string &output, string huffmanCodification) {
    if (current != NULL) {
        if (isLeaf(current)) {
            output = output + current->getElement().getValue() + "-" + huffmanCodification + ", ";
        }
        preOrder(current->getLeft(), output, (huffmanCodification + "0"));
        preOrder(current->getRight(), output, (huffmanCodification + "1"));
    }
}

void HBT::centralOrder(KnotHBT *current, string &output, string huffmanCodification) {
    if (current != NULL) {
        centralOrder(current->getLeft(), output, (huffmanCodification + "0"));
        if (isLeaf(current)) {
            output = output + current->getElement().getValue() + ", ";
        }
        centralOrder(current->getRight(), output, (huffmanCodification + "1"));
    }
}

void HBT::posOrder(KnotHBT *current, string &output, string huffmanCodification) {
    if (current != NULL) {
        posOrder(current->getLeft(), output, (huffmanCodification + "0"));
        posOrder(current->getRight(), output, (huffmanCodification + "1"));
        if (isLeaf(current)) {
            output = output + current->getElement().getValue() + ", ";
        }
    }
}