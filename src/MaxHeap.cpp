#include "MaxHeap.hpp"

MaxHeap::MaxHeap(unordered_map<string, int> *hash) {
    this->heap = new pair<string, int>[(*hash).size()];
    this->wordsNumber = 0;
    for (const auto &elemento : (*hash)) {
        insert(elemento.first, elemento.second);
    }
    hash->clear();
}

MaxHeap::~MaxHeap() {/*...*/ }

int MaxHeap::getWordsNumber() {
    return this->wordsNumber;
}

void MaxHeap::setWordsNumber(int newWordsNumber) {
    this->wordsNumber = newWordsNumber;
}

void MaxHeap::freeMemory() {
    delete[] heap;
}

bool MaxHeap::isEmpty() {
    return (this->wordsNumber == 0);
}

void MaxHeap::fixUp(int index) {
    int indexDad = (int)((index - 1) / 2);
    pair<string, int> swap;
    if (indexDad >= 0 && this->heap[index].second > this->heap[indexDad].second) {
        swap = this->heap[index];
        this->heap[index] = this->heap[indexDad];
        this->heap[indexDad] = swap;
        fixUp(indexDad);
    }
}

void MaxHeap::fixDown(int index) {
    int indexSon = ((2 * index) + 1);
    pair<string, int> swap;
    if (indexSon < this->wordsNumber && indexSon < this->wordsNumber - 1) {
        if (this->heap[indexSon].second < this->heap[indexSon + 1].second) {
            indexSon++;
        }
        if (this->heap[indexSon].second > this->heap[index].second) {
            swap = this->heap[index];
            this->heap[index] = this->heap[indexSon];
            this->heap[indexSon] = swap;
            fixDown(indexSon);
        }
    }
}

void MaxHeap::insert(string text, int frequency) {
    this->wordsNumber++;
    pair<string, int> element(text, frequency);
    this->heap[this->wordsNumber - 1] = element;
    fixUp(this->wordsNumber - 1);
}

void MaxHeap::remove() {
    try {
        if (isEmpty()) {
            throw "./MaxHeap::insert(string text, int frequency) !ERROR! => The heap is empty";
        }
        pair<string, int> aux;
        this->heap[0] = this->heap[this->wordsNumber - 1];
        this->heap[this->wordsNumber - 1] = aux;
        this->wordsNumber--;
        fixDown(0);
    }
    catch (const char *msg) {
        cerr << msg << endl;
    }
}

void MaxHeap::print(int K) {
    cout << "\n---------- TOP " << K << " itens MAX HEAP ----------\n\n";
    cout << "0\t" "WORD\\FREQUENCY\n" << endl;
    for (short int i = 0; i < K; i++) {
        cout << i + 1 << "\t" << this->heap[i].first << "\\" << this->heap[i].second << endl;
    }
    cout << "\n----------------------------------\n";
}

unordered_map<string, int> MaxHeap::getWords(short int amount, string searchWord) {
    unordered_map<string, int> returnWords;
    for (short int i = 0; i < amount; i++) {
        if (this->heap[0].first == searchWord) {
            i--;
        } else {
            returnWords[this->heap[0].first] = this->heap[0].second;
        }
        remove();
    }
    freeMemory();
    return returnWords;
}
