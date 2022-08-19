// El siguiete codigo explica como hacer una cola pasando los datos por estructura
// Autor: SrAlderson

#include <iostream>
// prototipo de funciones
struct valores insertar(int vector[5], struct valores v , int n);
struct valores eliminar(int vector[5], struct valores v, int n);
void imprimir (int vector[5], struct valores v, int n);
// Estructura

struct valores
{
    int indice; 
    int fin;
};


int main (){

    //Declaracion de la estructura
    struct valores v;
    //Declaracion de variables
    int vector[5];
    int n = 5; // Tamaño del vector
    v.indice = -1; // Valor inicial del indice
    v.fin = -1; // Valor inicial del fin
    // inicia el menu
    int op; 
    // Pregunta por la accion que quiera realizar

    do{
        int opcion1; // para validacion de la salida
        int opcion; // para seleccion del menu 
        
        printf ("\nPor favor seleccione alguna opcion\n");
        printf ("1.Insertar\n2.Eliminar\n3.Salir\nopcion: "); 
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                v = insertar(vector, v, n);
                op = 4;
                break;
            case 2: 
                imprimir(vector, v, n);
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

//Funciones
struct valores insertar(int vector[5], struct valores v, int n){
    //Declaracion de la estructura interna
    struct valores a;
    //aplicar valor struc dentro de la funcion
    a.indice = v.indice;
    a.fin = v.fin;
    int dato; 
    //Lectura de dato
    printf("Por favor ingrese un dato: ");
    scanf("%i", &dato);

    // Validaciones
    // Caso 1: Cuando la cola esta vacia
    if (a.fin == -1){
        
        a.indice = 0; 
        a.fin = 0;
        vector[a.fin] = dato; 

    //Caso 2: Cuando la cola esta llena
    }else if ((a.fin+1)%n == a.indice){

        printf("La cola esta llena, no se puede ingresar dato \n");

    }else{
    // Caso 3: General 
        a.fin = (a.fin+1) % n; // Esto encaso de que fin sea 4  y halla espacion en la posicion 0 del vector 
        vector[a.fin] = dato; 
        
    }
    
    return a; 
}

struct valores eliminar(int vector[5], struct valores v, int n){
    //Declaracion de la estructura interna
    struct valores a;
    //aplicar valor struc dentro de la funcion
    a.indice = v.indice;
    a.fin = v.fin;
    
    // Validaciones
    // Caso 1:
    if (a.fin == -1){
        printf("La cola esta vacia, no se puede eliminar datos");

    }else if (a.indice == a.fin){
        // Esto de aqui para cuando solo haya un dato en la cola 
        a.indice = -1;
        a.fin = -1;
    }else{
        // Caso General, eliminacion de dato
        a.indice = a.indice + 1;            
        
    }

    return a; 
}

void imprimir (int vector[5], struct valores v, int n){
    
    if(v.indice == -1 && v.fin ==-1){
        printf("La cola esta vacia, por favor ingresar un dato. \n");
        //Muestra vector vacio
        printf ("\ndatos: ");
        printf ("\np-vec: ");
        for (int k =0; k <= 4; k++){
            printf("%i ", k);
        }
    }else{
        // Imprime el valor del vector
        printf ("\ndatos: ");
        for (int j = v.indice; j<=v.fin; j++){
            printf("%i ", vector[j]);
        }
        // Imprime la posicion del vector
        printf ("\np-vec: ");
        for (int k =v.indice; k <=v.fin; k++){
            printf("%i ", k);
        }
    }

}