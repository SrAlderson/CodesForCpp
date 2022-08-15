/*Codigo base de un menu, en donde se confirma la salida del programa*/

/*Author: SrAlderson*/

#include <iostream>

int main (){
    
    int op; // inicia el menu 
    
    do{
        // Pregunta por la accion que quiera realizar
        int opcion1; // para validacion de la salida
        int opcion; // para seleccion del menu 
        
        printf ("Por favor seleccione alguna opcion \n");
        printf ("1.Insertar\n2.Eliminar\n3.Salir\nopcion: "); 
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                // Funcion 1
                op = 4;
                break;
            case 2: 
                //Funcion 2
                op = 4;
                break;
            case 3:
                // Validacion de la salida
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
                // Caso para que solo acepte el menu propuesto
                printf ("Opcion invaldia, ingrese otra opcion de nuevo");
                break;
        }

    } while (op == 4); // Menu queda corriende hasta que se valide la confirmacion de fin del programa

    printf ("Usted ha salido del programa\n");   

    return 0;
}