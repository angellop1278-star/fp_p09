#include<stdio.h>
#define RED "\033[31m"

int main(int argc, char **argv){
    FILE *archivo;
    char linea[256]; //linea contiene hasta 256 caracteres
    
    if(argc<2){
        printf(RED"Error Fatal: hacen falta argumentos\n");
        return 1;
    }
    
    archivo= fopen(argv[1], "a"); //argv es un arreglo de cadenas, argc numero de cadenas almacenadas en argv

        if(archivo!=NULL){
            printf("El archivo se abrio correctamente\n");
            char cosa[]="play5";
            float precio= 12000.00;
            //while(feof(archivo)==0){//feof retorna un 0 cuando no ha encontrado el fin de archivo 
            fprintf(archivo, "\n%s\t%f", cosa, precio);
                //printf("%s\t%.2f", cosa, precio);
                //}
            int res=fclose(archivo);
            printf("fclose=%d\n",res);
        }else{
            printf(RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
        }
        return 0;
    }