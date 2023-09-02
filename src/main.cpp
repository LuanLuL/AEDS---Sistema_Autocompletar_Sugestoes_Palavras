#include <iostream>
#include <clocale>
#include "AVL.hpp"
#include "KnotAVL.hpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	AVL tree;
	KnotAVL palavra1(12, "antes");
	KnotAVL palavra2(12, "tudo");
	KnotAVL palavra3(12, "cade");
	KnotAVL palavra4(12, "soldado");
	KnotAVL palavra5(12, "mesmo");

	tree.insert(palavra1);
	tree.insert(palavra2);
	tree.insert(palavra3);
	tree.insert(palavra4);
	tree.insert(palavra5);

	cout << "\n------------------------\n\nKEY \\ WORD \\ FREQUENCY \n\n";
	tree.centralOrder(tree.getRoot());
	cout << "\n------------------------\n\n";
}