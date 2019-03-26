#ifndef FPRIM_H_INCLUDED
#define FPRIM_H_INCLUDED
int V;


//retorna vertice não examinado de menor valor ponderado
int minKey(int key[], bool mstSet[])
{

int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
        min = key[v], min_index = v;

return min_index;
}


void printMST(int parent[], int n, int graph[V][V])
{
    int total = 0;
    printf("Aresta \tValor\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        total = total + graph[i][parent[i]];
    }
    printf ("\nSolucao: %d", total);
}


void primMST(int graph[V][V])
{
    // parent deve guardar toda spanning tree construída
    int parent[V];
    // Usado para pegar o menor valor entre os vertices examinados
    int key[V];
    // Vértices ainda não incluído na árvore
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    //Primeiro vértice
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count++)
    {
        //pega vértice não incluído na árvore de menor valor
        int u = minKey(key, mstSet);

        // adiciona o vértice na árvore
        mstSet[u] = true;


        // Atualiza key e parent de vértices não incluídos na MST adjacentes àquele que foi selecionado
        for (int v = 0; v < V; v++)

        // graph[u][v] deve ser > 0 para vértices adjacentes
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v]; 
    }

    printMST(parent, V, graph);
}


#endif // FPRIM_H_INCLUDED
