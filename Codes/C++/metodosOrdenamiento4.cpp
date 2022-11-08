/*Este codigo tiene la finalidad mostrar la implementacion
del metodo de ordenamiento radix*/

//Librerias
#include <stdlib.h>
#include <stdio.h>

//Prototipo de funciones

void metodoRadix(int vector[10], int tamanoReal, int);
void busquedaElemento (int vector[10], int tamanoReal);
void ordenamiento(int vector[10], int tamanoReal, int n);
void imprimirVector(int vector[10], int tamanoReal);

//Codigo

int main (){

    int vector [10] = {45,18,23,17,12,5,72,43,21};
    int tamano = 10; 
    int tamanoReal=tamano-1;
    busquedaElemento(vector, tamanoReal);
    //imprimirVector(vector, tamanoReal);
}

//Funciones

void busquedaElemento (int vector[10], int tamanoReal){
    int valorNumero = vector[0];
    for (int i=0; i<tamanoReal; i++){
        if(vector[i]>valorNumero){
            valorNumero=vector[i];
        }
    }
    //Llamado a la funcion radix
    metodoRadix(vector, tamanoReal, valorNumero);
}


void metodoRadix(int vector[10], int tamanoReal, int valorNumero){
    int valor = valorNumero;
    for (int i=1; valor/i>0; i*=10){
        ordenamiento(vector, tamanoReal,i);
        imprimirVector(vector, tamanoReal);
        printf("\n");
    }
}

void ordenamiento(int vector[10], int tamanoReal, int n){

    int vectorOrdenado[tamanoReal+1];
    int numero = (vector[0]/n)%10;

    for (int i=1; i<tamanoReal; i++){
        if((vector[i]/n)%10 > numero){
            numero = vector[i];
        }
    }

    int vector2[numero+1];

    for(int i=0; i<numero; i++){
        vector2[i]=0;
    }
    for(int i=0; i<tamanoReal;i++){
        vector2[(vector[i]/n) % 10]++;
    }
    for(int i=1; i<10; i++){
        vector2[i] += vector2[i-1];
    }
    for(int i=tamanoReal-1; i>=0; i--){
        vectorOrdenado[vector2[(vector[i]/n) % 10]-1] = vector[i];
        vector2[(vector[i]/n) % 10]--;
    }
    for(int i=0; i<tamanoReal; i++){
        vector[i]=vectorOrdenado[i];
    }
}

void imprimirVector(int vector[10], int tamanoReal){
    for(int i=0; i<tamanoReal; i++){
        printf("%d ", vector[i]);
    }
}