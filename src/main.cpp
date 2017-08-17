#include "Arvore.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **args){

	Arvore<char> a = Arvore<char>();
	char* c = (char*)malloc(15*sizeof(char));
//	a.insert('A');
//	a.insert('B');
//	a.insert('C');
//	a.insert('D');
//	a.insert('E');
//	a.insert('F');
//	a.insert('G');
//	a.insert('H');
//	a.insert('I');
//	a.insert('J');
//	a.insert('K');
//	a.insert('L');
//	a.insert('M');
//	a.insert('N');
//	a.insert('O');
//	a.insert('P');
//	a.insert('Q');
//	a.insert('R');
//	a.insert('S');
//	a.insert('T');
//	a.insert('U');
//	a.insert('V');
//	a.insert('W');
//	a.insert('X');
//	a.insert('Y');
//	a.insert('Z');
	
	a.insert('S');
	a.insert('A');
	a.insert('T');
	a.insert('U');
	a.insert('V');

	
	a.remove_Node(a.root,'A');
	//a.remove('A');
	//a.remove('Q');
	//a.remove('L');
	//a.remove('F');
	//a.remove('V');
	//a.remove('E');

	std::cout << '\n' << a << '\n' << '\n'
						<< "count:" << a.getCount() << '\n'
						<< "height:" << a.getHeight() << '\n' << '\n';
	cin >> c;
	
	return 0;
}
