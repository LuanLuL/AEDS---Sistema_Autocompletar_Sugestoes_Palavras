#include <iostream>
#include <clocale>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "ConnectionFactory.hpp"
#include "MaxHeap.hpp"

#define FILES 6
#define TOPK 300

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    ConnectionFactory DAO;
    string output = "INPUT\t|\tPALAVRA BUSCADA\t|\tQUANTIDADE DE APARIÇÕES DA PALAVRA BUSCADA\t|\tÁRVORE BINÁRIA DE BUSCA\t|\tÁRVORE AVL\t|\tÁVORE DE HUFFMAN\t|\n";
    output = output + "__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n";
    vector<string> search = DAO.getFileSearch("pesquisar.txt");
    for (short int j = 0; j < search.size(); j++) { // for each word of 'pesquisar.txt'
        unordered_map<string, int> wordsHash;
        for (short int i = 1;i <= FILES;i++) { // for each input 
            ifstream file = DAO.getConnectionIf("input" + to_string(i) + ".txt");
            if (DAO.isThereWord(file, search[j])) {
                DAO.select(file, &wordsHash); // pulls the words and their frequencies to hash
                output = output + to_string(i) + "\t|\t" + search[j] + "\t|\t" + to_string(wordsHash[search[j]]) + "\t|\t[";
                MaxHeap heapTree(&wordsHash); // creates heap and cleans hash's memory
                wordsHash = heapTree.getWords(TOPK, search[j], i); // gets the most frequency words this input and cleans heap's memory
                output = output + DAO.tidyOutput(wordsHash) + "\t|\n\n"; // adds datas to output
            } else {
                output = output + to_string(i) + "\t|\t" + search[j] + "\t|\t0\t|\n\n";
            }
            DAO.closeConnection(file);
        }
        output = output + "__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n";
        // cout << output;
    }
    ofstream fileOut = DAO.getConnectionOf("output.txt");
    fileOut << output;
    DAO.closeConnection(fileOut);
}