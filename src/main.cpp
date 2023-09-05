#include <iostream>
#include <clocale>
#include <unordered_map>
#include <string>
#include <vector>
#include "ConnectionFactory.hpp"
#include "Word.hpp"
#include "Heap.hpp"

#define FILES 6
#define TOPK 20

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    ConnectionFactory DAO;
    string output = "_______________________________________________________\n";
    vector<string> search = DAO.getFileSearch("pesquisar.txt");
    for (short int j = 0;j < search.size();j++) {
        unordered_map<string, int> wordsHash;
        output = output + "\nPalavra pesquisada: \'" + search[j] + "\'";
        for (short int i = 1;i <= FILES;i++) {
            ifstream file = DAO.getConnectionIf("input" + to_string(i) + ".txt");
            output = output + "\n\nINPUT " + to_string(i) + "\n";
            bool continueIndex = DAO.isThereWord(file, search[j]);
            file.seekg(0);
            if (continueIndex) {
                DAO.select(file, &wordsHash);
                output = output + "Frequência palavra pesquisada: \'" + to_string(wordsHash[search[j]]) + "\'\n";
                Heap heapTree(&wordsHash);
                wordsHash.clear();
                Word *wordsMostFrequency = heapTree.getWords(TOPK, search[j]);
                heapTree.freeMemory();
                output = output + "Palavras mais relevantes: \'[";
                for (int k = 0;k < TOPK;k++) {
                    output = output + wordsMostFrequency[k].getValue();
                    if (k == TOPK - 1) {
                        output = output + "]\n";
                    } else {
                        output = output + ", ";
                    }
                }
            } else {
                output = output + "Frequência palavra pesquisada: \'0\'\n";
            }
            DAO.closeConnection(file);
        }
        output = output + "\n_______________________________________________________\n";
    }
    ofstream file = DAO.getConnectionOf("output.txt");
    file << output;
    DAO.closeConnection(file);
}