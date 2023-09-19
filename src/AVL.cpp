#include "AVL.hpp"

AVL::AVL() {
    this->root = NULL;
}

AVL::AVL(unordered_map<string, int> &hash) {
    this->root = NULL;
    for (const auto &element : hash) {
        KnotAVL newElement(element.second, element.first);
        insert(newElement);
    }
}

AVL::~AVL() {
    removeTree();
}

KnotAVL *AVL::getRoot() {
    return this->root;
}

void AVL::setRoot(KnotAVL *newRoot) {
    this->root = newRoot;
}

bool AVL::isEmpty() {
    return this->root == NULL;
}

void AVL::insert(KnotAVL newKnot) {
    bool grow;
    KnotAVL *dad = NULL;
    addKnot(newKnot, this->root, dad, grow);
}

void AVL::addKnot(KnotAVL newKnot, KnotAVL *&current, KnotAVL *&dad, bool &grow) {
    if (current == NULL) {
        grow = true;
        if (dad == NULL) {
            current = new KnotAVL(newKnot.getElement().getFrequency(), newKnot.getElement().getValue());
        } else {
            current = new KnotAVL(newKnot.getElement().getFrequency(), newKnot.getElement().getValue());
            if (newKnot.getElement().getKey() < dad->getElement().getKey()) {
                dad->setLeft(current);
            } else if (newKnot.getElement().getKey() > dad->getElement().getKey()) {
                dad->setRight(current);
            }
        }
    } else if (newKnot.getElement().getKey() < current->getElement().getKey()) {
        KnotAVL *pointer = current->getLeft();
        addKnot(newKnot, pointer, current, grow);
        if (grow) {
            current->setBalance(-1);
        }
        if (!(current->getBalance() <= 1 && current->getBalance() >= -1)) {
            choseRotation(current, dad, grow);
        }
        if (current->getBalance() == 0 && grow) {
            grow = false;
        }
    } else if (newKnot.getElement().getKey() > current->getElement().getKey()) {
        KnotAVL *pointer = current->getRight();
        addKnot(newKnot, pointer, current, grow);
        if (grow) {
            current->setBalance(1);
        }
        if (!(current->getBalance() <= 1 && current->getBalance() >= -1)) {
            choseRotation(current, dad, grow);
        }
        if (current->getBalance() == 0 && grow) {
            grow = false;
        }
    } else {
        cout << "\n\n./AVL::insert(int frequency, string item) !ERROR! => KnotAVL's key already inserts in the AVL\n\n";
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
    if (current != NULL && current != this->root) {
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
        if (current->getBalance() > 1 || current->getBalance() < -1) {
            choseRotation(current, dad, decrease);
        }
        if (decrease && current->getBalance() != 0) {
            decrease = false;
        }
    } else {
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
    }
}

void AVL::remove(string item) {
    Word lookFor(item);
    KnotAVL *dad = NULL;
    bool decrease;
    searchToRemove(lookFor, this->root, dad, decrease);
}

void AVL::removeAll(KnotAVL *current) {
    if (current != NULL) {
        removeAll(current->getLeft());
        removeAll(current->getRight());
        delete(current);
        current = NULL;
    }
}

void AVL::removeTree() {
    removeAll(this->root);
    this->root = NULL;
}

Word AVL::getNextLeft(KnotAVL *aux) {
    aux = aux->getLeft();
    while (aux->getRight() != NULL) {
        aux = aux->getRight();
    }
    return aux->getElement();
}

Word AVL::getNextRight(KnotAVL *aux) {
    aux = aux->getRight();
    while (aux->getLeft() != NULL) {
        aux = aux->getLeft();
    }
    return aux->getElement();
}

void AVL::deleteKnotAVL(KnotAVL *&current, KnotAVL *&dad, bool &decrease) {
    if (dad == NULL) {
        KnotAVL *temporary;
        if (current->getLeft() == NULL && current->getRight() == NULL) {
            delete(this->root);
            this->root = NULL;
        } else if (current->getLeft() == NULL) {
            current->setElement(getNextRight(current));
            temporary = current->getRight();
            searchToRemove(current->getElement(), temporary, this->root, decrease);
            if (decrease) {
                current->setBalance(-1);
            }
        } else {
            current->setElement(getNextLeft(current));
            temporary = current->getLeft();
            searchToRemove(current->getElement(), temporary, this->root, decrease);
            if (decrease) {
                current->setBalance(1);
            }
        }
    } else if (current->getLeft() == NULL) {
        if (current == dad->getLeft()) {
            dad->setLeft(current->getRight());
            delete(current);
            current->clearBalance();
        } else {
            dad->setRight(current->getRight());
            delete(current);
            current->clearBalance();
        }
        decrease = true;
    } else if (current->getRight() == NULL) {
        if (current == dad->getLeft()) {
            dad->setLeft(current->getLeft());
            delete(current);
            current->clearBalance();
        } else {
            dad->setRight(current->getLeft());
            delete(current);
            current->clearBalance();
        }
        decrease = true;
    } else {
        current->setElement(getNextLeft(current));
        KnotAVL *temporary = current->getLeft();
        searchToRemove(current->getElement(), temporary, current, decrease);
        if (decrease) {
            current->setBalance(1);
        }
    }
}

void AVL::preOrder(KnotAVL *current, string &output) {
    if (current != NULL) {
        output = output + current->getElement().getValue() + ", ";
        preOrder(current->getLeft(), output);
        preOrder(current->getRight(), output);
    }
}

void AVL::centralOrder(KnotAVL *current, string &output) {
    if (current != NULL) {
        centralOrder(current->getLeft(), output);
        output = output + current->getElement().getValue() + ", ";
        centralOrder(current->getRight(), output);
    }
}

void AVL::posOrder(KnotAVL *current, string &output) {
    if (current != NULL) {
        posOrder(current->getLeft(), output);
        posOrder(current->getRight(), output);
        output = output + current->getElement().getValue() + ", ";
    }
}

void AVL::leftRotation(KnotAVL *&current, KnotAVL *&dad) {
    KnotAVL *newDad = current->getRight();
    current->setRight(newDad->getLeft());
    newDad->setLeft(current);
    if (dad == NULL) {
        current = newDad;
    } else if (current == dad->getLeft()) {
        dad->setLeft(newDad);
    } else if (current == dad->getRight()) {
        dad->setRight(newDad);
    }
}

void AVL::rightRotation(KnotAVL *&current, KnotAVL *&dad) {
    KnotAVL *newDad = current->getLeft();
    current->setLeft(newDad->getRight());
    newDad->setRight(current);
    if (dad == NULL) {
        current = newDad;
    } else if (current == dad->getLeft()) {
        dad->setLeft(newDad);
    } else if (current == dad->getRight()) {
        dad->setRight(newDad);
    }
}

void AVL::doubleLeftRotation(KnotAVL *&current, KnotAVL *&dad) {
    KnotAVL *aux = current->getLeft();
    leftRotation(aux, current);
    rightRotation(current, dad);
}

void AVL::doubleRightRotation(KnotAVL *&current, KnotAVL *&dad) {
    KnotAVL *aux = current->getRight();
    rightRotation(aux, current);
    leftRotation(current, dad);
}

void AVL::choseRotation(KnotAVL *&current, KnotAVL *&dad, bool &grow) {
    KnotAVL *sun, *grandSun;
    if (current->getBalance() == -2) {     // rotação para a direita
        sun = current->getLeft();
        if (sun->getBalance() == -1) {     // simples
            current->setBalance(2);
            sun->setBalance(1);
            rightRotation(current, dad);
        } else if (sun->getBalance() == 0) {     // simples
            current->setBalance(1);
            sun->setBalance(1);
            rightRotation(current, dad);
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
            grow = false;
            doubleLeftRotation(current, dad);
        }
    } else if (current->getBalance() == 2) { // rotação para a esquerda
        sun = current->getRight();
        if (sun->getBalance() == 1) {     // simples
            current->setBalance(-2);
            sun->setBalance(-1);
            leftRotation(current, dad);
        } else if (sun->getBalance() == 0) {     // simples
            current->setBalance(-1);
            sun->setBalance(-1);
            leftRotation(current, dad);
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
            grow = false;
            doubleRightRotation(current, dad);
        }
    }
}
