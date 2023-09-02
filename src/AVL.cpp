#include "AVL.hpp"

AVL::AVL() {
    this->root = NULL;
}

AVL::~AVL() {
    deleteBTS(this->root);
}

KnotAVL *AVL::getRoot() {
    return this->root;
}

void AVL::setRoot(KnotAVL *newRoot) {
    this->root = newRoot;
}

void AVL::deleteBTS(KnotAVL *current) {
    if (current != NULL) {
        deleteBTS(current->getLeft());
        deleteBTS(current->getRight());
        current = nullptr;
        delete(current);
    }
}

bool AVL::isEmpty() {
    return this->root == NULL;
}

bool AVL::isFull() {
    try {
        KnotAVL *ponteiro = new KnotAVL;
        delete(ponteiro);
        return false;
    }
    catch (bad_alloc exception) {
        return true;
    }
}

void AVL::insert(KnotAVL newKnot) {
    bool grow;
    addKnot(newKnot, this->root, grow);
}

void AVL::addKnot(KnotAVL newKnot, KnotAVL *&current, bool &grow) {
    if (current == NULL) {
        current = new KnotAVL(newKnot.getElement().getFrequency(), newKnot.getElement().getValue());
        grow = true;
    } else if (newKnot.getElement().getKey() < current->getElement().getKey()) {
        KnotAVL *pointer = current->getLeft();
        addKnot(newKnot, pointer, grow);
        if (grow) {
            current->setBalance(-1);
        }
    } else if (newKnot.getElement().getKey() > current->getElement().getKey()) {
        KnotAVL *pointer = current->getRight();
        addKnot(newKnot, pointer, grow);
        if (grow) {
            current->setBalance(1);
        }
    } else {
        cout << "\n\n./BST::insert(int frequency, string item) !ERROR! => KnotBST's key already inserts in the BST\n\n";
    }
    choseRotation(current);
    if (grow && current->getBalance() == 0) {
        grow = false;
    }
}

KnotAVL *AVL::search(string item) {
    KnotAVL *lookFor = new KnotAVL(item);
    KnotAVL *aux = this->root;
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

void AVL::searchToRemove(Word lookFor, KnotAVL *&current, KnotAVL *&dad, bool &decrease) {
    if (current != NULL) {
        if (lookFor.getKey() < current->getElement().getKey()) {
            KnotAVL *temporary = current->getLeft();
            searchToRemove(lookFor, temporary, current, decrease);
            if (decrease) {
                current->setBalance(1);
            }
        } else if (lookFor.getKey() > current->getElement().getKey()) {
            KnotAVL *temporary = current->getRight();
            searchToRemove(lookFor, temporary, current, decrease);
            if (decrease) {
                current->setBalance(-1);
            }
        } else {
            deleteKnotAVL(current, dad, decrease);
        }
        choseRotation(current);
        if (decrease && current->getBalance() != 0) {
            decrease = false;
        }
    }
}

void AVL::remove(string item) {
    Word lookFor(item);
    KnotAVL *dad = NULL;
    bool decrease;
    searchToRemove(lookFor, this->root, dad, decrease);
}

Word AVL::getNextKnotAVL(KnotAVL *aux) {
    aux = aux->getLeft();
    while (aux->getRight() != NULL) {
        aux = aux->getRight();
    }
    return aux->getElement();
}

void AVL::deleteKnotAVL(KnotAVL *&current, KnotAVL *&dad, bool &decrease) {
    if (dad == NULL) {
        current->setElement(getNextKnotAVL(current));
        KnotAVL *temporary = current->getLeft();
        searchToRemove(current->getElement(), temporary, this->root, decrease);
    } else if (current->getLeft() == NULL) {
        if (current == dad->getLeft()) {
            dad->setLeft(current->getRight());
            delete(current);
        } else {
            dad->setRight(current->getRight());
            delete(current);
        }
        decrease = true;
    } else if (current->getRight() == NULL) {
        if (current == dad->getLeft()) {
            dad->setLeft(current->getLeft());
            delete(current);
        } else {
            dad->setRight(current->getLeft());
            delete(current);
        }
        decrease = true;
    } else {
        current->setElement(getNextKnotAVL(current));
        KnotAVL *temporary = current->getLeft();
        searchToRemove(current->getElement(), temporary, current, decrease);
        if (decrease) {
            current->setBalance(1);
        }
    }
}

void AVL::preOrder(KnotAVL *current) {
    if (current != NULL) {
        cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
        preOrder(current->getLeft());
        preOrder(current->getRight());
    }
}

void AVL::centralOrder(KnotAVL *current) {
    if (current != NULL) {
        centralOrder(current->getLeft());
        cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
        centralOrder(current->getRight());
    }
}

void AVL::posOrder(KnotAVL *current) {
    if (current != NULL) {
        posOrder(current->getLeft());
        posOrder(current->getRight());
        cout << current->getElement().getKey() << " / " << current->getElement().getValue() << " / " << current->getElement().getFrequency() << endl;
    }
}

void AVL::leftRotation(KnotAVL *&current) {
    KnotAVL *newDad = current->getRight();
    current->setRight(newDad->getLeft());
    newDad->setLeft(current);
    current = newDad;
}

void AVL::rightRotation(KnotAVL *&current) {
    KnotAVL *newDad = current->getLeft();
    current->setLeft(newDad->getRight());
    newDad->setRight(current);
    current = newDad;
}

void AVL::doubleLeftRotation(KnotAVL *&current) {
    KnotAVL *sun = current->getLeft();
    leftRotation(sun);
    current->setLeft(sun);
    rightRotation(current);
}

void AVL::doubleRightRotation(KnotAVL *&current) {
    KnotAVL *sun = current->getRight();
    rightRotation(sun);
    current->setRight(sun);
    leftRotation(current);
}

void AVL::choseRotation(KnotAVL *&current) {
    KnotAVL *sun, *grandSun;
    if (current->getBalance() == -2) {     // rotação para a direita
        sun = current->getLeft();
        if (sun->getBalance() == -1) {     // simples
            current->setBalance(2);
            sun->setBalance(1);
            rightRotation(current);
        } else if (sun->getBalance() == 0) {     // simples
            current->setBalance(1);
            sun->setBalance(1);
            rightRotation(current);
        } else if (sun->getBalance() == 1) {     // dupla
            grandSun = sun->getRight();
            if (grandSun->getBalance() == -1) {
                current->setBalance(3);
                sun->setBalance(-1);
                grandSun->setBalance(1);
            } else if (grandSun->getBalance() == 0) {
                current->setBalance(2);
                sun->setBalance(-1);
            } else if (grandSun->getBalance() == 1) {
                current->setBalance(2);
                sun->setBalance(-2);
                grandSun->setBalance(-1);
            }
            doubleLeftRotation(current);
        }
    } else if (current->getBalance() == 2) { // rotação para a esquerda
        sun = current->getRight();
        if (sun->getBalance() == 1) {     // simples
            current->setBalance(-2);
            sun->setBalance(-1);
            leftRotation(current);
        } else if (sun->getBalance() == 0) {     // simples
            current->setBalance(-1);
            sun->setBalance(-1);
            leftRotation(current);
        } else if (sun->getBalance() == -1) {     // dupla
            grandSun = sun->getLeft();
            if (grandSun->getBalance() == -1) {
                current->setBalance(-2);
                sun->setBalance(2);
                grandSun->setBalance(1);
            } else if (grandSun->getBalance() == 0) {
                current->setBalance(-2);
                sun->setBalance(1);
            } else if (grandSun->getBalance() == 1) {
                current->setBalance(-3);
                sun->setBalance(1);
                grandSun->setBalance(-1);
            }
            doubleRightRotation(current);
        }
    }
}
