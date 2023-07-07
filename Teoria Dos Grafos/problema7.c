#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Bruno Menezes Gottardo Ladeia - 11048216.
* O objetivo do problema 7 é encontrar o caminho mínimo
* de um vértice até outro. Caso esse caminho não exista
* imprimira a mensagem "ERRO: 3.1415”.
*/

/* Utilizando Estruturas (biblioteca) de grafos
* mostrados nas vídeo aulas, com leve adaptações
*/
typedef struct {
  int tail;
  int head;
  double w;
} Edge;

typedef struct {
  int item;
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
  link *adj;
  double *cost;
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

// Assinaturas funcoes grafos
Graph graph(int);
void graph_destroy(Graph);

int graph_order(Graph);
int graph_size(Graph);

void graph_insert_edge(Graph, Edge);
void graph_insert_edges(Graph, Edge*);

void graph_relax(Graph, int, Heap);
void graph_dijkstra(Graph, int);

// Assinaturas funcoes list
link list_insert(link, int, double);
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
void heap_decrease_key(Heap, int, double);
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

  return i;
}

link list_insert(link head, int w, double weight) {
  link p = malloc(sizeof(*p));
  p->w = w;
  p->next = head;
  p->weight = weight;
  return p;
}

link list_destroy(link head) {
  if (head) {
    list_destroy(head->next);
    free(head);
    head = NULL;
  }
  return NULL;
}

Graph graph(int V) {
  Graph G = malloc(sizeof(*G));

  G->V = V;
  G->E = 0;
  G->cost = malloc (V * sizeof(*(G->cost)));
  G->adj = malloc(V * sizeof(*(G->adj)));

  for (int u = 0; u < V; u++) {
    G->adj[u] = NULL;
    G->cost[u] = INFINITY;
  }

  return G;
}

void graph_destroy(Graph G) {
  for (int u = 0; u < G->V; u++)
    list_destroy(G->adj[u]);
  free(G->adj);
  G->adj = NULL;
  free(G);
  G = NULL;
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
  G->adj[e.tail] = list_insert(G->adj[e.tail], e.head, e.w);
  G->E += 1;
}

// Funcao auxiliar, que será responsável
// por fazer o relaxamento dos arcos
// e corrigir os custos mínimos para
// cada vértice alcançável (como visto em sala)
void graph_relax(Graph g, int v, Heap h) {
  for (link p = g->adj[v]; p != NULL; p = p->next) {
    if (g->cost[p->w] > g->cost[v] + p->weight) {
      g->cost[p->w] = g->cost[v] + p->weight;
      heap_decrease_key(h, p->w, g->cost[p->w]);
    }
  }
}

// Principal algoritmo da execução do problema
// Calculará os caminhos de custos mínimos 
// Para v a todo outro vértice do grafo.
void graph_dijkstra(Graph g, int v) {
  Heap h = heap(g->V);

  for (int i = 0; i < g->V; i++) {
    heap_insert(h, i, INFINITY);
  }

  g->cost[v] = 0;
  heap_decrease_key(h, v, 0);
  while(heap_size(h) > 0) {
    Item u = heap_extract_min(h);
    graph_relax(g, u.item, h);
  }
  
  heap_destroy(h);
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
  h = NULL;
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
void heap_decrease_key(Heap h, int index, double priority) {
  h->itemList[h->it2idx[index]].key = priority;
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
* A entrada do programa está conforme foi pedido pelo Problema 7 utilizando padronizações por meio de scanf.
*/
int main(void) {
  int order, size, x, y;
  double w;
  Graph g;

  // Numero de vertices
  scanf("%d", &order);

  // Cria a estrutura de grafo
  // em formato de matriz de adjacencia
  g = graph(order);

  // Recebe o número de arestas
  scanf("%d", &size);

  // Insere os vértices no grafo
  for(int i = 0; i < size; i++) {
    scanf("%d %d %lf", &x, &y, &w);
    graph_insert_edge(g, edge(x, y, w));
  }

  // Recebe o vértice de origem e de desitno.
  scanf("%d %d", &x, &y);

  // Calcula o caminho mínimo entre os vértices
  graph_dijkstra(g, x);

  // Imprime o comprimento com as 4 casas decimais
  // Caso não seja alcançável, imprime a mensagem de erro
  if (g->cost[y] != INFINITY)
    printf("%.4f\n", g->cost[y]);
  else
    printf("ERRO: 3.1415\n");
    
  // Destroi o grafo utilizado e libera memória
  graph_destroy(g);

  return 0;
}
