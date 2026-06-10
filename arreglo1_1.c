#include <stdio.h>
#include <stdbool.h>
#include <math.h>
float suma(float a, float b){//Parametros
    float c;
    c= a+b;
    return c;
}
float resta(float a, float b){
    return a-b;
}
float mul(float a, float b){
    return a*b;
}
float div(float a, float b){
    if(b==0){
        printf("La division no existe");
        return INFINITY;
    }
    return a/b;
    
}
void menu(){
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Salir\n");
}
int main(){

float x, y, z ;//Argumentos
int op;
while(true){
    menu(); //Lammando a la funcion menu
    printf("Selecciona una opcion: ");
    scanf("%d", &op);
    if(op==5) return 0;
    printf("Ingresa el primer valor: ");
    scanf("%f", &x);
    printf("Ingresa el segundo valor: ");
    scanf("%f", &y);

    switch (op)
    {
    case 1: 
        z=suma(x,y);
        printf("%f+%f=%f\n", x,y,z);
        break;
        case 2:
         z=resta(x,y);
        printf("%f-%f=%f\n", x,y,z);
        break; 
    case 3: 
         z=mul(x,y);
        printf("%f*%f=%f\n", x,y,z);
        break; 
    case 4: 
        z=div(x,y);
        if(z!= INFINITY)
        printf("%f/%f=%f\n", x,y,z);
        break; 
    case 5: 
        return 0;
        default:
        printf("Opcion no valida\n");
    }
}   
}