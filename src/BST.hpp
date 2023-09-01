#ifndef __BST_HPP
#define __BST_HPP

#include <iostream>
#include <cstddef>
#include "KnotBST.hpp"
#include "Word.hpp"
using namespace std;

class BST {
private:
	KnotBST *root;
public:
	BST();
	~BST();
	KnotBST *getRoot();
	void setRoot(KnotBST *newRoot);
	void deleteBTS(KnotBST *current);
	bool isEmpty();
	bool isFull();
	void insert(int frequency, string item);
	KnotBST *search(string item);
	void searchToRemove(Word lookFor, KnotBST *&current, KnotBST *&dad);
	void remove(string item);
	Word getNextKnotBST(KnotBST *aux);
	void deleteKnotBST(KnotBST *&current, KnotBST *&dad);
	void preOrder(KnotBST *current);
	void centralOrder(KnotBST *current);
	void posOrder(KnotBST *current);
};

#endif
