#include <stdio.h>
/*Este programa sirve para imprimir las direcciones de los elemnetos de un arreglo*/
int main(){
    int array[7];
    float array2[10];

    printf("El tamaño de un entero en bytes es: %d\n", sizeof(int));

    for(int i=0; i<7; ++i){
        printf("La direccion del elemnto %d es %p\n ", i, &array[i]);
    }
    for(int i=0; i<10; ++i){
        printf("La direccion del elemnto %d es %p\n ", i, &array2 [i]);
    }
    return 0;
}