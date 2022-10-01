/*El objetivo de este codigo es poder visualizar como son los
 recorridos para los arboles binarios: pre-order, in-order, post-order
 */

//Autor:

//Librerias

#include <stdlib.h>
#include <stdio.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo)) 

//Prototipo de funciones

void insertar(struct nodo **,int datoF);
void buscarElemento (struct nodo **, int dato);
void eliminarNodo (struct nodo **, int datoE);
void preOrden (struct nodo *);
void inOrden(struct nodo *);
void postOrden(struct nodo *);

//Estructura del arbol

struct nodo {

    struct nodo *izquierda;
    int datoN;
    struct nodo *derecha;
    struct nodo *padre; 

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
                int datoF;
                printf("Por favor ingrese un dato: ");
                scanf("%i", &datoF);
                insertar(&p, datoF);
                op = 1;
            break;
            case 2:
                printf("El recorrido en preOrden del arbol es: ");
                preOrden(p);
                printf("\n");
                op = 1; 
            break;
            case 3:
                printf("El recorrido en inOrden del arbol es: ");
                inOrden(p);
                printf("\n");
                op = 1; 
            break;
            case 4:
                printf("El recorrido en postOrden del arbol es: ");
                postOrden(p);
                printf("\n");
                op = 1; 
            break;
            case 5:
                int dato;
                printf("Por favor ingrese el dato que desea buscar: ");
                scanf("%i", &dato);
                buscarElemento(&p, dato);
                op = 1; 
            break;
            case 6:
                //Caso -> Eliminar
                int datoE;
                printf("Por favor ingrese el dato que desea eliminar: ");
                scanf("%i", &datoE);
                eliminarNodo(&p, datoE);
                op = 1;
            break;
            default:
                op = 0; 
            break;
        }
    } while(op==1);
    
}

//Funciones

void insertar(struct nodo **p, int datoF){
    // Se crea una copia del arbol
    struct nodo *q; 
    //Para registar el dato
    int flag = 0;
    
    q = localizar; 
    q->datoN = datoF;
    q->izquierda = NULL;
    q->derecha = NULL;

    //Caso 1: Cuando el arbol no exixste
    if (*p == NULL){
        *p = q;
    }else{
        struct nodo *aux = *p; // Copia de P para ir recorriendo
        
        while(flag == 0){
            //Recorrido del arbol
            //Caso 2: Cuando el dato ingresado es menor
            if (datoF < aux->datoN){
                if (aux->izquierda != NULL){
                    aux = aux->izquierda;
                    flag = 0;
                }else{
                    aux->izquierda = q;
                    flag=1;
                }
            }else{
                // Caso 3: Cuando el dato ingresado es mayor
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
}
void buscarElemento (struct nodo **p, int dato){
    struct nodo *aux = *p;
    //Caso 1: Arbol esta vacio      
    if (*p==NULL){
        printf("Arbol esta vacio o el dato no existe\n");
    }else{
        if (dato == aux->datoN){
            printf("El dato se ha encontrado.\nValor encontrado: %i \n", aux->datoN);
        }else{
            if (dato < aux->datoN){
                aux = aux->izquierda;
                *p = aux;
                buscarElemento(p, dato);
            }else{
                aux = aux ->derecha;
                *p = aux;
                buscarElemento(p, dato);
            }
        }
    }
}

void eliminarNodo(struct nodo **p, int datoE){
    // Se crea una copia del arbol para trabajar con ella
    struct nodo *aux = *p;
    //Recorrido del arbol
    //Para cuando el arbol esta vacio
    if (*p == NULL){
        printf("Arbol se encuentra vacio no hay elementos para eliminar. \n");
    }else if (datoE < aux->datoN){
        // Cuando el dato a elimnar es menor al dato del NODO
        aux = aux->izquierda; 
        *p=aux; 
        printf("IZ\n");
        eliminarNodo(p,datoE);
    }else if(datoE > aux->datoN){
        //Cuando el dato a eliminar es mayor al dato del NODO
        aux = aux->derecha;
        *p=aux; 
        printf("DR\n");
        eliminarNodo(p,datoE);
    }else{
        //Cuando el dato a eliminar es igual al dato NODO
        
        //Caso 1: Nodo con subarbol derecho e izquierdo
        if (aux->derecha && aux->izquierda){
            printf("tuki 1\n");
            printf("dato aux: %i\n", aux->datoN);
            //Evaluando la parte mas izquierda del sub arbol derecho
            struct nodo *q;
            q = *p;
            q = q->derecha; 
            while (q->izquierda != NULL){
                q = q->izquierda; 
            }
            printf("El nodo mas izquierdo es: %i\n", q->datoN);
            // Reemplazo del nodo mas izquierdo por el nodo a eliminar
            aux->datoN = q->datoN;
        }
        //Caso 2: Nodo con subarbol derecho o izquierdo
        if (aux->izquierda == NULL && aux->derecha!=NULL){
            printf("tuki 2\n");
            struct nodo *q; 
            q = *p;
            q = q->derecha;
            aux = q; 
            q->derecha = NULL;
            q->izquierda = NULL;
            delete q;
        }
    }




//Caso 3: Nodo hoja




}



void preOrden (struct nodo *p){
    
    if (p!=NULL){
        printf("%i\t", p->datoN);
        preOrden(p->izquierda);
        preOrden(p->derecha);
    }

}
void inOrden(struct nodo *p){

    if (p!=NULL){
        inOrden(p->izquierda);
        printf("%i\t", p->datoN); 
        inOrden(p->derecha);
    }

}
void postOrden(struct nodo *p){

    if (p!=NULL){
        postOrden(p->izquierda);
        postOrden(p->derecha);
        printf("%i\t", p->datoN); 
    }

}