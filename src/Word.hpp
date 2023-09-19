#ifndef __WORD_HPP
#define __WORD_HPP

#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Word {
private:
    int key;
    int frequency;
    string value;
public:
    Word();
    Word(int frequency, string value);
    Word(string value);
    ~Word();
    int getFrequency();
    void setFrequency(int newFrequency);
    int getKey();
    void setKey(string parameter);
    string getValue();
    void setValue(string newValue);
};

#endif
