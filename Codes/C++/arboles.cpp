/*El objetivo de este codigo es poder visualizar como son los
 recorridos para los arboles binarios: pre-order, in-order, post-order
 */

//Autor:

//Librerias

#include <stdlib.h>
#include <stdio.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo)) 

//Prototipo de funciones

void insertar(struct nodo **);
void buscarElemento (struct nodo **);
void preOrden (struct nodo **);
void inOrden(struct nodo *);
void postOrden(struct nodo *);

//Estructura del arbol

struct nodo {

    struct nodo *izquierda;
    int datoN;
    struct nodo *derecha;

};

//Codigo

int main(){

    //Se crea el nodo apuntado a vacio
    struct nodo *p;
    p = NULL;
    int op = 1; 
    do {
        int opcion;
        printf("Opcion: ");
        scanf("%i", &opcion);
        switch (opcion){
            case 1:
                insertar(&p);
                op = 1;
            break;
            case 2:
                //preOrden(&p);
                op = 1; 
            break;
            default:
                op = 0; 
            break;
        }
    } while(op==1);
    
}

//Funciones

void insertar(struct nodo **p){
    // Se crea una copia del arbol
    struct nodo *q; 

    //Para registar el dato
    int datoF;
    int flag = 0;
    printf("Por favor ingrese un dato: ");
    scanf("%i", &datoF);

    q = localizar; 
    q->datoN = datoF;
    q->izquierda = NULL;
    q->derecha = NULL;

    //Caso 1: Cuando el arbol no exixste
    if (*p == NULL){
        *p = q;
    }else{
        struct nodo *aux = *p; // Copia de P para ir recorriendo
        //Caso 2: Cuando el dato ingresado es menor
        while(datoF < aux ->datoN && flag == 0){
            //Recorrido del arbol
            if (aux->izquierda != NULL){
                aux = aux->izquierda;
                flag = 0;
            }else{
                aux->izquierda = q;
                flag=1;
            }
        }
        // Caso 3: Cuando el dato ingresado es mayor
        while (datoF > aux ->datoN && flag ==0){
            //Recorrido del arbol
            if (aux->derecha != NULL){
                aux = aux->derecha;
                flag = 0; 
            }else{
                aux->derecha=q;
                flag=1; 
            }
        }


    }

}
void buscarElemento (struct nodo **){

}
/*
void preOrden (struct nodo **p){
    struct nodo *aux;
    aux = *p;
    if (aux!=NULL){
        printf("%i", aux->datoN);
        preOrden(aux->izquierda);
        preOrden(aux->derecha);
    }

}*/
void inOrden(struct nodo *){

}
void postOrden(struct nodo *){

}