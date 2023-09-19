#include "Word.hpp"

Word::Word() {
    this->key = -1;
    this->frequency = -1;
    this->value = "";
}

Word::Word(int frequency, string value) {
    this->frequency = frequency;
    this->value = value;
    setKey(this->value);
}

Word::Word(string value) {
    this->frequency = -1;
    this->value = value;
    setKey(this->value);
}

Word::~Word() {/*...*/ }

int Word::getFrequency() {
    return this->frequency;
}

void Word::setFrequency(int newFrequency) {
    this->frequency = newFrequency;
}

int Word::getKey() {
    return this->key;
}

void Word::setKey(string parameter) {
    hash<string> hasher;
    this->key = hasher(parameter);
}

string Word::getValue() {
    return this->value;
}

void Word::setValue(string newValue) {
    this->value = newValue;
    setKey(this->value);
}