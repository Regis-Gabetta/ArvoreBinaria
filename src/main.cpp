#include "Arvore.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **args){

	Arvore<char> a = Arvore<char>();
	char* c = (char*)malloc(15*sizeof(char));
	a.insert('Z');
	a.insert('A');
	a.insert('C');
	a.insert('B');
	a.insert('D');
	a.insert('F');
	a.insert('E');
	a.insert('W');
	a.insert('X');
	a.insert('Y');
	a.insert('Z');
	a.insert('a');
	a.insert('y');
	a.insert('w');
	a.insert('q');
	a.insert('k');
	a.insert('Q');
	a.insert('h');
	a.insert('S');
	a.insert('T');
	a.insert('U');
	a.insert('V');
	a.insert('W');
	a.insert('X');
	a.insert('Y');
	a.insert('Z');
	
	
	a.remove_Node(a.root,'A');
	a.remove_Node(a.root, 'S');
	a.remove_Node(a.root, 'T');
	a.remove_Node(a.root, 'A');
	a.remove_Node(a.root, 'E');
	a.remove_Node(a.root, 'G');
	a.remove_Node(a.root, 'G');

	
	std::cout << '\n' << a << '\n' << '\n'
						<< "count:" << a.getCount() << '\n'
						<< "height:" << a.getHeight() << '\n' << '\n';
	cin >> c;
	
	return 0;
}
