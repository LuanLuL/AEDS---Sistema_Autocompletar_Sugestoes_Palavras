#ifndef __BST_HPP
#define __BST_HPP

#include <iostream>
#include <cstddef>
#include <unordered_map>
#include "KnotBST.hpp"
#include "Word.hpp"
using namespace std;

class BST {
private:
	KnotBST *root;
public:
	BST();
	BST(unordered_map<string, int> &hash);
	~BST();
	KnotBST *getRoot();
	void setRoot(KnotBST *newRoot);
	bool isEmpty();
	void insert(KnotBST item);
	KnotBST *search(string item);
	void searchToRemove(Word lookFor, KnotBST *&current, KnotBST *&dad);
	void remove(string item);
	void removeAll();
	Word getNextLeft(KnotBST *aux);
	Word getNextRight(KnotBST *aux);
	void deleteKnotBST(KnotBST *&current, KnotBST *&dad);
	void preOrder(KnotBST *current, string &output);
	void centralOrder(KnotBST *current, string &output);
	void posOrder(KnotBST *current, string &output);
};

#endif
