#include "Arvore.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **args){

	Arvore<char> a = Arvore<char>();

	a.insert('M');
	a.insert('C');
	a.insert('G');
	a.insert('D');
	a.insert('Z');

	std::cout << '\n' << a.toString() << '\n' << '\n';
	
	return 0;
}
