/*El objetivo de este codigo es crear una agenda
haciendo el uso de listas doblemente encadanedas con el fin de 
que se puede ordenar por agluno de los criterios del nodo*/

// Autor: Giovanni Gonzalez

/*Parla de que trata el codigo*/

//Librerias
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo)) 

//Prototipo de funciones

void insertar(struct nodo **); 
void buscarCodigo(struct nodo **);
void buscarNombre(struct nodo **);
void eliminarCodigo(struct nodo **);
void imprimir(struct nodo *);

// Estructura

struct nodo {

    struct nodo *anterior;
    int codigo; 
    char nombre[30];
    int telefono;
    char correo[30];
    struct nodo *siguiente;

};

// Codigo

int main (){

    struct nodo *p; // Se crea la lista
    p = NULL; // Se manda la lista vacia en el primer instante
    int op = 1; 

    do { 
        // Variables para el menu

        int opcion; 
        int salida; 
        printf("\nAngenda de contactos");
        printf("\nPor favor seleccione alguna de las siguientes opciones: ");
        printf("\n1.Insertar Contacto\n2.Buscar Contacto por codigo\n3.Buscar Contacto por nombre\n4.Eliminar Contacto por Codgio\n5.Salir\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion){
            case 1:
                // Caso: Agregar contacto 
                insertar(&p);
                op=1;
                break;
            case 2:
                // Caso: Busqueda de contacto por codigo
                buscarCodigo(&p);
                op=1;
                break;
            case 3:
                // Caso: Busqueda de contacto por nombre
                buscarNombre(&p);
                op = 1;
                break;
            case 4:
                eliminarCodigo(&p);
                op = 1;
                break;
            case 5:
                // Caso:  SALIR
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
    } while(op == 1);
    printf("\nSalio de la agenda de contactos\n");
}


// Funciones
void insertar (struct nodo **p){
    
    struct nodo *q; // Se crea una copía de la lista recibida
    
    // Variables para los datos de la lista
    int code;
    char name [30];
    int phone;
    char email [30];

    printf("\nIngrese un codigo para el contacto: ");
    scanf("%i", &code);
    fflush(stdin);
    q = localizar; 
    q -> codigo = code;
    q -> anterior = NULL;
    q -> siguiente = NULL; 
    
    //Validacion de CODIGO en la LISTA
    struct nodo *aux1 = *p;
    // Caso 1: Lista vacia
    if (aux1 == NULL){
        printf ("\nIngrese los demas datos\n");
        printf("Ingrese el nombre del contacto: ");
        fflush(stdin);
        scanf("%[^\n]", &name);
        fflush(stdin);
        printf("Ingrese el telefono del contacto: ");
        scanf("%i", &phone);
        fflush(stdin);
        printf("Ingrese el correo del contacto: ");
        scanf("%[^\n]", &email);
        fflush(stdin);
        // Colocar los valores en la lista
        strcpy(q->nombre, name);
        q -> telefono = phone; 
        strcpy(q->correo, email);
    }else{
        // Recorrido de la lista      
        while (aux1->siguiente !=NULL && aux1->codigo != code){
           aux1 = aux1->siguiente; 
        }
        if (code == aux1->codigo){
            printf("\nEste codigo ya se encuentra registrado.\nIngrese un nuevo codigo.");
        }else{
            printf ("\nIngrese los demas datos\n");
            printf("Ingrese el nombre del contacto: ");
            fflush(stdin);
            scanf("%[^\n]", &name);
            fflush(stdin);
            printf("Ingrese el telefono del contacto: ");
            scanf("%i", &phone);
            fflush(stdin);
            printf("Ingrese el correo del contacto: ");
            scanf("%[^\n]", &email);
            fflush(stdin);
            // Colocar los valores en la lista
            strcpy(q->nombre, name);
            q -> telefono = phone; 
            strcpy(q->correo, email);
        }
    }

    //Validaciones para agregar el contacto
    //Caso 1 -> Lista vacia
    if (*p == NULL){  
        *p = q;
    }else{
        struct nodo *aux = *p;
        // Recorido de la lista
        while (aux -> siguiente != NULL && aux-> codigo < code){
            aux = aux->siguiente;
        }
        // Caso 1: CUANDO SOLO HAY UN ELEMENTO
        if (aux->anterior == NULL && aux->siguiente == NULL){
            if (code > aux -> codigo){
                aux -> siguiente = q; 
                q -> anterior = aux; 
                q -> siguiente = NULL;
            }else{
                aux -> anterior = q; 
                q -> siguiente = aux; 
                q -> anterior = NULL;
                *p = q; // Dejar esto para indicar que el nuevo elemento inicia en Q
            }
        }else if (aux -> siguiente == NULL && code > aux-> codigo){
            // Caso 2: Cuando el CODIGO es el mayor de la lista
            aux -> siguiente = q; 
            q -> anterior = aux; 
            q -> siguiente = NULL;
        }else if (aux -> anterior == NULL && code < aux -> codigo){
            // Caso 3: Cuando el CODIGO es el menor de la lista
            aux -> anterior = q; 
            q -> siguiente = aux; 
            q -> anterior = NULL;
            *p = q; // Dejar esto para indicar que el nuevo elemento inicia en Q
        }else if (aux->anterior != NULL && aux->siguiente != NULL){
            // Caso: 4 Caso General | Adicion del dato en medio de dos nodos
            q -> siguiente = aux; 
            q -> anterior = aux -> anterior;
            aux -> anterior = q; 
            q -> anterior -> siguiente = q;
        } 
    }
    imprimir(*p);
}

void buscarCodigo(struct nodo **p){
    // Creacion de la estructura COPIA y busqueda en la LISTA
    struct nodo *q; 
    q = *p; 
    // Cuando se encuentre vacio
    if (q == NULL){
        printf ("\nAgenda vacia. No hay informacion registrada.\n");
    }else{

        int code;
        // Pregunta por el CODIGO
        printf("\nIngrese el codigo que desea buscar: ");
        scanf("%i", &code);
        // Recorrido de la lista | Se pregunta solo por el q->siguiente == NULL
        while (q -> siguiente != NULL && code != q->codigo){
            q = q->siguiente;
        }
        // Se muestra informacion de CODIGO
        if (code == q->codigo){
            printf("\nEl contacto esta creado.\nEsta es la informacion: \nCodigo: %i \nNombre: %s \nTelefono: %i \nCorreo: %s ", q->codigo, q->nombre, q->telefono, q->correo);
        }else{
            printf("\nEl contacto no esta creado.");
        }
    }
}

void buscarNombre(struct nodo **p){
    // Creacion de la estructura COPIA y busqueda en la LISTA
    struct nodo *q; 
    q = *p; 
    // Cuando se encuentre vacio
    if (q == NULL){
        printf ("\nAgenda vacia. No hay informacion registrada.\n");
    }else{
        char name[30];
        // Pregunta por el NOMBRE
        printf("\nIngrese el nombre que desea buscar: ");
        fflush(stdin);
        scanf("%[^\n]", &name);
        fflush(stdin);
        // Recorrido de la lista | Se pregunta solo por el q->siguiente == NULL
        while (q -> siguiente != NULL && name != q->nombre){
            q = q->siguiente;
        }
        // Se muestra informacion de CODIGO | Comparacion con la funcion strlen()
        if (strlen(name) == strlen(q->nombre)){
            printf("\nEl contacto esta creado.\nEsta es la informacion: \nCodigo: %i \nNombre: %s \nTelefono: %i \nCorreo: %s ", q->codigo, q->nombre, q->telefono, q->correo);
        }else{
            printf("\nEl contacto no esta creado.");
        }
    }
}

void eliminarCodigo(struct nodo **p){

    struct nodo *q; 

    //Caso 1: Cuando la lista esta vacia
    if (*p == NULL){
        printf("No se puede eliminar elementos, la agenda esta vacia\n");
    }else{ 
        //Se crea una copia de P
        q = *p;
        // Caso 2: Ultimo elemento de la lista
        if (q -> siguiente == NULL && q->anterior == NULL){
            printf("Dato eliminado es: %i \n" , q -> codigo);
            delete q; 
            *p = NULL;
        }else{
            int code;
            int flag = 0;
            printf("\nIngrese el codigo que desea eliminar: ");
            scanf("%i", &code);
            fflush(stdin);

            struct nodo *aux; // Variables auxiliar es una copia de P
            aux = *p;
            // Recorrido de la lista
            while (aux->siguiente != NULL && flag == 0) {
                printf("\nentro");
                if (aux->codigo == code){
                    flag = 1;
                }else{
                    aux = aux ->siguiente;
                }
            }
            // Caso 3: Cuando se elimina el primer elemento de la lista 
            if (aux ->anterior == NULL && aux->codigo == code){
                printf("Dato eliminado es: %i \n" , q -> codigo);
                aux = aux -> siguiente;
                q -> siguiente ->anterior = NULL;
                delete q;    
                q = aux;   
                *p = q;         
            }
            // Caso 4: Cuando se elimina el ultimo elemento de la lista 
            if (aux ->siguiente == NULL && aux->codigo == code){
                q = aux;
                printf("Dato eliminado es: %i \n" , q -> codigo);
                aux = aux -> anterior;
                q -> anterior ->siguiente = NULL;
                delete q;  
            }
            //Caso 5: Cuando se elimina un nodo entre dos nodos
            if (aux -> anterior != NULL && aux->siguiente !=NULL){
                if (aux->codigo == code){
                    q = aux; 
                    printf("Dato eliminado es: %i \n" , q -> codigo);
                    aux = aux->anterior;
                    q -> anterior -> siguiente = q ->siguiente;
                    q -> siguiente -> anterior = q ->anterior;
                    delete q;

                }
            }

        }

    }

    imprimir(*p);


}

void imprimir (struct nodo *p){
    printf("\nEstos son sus contactos: \n");
    while(p!=NULL){
        printf("%i , %s, %i, %s \n", p->codigo, p->nombre, p-> telefono, p->correo);
        p = p -> siguiente;
    }
}