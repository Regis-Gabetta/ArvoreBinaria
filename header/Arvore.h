#ifndef ARVORE
#define ARVORE

#include <stdlib.h>
#include <string>

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)
#define bf(n) (height(n->l) - height(n->r))

using namespace std;

template<typename T>
class Arvore{

	struct Node{
		T info;
		Node *l;
		Node *r;
		Node *p;

		unsigned int h;
	};
 public:
  Arvore();
  ~Arvore();
  Arvore(const Arvore<T> *a);
  unsigned int getCount() const;
	unsigned int getHeight() const;


	void insert(T o);
	char remove(T o);
	int remove_Node(Node *raiz, T o);
	struct Node* procuraMenor(struct Node *atual);
	std::string toString();
	
 protected:
  Node *root; 
	unsigned int count;
	std::string toStringAux(const Node *no);
	
	void rotateLeft(Node *x);
	void rotateRight(Node *y);
	void copyNode(Node *n1, Node *n2);
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
unsigned int Arvore<T>::getHeight() const{
	return height(root);
}

template<typename T>
unsigned int Arvore<T>::getCount() const{
	return count;
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
int Arvore<T>::remove_Node(Node *raiz, T o){
	if(raiz == NULL)
		return 0;
	int res;
	if(o < raiz->info)
	{
		if((res = remove_Node(&raiz->l,o)) == 1)
			if(bf(raiz) >= 2)
				if(raiz->r->l->h <= raiz->r->r->h)
					rotateLeft(raiz);
				else
				{
					rotateRight(raiz->r);
					rotateLeft(raiz);
				}
	} 
	
	if(o > raiz->info)
	{
		if((res = remove_Node(&raiz->r,o)) == 1)
			if(bf(raiz) >= 2)
				if(raiz->l->r->h <= raiz->l->l->h)
					rotateRight(raiz);
				else
				{
					rotateLeft(raiz->l);
					rotateRight(raiz);
				}
	}

	if(raiz->info == valor)
	{
		if(raiz->l == NULL || raiz->r == NULL)
		{
			struct Node *old = raiz;
			if(raiz->l != NULL)
				copyNode(raiz->l,raiz);
				//raiz = raiz->l;
			else
				copyNode(raiz->r,raiz);
				//raiz = raiz->r;
			free(old);
		}
		else
		{
			struct Node* temp = procuraMenor(raiz->r);
			raiz->info = temp->info;
			remove_Node(&raiz->r,raiz->info);
			if(bf(raiz) >= 2)
				if(raiz->l->r->h <= raiz->l->l)
					rotateRight(raiz);
				else 
				{
					rotateLeft(raiz->l);
					rotateRight(raiz);
				}
					
		}
		return 1;
	}
	return res;	

}

template<typename T>
struct Node* Arvore<T>::procuraMenor(struct Node *atual){
	struct Node *no1 = atual;
	struct Node *no2 = atual->l;
	while(no2 != NULL){
		no1 = no2;
		no2 = no2->l;
	}
	return no1;
}


template<typename T>
char Arvore<T>::remove(T o){
	Node* nor = root;
	while(nor != NULL){
		if (nor->info == o)
			break;
		
		else
			if (o < nor->info)
				nor = nor->l;
			else
				nor = nor->r;
	}
	
	if (nor != NULL){
		Node* no = nor->p;
		Node* nop = no;
		delete nor; // NAAAAAAAAAAO
								// ERRRADDDDDOOOO
		
	}
	
	return 0;
}

template<typename T>
void Arvore<T>::copyNode(Node *n1, Node* n2){
	n2->l = n1->l;
	n2->r = n1->r;
	n2->p = n1->p;
	n2->info = n1->info;
	n2->h = n1->h;
}

template<typename T>
void Arvore<T>::rotateRight(Node *y){
	Node* temp = (Node*) malloc(sizeof(Node));
	copyNode(y, temp);
	
	Node* x = y->l;
	Node* xr = x->r;
	Node* yp = y->p;
	copyNode(x, y);
	y->p = yp;
	
	if(y->l != NULL)
		y->l->p = y;
	
	copyNode(temp, x);
	y->r = x;
	x->p = y;
	
	x->l = xr;
	
	if (xr != NULL)
		xr->p = temp;
	
	x->h = max(height(x->l),height(x->r)) + 1;
	y->h = max(height(x->l),height(x->r)) + 1;
	
	delete temp;
}

template<typename T>
void Arvore<T>::rotateLeft(Node *x){
	Node* temp = (Node*) malloc(sizeof(Node));
	copyNode(x, temp);
	
	Node* y = x->r;
	Node* yl = y->l;
	Node* xp = x->p;
	copyNode(y, x);
	x->p = xp;
	
	if (x->r != NULL)
		x->r->p = x;
	
	copyNode(temp, y);
	x->l = y;
	y->p = x;
	
	y->r = yl;
	
	if (yl != NULL)
		yl->p = temp;
	
	y->h = max(height(y->l),height(y->r)) + 1;
	x->h = max(height(x->l),height(x->r)) + 1;
	
	delete temp;
}

template<typename T>
void Arvore<T>::insert(T o){
	Node *no = root;
	
	if (root == NULL){
		root = (Node*) malloc(sizeof(Node));
		root->p = NULL;
		root->l = NULL;
		root->r = NULL;
		root->info = o;
		root->h = 1;
		no = root;
		count++;
	}

	else
		while(1){
			if (o < no->info){
				if (no->l == NULL){
					no->l =	(Node*) malloc(sizeof(Node));
					no->l->info = o;
					no->l->l = NULL;
					no->l->r = NULL;
					no->l->p = no;
					
					no = no->l;
					count++;
					break;
				}
				no = no->l;
				continue;
			}

			if (o > no->info){
				if (no->r == NULL){
					no->r =	(Node*) malloc(sizeof(Node));
					no->r->info = o;
					no->r->l = NULL;
					no->r->r = NULL;
					no->r->p = no;
					
					no = no->r;
					count++;
					break;
				}

				no = no->r;
				continue;
			 }

			return;
			break;
		}

	Node* nop = no;
	
	while(no != NULL){
		no->h = max(height(no->l),height(no->r)) + 1;

		int balanceF = bf(no);
		
		if (balanceF > 1){
		 	if(o < no->l->info){
		 		rotateRight(no);
		 	}

		 	else{
		 		rotateLeft(no->l);
				rotateRight(no);
			}
			
			continue;
		}

		else if (balanceF < -1){
		 	if(o > no->r->info){
		 		rotateLeft(no);
		 	}

		 	else{
		 		rotateRight(no->r);
				rotateLeft(no);
			}
			
			continue;
		}
		
		
		nop = no;
		no = no->p;
	}
	
	root = nop;
}
#endif
