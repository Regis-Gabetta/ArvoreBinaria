#ifndef LISTA_SIMPLES
#define LISTA_SIMPLES

#include <stdlib.h>
#include <excpt.h>

using namespace std;

template<typename T>
class Arvore{

	struct No{
		T info;
		struct No *nx;
		struct No *pv;
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
void Arvore<T>::delete(T& o){
	
}

template<typename T>
void Arvore<T>::balance(T& o){
	
}

#endif
