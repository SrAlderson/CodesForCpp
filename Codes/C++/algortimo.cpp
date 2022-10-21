//Algoritmo de Floyd

//Librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Funciones 
void procesamientoFloyd (int n);
void rutaNodos(int matrizDistancia[][5], char matrizRecorrido[][5]);
void recorridoNodos(char matrizRecorridos[][5],int nodoInicio, int nodoFinal);
void imprimirMatrices(int matrizDistancia[][5], char matrizRecorrido[][5], int k);

// Declaracion de la variable inf
int INF = __INT_MAX__;

/*
Matriz de distancias                        Matriz de recorrido
Tomando como referencia:                    Tommando como referencia: 

    -   A   B   C   D   E                   -   A   B   C   D   E
    A   0   10  INF 6   INF                 A   A   B   C   D   E
    B   INF 0   3   5   INF                 B   A   B   C   D   E
    C   INF INF 0   INF 3                   C   A   B   C   D   E
    D   4   INF 2   0   INF                 D   A   B   C   D   E
    E   INF INF INF 5   0                   E   A   B   C   D   E

*/
// INF se da por que no hay conexion directa al NODO

//Codigo
int main (){
    int opcion; 
    int op = 0;
    int n = 5; 

    do{
        int opcion1 = 0;
        printf("\nPor favor elija una opcion.\n1.Procesamiento de algoritmo.\n2.Salir.\nOpcion: ");
        scanf("%i", &opcion);
        switch (opcion){
            case 1:
                procesamientoFloyd(n);
                op=0;
            break;
            case 2:
                printf("Realmente quiere salir del programa\n");
                printf("1.Si\n2.No\nOpcion: ");
                scanf("%i", &opcion1);
                if (opcion1 == 1){
                    op = 1; 
                }else{
                    op = 0;
                }
            break;
            default:
                printf("Usted ha seleccionado una opcion invalida\n");
            break;
        }
    }while(op == 0); 
}

void procesamientoFloyd (int n){
    //Valores
    int matrizDistancia[n][5]={
        {0,10,INF,6,INF},
        {INF,0,3,5,INF},
        {INF,INF,0,INF,3},
        {4,INF,2,0,INF},
        {INF,INF,INF,5,0}
    };
    char matrizRecorrido[n][5] = {
        {'A','B','C','D','E'},
        {'A','B','C','D','E'},
        {'A','B','C','D','E'},
        {'A','B','C','D','E'},
        {'A','B','C','D','E'}
    };

    int k = 0; // Referente al tipo de fila y columna evaluado
    do {
        for (int i=0; i<5 ; i++){
            for (int j=0; j<5; j++){
                int suma = 0; 
                //Comprobando fila y columna trabajada
                if (i == k || j ==k){
                    matrizDistancia [i][j] = matrizDistancia [i][j]; 
                    matrizRecorrido [i][j] = matrizRecorrido [i][j];
                }else{
                    //Se pregunta si es infinito
                    if(matrizDistancia[k][j] == INF || matrizDistancia[i][k] == INF){
                        suma = INF;
                    }else {
                        suma = matrizDistancia[k][j] + matrizDistancia[i][k];
                    }
                    //Se pregunta por la suma
                    if (suma < matrizDistancia[i][j]){
                        matrizDistancia[i][j] = suma;
                        switch(k){
                            case 0:
                                matrizRecorrido [i][j] = 'A';
                            break;
                            case 1:
                                matrizRecorrido [i][j] = 'B';
                            break;
                            case 2:
                                matrizRecorrido [i][j] = 'C';
                            break;
                            case 3:
                                matrizRecorrido [i][j] = 'D';
                            break;
                            case 4:
                                matrizRecorrido [i][j] = 'E';
                            break;
                        }
                    }else{
                        matrizDistancia[i][j] = matrizDistancia[i][j];
                        matrizRecorrido [i][j] = matrizRecorrido [i][j];
                    }
                }
            }
        }
        imprimirMatrices(matrizDistancia, matrizRecorrido, k);
        k++;
    } while(k!=n);
    rutaNodos(matrizDistancia, matrizRecorrido);

}

void rutaNodos(int matrizDistancia[][5], char matrizRecorrido[][5]){
    int nodoInicio; 
    int nodoFinal;
    printf("Ingrese nodo inicio y final teniendo encuenta esto:\nA=0\nB=1\nC=2\nD=3\nE=4\n");
    printf("Nodo Inicio: ");
    scanf("%i", &nodoInicio);
    printf("Nodo Final: ");
    scanf("%i", &nodoFinal);

    for (int i = 0; i < 5; i++){
        for(int j = 0; j<=nodoFinal; j++){
            if(i == nodoInicio && j == nodoFinal){
                printf("El valor entre los dos nodos es: %i", matrizDistancia[i][j]);
            }
        }
    }
    recorridoNodos(matrizRecorrido, nodoInicio, nodoFinal);
}

void recorridoNodos(char matrizRecorridos[][5],int nodoInicio, int nodoFinal){
    
    int a=0;
    char nodoI;
    char nodoF;
    //Pasando nodo inicial y final a CHAR
    switch(nodoInicio){
        case 0:
            nodoI = 'A';
        break;
        case 1:
            nodoI = 'B';
        break;
        case 2:
            nodoI = 'C';
        break;
        case 3:
            nodoI = 'D';
        break;
        case 4:
            nodoI = 'E';
        break;
    }
    switch(nodoFinal){
        case 0:
            nodoF = 'A';
        break;
        case 1:
            nodoF = 'B';
        break;
        case 2:
            nodoF = 'C';
        break;
        case 3:
            nodoF = 'D';
        break;
        case 4:
            nodoF = 'E';
        break;
    }

    char temporal = nodoF;
    char recorrido;
    printf("\nNodo: %c\n", nodoI);
    do {
        for (int i = 0; i < 5; i++){
            for(int j = 0; j<=nodoFinal; j++){
                if(temporal == matrizRecorridos[i][j]){
                    a = 1;
                }else{
                    if(i == nodoInicio && j == nodoFinal){
                        recorrido = matrizRecorridos[i][j];
                        switch (matrizRecorridos[i][j]) {
                            case 'A':
                                nodoInicio = 0;
                                i=0;
                                j=0;
                            break;
                            case 'B':
                                nodoInicio = 1;
                                i=0;
                                j=0;
                            break;
                            case 'C':
                                nodoInicio = 2;
                                i=0;
                                j=0;
                            break;
                            case 'D':
                                nodoInicio = 3;
                                i=0;
                                j=0;
                            break;
                            case 'E':
                                nodoInicio = 4;
                                i=0;
                                j=0;
                            break;
                        }
                        printf("\nNodo: %c\n", recorrido);
                    }
                }
            }
        }
    } while (a!=1);
    printf("\nNodo: %c\n", nodoF);
}

void imprimirMatrices(int matrizDistancia[][5], char matrizRecorrido[][5], int k){
    printf("Recorrido: %i\n", k+1);
    printf("Matriz de Distancia\n");
    for (int i=0 ; i<5 ; i++){
        for (int j = 0; j<5; j++){
            printf("%i\t", matrizDistancia[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //Para la matriz de distancias
    printf("Matriz de Recorrido\n");
    for (int i=0 ; i<5 ; i++){
        for (int j = 0; j<5; j++){
            printf("%c\t", matrizRecorrido[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

