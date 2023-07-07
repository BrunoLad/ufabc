#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Bruno Menezes Gottardo Ladeia - 11048216.
* O objetivo da empresa é conseguir maximizar o número
* de assentos de um voo, fazendo alavancagem do fato
* de que a empresa realiza bastante escalas.
* A empresa consegue esta maximização ao 
* transportar mais passageiros com menos novos voos
* (voos individuais).
* Note que isso é equivalente a calcular o número
* de componentes maximais de um grafo - 1,
* que seria a quantidade de novos voos
* que precisaria sair a partir de uma componente
* maximal para chegar a todos os outros.
* Pois, num mesmo componente conexo, eu consigo
* atingir todos os outros aeroportos presentes ali.
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

int graph_complete_search(Graph);
void graph_DFS(Graph, int, int *);

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

/* Função principal do código
* Ele roda a busca em profundiade no grafo inteiro
* A cada execução da busca em profundidae, se aquele
* vértice ainda não foi atingido, significa que ele
* está numa outra componente conexa do grafo.
* Então cada execucação irá calcular a quantidade de
* componentes conexas e retornar
*/
int graph_complete_search(Graph g) {
  int count = 0;
  int *visited = malloc(g->V * sizeof(int));
  for (int i = 0; i < g->V; i++)
    visited[i] = 0;
  
  for(int i = 0; i < g->V; i++) {
    if (!visited[i]) {
      graph_DFS(g, i, visited);
      count++;
    }
  }
  
  return count - 1;
}

// Função de busca em profundidade simples
// para matriz de adjacencia.
// Verificando se existe aresta e se o vértice não
// foi explorado
void graph_DFS(Graph g, int vertex, int *visited) {
  visited[vertex] = 1;

  for(int i = 0; i < g->V; i++) {
    if(!visited[i] && g->adj[vertex][i]) {
      graph_DFS(g, i, visited);
    }
  }
}

/*
* A entrada do programa está conforme foi pedido pelo Problema * 3 utilizando padronizações por meio de scanf.
*/
int main(void) {
  int order, size, u, v;
  int *guests;
  Graph g;

  scanf("%d", &order); // Numero de vertices
  scanf("%d", &size); // Numero de arestas

  // Cria a estrutura de grafo
  // em formato de matriz de adjacencia
  g = graph(order);

  // Preenche as arestas
  for (int i = 0; i < size; ++i) {
    scanf("%d %d", &u, &v);

    graph_insert_edge(g, edge(u, v));
  }

  // Imprime a quantidade de voos novos necessários
  printf("# de novos voos: %d", graph_complete_search(g));

  return 0;
}
