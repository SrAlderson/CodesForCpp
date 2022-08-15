// El siguiete codigo explica como hacer una pila pasando los datos por refrencia
// Autor: SrAlderson

#include <iostream>

// prototipo de funciones

void imprimir(int vector [5], int &indice);
int insertar(int vector[5], int *indice, int *n);
int eliminar(int vector[5], int *indice, int *n);

int main (){
    
    int op; // inicia el menu
    int vector[5]; // Debe tener un tamaño fijo
    int indice = -1; // Debe iniciar en este valor para decir que la pila esta vacia
    int n = 5; // Esto hace referencia al tamaño del vector
    
    // Pregunta por la accion que quiera realizar
    do{
        int opcion1; // para validacion de la salida
        int opcion; // para seleccion del menu 
        
        printf ("Por favor seleccione alguna opcion \n");
        printf ("1.Insertar\n2.Eliminar\n3.Salir\nopcion: "); 
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                indice = insertar(vector, &indice, &n);
                imprimir (vector, indice);
                op = 4;
                break;
            case 2: 
                indice = eliminar(vector, &indice, &n);
                imprimir (vector, indice);
                op = 4;
                break;
            case 3:
                printf("Usted realmente quiere salir del programa \n");
                printf(" 1. Si \n 2.No \n opcion: ");
                scanf("%d", &opcion1);
                if (opcion1 == 1){
                    op = 0;
                }else{ 
                    op = 4;
                }
                break;
            default:
                printf ("Opcion invaldia, ingrese otra opcion de nuevo");
                break;
        }

    } while (op == 4); // Menu queda corriende hasta que se valide la confirmacion de fin del programa

    printf ("Usted ha salido del programa\n");   

    return 0;
}

// Funciones

// Añade un dato en la posicion i del vector
int insertar(int vector[5], int *indice, int *n){
    // Se declara la variable dato para poder dejar esa en el indice del vector
    int dato; 
    // Validacion de si la pila esta llena
    if (*(indice)== *(n)-1){
        printf("Pila llena, no se puede agregar datos \n");
    }else{
        // Se aumenta en 1 para enviar el indice, marcando asi que esa posicion ya fue llenada
        *(indice) = *(indice) + 1;
        printf ("Por favor ingrese un dato: ");
        scanf("%i", &dato); 
        vector[*(indice)]= dato; // Se llena el vector en la posicion i con el dato
    }

    return *indice;
}

// Elimina posicion por posicion los datos del vector
int eliminar (int vector[5], int *indice, int *n){
    // Validacion si la pila se encuentra vacia
    if (*(indice) == -1){
        printf ("No se puede elimnar datos, pila esta vacia \n");
    }else{
        vector[*(indice)] = vector[*(indice)] - 1;
        *(indice) = *(indice) - 1;
    }
    return *indice;
}

// Imprime el vector
void imprimir (int vector[5], int &indice){
    int j; // permite la lectura del vector
    if (indice == -1){
        printf("No se puede imprimir la pila, pila vacia \n"); // Este aviso puede aparecer dos veces dado a que la condicion se encuentra cada funcion
    }else{
        for (j = 0; j <= indice; j++){
            printf("En la posicion [%i] del vector esta el valor -> %i \n", j, vector[j]);
        }
    }
}