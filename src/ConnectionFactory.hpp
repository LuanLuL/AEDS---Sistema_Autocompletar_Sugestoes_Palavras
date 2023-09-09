#ifndef __CONNECTIONFACTORY_HPP
#define __CONNECTIONFACTORY_HPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Word.hpp"
#include "AVL.hpp"
#include "BST.hpp"
#include "HBT.hpp"

using namespace std;

class ConnectionFactory {
private:
    vector<string> stopWords;
public:
    ConnectionFactory();
    ~ConnectionFactory();
    vector<string> getStopWords();
    void setStopWords(vector<string> newStopWords);
    ifstream getConnectionIf(string path);
    void closeConnection(ifstream &dataset);
    ofstream getConnectionOf(string path);
    void closeConnection(ofstream &dataset);
    void select(ifstream &dataset, unordered_map<string, int> *hash);
    string removeAccents(string linha);
    bool isStopWord(string palavra);
    vector<string> getFileSearch(string word);
    bool isThereWord(ifstream &dataset, string word);
    void tidyOutput(unordered_map<string, int> *hash, short int size, short int output);
};

#endif