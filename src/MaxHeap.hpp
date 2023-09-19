#ifndef __MAXHEAP_HPP
#define __MAXHEAP_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "Word.hpp"
using namespace std;

class MaxHeap {
private:
    int wordsNumber;
    pair<string, int> *heap;
public:
    MaxHeap(unordered_map<string, int> *hash);
    ~MaxHeap();
    int getWordsNumber();
    void setWordsNumber(int newWordsNumber);
    void freeMemory();
    bool isEmpty();
    void fixUp(int index);
    void fixDown(int index);
    void insert(string text, int frequency);
    bool remove(short int file);
    void print(int K);
    unordered_map<string, int> getWords(short int amount, string searchWord, short int file);
};

#endif