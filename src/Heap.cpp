#include "Heap.hpp"

Heap::Heap(unordered_map<string, int> *hash) {
    this->heap = new pair<string, int>[(*hash).size()];
    this->wordsNumber = 0;
    for (const auto &elemento : (*hash)) {
        insert(elemento.first, elemento.second);
    }
}

Heap::~Heap() {/*...*/ }

int Heap::getWordsNumber() {
    return this->wordsNumber;
}

void Heap::setWordsNumber(int newWordsNumber) {
    this->wordsNumber = newWordsNumber;
}

void Heap::freeMemory() {
    delete[] heap;
}

bool Heap::isEmpty() {
    return (this->wordsNumber == 0);
}

void Heap::fixUp(int index) {
    int indexDad = (int)((index - 1) / 2);
    pair<string, int> swap;
    // Is there a father less than his son?
    if (indexDad >= 0 && this->heap[index].second > this->heap[indexDad].second) {
        swap = this->heap[index];
        this->heap[index] = this->heap[indexDad];
        this->heap[indexDad] = swap;
        fixUp(indexDad);
    }
}

void Heap::fixDown(int index) {
    int indexSon = ((2 * index) + 1);
    pair<string, int> swap;
    // How many sons does have?
    if (indexSon < this->wordsNumber && indexSon < this->wordsNumber - 1) {
        // Two children. so which son is bigger than his father?
        if (this->heap[indexSon].second < this->heap[indexSon + 1].second) {
            indexSon++;
        }
        // Is there a son more bigger than his father?
        if (this->heap[indexSon].second > this->heap[index].second) {
            swap = this->heap[index];
            this->heap[index] = this->heap[indexSon];
            this->heap[indexSon] = swap;
            fixDown(indexSon);
        }
    }
}

void Heap::insert(string text, int frequency) {
    this->wordsNumber++;
    pair<string, int> element(text, frequency);
    this->heap[this->wordsNumber - 1] = element;
    fixUp(this->wordsNumber - 1);
}

void Heap::remove() {
    try {
        if (isEmpty()) {
            throw "./Heap::insert(string text, int frequency) !ERROR! => The heap is empty";
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

void Heap::print(int K) {
    cout << "\n---------- TOP " << K << " itens ----------\n\n";
    cout << "0\t" "WORD\\FREQUENCY\n" << endl;
    for (short int i = 0; i < K; i++) {
        cout << i + 1 << "\t" << this->heap[i].first << "\\" << this->heap[i].second << endl;
    }
    cout << "\n----------------------------------\n";
}

Word *Heap::getWords(int amount, string searchWord) {
    Word *array = new Word[amount];
    Word aux;
    for (int i = 0; i < amount; i++) {
        if (this->heap[0].first == searchWord) {
            i--;
        } else {
            aux.setValue(this->heap[0].first);
            aux.setFrequency(this->heap[0].second);
            array[i] = aux;
        }
        remove();
    }
    return array;
}
