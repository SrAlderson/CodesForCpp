// El siguiete codigo explica como hacer una cola pasando los datos por estructura
// Autor: SrAlderson

#include <iostream>

// prototipo de funciones

int main (){
    
    int op; // inicia el menu
  
    // Pregunta por la accion que quiera realizar
    do{
        int opcion1; // para validacion de la salida
        int opcion; // para seleccion del menu 
        
        printf ("Por favor seleccione alguna opcion \n");
        printf ("1.Insertar\n2.Eliminar\n3.Salir\nopcion: "); 
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                //Funcion insertar
                op = 4;
                break;
            case 2: 
                //Fucnion eliminar
                op = 4;
                break;
            case 3:
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
                printf ("Opcion invaldia, ingrese otra opcion de nuevo");
                break;
        }

    } while (op == 4); // Menu queda corriende hasta que se valide la confirmacion de fin del programa

    printf ("Usted ha salido del programa\n");   

    return 0;
}
//Funciones