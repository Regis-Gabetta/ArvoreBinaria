#include "Arvore.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **args){

	Arvore<char> a = Arvore<char>();

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
	
	a.insert('X');
	a.insert('A');
	a.insert('E');
	a.insert('C');
	a.insert('G');
	a.insert('I');
	a.insert('K');
	a.insert('P');
	a.insert('F');
	a.insert('L');
	a.insert('R');
	a.insert('J');
	a.insert('N');
	a.insert('O');
	a.insert('S');
	a.insert('B');
	a.insert('H');
	a.insert('Q');
	a.insert('T');
	a.insert('M');
	a.insert('D');
	a.insert('V');
	a.insert('U');
	a.insert('W');
	a.insert('Y');
	a.insert('Z');
	
	

	std::cout << '\n' << a.toString() << '\n' << '\n'
						<< "count:" << a.getCount() << '\n'
						<< "height:" << a.getHeight() << '\n' << '\n';
	
	return 0;
}
