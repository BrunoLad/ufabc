#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Bruno Menezes Gottardo Ladeia - 11048216.
* O objetivo do programa é determinar se é possível, com base de uma lista de convidados
* em formato de grafos, realizar um "churrasco épico"
* (onde todos os integrantes conhecem uns aos outros)
* A entrada do programa está conforme foi pedido pelo Problema 2
* utilizando padronizações por meio de scanf.
*/


/* Utilizando Estruturas (biblioteca) de grafos
* mostrados nas vídeo aulas
*/
#ifndef __GRAPH_H_
#define __GRAPH_H_

typedef struct {int u; int v;} Edge;

Edge edge(int, int);

typedef struct graph* Graph;

Graph graph(int);
void graph_destroy(Graph);

int graph_order(Graph);
int graph_size(Graph);

void graph_insert_edge(Graph, Edge);
void graph_insert_edges(Graph, Edge*);
void graph_remove_edge(Graph, Edge);
void graph_remove_edges(Graph, Edge*);

int graph_has_edge(Graph, Edge);
void graph_edges(Graph, Edge*);

int graph_degree(Graph, int);
int graph_neighbors(Graph, int, int*);

Graph graph_copy(Graph);

void graph_print(Graph);
void graph_print_edges(Graph);

Graph graph_squared(Graph);

Graph graph_GNP(int, double);
Graph graph_euclidean_neighborhood(int, double);

#endif // __GRAPH_H_

Edge edge(int u, int v) {
  Edge e = {u, v};
  return e;
}

struct graph {
  int V;
  int E;
  char **adj;
};

Graph graph(int V) {

  assert(V > 0);

  // http://c-faq.com/aryptr/fn33.html
  Graph G = malloc(sizeof(*G));
  G->V = V;
  G->E = 0;

  G->adj = malloc(V * sizeof(*G->adj)); 
  for (int u = 0; u < V; u++) {
      G->adj[u] = malloc(V * sizeof(G->adj[u]));
      for (int v = 0; v < V; v++)
          G->adj[u][v] = 0;
  }
  return G;
}

void graph_destroy(Graph G) {
  assert(G);

  for (int u = 0; u < G->V; u++)
      free(G->adj[u]);

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
  assert(e.u >= 0 && e.v < G->V);
  assert(e.v >= 0 && e.v < G->V);

  if (!G->adj[e.u][e.v])
      G->E += 1;
  G->adj[e.u][e.v] = 1;
  G->adj[e.v][e.u] = 1;
}

void graph_remove_edge(Graph G, Edge e) {
  if (G->adj[e.u][e.v])
      G->E -= 1;
  G->adj[e.u][e.v] = 0;
  G->adj[e.v][e.u] = 0;
}

int graph_has_edge(Graph G, Edge e) {
  return G->adj[e.u][e.v];
}

void graph_edges(Graph G, Edge* edges) {
  assert(G);
  assert(edges);

  int k = 0;
  for (int u = 0; u < G->V; u++)
      for (int v = 0; v < G->V; v++)
          if (G->adj[u][v]) {
              edges[k] = edge(u, v);
              k += 1;
          }
}

int graph_degree(Graph G, int u) {
  int d = 0;
  for (int v = 0; v < G->V; v++)
      if (G->adj[u][v])
          d += 1;
  return d;
}

/*
* Funcao principal responsavel por verificar se é possível
* realizar um churrasco épico ou não.
* Caso seja possível retorna "SIM\n", senão retorna "NÃO\n"
* Foi adotado uma estratégia gulosa para verificação 
* dos vértices. Partindo dos que tem menor grau,
* para os que tem maior grau. Se algum de menor
* grau já não tiver conexão com qualquer outro
* na lista de convidados, então aquela lista
* poderá ser descartado como um todo.
*/
char* epicBbq(Graph g, int * guests, int numGuests) {
  int *degreeOrderedVertices = malloc(numGuests * sizeof(guests));
  int count = 0;

	// No caso de ser um único convidado pra festa
	// Aceito por vacuidade.
  if (numGuests == 1)
    return "SIM\n";

  for (int i = 0; i < numGuests; i++) {
    int degree = graph_degree(g, *(guests + i)), index;
    int j;
    
    for (j = count - 1; (j >= 0 && graph_degree(g,degreeOrderedVertices[j]) > degree); j--)
      degreeOrderedVertices[j + 1] = degreeOrderedVertices[j];

    degreeOrderedVertices[j + 1] = guests[i];
    count++;
  }

  for (int i = 0; i < numGuests - 1; ++i){
    for (int j = i + 1; j < numGuests; ++j){
      if(!graph_has_edge(g, edge(degreeOrderedVertices[i], degreeOrderedVertices[j])))
        return "NAO\n";
    }
  }

  return "SIM\n";
}

int main(void) {
  int order, size, u, v, tests, numGuests;
  int *guests;
  char **results;
  Graph g;

  scanf("%d", &order); // Numero de vertices
  scanf("%d", &size); // Numero de arestas

  // cria a estrutura de grafo
  // em formato de matriz de adjacencia
  g = graph(order);

  // preenche as arestas
  for (int i = 0; i < size; ++i) {
    scanf("%d %d", &u, &v);

    graph_insert_edge(g, edge(u, v));
  }

  // recebe a quantidade de
  // possíveis listas
  scanf("%d", &tests);
  results = malloc(tests * sizeof(results));

  for (int i = 0; i < tests; i++){
    scanf("%d ", &numGuests);
    guests = malloc(numGuests * sizeof(guests));
    
    for (int j = 0; j < numGuests - 1; j++) {
      scanf("%d", (guests + j));
    }

    // recebe o último convidado
    scanf("%d", (guests + numGuests - 1));
    // Armazena o resultado para posterior impressão
    results[i] = epicBbq(g, guests, numGuests);
  }

  // imprime todos os resultados
  for (int i = 0; i < tests; i++){
    printf("%s", results[i]);
  }

  return 0;
}