#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Bruno Menezes Gottardo Ladeia - 11048216.
* O objetivo do problema 4 é encontrar os vértices
* que sejam de cortes (terminais) com base no grafo
* fornecido. A forma eficiente de fazer isso,
* num grafo esparso, é utilizando uma estrutura em
* lista de adjacência e fazer uma verificação
* similar ao de aresta de corte visto nas vídeo aulas.
* Esse algoritmo foi provado, nas aulas,
* que possuicomplexidade O(V + E).
*/

/* Utilizando Estruturas (biblioteca) de grafos
* mostrados nas vídeo aulas
*/
typedef struct {int u; int v;} Edge;
typedef struct node *link;
typedef struct graph* Graph;

Edge edge(int, int);

Graph graph(int);
void graph_destroy(Graph);

int graph_order(Graph);
int graph_size(Graph);

void graph_insert_edge(Graph, Edge);
void graph_insert_edges(Graph, Edge*);

int graph_has_edge(Graph, Edge);
void graph_edges(Graph, Edge*);

int graph_degree(Graph, int);
int graph_neighbors(Graph, int, int*);

// Assinaturas das funções criadas para o problema 4
void graph_DFS_search_bridge(Graph, int);
void graph_print_available_targets(Graph);

Edge edge(int u, int v) {
  Edge e = {u, v};
  return e;
}

struct node {
    int w; 
    link next;
};

struct graph {
    int V;
    int E;
    link *adj;
    int *visited;
    int *predecessor;
    int *order;
    int *low;
    int visitingOrder;
    int *cutVertex;
    int totalCutVertexs;
};

struct list {
  link head;
  int size;
};

link list_insert(link head, int w) {
    link p = malloc(sizeof(*p));
    p->w = w;
    p->next = head;
    return p;
}

link list_destroy(link head) {
    if (head) {
        list_destroy(head->next);
        free(head);
    }
    return NULL;
}

Graph graph(int V) {
    Graph G = malloc(sizeof(*G));

    G->V = V;
    G->E = 0;
    G->visitingOrder = 0;
    G->totalCutVertexs = 0;
    G->adj = malloc(V * sizeof(*(G->adj)));
    G->visited = malloc(V * sizeof(*(G->visited)));
    G->predecessor = malloc(V * sizeof(*(G->predecessor)));
    G->order = malloc(V * sizeof(*(G->order)));
    G->low = malloc(V * sizeof(*(G->low)));
    G->cutVertex = malloc(V * sizeof(*(G->cutVertex)));

    for (int u = 0; u < V; u++)
        G->adj[u] = NULL;
    
    return G;
}

void graph_destroy(Graph G) {
    for (int u = 0; u < G->V; u++)
        list_destroy(G->adj[u]);
    free(G->adj);
    free(G->visited);
    free(G->predecessor);
    free(G->order);
    free(G->low);
    free(G->cutVertex);
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
    G->adj[e.u] = list_insert(G->adj[e.u], e.v);
    G->adj[e.v] = list_insert(G->adj[e.v], e.u);
    G->E += 1;
}

int graph_has_edge(Graph G, Edge e) {
    for (link p = G->adj[e.u]; p != NULL; p = p->next)
        if (p->w == e.v)
            return 1;
    return 0;
}

void graph_edges(Graph G, Edge* edges) {
    int k = 0;
    for (int u = 0; u < G->V; u++)
        for (link p = G->adj[u]; p != NULL; p = p->next) {
            edges[k] = edge(u, p->w);
            k += 1;
        }
}

int graph_degree(Graph G, int u) {
    int d = 0;
    for (link p = G->adj[u]; p != NULL; p = p->next)
        d += 1;
    return d;
}

int graph_neighbors(Graph G, int u, int* neigh) {
    int i = 0;
    for (link p = G->adj[u]; p != NULL; p = p->next) {
        neigh[i] = p->w;
        i += 1;
    }
    return i;
}

// Função auxiliar para iniciar a busca em profundidade
// Executa para todos os nós das árvores que não
// Foram executados
void graph_DFS(Graph G) {
  for (int i = 0; i < G->V; i++) {
    G->visited[i] = 0;
    G->predecessor[i] = -1;
    G->cutVertex[i] = 0;
  }

  for (int i = 0; i < G->V; i++) {
    if (!G->visited[i]) {
      G->predecessor[i] = i;
      graph_DFS_search_bridge(G, i);
    }
  }
}

/*
* Funcao principal responsavel por realizar a busca.
*/
void graph_DFS_search_bridge(Graph G, int v) {
  int subtree = 0; // Usado para calcular a quantidade de subárvores no vértice em questão.
  G->visited[v] = 1;
  G->low[v] = G->order[v] = ++G->visitingOrder;
  for (link p = G->adj[v]; p != NULL; p = p->next) {
    int otherVertex = p->w;
    if(!G->visited[otherVertex]) {
      subtree++;
      G->predecessor[otherVertex] = v;
      graph_DFS_search_bridge(G, otherVertex); // Chamada recursiva
      // Se v não for algum nó raiz e se o mínimo dos nós raízes do vértice filho de v forem maoires do que a ordem de descoberta de V, significando que não tem nenhuma aresta de retorno para algum parente de V, pois necessariamente teria que seguir a ordem de descobrimento formal por meio de v.
      if(G->predecessor[v] != v && G->low[otherVertex] >= G->order[v]){
        // Vertice é de corte, então é inserido na lista
        // de vértices de corte e impeça
        // que conte aquele vértice mais de uma vez
        if (!G->cutVertex[v]) {
          G->totalCutVertexs++;
        }
        G->cutVertex[v] = 1;
      }
      // Neste caso verifica se é o nó raiz da busca DFS
      // Se for e ele tiver, pelo menos, 2 filhos que não
      // foram visitados, significa dizer que ele é de corte
      // Pois, se fossem visitados antes, significa que tem 
      // arestas de algum nó filho da raiz, que ligue
      // ao nó filho sendo analisado e consequentemente
      // um outro caminho.
      if(G->predecessor[v] == v && subtree > 1) {
        // Vertice é de corte, então é inserido na lista
        // de vértices de corte
        if (!G->cutVertex[v]) {
          G->totalCutVertexs++;
        }
        G->cutVertex[v] = 1;
      }
      G->low[v] = G->low[v] <= G->low[otherVertex] ?
              G->low[v] :
              G->low[otherVertex];
    }
    else if(otherVertex != G->predecessor[v]) {
      G->low[v] = G->low[v] <= G->order[otherVertex] ?
                  G->low[v] :
                  G->order[otherVertex];
    }
  }
}

/*
* Função auxiliar utilizada para imprimir
* o total de alvos, bem como quais são.
* Com base no vetor auxiliar booleano
* Para indicar quais que são os vértices
* de interesse
*/
void graph_print_available_targets(Graph g) {
  printf("# de alvos possiveis: %d\n", g->totalCutVertexs);
  for (int i = 0; i < g->V; i++) {
    if (g->cutVertex[i]){
      printf("%d\n", i);
    }
  }
}

/*
* A entrada do programa está conforme foi pedido pelo Problema 4 utilizando padronizações por meio de scanf.
*/
int main(void) {
  int order, size, u, v;
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

  graph_DFS(g);

  graph_print_available_targets(g);

  graph_destroy(g);

  return 0;
}
