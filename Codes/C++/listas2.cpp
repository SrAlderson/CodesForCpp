/* Este codigo tiene la finalidad de poder hacer la insercion de datos 
ya sea por izquierda o por derecha de la lista, al igual que el metodo
de eliminarcion.
*/

//Autor: Giovanni Gonzalez 


//Librerias
#include <stdlib.h>
#include <stdio.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo)) 
/*Localizar tiene la funcion de reservar el espacio de memoria cada vez que se cree un nodo*/


// Prototipo de funciones
void insertarDerecha (struct nodo **);
void insertarIzquierda (struct nodo **); // Se envia el apuntador del apuntador
void eliminarDerecha(struct nodo **);
void eliminarIzquierda(struct nodo **);
void buscarElemento(struct nodo **);
void imprimir (struct nodo *); // Solo se envia el apuntador

// Estructura
struct nodo {
    int dato;
    struct nodo *siguiente;
};

// Codigo

int main (){

    struct nodo *p; // Aqui se menciona que la LISTA esta vacia
    p = NULL;
    int op; // Inicio del menu

    do{

        int opcion; // Seleccion del menu
        int opcion1; // Confirmaicon de salida

        printf ("\nPor favor seleccione alguna de las siguientes opciones:");
        printf ("\n1.Insertar Derecha\n2.Eliminar Derecha\n3.Insertar Izquierda\n4.Eliminar Izquierda\n5.Buscar\n6.Salir");
        printf ("\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion){
            case 1:
                // Caso de INSERTAR DERECHA
                insertarDerecha(&p);
                op = 7;
            break;

            case 2:
                // Caso de ELIMINAR DERECHA
                eliminarDerecha(&p);
                op = 7;
            break;

            case 3:
                // Caso de INSERTAR IZQUIERDA
                insertarIzquierda(&p);
                op = 7;
            break;

            case 4:
                // Caso de ELIMANAR IZQUIERDA    
                eliminarIzquierda(&p);
                op = 7;
            break;

            case 5:
                // Caso de BUSCAR
                buscarElemento(&p);
                op = 7;
            break;

            case 6:
                // Caso de SALIR
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

    }while(op == 7);

    printf ("Usted ha salido del programa\n"); // Mensaje de verificacion   

    return 0;

}

//Funciones

void insertarDerecha (struct nodo **p){

    struct nodo *q;
    int datoF; 
    printf("Ingrese un dato: ");
    scanf("%i", &datoF);
    q = localizar; 
    q -> dato = datoF;
    q -> siguiente = NULL;

    //Caso 1 -> Lista vacia
    if (*p == NULL){
        *p = q; // Asigna el nuevo nodo y lo apunta a NULL
    }else{
        // Caso 2 -> Lista con elementos
        // Se debe recorrer la lista hasta encontar el valor final
        struct nodo *aux = *p;
        while (aux -> siguiente != NULL){
            aux = aux -> siguiente;
        } 
        aux -> siguiente = q;
    }
    imprimir(*p);
}

void eliminarDerecha(struct nodo **p){

    struct nodo *q; 
    // Caso 1 -> cuando la lista esta vacia
    if (*p == NULL){

        printf("No se puede eliminar elementos, lista esta vacia\n");

    }else{ 
        // se crea una copia de P
        q = *p;
        // Caso 2 -> Es el ultimo elemento de la lista
        if (q -> siguiente == NULL){
            printf("Dato eliminado es: %i \n" , q -> dato);
            delete q; 
            *p = NULL;
        }else{
            // Caso 3 -> General (hay otros datos)
            struct nodo *q; 
            struct nodo *aux; // Variables auxiliar es una copia de P
            q = *p; 
            aux = *p;

            while (q -> siguiente!= NULL){
                aux = q; // Copia Q
                q = q -> siguiente; // Mueve Q
            }
            printf("Dato eliminado es: %i \n" , q -> dato);
            aux ->siguiente = NULL; // Apunta a Q al ultimo nodo dado que es el fin de P
            delete q;
        }

    }

    imprimir(*p);

}

void insertarIzquierda (struct nodo **p){

    struct nodo *q; // Se crea un nodo nuevo Q
    int datoF; // Crear variable dato 
    printf("Ingrese un dato: ");
    scanf("%i", &datoF);
    q = localizar; // Se asigna un espacio de memoria a Q
    q -> dato = datoF; // Se asigna el dato al valor de DATO de la estructura
    q -> siguiente = *p; // Asigna el valor de Q a el apuntador de P
    *p = q; 
    imprimir(*p);

}

void eliminarIzquierda(struct nodo **p){

    struct nodo *q; 
    
    // Caso 1 -> cuando la lista esta vacia
    if (*p == NULL){

        printf("No se puede eliminar elementos, lista esta vacia\n");

    }else{ 
        // se crea una copia de P
        q = *p;
        // Caso 2 -> Es el ultimo elemento de la lista
        if (q -> siguiente == NULL){
            printf("Dato eliminado es: %i \n" , q -> dato);
            delete q; 
            *p = NULL;
        }else{
            // Caso 3 -> General (hay otros datos)
            printf("Dato eliminado es: %i \n" , q -> dato);
            *p = q -> siguiente;
            delete q; 
        }

    }
    imprimir(*p);

}

void imprimir (struct nodo *p){

    printf("Los datos de la lista son: \n");

    while(p!=NULL){
        printf("%i", p->dato);
        p = p -> siguiente;
    }

}

void buscarElemento (struct nodo **p){

    int elemento; 
    int flag = 0; 

    printf("Por favor ingrese el elemento que desea buscar: ");
    scanf("%i", &elemento);

    struct nodo *q; 
    q = *p; 

    while ((q != NULL) && (q->dato <= elemento)){
        
        if (q->dato == elemento){
            printf("El elemento hallado es: %i\n", q->dato);
            flag = 1; 
        }
        
        q = q->siguiente;
    }

    if (flag == 1){
        printf("Su elemento esta dentro de la lista\n");
        
    }else{
        printf("Elemento no se encuentra en la lista");
    }

}