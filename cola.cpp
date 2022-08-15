// El siguiete codigo explica como hacer una cola pasando los datos por estructura
// Autor: SrAlderson

#include <iostream>

// prototipo de funciones
struct valores insertar(int vector[5], struct valores v , int n);
struct valores eliminar(int vector[5], struct valores v);
void imprimir (int vector[5], struct valores v);
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
                imprimir(vector, v);
                op = 4;
                break;
            case 2: 
                v = eliminar(vector, v);
                imprimir(vector, v);
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
    //
    struct valores a;
    //aplicar valor struc dentro de la funcion
    a.indice = v.indice;
    a.fin = v.fin;
    int dato; 
    //Lectura de dato
    printf("Por favor ingrese un dato: ");
    scanf("%i", &dato);

    // Validaciones

    if (a.indice == -1){
        a.indice = 0; 
        a.fin = 0;
        vector[a.fin] = dato; 


    }else if (a.fin == n-1){

        printf("La cola esta llena, no se puede ingresar dato \n");

    }else{
        a.fin = a.fin + 1; 
        vector[a.fin] = dato; 
        
    }
    
    return a; 
}

struct valores eliminar(int vector[5], struct valores v){
    //
    struct valores a;
    //aplicar valor struc dentro de la funcion
    a.indice = v.indice;
    a.fin = v.fin;
    
    // Validaciones

    if (a.indice == -1 && a.fin == -1){
        printf("La cola esta vacia, no se puede eliminar datos");

    }else if (a.indice == a.fin){
        
        vector[a.indice] = vector[a.indice] - 1; 
        a.indice = -1;
        a.fin = -1;
        

    }else{

        vector[a.indice] = vector[a.indice] - 1; 
        a.indice = a.indice + 1;            
        
    }
    
    return a; 
}

void imprimir (int vector[5], struct valores v){
    int vector2;
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