/*El siguiente codigo tiene el objetivo de mostrar como es el
uso de la recursividad*/

//Autor: SrAlderson

#include <stdio.h>
#include <stdlib.h>

// prototipo de funciones

int sumaVector(int vector[10], int tamano);
void busquedaElemento(int vector[10], int tamano, int elemento);
void imprimirVector(int vector [10], int tamano);

//Codigo
int main (){
    int vector[10] = {0,1,2,3,4,5,6,7,8,9};
    int tamano = 9;
    int elemento;
    
    int op = 1; 

    do {
        int opcion; // Seleccion del menu
        int opcion1; // Confirmaicon de salida

        printf ("\nPor favor seleccione alguna de las siguientes opciones:");
        printf ("\n1.Sumar datos del vector\n2.Buscar elemento\n3.Imprimir vector\n4.Salir");
        printf ("\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion){
            case 1:
                // Caso SUMA ELEMENTOS DE VECTOR
                printf("\nLa suma de los datos del vector es: %i", sumaVector(vector, tamano));
                printf("\n");
                op = 1;
            break;

            case 2:
                // Caso BUSCAR ELEMENTO
                printf("Ingrese el numero que quiere buscar: ");
                scanf("%i", &elemento);
                busquedaElemento (vector, tamano, elemento);
                printf("\n");
                op = 1;
            break;

            case 3:
                // Caso IMPRIMIR VECTOR
                printf("\nLos datos del vector son los siguientes: ");
                imprimirVector(vector, tamano);
                printf("\n");
                op = 1;
            break;

            case 4:
                // Caso SALIR
                printf("Usted realmente quiere salir del programa \n");
                printf("1.Si\n2.No\nopcion: ");
                scanf("%d", &opcion1);
                if (opcion1 == 1){
                    op = 0;
                }else{ 
                    op = 7;
                }
            break;

            default:
                printf("Ha seleccionado una opcion invalida");
            break;
        }
    }while (op==1);

    printf ("Usted ha salido del programa\n"); // Mensaje de verificacion   
    return 0;
}

//Funciones 
int sumaVector(int vector [10], int tamano){
    if (tamano == 0 ){
        return vector[tamano];
    }else{
        tamano = tamano -1; 
        return vector[tamano + 1] + sumaVector(vector, tamano);
    }
}

void imprimirVector(int vector [10], int tamano){
    if (tamano > 0){
        imprimirVector(vector, tamano-1);
        printf("%i", vector[tamano]);
    }else{
        printf("%i", vector[tamano]);
    }
}

void busquedaElemento(int vector[10], int tamano, int elemento){
    if (tamano >=0){
        if (elemento == vector [tamano]){
            printf("\nElemento dentro del vector \nSu elemento es: %i ", vector[tamano]);
        }else{
            busquedaElemento(vector, tamano-1, elemento);
        }
    }else{
        printf("\nElemento no esta dentro del vector.");
    }
}