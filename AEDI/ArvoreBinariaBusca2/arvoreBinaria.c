#include <stdio.h>
#include <stdlib.h>

// typedef struct LinkedNode LinkedNode;
// struct LinkedNode {
//   int RA;
//   LinkedNode *proximo;
// };

////utilizado somente para a busca
// typedef struct auxBusca auxBusca;
// struct auxBusca {
// 	int nota;
// 	int operacoes;
// };

typedef struct TreeNode TreeNode;
struct TreeNode {
	int RA;
	int nota;
	TreeNode * esquerda;
	TreeNode * direita;
};

typedef struct Tree Tree;
struct Tree {
	TreeNode *inicio;
};

// LinkedNode* insercaoL(int ra, LinkedNode *ref) {
//   LinkedNode *nova = malloc(sizeof(LinkedNode));
//   nova->proximo = NULL;
//   nova->RA = ra;

//   //lista vazia
//   if(ref==NULL){
//     ref = nova;
//     return ref;
//   }else{

//   	//insercao na primeira posicao
//   	if(nova->RA < ref->RA){
//   		nova->proximo = ref;
//   		ref = nova;
//   		return ref;
//   	}

//     LinkedNode *tmp = ref;
//     //insercao meio
//     while(tmp->proximo!=NULL){
//         if(nova->RA == tmp->RA){
//         	return ref;
//         }

//         if(nova->RA < (tmp->proximo)->RA){
//           nova->proximo = tmp->proximo;
//           tmp->proximo = nova;
//           return ref;
//         }

//       tmp = tmp->proximo;
//     }

//     //insercao final
//     tmp->proximo = nova;
//     return ref;
//   }
// }

TreeNode *insertT(TreeNode *t, int key, int nota) {
	if (t == NULL)
	{
		TreeNode *tmp = malloc(sizeof(TreeNode));
		tmp->RA = key;
		tmp->nota = nota;
		tmp->direita = tmp->esquerda = NULL;
		return tmp;
	}

	if(key < t->RA){
		t->esquerda = insertT(t->esquerda, key, nota);
	}else{
		if(key > t->RA){
			t->direita = insertT(t->direita, key, nota);
		}else{
			t->RA = key;
			t->nota = nota;
		}
	}
	return t;
}

/*int buscaLista(LinkedNode *inicio, int val){
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
}*/

//retorna a nota daquele RA em questão, caso exista
//a estrutura auxiliar é para contar a quantidade de operações
TreeNode * buscaArvore(Tree *tr, int val){
	int cont = 0;
	if(tr == NULL){
		printf("C=%d ", cont);
		return NULL;
	}
	TreeNode *tmp = tr->inicio;
	
	while(tmp!=NULL){
		cont++;
		if(tmp->RA == val){
			printf("C=%d ", cont);
			return tmp;
		}else{
			if(val > tmp->RA){
				tmp = tmp->direita;
			}else{
				tmp = tmp->esquerda;
			}
		}
	}
	// aux->operacoes = cont;
	printf("C=%d ", cont);
	return NULL;
}

//método auxiliar para ir atualizando o maior caminho dentro da árvore
// foi utilizado o conceito de busca em profundidade
void buscaCega(TreeNode *atu, int cont, int *ref){
	
	cont++;
	if(atu->esquerda != NULL){
		buscaCega(atu->esquerda, cont, ref);
	}
	
	if(atu->direita != NULL){
		buscaCega(atu->direita, cont, ref);
	}

	if(cont > (*ref))
		(*ref) = cont;
}

//retorna a altura da árvore em questão
int alturaArvore(Tree *tr){
	int alt = -1;
	TreeNode *tmp = tr->inicio;
	
	int cont = 0;
	int *aux = &cont;
	
	if(tmp!=NULL)
		buscaCega(tmp, 0, aux);

	return cont + alt;
}

//remove o nó com o RA especificado
TreeNode * removeArvore(TreeNode *t, int ra){
	if(t != NULL){
		if(t->RA == ra){
			if(t->esquerda == NULL && t->direita == NULL){
				free(t);
				return NULL;
			} else{
				TreeNode *tmp = NULL;
				if(t->esquerda != NULL && t->direita == NULL){
					tmp = t->esquerda;
				} else {
					if(t->direita != NULL && t->esquerda == NULL){
						tmp = t->direita;
					} else {
						TreeNode *aux = t->direita;
						TreeNode *ant = t;
						while(aux->esquerda != NULL){
							ant = aux;
							aux = aux->esquerda;
						}
						tmp = aux;
						
						if(tmp != t->direita) {
							
							if(tmp->direita == NULL){
								ant->esquerda = NULL;
							} else {
								ant->esquerda = tmp->direita;
							}
							tmp->direita = t->direita;
						}
						tmp->esquerda = t->esquerda;
					}
				}
				free(t);
				return tmp;
			}
		} else {
			if(ra < t->RA){
				t->esquerda = removeArvore(t->esquerda, ra);
			}else{
				t->direita = removeArvore(t->direita, ra);
			}
		}
	}
	
	return t;
}

int main(int argc, char const *argv[])
{
	/* code */
	char op;
	Tree *tr = malloc(sizeof(Tree));
	tr->inicio = NULL;

	do{
		scanf("\n%c", &op);
		int ra, nota;
		TreeNode *res = NULL;
		switch(op){
			case 'I':
				//insere um item na arvore
				//RA é único, caso passe RA e Nota, atualiza a nota
				//naquele RA específico
				scanf("%d %d", &ra, &nota);
				tr->inicio = insertT(tr->inicio, ra, nota);
				break;
			case 'R':
				scanf("%d", &ra);
				tr->inicio = removeArvore(tr->inicio, ra);
				//remove o nó com o RA informado
				break;
			case 'B':
				scanf("%d", &ra);
				res = buscaArvore(tr, ra);
				printf("Nota=%d\n", res != NULL ? res->nota : -1);
				res = NULL;
				//busca o nó com RA informado
				//retornando a nota e a quantidade de operações realizadas
				break;
			case 'A':
				printf("A=%d\n", alturaArvore(tr));
				//mostra a altura da árvore
				break;
			default:
				//apenas por convenção
				break;
		}
	}while(op != 'P');

	return 0;
}