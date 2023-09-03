#include <iostream>
#include <clocale>
#include "AVL.hpp"
#include "KnotAVL.hpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	AVL tree;
	KnotAVL palavra1(12, "cade");
	KnotAVL palavra2(12, "tudo");
	KnotAVL palavra3(12, "antes");
	KnotAVL palavra6(12, "mesm");
	KnotAVL palavra7(12, "mesd");

	tree.insert(palavra1);
	tree.insert(palavra2); 
	tree.insert(palavra3);
	tree.insert(palavra6);
	tree.insert(palavra7);

	cout << "\n------------------------\n\nKEY \\ WORD \\ FREQUENCY \n\n";
	tree.centralOrder(tree.getRoot());
	cout << "\n------------------------\n\n";
}