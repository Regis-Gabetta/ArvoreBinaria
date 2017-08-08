#ifndef LISTA_SIMPLES
#define LISTA_SIMPLES

#include <stdlib.h>
#include <excpt.h>

using namespace std;

template<typename T>
class Arvore{

	struct No{
		T info;
		struct No *l;
		struct No *r;
		struct No *p;
	};

 public:
  Arvore();
  ~Arvore();
  Arvore(const Arvore<T> *a);
  unsigned int getCount() const;


	void insert(T o);
	void delete();
	void insert(T o);
	
 protected:
  struct NoLista *root; 
	unsigned int count;
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
Arvore<T>::~Arvore(){
  
}

template<typename T>
void Arvore<T>::delete(){
	
}

template<typename T>
void Arvore<T>::insert(T& o){
	No *no = root;

	if (root == NULL){
		root = new No(o, NULL, NULL);
	}

	else
		while(1){
			if (o < no->info){
				if (no->l == NULL){
					no->l = new No(o, NULL, NULL);
					break;
				}

				no = no->l;
				continue;
			}

			if (o > no->info){
				if (no->r == NULL){
				 no->r = new No(o, NULL, NULL);
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
