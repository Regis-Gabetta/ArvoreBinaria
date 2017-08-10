#ifndef ARVORE
#define ARVORE

#include <stdlib.h>
#include <string>

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
	void remove();
	void balance();
	std::string toString();
	
 protected:
  struct Node *root; 
	unsigned int count;
	std::string toStringAux(const struct Node *no); 
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
std::string Arvore<T>::toString(){
	return toStringAux(root);
}

template<typename T>
std::string Arvore<T>::toStringAux(const Node *no){

	std::string str = "";
	
	if (no != NULL){
		str += "(";
		
		str += toStringAux(no->l);

		str += no->info;

		str += toStringAux(no->r);

		str += ")";
	}

	return str;
}

template<typename T>
Arvore<T>::~Arvore(){
  
}

template<typename T>
void Arvore<T>::remove(){
}

template<typename T>
void Arvore<T>::insert(T o){
	Node *no = root;
	
	if (root == NULL){
		root = (struct Node*) malloc(sizeof(struct Node));
		root->l = NULL;
		root->r = NULL;
		root->info = o;
	}

	else
		while(1){
			if (o < no->info){
				if (no->l == NULL){
					no->l =	(struct Node*) malloc(sizeof(struct Node));
					no->l->info = o;
					no->l->l = NULL;
					no->l->r = NULL;
					break;
				}

				no = no->l;
				continue;
			}

			if (o > no->info){
				if (no->r == NULL){
					no->r =	(struct Node*) malloc(sizeof(struct Node));
					no->r->info = o;
					no->r->l = NULL;
					no->r->r = NULL;
					break;
				}

				no = no->r;
				continue;
			 }

			break;		
		} 
}

template<typename T>
void Arvore<T>::balance(){
	
}

#endif
