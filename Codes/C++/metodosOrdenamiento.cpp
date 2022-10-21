/*Este codigo tiene como fin poder dejar implementado 
los metodos de ordenamiento de SHAKE y BURBUJA*/

//Autor: SrAlderson

//Librerias
#include <stdlib.h>
#include <stdio.h>

//Prototipo de funciones
void burbuja(int vector[20], int vectorCopia[20], int n);
void shake(int vector[20], int vectorCopia[20], int n); 
void metodosSinBandera(int vector[20], int vectorCopia[20], int n);
void imprimir(int vector[20], int n);
void copiaVector(int vector[20], int vectorCopia[20], int n , int bandera);
void menu(int op);

//Codigo
int main (){
    int op = 0; 
    menu(op);
}
//Funciones
void menu(int op){
    //Vector solicitado
    int vectorCopia[20];
    int vector[20] = {8,9,7,3,2,13,20,15,11,10,14,6,1,16,19,4,17,5,12,18}; // Vector valores en desorden
    //int vector[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; // Vector valores organizados
    int n = 20; //Tamaño del vector

    //Ciclo repetitivo del menu
    do {
        int opcion; // Seleccion del menu
        int opcion1; // Confirmaicon de salida
        
        printf ("\nPor favor seleccione alguna de las siguientes opciones:");
        printf ("\n1.Metodo Burbuja\n2.Metodo Shake\n3.Metodos Sin bandera\n4.Salir");
        printf ("\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion){
            case 1:
                // Metodo Burbuja
                burbuja(vector,vectorCopia,n);
                op = 1; 
            break;

            case 2:
                // Metodo Shake
                shake(vector,vectorCopia,n);
                op = 1; 
            break;
            
            case 3:
                // Metodo Sin Bandera
                metodosSinBandera(vector,vectorCopia,n);
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
                    op = 1;
                }
            break;

            default:
                printf("Ha seleccionado una opcion invalida");
            break;
        }

    }while (op==1);
    printf ("Usted ha salido del programa\n"); // Mensaje de verificacion
}
void burbuja(int vector[20], int vectorCopia[20], int n){
    int temporal;
    int flag = 0;
    //Vector Copia
    copiaVector(vector, vectorCopia, n, 0);
    //Recorrido del vector teniendo en cuenta la posicion
    for(int i=0; i<n-1; i++){
        printf("Recorrido: %i\n",i+1);
        //Recorrido del vector teniendo en cuenta la posicion actual + 1
        for (int j=i+1; j<n; j++){
            // Validacion de las posiciones
            if(vector[i]>vector[j]){
                temporal = vector[i];
                vector[i] = vector[j];
                vector[j] = temporal;
                flag = 1; 
            }
        }
        //Visualizacion vector
        imprimir(vector,n);
        //Condicional si el vector esta ordenado
        if (flag == 0){
            break;
        }
    }
    copiaVector(vector, vectorCopia, n, 1);
}
void shake(int vector[20], int vectorCopia[20], int n){
    int temporal; 
    int flag = 0; 
    //Vector copia
    copiaVector(vector, vectorCopia, n, 0);
    // Recorrido del vector teniendo encuenta la posicion
    for(int i=0; i<n-1; i++){
        printf("Recorrido: %i\n",i+1);
        //Recorrido del vector teniendo en cuenta la siguiente posicion
        for (int j=0; j<n-1; j++){
            // Validacion de las posiciones
            if (vector[j+1] < vector[j]){
                temporal = vector[j+1];
                vector[j+1] = vector[j]; 
                vector[j] = temporal;
                flag=1; 
            }
        }
        //Visualizacion vector
        imprimir(vector,n);
        //Condicional si el vector esta ordenado
        if (flag == 0){
            break;
        }
    }
    copiaVector(vector, vectorCopia, n, 1);
}
void copiaVector (int vector[20], int vectorCopia[20], int n , int bandera){
    
    //Copia vector original
    if(bandera==0){
        for (int i=0; i<n; i++){
            vectorCopia[i] = vector[i];
        }
    }
    if(bandera==1){
        for (int i=0; i<n; i++){
            vector[i] = vectorCopia[i];
        }
    }

}
void metodosSinBandera(int vector[20], int vectorCopia[20], int n){
    //Funcion arroja los dos metodos al tiempo
    int temporal;
    int flag = 0;

    printf("Metodo Burbuja: \n");
    //Vector Copia
    copiaVector(vector, vectorCopia, n, 0);
    //Recorrido del vector teniendo en cuenta la posicion
    for(int i=0; i<n-1; i++){
        printf("Recorrido: %i\n",i+1);
        //Recorrido del vector teniendo en cuenta la posicion actual + 1
        for (int j=i+1; j<n; j++){
            // Validacion de las posiciones
            if(vector[i]>vector[j]){
                temporal = vector[i];
                vector[i] = vector[j];
                vector[j] = temporal;
            }
        }
        //Visualizacion vector
        imprimir(vector,n);
    }
    copiaVector(vector, vectorCopia, n, 1);

    printf("Metodo Shake: \n");
    //Vector copia
    copiaVector(vector, vectorCopia, n, 0);
    // Recorrido del vector teniendo encuenta la posicion
    for(int i=0; i<n-1; i++){
        printf("Recorrido: %i\n",i+1);
        //Recorrido del vector teniendo en cuenta la siguiente posicion
        for (int j=0; j<n-1; j++){
            // Validacion de las posiciones
            if (vector[j+1] < vector[j]){
                temporal = vector[j+1];
                vector[j+1] = vector[j]; 
                vector[j] = temporal;
            }
        }
        //Visualizacion vector
        imprimir(vector,n);
    }
    copiaVector(vector, vectorCopia, n, 1);
}
void imprimir (int vector[20], int n){
    printf("Vector: ");
    for (int i=0; i < n; i++){
        printf("%i,", vector[i]);
    }
    printf("\n");
}