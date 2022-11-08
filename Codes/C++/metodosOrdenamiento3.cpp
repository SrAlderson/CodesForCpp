/*Este codigo tiene la finalidad de mencionar como es la 
implementacion del metodo de ordenamiento por monticulos realizando
esto por medio de un vector y haciendo uso de recursividad*/

//Autor: Giovanni Gonzalez

//Librerias

#include <stdlib.h>
#include <stdio.h>

//Prototipo Funciones

void metodoMonticulo(int vectorMonticulo [10], int tamano, int ultimo);
void imprimirVector (int vector[10], int tamano);

//Codigo

int main (){

    int vectorMonticulo [10] = {5,8,6,1,4,7,3,9,2,0};
    int tamano = 10;
    int ultimo = tamano - 1;
    printf("Vector Original: \n");
    imprimirVector(vectorMonticulo, tamano);
    printf("----------------------\n");
    printf("Vector Ordenado: \n");
    metodoMonticulo(vectorMonticulo, tamano, ultimo);
}

//Funciones

void metodoMonticulo(int vectorMonticulo [10], int tamano, int ultimo){
    int tam = ultimo;
    int padre = (ultimo - 1)/2;
    int auxiliar;
    int flag = 0; 
    //Acomodacion de elementos
    printf("Vector Inicial: "); 
    imprimirVector(vectorMonticulo, tamano);

    do{
        //Variables
        int hijoIzquierdo = 2*padre + 1;
        int hijoDerecho = 2*padre + 2; 
        
        //Validacion si el padre tiene UNO o DOS hijos
        //Caso 1: Solo hijo IZQUIERDO
        if (hijoDerecho>tam){
            flag = 1; 
            if (vectorMonticulo[padre]<vectorMonticulo[hijoIzquierdo]){
                auxiliar  = vectorMonticulo[padre];
                vectorMonticulo[padre] = vectorMonticulo[hijoIzquierdo];
                vectorMonticulo[hijoIzquierdo] = auxiliar;
            }
        }
        //Caso 2: Solo hijo DERECHO
        if (hijoIzquierdo>tam){
            flag = 1; 
            if (vectorMonticulo[padre]<vectorMonticulo[hijoDerecho]){
                auxiliar  = vectorMonticulo[padre];
                vectorMonticulo[padre] = vectorMonticulo[hijoDerecho];
                vectorMonticulo[hijoDerecho] = auxiliar;
            }
        }
        //Caso General: Padre tiene AMBOS hijos
        if (flag == 0){
            if (vectorMonticulo[hijoIzquierdo]>vectorMonticulo[hijoDerecho]){
                if (vectorMonticulo[padre]<vectorMonticulo[hijoIzquierdo]){
                    auxiliar  = vectorMonticulo[padre];
                    vectorMonticulo[padre] = vectorMonticulo[hijoIzquierdo];
                    vectorMonticulo[hijoIzquierdo] = auxiliar;
                }
            }else{
                if (vectorMonticulo[padre]<vectorMonticulo[hijoDerecho]){
                    auxiliar  = vectorMonticulo[padre];
                    vectorMonticulo[padre] = vectorMonticulo[hijoDerecho];
                    vectorMonticulo[hijoDerecho] = auxiliar;
                }
            }
        }

        flag = 0; // Bandera para evaluar solo cuando el padre tiene los dos hijos
        padre--;//Movimiento del padre

    }while (padre != - 1);

    //Visualizacion del vector cuando el elemento mayor del array queda en la posicion 0
    printf("Movimiento Vector:");
    imprimirVector(vectorMonticulo, 10);

    //Cambio de posicion
    auxiliar = vectorMonticulo[0]; 
    vectorMonticulo[0] = vectorMonticulo[ultimo];
    vectorMonticulo[ultimo] = auxiliar;

    //Visualizacion vector ordenado
    printf("Vector Ordenado: ");
    imprimirVector(vectorMonticulo, tamano);

    //Cambio de variables
    ultimo --;
    
    //Uso recursividad para ordenar el array
    if (ultimo > 0){
        metodoMonticulo(vectorMonticulo, 10, ultimo);
    }
}

void imprimirVector (int vector[10], int tamano){
    for (int i=0; i < tamano; i++){
        printf("%i,", vector[i]);
    }
    printf("\n");
}