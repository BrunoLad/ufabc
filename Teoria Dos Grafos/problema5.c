#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Bruno Menezes Gottardo Ladeia - 11048216.
* O objetivo do problema 5 é encontrar a Arvore Geradora Minima (AGM)
* que construa estações interligadas com a central, de forma a gastar
* o minimo de fibra optica possivel.
*/

/* Utilizando Estruturas (biblioteca) de grafos
* mostrados nas vídeo aulas
*/
typedef struct {
  int u;
  int v;
  double w;
} Edge;

typedef struct point {
  int xCoord;
  int yCoord;
} point;

typedef struct {
  int item;
  int references;
  double key;
} Item;

typedef struct node* link;
typedef struct graph* Graph;
typedef struct point* Point;
typedef struct queue* Heap;

struct node {
  int w;
  double weight;
  link next;
};

struct graph {
  int V;
  int E;
  Point vertexCoordinates;
  link *adj;
  int * connected;
  double totalLength;
};

struct list {
  link head;
  int size;
};

struct queue {
  Item* itemList;
  int* it2idx;
  int nItems;
};

// Assinaturas demais funcoes
Edge edge(int, int, double);
Item item(int, double);

// Assinaturas funcoes grafos custom
Graph graph(int);
void graph_destroy(Graph);

int graph_order(Graph);
int graph_size(Graph);

void graph_insert_edge(Graph, Edge);
void graph_insert_edge_order(Graph, Edge);
void graph_insert_edges(Graph, Edge*);
void graph_print_edges(Graph);

void graph_complete(Graph);
point graph_update_coordinates(int, int, int);
Graph graph_mst_tree(Graph);

// Assinaturas funcoes list
link list_insert(link, int, double);
link list_insert_order(link, int, double);
link link_destroy(link);

// Assinaturas funcoes Heap
Heap heap(int);
int heap_parent(int);
int heap_left_child(int);
int heap_right_child(int);
int heap_size(Heap);
void heap_destroy(Heap);
void heap_insert(Heap, int, double);
Item heap_extract_min(Heap);
void heap_decrease_key(Heap, int, double, int);
void heap_correct_upper_tree(Heap, int);
void heap_swap_elements(Heap, int, int);
void heap_correct_lower_tree(Heap, int);
int heap_contains(Heap, int);

Edge edge(int u, int v, double weight) {
  Edge e = {u, v, weight};
  return e;
}

// Item auxiliar para manipulacao na heap
Item item(int v, double weight) {
  Item i;
  i.item = v;
  i.key = weight;
  i.references = v;

  return i;
}

link list_insert(link head, int w, double weight) {
  link p = malloc(sizeof(*p));
  p->w = w;
  p->next = head;
  p->weight = weight;
  return p;
}

link list_insert_order(link head, int w, double weight) {
  link p = malloc(sizeof(*p));
  p->w = w;
  p->weight = weight;

  if(head == NULL || head->w >= w) {
    p->next = head;
    head = p;
  } else {
    link current = head;
    while(current->next != NULL && current->next->w < w) {
      current = current->next;
    }
    p->next = current->next;
    current->next = p;
  }

  return head;
}

link list_destroy(link head) {
  if (head) {
    list_destroy(head->next);
    free(head);
  }
  return NULL;
}

Graph graph(int V) {
  long possibleConnections = ((V*V) - V)/2;
  Graph G = malloc(sizeof(*G));

  G->V = V;
  G->E = 0;
  G->totalLength = 0;
  G->adj = malloc(V * sizeof(*(G->adj)));
  G->vertexCoordinates = malloc(V * sizeof(*(G->vertexCoordinates)));
  G->connected = malloc(V * sizeof(*G->connected));

  for (int u = 0; u < V; u++) {
    G->adj[u] = NULL;
    G->connected[u] = 0;
  }

  return G;
}

void graph_destroy(Graph G) {
  for (int u = 0; u < G->V; u++)
    list_destroy(G->adj[u]);
  free(G->adj);
  free(G->connected);
  free(G);
}

int graph_order(Graph G) {
  assert(G);

  return G->V;
}

int graph_size(Graph G) {
  assert(G);

  return G->E;
}

void graph_insert_edge(Graph G, Edge e) {
  G->adj[e.u] = list_insert(G->adj[e.u], e.v, e.w);
  G->adj[e.v] = list_insert(G->adj[e.v], e.u, e.w);
  G->connected[e.u] = 1;
  G->connected[e.v] = 1;
  G->E += 1;
}

void graph_insert_edge_order(Graph G, Edge e) {
  G->adj[e.u] = list_insert_order(G->adj[e.u], e.v, e.w);
  G->adj[e.v] = list_insert_order(G->adj[e.v], e.u, e.w);
  G->connected[e.u] = 1;
  G->connected[e.v] = 1;
  G->E += 1;
}

// Imprime as arestas do grafo
// Utilizado para impressao do resultado final do problema
void graph_print_edges(Graph G) {
  for (int u = 0; u < G->V; u++)
    for (link p = G->adj[u]; p != NULL; p = p->next) 
      if (u < p->w)
        printf("%d %d\n", u, p->w);
}

// Constroi o grafo K-completo (V-1 completo) para
// que o prim possa ser executado nele.
void graph_complete(Graph G) {
  for(int i = 0; i < G->V - 1; i++)
  {
    for(int j = i + 1; j < G->V; j++){
      double xDifference = (double)(G->vertexCoordinates[j].xCoord - G->vertexCoordinates[i].xCoord);
      double yDifference = (double)(G->vertexCoordinates[j].yCoord - G->vertexCoordinates[i].yCoord);
      double weight = sqrt(pow(xDifference, 2.0) + pow(yDifference, 2.0));
      G->totalLength += weight;
      graph_insert_edge(G, edge(i, j, weight));
    }
  }
}

// Guarda as coordenadas daquele vertice num vetor auxiliar
// para posterior calculo dos pesos (distancias)
point graph_update_coordinates(int index, int xCoord, int yCoord) {
  point p;
  p.xCoord = xCoord;
  p.yCoord = yCoord;
  return p;
}

/* Funcao principal que calcula a AGM
* Analogo ao codigo de prim mostrado nas videoaulas
* porem algumas adaptacoes foram necessarias para o problema em questao
* bem como algumas alteracoes foram necessárias devido a divergência
* das estruturas utilizadas.
* Entao o algoritmo abaixo precisou de duas condicoes a mais
* uma delas é que a aresta minima só é adicionado ao novo Grafo construido
* depois que o corte do Grafo, bem como as arestas pertencentes a este corte,
* sejam determinados, de forma que o mais leve seja escolhido para inclusao.
* A outra condicao eh a verificao se, o vertice obtido da heap e, para cada um de
* seus vizinhos, ambos nao existam no novo grafo simultaneamente. Pois, caso exista,
* eu não posso considerar a aresta em questao para ser atualizada e incluida na heap.
* pois essa aresta formaria um ciclo e, no final, não teríamos uma AGM.
* A complexidade é O(V²lgV) pois um grafo (V-1)-completo tem binomial (V 2),
* que equivale a (V² - V)/2, que é O(V²). Como sabemos que, como foi mostrado em aula,
* que o algoritmo de prim eh O(ElgV), como o tamanho do grafo é equivalente a V²,
* temos que a complexidade passa a ser O(V²lgV). As operacoes inseridas (de comparacao)
* sao constantes e não afetam a complexidade do algoritmo, com ressalva da insercao
* no novo grafo, na lista de adjacencia daquele vertice, de forma ordenada.
* Esta operacao eh O(V) no pior caso, e poderia aumentar a complexidade do algoritmo.
* Porem ele esta dentro do 1° laço, que executa V vezes. Logo tera uma complexidade
* de O(V²), que cresce mais devagar que a O(V²lgV).
*/
Graph graph_mst_prim(Graph G) {
  Graph newTree = graph(G->V);
  Heap h = heap(G->V);

  for(int i = 0; i < G->V ; i++) {
    heap_insert(h, i, INFINITY);
  }

  heap_decrease_key(h, 0, 0, 0);
  while(heap_size(h) > 0) {
    Item u = heap_extract_min(h);
    if(u.references != u.item) {
      newTree->totalLength += u.key;
      Edge e = edge(u.item, u.references, u.key);
      graph_insert_edge_order(newTree, edge(u.item, u.references, u.key));
    }
    for(link p = G->adj[u.item]; p != NULL; p = p->next) {
      if (heap_contains(h, p->w) && p->weight < h->itemList[h->it2idx[p->w]].key && !(newTree->connected[u.item] && newTree->connected[p->w])) {
        heap_decrease_key(h, p->w, p->weight, u.item);
      }
    }
  }

  heap_destroy(h);

  return newTree;
}

int heap_parent(int idx) {
  return floor(idx / 2.0);
}

int heap_left_child(int idx) {
  return 2 * idx;
}

int heap_right_child(int idx) {
  return (2 * idx) + 1;
}

// "construtor" da heap
Heap heap(int max_size) {
  Heap h = malloc(sizeof(*h));
  h->nItems = 0;
  h->itemList = malloc((max_size + 1) * sizeof(*h->itemList));
  h->it2idx = malloc(max_size * sizeof(*h->it2idx));
  for (int i = 0; i < max_size; i++)
    h->it2idx[i] = -1;
  return h;
}

// Destroi a heap depois de utilizada
void heap_destroy(Heap h) {
  free(h->it2idx);
  free(h->itemList);
  free(h);
}

// Retorna quantos elementos atualmente tem na heap
int heap_size(Heap h) {
  return h->nItems;
}

// Funcao responsavel por inserir um novo elemento
// na heap
void heap_insert(Heap h, int vertex, double weight) {
  Item i = item(vertex, weight);
  ++h->nItems;
  h->itemList[h->nItems] = i;
  h->it2idx[vertex] = h->nItems;
  heap_correct_upper_tree(h, h->nItems);
}

// Funcao responsavel por extrair o menor
// elemento da heap
Item heap_extract_min(Heap h) {
  Item min = h->itemList[1];
  h->it2idx[min.item] = -1;
  h->itemList[1] = h->itemList[h->nItems];
  --h->nItems;
  h->it2idx[h->itemList[1].item] = 1;
  heap_correct_lower_tree(h, 1);
  return min;
}

// Funcao da heap que ira diminuir o valor da distancias
// aumentando a prioridade (por ser heap minima)
void heap_decrease_key(Heap h, int index, double priority, int references) {
  h->itemList[h->it2idx[index]].key = priority;
  h->itemList[h->it2idx[index]].references = references;
  heap_correct_upper_tree(h, h->it2idx[index]);
}

// Funcao auxiliar para corrigir as arvores
// dos nos pais, tanto quando diminui a prioridade,
// quanto quando insere um novo elemento na heap
void heap_correct_upper_tree(Heap h, int index) {
  while(index > 1 && h->itemList[heap_parent(index)].key > h->itemList[index].key) {
    heap_swap_elements(h, index, heap_parent(index));
    index = heap_parent(index);
  }
}

// Funcao auxiliar para corrigir
// as subArvores quando o elemento
// minimo e removido
void heap_correct_lower_tree(Heap h, int index) {
  int left = heap_left_child(index);
  int right = heap_right_child(index);
  int smallest = index;

  if (left <= h->nItems && h->itemList[left].key < h->itemList[index].key)
    smallest = left;
  else
    smallest = index;

  if (right <= h->nItems && h->itemList[right].key < h->itemList[smallest].key)
    smallest = right;

  if (smallest != index) {
    heap_swap_elements(h, index, smallest);
    heap_correct_lower_tree(h, smallest);
  }
}

// Funcao auxiliar para trocar os elementos da heap
// de posicao
void heap_swap_elements(Heap h, int index1, int index2) {
  Item item1 = h->itemList[index1];
  Item item2 = h->itemList[index2];
  h->itemList[index1] = item2;
  h->it2idx[item2.item] = index1;
  h->itemList[index2] = item1;
  h->it2idx[item1.item] = index2;
}

// Verifica se aquele elemento existe na heap
int heap_contains(Heap h, int v) {
  return h->it2idx[v] != -1;
}

/*
* A entrada do programa está conforme foi pedido pelo Problema 5 utilizando padronizações por meio de scanf.
*/
int main(void) {
  int order, x, y;
  Graph g;

  // Numero de vertices
  scanf("%d", &order);

  // Cria a estrutura de grafo
  // em formato de matriz de adjacencia
  g = graph(order);

  // Coleta as coordenadas de cada vértice e armazena-o num vetor auxiliar,
  for(int i = 0; i < order; i++) {
    scanf("%d %d", &x, &y);
    g->vertexCoordinates[i] = graph_update_coordinates(i, x, y);
  }

  // Constroi o grafo completo com base nos vertices recebidos
  graph_complete(g);

  // Funcao responsavel por calcular a agm
  Graph newTree = graph_mst_prim(g);

  // Imprime o comprimento com as 4 casas decimais
  printf("comprimento de cabeamento minimo: %.4f\n", newTree->totalLength);

  // Imprime a arvore de prim
  graph_print_edges(newTree);

  graph_destroy(g);

  return 0;
}
