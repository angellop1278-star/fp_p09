#include <stdio.h>
/*Este programa sirve permite trabajar con un arreglo a traves de un apuntador 
Apuntador es una variable que almacena direccion de memoria del primer elemento
El nombre de un arreglo*/
int main(){
    int array[10];
    int *apuntador;
    apuntador = &array[12]; //Asignando la direccion del primer elemento del array al apuntador 
    //array = &array[0]; (Otra forma de hacerlo)
     for(int i=-12; i<13; ++i){
        printf("Ingresa el valor del elemento %d: ", i);
        //scanf (%d, &array[i]); (Representa la direccion de memoria del elemento i)
        scanf("%d", (apuntador+i));
    }
    printf("[ ");
     for(int i=-12; i<13; ++i){
        printf("%d  (%p),", *(apuntador + i), (apuntador+i)); //Caundo anteponemos un asterisco obtenemos el valor contenido en la direccion de memoria que guarda el apuntador
    }
    printf("]\n");
    return 0;
}