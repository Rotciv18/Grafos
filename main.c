#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
#include <stdlib.h>
#include "fprim.h"
#include "fdij.h"

int main(int argc, char *argv[])
{
    FILE* file = fopen ("dij10.txt", "r"); //abre o arquivo passado como argumento
    if (file == NULL)
    {
      printf ("Falha ao tentar ler arquivo.");
      return 1;
    }

    int coluna = 0;         //Con
    int j = 0;              //ta
    int i = 0;              //do
    int tam = 0;            //res
    int start = 0;

    fscanf (file, "%d", &i);    //Lê o primeiro valor como número de vertices no arquivo
    tam = i;
    int limite = tam;   //uma linha deve ter [limite] colunas a serem lidas
    int array[tam][tam];
    fscanf(file, "%d", &i);
    for (coluna = 0; coluna < tam - 1 ; coluna++)
    {
        for (j = start; j < limite ; j++){
            if (coluna == j){
                array[coluna][j] = array[j][coluna] = 0;
                continue;
            }
            array[coluna][j] = array[j][coluna] = i;
            fscanf (file, "%d", &i);
        }
        start++;
    }
    limite = tam;
    for (coluna = 0; coluna < tam ; coluna++){
        for (j = 0; j < limite; j++){
            if (coluna == j){
                printf (" %d ", array[coluna][j]);
                continue;
            }
            printf(" %d ", array[coluna][j]);
        }
        printf ("\n");
    }
    printf("-------------------------------------------------------\n\n\n");
    V = tam;
    int esc = atoi(argv[1]);
    switch (esc){
    case 1:
        primMST(array);
        break;
    case 2:
        printf ("Escolha vertice de partida: ");
        int x;
        scanf("%d", &x);
        if (x > tam){
            printf ("\nVertice inexistente.");
            return 1;
        }
        dijkstra(array, tam, x);
        break;
    }
    //dijkstra(array, tam, 0);

	return 0;
}
