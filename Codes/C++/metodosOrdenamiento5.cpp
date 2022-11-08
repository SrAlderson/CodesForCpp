/*Este codigo tiene como finalidad mostrar los metodos de 
ordenamiento de busqueda secuencial y busqueda binaria, en donde para 
la busqueda binaria es necesario contar con un metodo de ordenamiento 
primero para lograrlo, en este caso se usa el metodo quick sort*/

//Autor:Giovanni Gonzalez

//Librerias

#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones

void busquedaSecuencial (int vector[30], int tamano, int numero);
void busquedaBinaria (int vector[30], int tamano, int numero, int derecha, int izquierda);
void metodoQuick (int vector[30], int primero, int ultimo);
void imprimirVector (int vector[30], int tamano);
void tabla (int derecha, int izquierda, int medio);
//Codigo

int main (){

    int op =1;
    do {

        int vector[30]={30,8,9,22,7,3,27,2,13,20,24,15,11,28,10,14,6,26,1,16,19,25,4,23,17,5,21,12,18,29};
        int tamano = 30;
        int numero;
        int opcion;
        int salida;  
        printf("Por favor ingrese el numero a buscar: ");
        scanf("%d", &numero);
        printf("Por favor ingrese el metodo de busqueda a emplear:\n1.Metodo de busqueda secuencial\n2.Metodo de busqueda binaria.\n3.Salir.\nOpcion: ");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                // Metodo de busqueda secuencial
                busquedaSecuencial(vector, tamano, numero);
                op=1;
            break;
            case 2:
                // Metodo de busqueda binaria
                //Ordenamiento del vector
                printf("Vector Original: ");
                imprimirVector(vector, tamano);
                metodoQuick(vector, 0, tamano-1);
                printf("Vector Ordenado: ");
                imprimirVector(vector, tamano);
                busquedaBinaria(vector, tamano, numero, tamano-1, 0);
                op=1;
            break;
            case 3:
                //Salir
                printf("Realmente quiere finalizar el programa:\n1.Si\n2.No\nOpcion: ");
                scanf("%i", &salida);
                if(salida == 1){
                    op=0;
                }else{
                    op=1;
                }
            break;
            default:
                printf("Ha ingresado una opcion invalida.\n");
                op=1;
            break;
        }

    }while(op==1);    
}

//Funciones
void busquedaSecuencial (int vector[30], int tamano, int numero){
    int tamanoReal = tamano - 1;
    int flag = 0;
    for (int i=0; i<=tamanoReal; i++){
        if(numero == vector[i]){
            printf("El numero esta en la posicion %i del vector.\n", i);
            flag=1;
        }
    }
    if(flag==0){
        printf("El numero no esta dentro de la lista.\n");
    }
}
void metodoQuick (int vector[30], int primero, int ultimo){
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
void imprimirVector (int vector[30], int tamano){
    for (int i=0; i < tamano; i++){
        printf("%i ", vector[i]);
    }
    printf("\n");
}
void busquedaBinaria (int vector[30], int tamano, int numero, int derecha, int izquierda){   
    //Busqueda del elemento
    int izquierda1 = izquierda;
    int derecha1 = derecha;
    int medio = (izquierda1+derecha1)/2;
    int flag;
    int bandera;
    tabla(derecha1, izquierda1, medio);

    //Caso 1: Validacion si es posicion contigua
    int diferencia = izquierda1-derecha1;
    if(diferencia == 1 || diferencia == -1){
        if(numero==vector[derecha1]){
            printf("Se encontro el elemento en la posicion %i \n", derecha1);
        }else{
            if(numero==vector[izquierda1]){
                printf("Se encontro el elemento en la posicion %i \n", izquierda1);
            }else{
                bandera=1;
            }
        }
        flag=1;
    }else{
        //Caso 2: Medio contiene el dato a encontrar
        if (vector[medio]==numero){
            printf("Se encontro el elemento en la posicion %i \n", medio);
            flag=1;
        }else{
            //Caso 3: Evaluacion normal del vector
            if (numero>vector[medio]){
                izquierda1 = medio;
                derecha1 = derecha1;
                flag = 0; 
            }else{
                if (numero<vector[medio]){
                    izquierda1 = izquierda1;
                    derecha1 = medio;
                    flag = 0;
                }
            } 
        }
    }
    
    //Condicionales
    if (flag==0){
        //Visualizacion 
        //tabla(derecha1, izquierda1, medio);
        busquedaBinaria(vector, tamano, numero, derecha1, izquierda1);
    }
    if(bandera==1){
        printf("numero no encontrado \n");
    }
}
void tabla (int derecha, int izquierda, int medio){
    printf("Izq\tDer\tMedio");
    printf("\n");
    printf("%i\t%i\t%i", izquierda, derecha, medio);
    printf("\n");
}