/* Este codigo tiene como objetivo mostrar como es el funcionamiento
y la implementacion del metodo de ordenamiento quicksort*/

//Autor: Giovanni Gonzalez

//Librerias
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Prototipo de funciones

void metodoQuick (int vector[20], int primero, int ultimo);
void imprimirVector (int vector[20], int tamano);
//Codigo

int main(){
    //Declaracion del vector
    int vectorQuick[20] = {8,9,7,3,2,13,20,15,11,10,14,6,1,16,19,4,17,5,12,18};
    int tamano = 20;
    //Visualizacion vector inicial
    printf("Vector Inicial: \n");
    imprimirVector(vectorQuick, tamano);
    //Visualizacion vector organizado
    printf("Vector Ordenado: \n");
    metodoQuick(vectorQuick, 0, tamano-1);

}

//Funciones
void metodoQuick (int vector[20], int primero, int ultimo){
    int temporal;
    int i = primero; 
    int j = ultimo; 
    int a = (primero + ultimo)/2;
    int pivote = vector[a];   
     
    do{
        //Validacion de menores
        while(vector[i]<pivote){
            i++;
        }
        //Validacion de mayores
        while(vector[j]> pivote){
            j--;
        }
        //Validacion de las sublistas
        if (i<=j){
            //Ordenamiento
            temporal = vector[i];
            vector[i] = vector[j];
            vector[j] = temporal;
            //Incremento de los punteros
            i++;
            j--;
            //Visualizacion vector
            imprimirVector(vector, 20);
        }
    }while(i<=j);
    
    //Aplicando recursividad
    if (primero < j){
        metodoQuick(vector, primero, j);
    }
    if (i < ultimo){
        metodoQuick(vector, i, ultimo);
    }
    
}

void imprimirVector (int vector[20], int tamano){
    printf("Vector: ");
    for (int i=0; i < tamano; i++){
        printf("%i,", vector[i]);
    }
    printf("\n");
}