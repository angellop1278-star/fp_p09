#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 15

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include<windows.h>
#else
    #include<termios.h>
    #include<unistd.h>
    #include<fcntl.h>
#endif

int snakeX, snakeY; // posición de la primera parte de la vibora
int fruitX, fruitY;
char direction='d';
int score=0;

int increaseScore(){
    static int score=0; //conservan su valor aunque la funcion haya terminado de ejecutarse
    score++;
    return score;
}
void moveSnake(int *x, int *y, char dir){
    switch(dir){
        case 'w': case 'W': (*y)--; break;
        case 's': case 'S': (*y)++; break;
        case 'a': case 'A': (*x)--; break;
        case 'd': case 'D': (*x)++; break;
    }
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
 #ifdef _WIN32
 char readInput(){
    if(_kbhit())return _getc();
    return direction;
 }
 #else
 char readInput(){
    struct termios oldt,newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt=oldt;
    newt.c_lflag &= ~(ICANON|ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf=fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_GETFL, oldf| O_NONBLOCK);

    ch=getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_GETFL, oldf);

    if(ch!=EOF)return ch;
    return direction;
}//funcion que sirve para no presionar enter para que se mueva
 #endif
/**
 * Función que sirve  para iniciar el juego
 */

void setup(){
    snakeX=WIDTH/2;
    snakeY=HEIGHT/2;

    fruitX = (rand()%(WIDTH-2))+1;
    fruitY = (rand()%(HEIGHT-2))+1;

}

void draw(){
    clearScreen();
    for(int i=0; i<HEIGHT;i++){
        for(int j=0; j<WIDTH; j++){
            if(j==0 || i ==0 || i==HEIGHT-1 || j == WIDTH-1){
                 printf(YELLOW"#");
                 continue;
            }
            if(snakeX==j && snakeY==i){
                printf(GREEN"S");
                continue;
            } 
            if(fruitX==j && fruitY==i){
                printf(RED"ò");
                continue;
            } 
            printf(RESET" ");
        }
        printf("\n");
    }
   printf(RESET"Score %d\n", score);
   // printf("Presiona W o S o D o A\n");
}

void logic(){
    
if(snakeX<=0||snakeX>=WIDTH||snakeY<=0||snakeY>=HEIGHT){
    printf("Game over\n");
    exit(0);
}//esta es toda la funcion
if(snakeX==fruitX && snakeY==fruitY){
    fruitX = (rand()%(WIDTH-2))+1;
    fruitY = (rand()%(HEIGHT-2))+1;
    score=increaseScore();
}
}
int main(){
    setup();
    while(true){
        draw();
        direction=readInput();
        moveSnake(&snakeX, &snakeY, direction);
        logic();
        #ifdef _WIN32
        sleep(150);
        #else
        usleep(150000);
        #endif

    }//main es la llamada a la funcion
    return 0;
}

