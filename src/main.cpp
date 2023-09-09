#include <iostream>
#include <clocale>
#include <unordered_map>
#include <string>
#include <vector>
#include "ConnectionFactory.hpp"
#include "Word.hpp"
#include "MaxHeap.hpp"

#define FILES 6
#define TOPK 5

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    ConnectionFactory DAO;
    vector<string> search = DAO.getFileSearch("pesquisar.txt");
    for (short int j = 0; j < search.size(); j++) { // for each word of 'pesquisar.txt'
        unordered_map<string, int> wordsHash;
        for (short int i = 1;i <= FILES;i++) { // for each input 
            ifstream file = DAO.getConnectionIf("input" + to_string(i) + ".txt");
            if (DAO.isThereWord(file, search[j])) {
                DAO.select(file, &wordsHash); // pulls the words and their frequencies to hash
                MaxHeap heapTree(&wordsHash); // creates heap and cleans hash's memory
                wordsHash = heapTree.getWords(TOPK, search[j]); // gets the most frequency words this input and cleans heap's memory
                DAO.tidyOutput(&wordsHash, TOPK, i); // adds datas to output
            }
            DAO.closeConnection(file);
        }
    }
}