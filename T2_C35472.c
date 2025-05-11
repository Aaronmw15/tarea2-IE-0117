#include <stdio.h>
//librerias para tener aleatoriedad
#include <stdlib.h>
#include <time.h>
void bubble_short(int arreglo[], int tamano){
    for (int i = 0; i < tamano - 1; i++) {// Recorremos el arreglo 
        // En cada pasada, compara elementos adyacentes
        for (int j = 0; j < tamano - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, se intercambian
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];      // Guarda temporalmente el valor de arr[j]
                arreglo[j] = arreglo[j + 1];    // Mueve el valor de arr[j + 1] a arr[j]
                arreglo[j + 1] = temp;      // Asigna el valor temporal a arr[j + 1]
            }
        }
    }

}

void selection_sort(int arreglo[], int tamano) {
    for (int i = 0; i < tamano - 1; i++) {
        int indice_minimo = i; // Asumimos que el mínimo está en la posición actual

        // Buscamos el índice del valor mínimo en el resto del arreglo
        for (int j = i + 1; j < tamano; j++) {
            if (arreglo[j] < arreglo[indice_minimo]) {
                indice_minimo = j;
            }
        }

        // Si encontramos un valor menor, lo intercambiamos con el actual
        if (indice_minimo != i) {
            int temp = arreglo[i];
            arreglo[i] = arreglo[indice_minimo];
            arreglo[indice_minimo] = temp;
        }
    }
}


int main(){
    //pedir tamaño
    int tamano;
    printf("Ingrese un tamaño para el arreglo: ");
    scanf(" %d", &tamano);

    //crear el arreglo
    int arreglo[tamano];//se crea el arreglo
    srand(time(NULL)); //inicializamos la semilla para el random

    for (int i = 0; i < tamano; i++) {//recorremos el arreglo y por cada casilla agregamos un numero al azar entre 0 y 99
        arreglo[i] = rand() % 100;
    }

    /*printf("Arreglo:\n[ ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]);
    }*/
    printf("]\n");
//implementamos alguno de los algoritmos.
    int eleccion=0;
    printf("Escriba [1] para BubbleShort y [2] para SelectionShort: ");
    scanf("%i", &eleccion);

    clock_t inicio=clock();//esta es una marca de tiempo para medir el rendimiento
    switch (eleccion){
    case 1:
        bubble_short(arreglo, tamano);
        break;
    case 2:
        selection_sort(arreglo, tamano);
        break;
    default:
        printf("Error: seleccion inválida\n");
        return 1;
    }
    clock_t fin=clock();//esta es una marca de tiempo para compararla con la primera, y ver cuanto tiempo tarda cada algoritmo

    double tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;//calculamos el rendimiento
   
    //imprimimos el resultado
    /*printf("Arreglo ordenado:\n[ ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]);
    }*/
    printf("]\n");
    printf("Tiempo de ejecución: %.6f segundos\n", tiempo_ejecucion); //imprimimos el tiempo
    return 0;
}