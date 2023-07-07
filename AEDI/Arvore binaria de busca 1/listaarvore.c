#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int RA;
  LinkedNode *proximo;
};

typedef struct TreeNode TreeNode;
struct TreeNode {
	int key;
	TreeNode * esquerda;
	TreeNode * direita;
};

typedef struct Tree Tree;
struct Tree {
	TreeNode *inicio;
};

LinkedNode* insercaoL(int ra, LinkedNode *ref) {
  LinkedNode *nova = malloc(sizeof(LinkedNode));
  nova->proximo = NULL;
  nova->RA = ra;

  //lista vazia
  if(ref==NULL){
    ref = nova;
    return ref;
  }else{

  	//insercao na primeira posicao
  	if(nova->RA < ref->RA){
  		nova->proximo = ref;
  		ref = nova;
  		return ref;
  	}

    LinkedNode *tmp = ref;
    //insercao meio
    while(tmp->proximo!=NULL){
        if(nova->RA == tmp->RA){
        	return ref;
        }

        if(nova->RA < (tmp->proximo)->RA){
          nova->proximo = tmp->proximo;
          tmp->proximo = nova;
          return ref;
        }

      tmp = tmp->proximo;
    }

    //insercao final
    tmp->proximo = nova;
    return ref;
  }
}

TreeNode *insertT(TreeNode *t, int key) {
	if (t == NULL)
	{
		TreeNode *tmp = malloc(sizeof(TreeNode));
		tmp->key = key;
		tmp->direita = tmp->esquerda = NULL;
		return tmp;
	}

	if(key < t->key){
		t->esquerda = insertT(t->esquerda, key);
	}else{
		if(key > t->key){
			t->direita = insertT(t->direita, key);
		}else{
			t->key = key;
		}
	}
	return t;
}

int buscaLista(LinkedNode *inicio, int val){
	LinkedNode *tmp = inicio;
	if(tmp==NULL){
		return 0;
	}
	int ant = tmp->RA;
	int itensPerc = 0;

	while(tmp!=NULL){
		itensPerc++;
		if(tmp->RA == val || (val < tmp->RA && val > ant) || (itensPerc == 1 && val < tmp->RA)){
			return itensPerc;
		}
		ant = tmp->RA;
		tmp = tmp->proximo;
	}

	return itensPerc;
}

int buscaArvore(Tree *tr, int val){
	if(tr == NULL){
		return 0;
	}
	TreeNode *tmp = tr->inicio;
	int cont = 0;

	while(tmp!=NULL){
		cont++;
		if(tmp->key == val){
			return cont;
		}else{
			if(val > tmp->key){
				tmp = tmp->direita;
			}else{
				tmp = tmp->esquerda;
			}
		}
	}
	return cont;
}

int main(int argc, char const *argv[])
{
	/* code */
	char op;
	int ra;
	Tree *tr = malloc(sizeof(Tree));
	tr->inicio = NULL;
	LinkedNode *inicio = NULL;

	scanf("%c %d", &op, &ra);

	while(op!='P' || ra!=0){

		if(op == 'I'){
			inicio = insercaoL(ra, inicio);
			tr->inicio = insertT(tr->inicio, ra);
		}else if(op=='B'){
			printf("L=%d A=%d\n", buscaLista(inicio, ra), buscaArvore(tr, ra));
		}
		scanf("%c", &op);
		scanf("%d", &ra);
	}

	return 0;
}