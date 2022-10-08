/*Este es un codigo para trabjar arboles binarios
en este caso se hace la insercion, busqueda y eliminacion de nodos
al igual que cada uno de los recorridos*/

//Autor: Giovanni Gonzalez

//Librerias
#include <stdio.h>
#include <stdlib.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo))

// Prototipo de funciones

void insertarNodo(struct nodo *&, int datoOp);
void buscarElemento(struct nodo*, int datoB);
void eliminarNodo(struct nodo *&, int datoE);
void preOrden (struct nodo *);
void inOrden(struct nodo *);
void postOrden(struct nodo *);

//Estructura nodo

struct nodo{
    struct nodo *derecha;
    int datoN;
    struct nodo *izquierda;
};

//Codigo
int main(){
    // Se crear el nodo para la primera vez
    nodo *arbol = NULL;
    //Para el funcionamiento del do/while
    int op =1; 
    do{
        int opcion; 
        int salida;
        printf("Arboles Binarios\nSelecciones alguna de las siguies opciones:");
        printf("\n1.Insertar nodo\n2.Buscar nodo\n3.Eliminar nodo\n4.Salir\nInserte opcion:");
        scanf("%i", &opcion);
        switch (opcion){
            case 1:
                //Caso INSERTAR
                int datoOp;
                printf("Por favor ingrese un valor: ");
                scanf("%i", &datoOp);
                insertarNodo(arbol, datoOp);
                printf("\nRecorrido en preOrden: ");
                preOrden(arbol);
                printf("\nRecorrido en inOrden: ");
                inOrden(arbol);
                printf("\nRecorrido en postOrden: ");
                postOrden(arbol);
                printf("\n");
                op = 1; 
            break;
            case 2: 
                //Caso BUSCAR
                int datoB; 
                printf("Por favor ingresar el valor a buscar: ");
                scanf("%i", &datoB);
                buscarElemento(arbol, datoB);
                op = 1; 
            break;
            case 3: 
                //Caso ELIMINAR
                int datoE; 
                printf("Por favor ingresar el valor a eliminar: ");
                scanf("%i", &datoE);
                eliminarNodo(arbol, datoE);
                printf("\nRecorrido en preOrden: ");
                preOrden(arbol);
                printf("\nRecorrido en inOrden: ");
                inOrden(arbol);
                printf("\nRecorrido en postOrden: ");
                postOrden(arbol);
                printf("\n");
                op = 1; 
            break;
            case 4:
                //Caso SALIR 
                printf("Usted realmente quiere salir del programa \n");
                printf("1.Si\n2.No\nopcion: ");
                scanf("%d", &salida);
                if (salida == 1){
                    op = 0;
                }else{ 
                    op = 1;
                }
            break;
            default:
                printf("\nUsted ha ingresado una opcion incorrecta. Por favor ingrese de nuevo la opcion");
            break;
        }
    }while(op==1);
}
//Funciones

void insertarNodo(struct nodo *&arbol, int datoOp){
    //Estructura del nuevo nodo
    // Se pregunta si el arbol esta vacio
    if(arbol != NULL){
        if(datoOp < arbol->datoN){
            insertarNodo(arbol->izquierda, datoOp);
        }else{
            if (datoOp > arbol->datoN){
                insertarNodo(arbol->derecha, datoOp);
            }else{
                printf("Dato repetido por favor ingresar otro numero\n");
            }
        }
    }else{
        //Para insertar un nuevo NODO
        struct nodo *nuevoNodo; 
        nuevoNodo = localizar;
        nuevoNodo->izquierda = NULL;
        nuevoNodo->derecha = NULL;
        nuevoNodo->datoN = datoOp;
        arbol = nuevoNodo;
    }
    //LLamado a cada uno de los RECORRIDOS para visualizacon
    
}
void buscarElemento (struct nodo *arbol, int datoB){
    //Se pregunta si el arbol esta vacio
    if (arbol==NULL){
        printf("Arbol esta vacio o el dato no existe\n");
    }else{
        if (datoB == arbol->datoN){
            printf("El dato se ha encontrado.\nValor encontrado: %i \n", arbol->datoN);
        }else{
            //Movimiento por la IZQUIERDA
            if (datoB < arbol->datoN){
                buscarElemento(arbol->izquierda, datoB);
            }else{
                //Movimiento por la DERECHA
                buscarElemento(arbol->derecha, datoB);
            }
        }
    }
}
void eliminarNodo(struct nodo *&arbol, int datoE){
    //Se pregunta si el arbol esta vacio
    if (arbol != NULL){
        //Se pregunta por el recorrido a IZQUIERDA
        if (datoE < arbol->datoN){
            eliminarNodo(arbol->izquierda, datoE);
        }else{
            //Se pregunta por el recorrido a DERECHa
            if(datoE > arbol->datoN){
                eliminarNodo(arbol->derecha, datoE);
            }else{
                //Dato eliminar = Dato arbol
                int datoEliminado = arbol->datoN;
                //Se crea copia del nodo evaluado
                struct nodo *nodo;
                nodo = arbol; 
                // Verificacion si hay NODOS por la DERECHA
                
                if(nodo->derecha == NULL){
                    arbol = nodo->izquierda;
                }else{
                    // Verificacion si hay NODOS por la IZQUIERDA
                    if(nodo->izquierda == NULL){
                        arbol = nodo->derecha;
                    }else{
                        printf("tuki3\n");
                        //Cuando el NODO tiene dos SUBARBOLES
                        struct nodo *aux = arbol->izquierda;
                        struct nodo *aux1; 
                        bool bandera = false;
                        while (aux->derecha != NULL){
                            aux1 = aux;
                            aux = aux->derecha;
                            bandera = true;
                        }
                        arbol->datoN = aux->datoN;
                        nodo = aux;
                        if (bandera == true){
                            aux1->derecha = aux->izquierda;
                        }else{
                            arbol->izquierda = aux->izquierda;
                        }
                    }
                }
                printf("\nDato eliminado: %i", datoEliminado);
                delete nodo;
            }
        }
    }else{
        printf("El arbol no tiene elementos para eliminar o el elemento no esta dentro del arbol.\n");
    }
}
void preOrden (struct nodo *arbol){   
    if (arbol!=NULL){
        printf("%i\t",arbol->datoN);
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}
void inOrden(struct nodo *arbol){
    if (arbol!=NULL){
        inOrden(arbol->izquierda);
        printf("%i\t",arbol->datoN);
        inOrden(arbol->derecha);
    }
}
void postOrden(struct nodo *arbol){
    if (arbol!=NULL){
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        printf("%i\t",arbol->datoN); 
    }
}