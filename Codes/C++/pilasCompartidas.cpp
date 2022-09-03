/*Este codigo tiene la finalidad de mostrar un ejemplo de pilas compartidas
esto quiere decir que el usuario va a poder llenar la pila tanto por la izquierda 
como por la derecha*/

//Autor: SrAlderson

//Librerias

#include <iostream>

// Prototipo de funciones

struct valores insertarPila1 (int vector[5], struct valores v, int n); 
struct valores insertarPila2 (int vector[5], struct valores v, int n); 
struct valores eliminarPila1 (int vector[5], struct valores v, int n);
struct valores eliminarPila2 (int vector[5], struct valores v, int n); 
void imprimir(int vector[5], struct valores v, int n); 

//Estructuras

struct valores
{
    int indicePila1; 
    int indicePila2; 
     
};


// Codigo

int main (){

    // Declaracion de la estructura
    struct valores v; 

    // Declaracion de las variables
    int vector [5]; 
    int n = 5; 
    v.indicePila1 = -1; 
    v.indicePila2 = n; 

    // Para el ciclo 

    int op; 

    do{

        // Para el menu 
        int opcion; 
        int opcion1;

        printf("\nPor favor seleccione alguna de las siguientes opciones:\n");
        printf("1.Insertar en Pila 1\n2.Insertar en Pila 2\n3.Eliminar en Pila 1\n4.Eliminar en Pila 2\n5.Salir\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:

                v = insertarPila1(vector, v, n);
                imprimir (vector, v, n);
                op = 6;

                break;
            case 2:
                
                v = insertarPila2(vector, v, n);
                imprimir (vector, v, n);
                op = 6;

                break;
            case 3:
                
                v = eliminarPila1(vector, v, n);
                imprimir(vector, v, n);
                op = 6;

                break;
            case 4:

                v = eliminarPila2(vector, v, n);
                imprimir(vector, v, n);
                op = 6;
                break;

            case 5: 
                printf("Usted realmente quiere salir del programa \n");
                printf("1.Si\n2.No\nopcion: ");
                scanf("%d", &opcion1);
                if (opcion1 == 1){
                    op = 0;
                }else{ 
                    op = 6;
                }
                break;
            default:
                printf ("Opcion invaldia, ingrese otra opcion de nuevo");
                break;
        }


    }while (op == 6);

    printf ("Usted ha salido del programa\n"); // Mensaje de verificacion   

    return 0; 
}

// Funciones

struct valores insertarPila1 (int vector[5], struct valores v, int n){
    // Esta funcion hace referencia cuando el usuario ingresa un dato por derecha

    // Declaracion de estructura interna
    struct valores a;

    // Aplicacion del struct

    a.indicePila1 = v.indicePila1;
    a.indicePila2 = v.indicePila2; 

    // Declaracion variable

    int dato; 

    // Lectura del dato

    printf("Por favor ingrese un dato en la Pila 1: ");
    scanf("%i", &dato); 

    // Validaciones

    // Caso 1 -> Pila vacia
    if (a.indicePila1 == -1 && a.indicePila2 == n){

        a.indicePila1 = 0; // Para ingrtesar dato en la posicion 0 del vector
        vector[a.indicePila1] = dato; 
        

    }else if (a.indicePila1 == n-1 || a.indicePila1 == a.indicePila2-1){
        // Caso 2 -> Pila llena
        printf("La Pila esta llena no se puede ingresar dato\n"); 
        
    }else{
        //Caso 3 -> General
        a.indicePila1 = a.indicePila1 + 1; // Se corre para ingresar en la siguiente posicion
        vector[a.indicePila1] = dato; 
        
    }
    
    return a; 
}

struct valores insertarPila2 (int vector[5], struct valores v, int n){

    // Esta funcion hace referencia cuando el usuario ingresa un dato por izquierda

    // Declaracion de estructura interna
    struct valores a;

    // Aplicacion del struct

    a.indicePila1 = v.indicePila1;
    a.indicePila2 = v.indicePila2; 

    // Declaracion variable

    int dato; 

    // Lectura del dato

    printf("Por favor ingrese un dato en la Pila 2: ");
    scanf("%i", &dato); 

    // Validaciones

    // Caso 1 -> Pila vacia
    if (a.indicePila1 == -1 && a.indicePila2 == n){

        a.indicePila2 = n-1; // Para ingrtesar dato en la posicion 0 del vector
        vector[a.indicePila2] = dato; 

    }else if (a.indicePila2 == 0 || a.indicePila1 == a.indicePila2-1){
        // Caso 2 -> Pila llena
        printf("La Pila esta llena no se puede ingresar dato"); 
        
    }else{
        //Caso 3 -> General
        a.indicePila2 = a.indicePila2 - 1; // Se corre para ingresar en la siguiente posicion
        vector[a.indicePila2] = dato; 

    }
    
    return a; 
    
}

struct valores eliminarPila1(int vector[5], struct valores v, int n){

    //Declaracion de estructura interna 

    struct valores a;

    // Aplicacion del struct

    a.indicePila1 = v.indicePila1;
    a.indicePila2 = v.indicePila2; 

    //Validaciones

    // Caso 1 -> Pila esta vacia
    if (a.indicePila1 == -1 && a.indicePila2 == n){
        printf("La Pila esta vacia, no se puede eliminar dato.");
    }else if(a.indicePila1 == -1){
        printf("La Pila 1 esta vacia, no se puede eliminar dato.");
    }else if (a.indicePila1 == 0){
        //Caso 2 -> Eliminar ultimo elemento de la Pila
        a.indicePila1 = -1;
    }else{
        // Caso 3 -> General
        a.indicePila1 = a.indicePila1 -1;
    }

    return a; 
}

struct valores eliminarPila2 (int vector[5], struct valores v, int n){

    //Declaracion de estructura interna 

    struct valores a;

    // Aplicacion del struct

    a.indicePila1 = v.indicePila1;
    a.indicePila2 = v.indicePila2; 

    //Validaciones

    // Caso 1 -> Pila esta vacia
    if (a.indicePila1 == -1 && a.indicePila2 == n){
        printf("La Pila esta vacia, no se puede eliminar dato.");
    }else if(a.indicePila2 == n){
        printf("La Pila 2 esta vacia, no se puede eliminar dato.");
    }else if (a.indicePila2 == n-1){
        //Caso 2 -> Eliminar ultimo elemento de la Pila
        a.indicePila2 = n;
    }else{
        // Caso 3 -> General
        a.indicePila2 = a.indicePila2 + 1;
    }

    return a; 

}


void imprimir(int vector[5], struct valores v, int n){

    if (v.indicePila1 == -1 && v.indicePila2 == n){
        
        printf("La pila esta vacia, por favor ingresar un dato. \n");

    }else {

        //Para la Pila 1
        printf("\nDatos de la Pila 1:");
        printf("\ndatos: "); 
        for (int i = 0; i <= v.indicePila1; i++){
            printf("%i", vector[i]); 
        }
        printf("\np-vec: "); 
        for (int j = 0; j <= v.indicePila1; j++){
            printf("%i", j); 
        }
        printf("\n");
        //Para la Pila 2
        printf("\nDatos de la Pila 2:");
        printf("\ndatos: "); 
        for (int k = v.indicePila2; k <= n-1; k++){
            printf("%i", vector[k]); 
        }
        printf("\np-vec: "); 
        for (int l = v.indicePila2; l <= n-1; l++){
            printf("%i", l); 
        }
        printf("\n");
        printf("\nIP1: %i", v.indicePila1);
        printf("\nIP2: %i", v.indicePila2);

    }
    

}
