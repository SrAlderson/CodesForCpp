/* El obejtivo del codigo es realizar la multipicacion de matices 
para este caso la matriz de mayores dimensiones que acepta es una de Nx4
dado a que se debe dejar un espacio fijo de memoria reservado
*/

// Autor SrAlderson

// Librerias

# include <iostream>

// Prototipo de funciones

void validacion (int filas1, int filas2, int columnas1, int columnas2 );
void imprimirMatrices(int matrizA[][4], int matrizB[][4],int filas1, int filas2, int columnas1, int columnas2);
void imprimirResultado(int matrizC[][4], int filas1, int columnas2);
void multiplicar (int matrizA[][4], int matrizB[][4], int filas1 , int columnas1, int columnas2); 

// Codigo

int main (){

    int filasM1;
    int filasM2;
    int columnasM1;
    int columnasM2;

    int op; 

    do {

        int opcion; 
        int opcion1;

        printf("Por favor escoja una de las siguientes opciones: \n");
        printf("1.Multiplicar\n2.Salir\nOpcion: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:

                printf ("\nDigitar la siguiente informacion\n"); 
                printf("ingresar numero de filas para la matriz A: ");
                scanf("%i", &filasM1);
                printf("ingresar numero de columnas para la matriz A: ");
                scanf("%i", &columnasM1);
                printf("ingresar numero de filas para la matriz B: ");
                scanf("%i", &filasM2);
                printf("ingresar numero de columnas para la matriz B: ");
                scanf("%i", &columnasM2);
                validacion (filasM1, filasM2, columnasM1, columnasM2);
                op = 0;
                break;
                 
            case 2: 

                printf("Realmente quiere salir del programa\n");
                printf("1.Si\n2.No\nOpcion: ");
                scanf("%i", &opcion1);
                if (opcion1 == 1){
                    op = 1; 
                }else{
                    op = 0;
                }
                break;

            default:
                printf("Usted ha seleccionado una opcion invalida\n");
                break;
        }

    } while (op==0);
    printf("Fin del programa\n");
}

void validacion (int filas1, int filas2, int columnas1, int columnas2 ){

// Funcion valida si se puede o no hacer la multiplicacion de matrices

    if (columnas1 == filas2 ){

        // Se procede a ingresar los datos

        // Para la matriz A 
        int matrizA [filas1][4];
        int matrizB [filas2][4];
        int flag = 0; 
        printf("Datos de la matriz A\n");
        // Recorre las filas
        for (int i = 0; i < filas1; i++){
            // Recorre las columnas
            for (int j = 0; j < columnas1; j++){
                printf("Ingrese el dato para la posicion [%i][%i]: ", i, j);
                scanf("%i", &matrizA[i][j]);
            }
        }
        // Para la matriz B
        printf("Datos de la matriz B\n");
        // Recorre las filas
        for (int i = 0; i < filas2; i++){
            // Recorre las columnas
            for (int j = 0; j < columnas2; j++){

                printf("Ingrese el dato para la posicion [%i][%i]: ", i, j);
                scanf("%i", &matrizB[i][j]);
            }
        } 
        // Imprime matrices 
        imprimirMatrices(matrizA, matrizB, filas1, filas2, columnas1, columnas2);
        // Envia datos a multiplicar
        multiplicar(matrizA, matrizB, filas1, columnas1, columnas2);

    } else {

        printf("No se puede hacer la operacion\n");
        printf("columnasM1 =! filasM2");

    }

}

void multiplicar (int matrizA[][4], int matrizB[][4], int filas1 , int columnas1, int columnas2){

    // Recorre la matriz resultante

    int matrizC [filas1][4]; 

    // Se llena la matriz C primero con 0 para garantizar que no quede con valores aleatorios para no afectar el resultado
    //Recorre filas
    for (int i=0 ; i< filas1; i++){
        //Recorre columnas
        for (int j=0; j< columnas2; j++){
            matrizC[i][j] = 0; 
        }
    }

    //Recorre filas
    for (int i=0 ; i< filas1; i++){
        //Recorre columnas
        for (int j=0; j< columnas2; j++){
            //Recorre columnas de A
            for (int k = 0; k<columnas1; k++){
                matrizC[i][j] = matrizC[i][j] + matrizA[i][k] * matrizB[k][j]; 
            }
        }
    }

    // Imprime resultado
    imprimirResultado(matrizC, filas1, columnas2);
    
}

void imprimirMatrices(int matrizA[][4], int matrizB[][4],int filas1, int filas2, int columnas1, int columnas2){
        
    // Imprime matrices ingresadas
    printf("Datos de la matriz A\n");
    // Recorre las filas
    for (int i = 0; i < filas1; i++){
        // Recorre las columnas
        for (int j = 0; j < columnas1; j++){
            printf("%i \t", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("Datos de la matriz B\n");
    // Recorre las filas
    for (int i = 0; i < filas2; i++){
        // Recorre las columnas
        for (int j = 0; j < columnas2; j++){
            printf("%i \t", matrizB[i][j]);
        }
        printf("\n");
    }
}

void imprimirResultado(int matrizC[][4], int filas1, int columnas2){

    printf("Datos de la matriz C\n");
    printf("El resultado de multiplicar AxB es: \n");
    // Recorre las filas
    for (int i = 0; i < filas1; i++){
        // Recorre las columnas
        for (int j = 0; j < columnas2; j++){
            printf("%i \t", matrizC[i][j]);
        }
        printf("\n");
    }

}