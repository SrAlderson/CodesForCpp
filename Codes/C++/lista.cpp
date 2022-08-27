// El siguiete codigo explica como hacer una LISTA en donde los datos son ingresados por derecha
// Autor: Giovanni Gonzalez

#include <stdlib.h>
#include <stdio.h>
#define localizar (struct nodo *)malloc(sizeof(struct nodo))

// Prototipo de funciones
void insertar(struct nodo *&, int );
void imprimir(struct nodo *);

// Estructura del nodo
struct nodo{

	int dato ;
	struct nodo *siguiente;

};

int main(){
    // Declaracion de la estructura
    struct nodo *lista = NULL; // LISTA en un principio apunta vacia
    int n;     
    // Inicia el menu
    int op; 
    // Pregunta por la accion que quiera realizar

    do{
        int opcion1; // para validacion de la salida
        int opcion; // para seleccion del menu 
        
        printf ("\nPor favor seleccione alguna opcion\n");
        printf ("1.Insertar\n2.Imprimir\n3.Salir\nopcion: "); 
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("ingrese un valor: ");
                scanf("%i", &n);
	            insertar(lista, n);
                op = 4;
                break;
            case 2: 
                imprimir(lista); 
                op = 4;
                break;
            case 3:
                printf("Usted realmente quiere salir del programa \n");
                printf("1.Si\n2.No\nopcion: ");
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

    printf ("Usted ha salido del programa\n"); // Mensaje de verificacion   

    return 0;

}

void insertar (struct nodo *&lista , int n){

    // Se envia la lista por REFERENCIA y n se envia por VALOR

    // Creacion del nodo 
    struct nodo * nuevo; // Para cada vez que se necesite un nuevo nodo
    struct nodo * auxiliar = lista; // AUXILIAR con el fin de poder ir agregando nuevos nodos

    nuevo = localizar; // Se separa el espacio de memoria
    nuevo -> dato = n;  // El N recibido se guarda en DATO del nodo

    // Caso 1: Lista vacia    
    if (lista == auxiliar){
        lista = nuevo;
    }   
   
    nuevo -> siguiente = auxiliar; // AUXILIAR apuntaria al inicio de la LISTA

}

void imprimir (struct nodo *lista){

    // Creacion del nodo
    struct nodo *posicion; 
    posicion = lista; // POSICION para ir recorriendo cada uno de los nodos de la lista

    while (posicion != NULL){
        printf("%i", posicion->dato); // Imprime datos de los nodos
        posicion = posicion ->siguiente; // Salta al siguiente nodo
    } 
}