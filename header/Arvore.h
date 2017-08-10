#ifndef ARVORE
#define ARVORE

#include <stdlib.h>
#include <excpt.h>

using namespace std;

template<typename T>
class Arvore{

	struct Node{
		T info;
		struct Node *l;
		struct Node *r;
		struct Node *p;
	};

 public:
  Arvore();
  ~Arvore();
  Arvore(const Arvore<T> *a);
  unsigned int getCount() const;


	void insert(T o);
	void delete();
	void insert(T o);
	String toString();
	
 protected:
  struct Node *root; 
	unsigned int count;
	String toStringAux(const Node *no, String str); 
};

template<typename T>
Arvore<T>::Arvore(){
  root = NULL; 
	count= 0;
}

template<typename T>
Arvore<T>::Arvore(const Arvore<T> *a){
	
}

template<typename T>
String Arvore<T>::toString(){
	return toStringAux(root, "");
}

template<typename T>
String Arvore<T>::toStringAux(const Node *no, String str){
	if (no != NULL){
		str += '(';
		
		str += toString(no->l, str);

		str += " " + no->info + " ";

		str += toString(no->r, str);

		str += ')';
	}

	return str;
}

template<typename T>
Arvore<T>::~Arvore(){
  
}

template<typename T>
void Arvore<T>::delete(){
	
}

template<typename T>
void Arvore<T>::insert(T& o){
	Node *no = root;

	if (root == NULL){
		root = new Node(o, NULL, NULL);
	}

	else
		while(1){
			if (o < no->info){
				if (no->l == NULL){
					no->l = new Node(o, NULL, NULL);
					break;
				}

				no = no->l;
				continue;
			}

			if (o > no->info){
				if (no->r == NULL){
					no->r = new Node(o, NULL, NULL);
					break;
			 }

				no = no->r;
				continue;
			 }

			break;		
		} 
}

template<typename T>
void Arvore<T>::balance(T& o){
	
}

#endif
