#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char **argv){

    if(SDL_Init(SDL_INIT_VIDEO)==0)
    {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    bool running = true;
    SDL_Event *event;

    SDL_Window *window = SDL_CreateWindow("Hola Mundo", //Titulo de la ventana
        SDL_WINDOWPOS_CENTERED, //Posicion de la ventana en X
        SDL_WINDOWPOS_CENTERED, //Posicion de la ventana en y
        800, //El ancho de la ventana
        600, //Alto de la ventana
        0
    );
    if(window = NULL);
    {
    printf("Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
    }
    SDL_RaiseWindow(window); //Envia la ventana al frente)
    while(running)
    {
            while(SDL_PollEvent(&event))
            {
            if(event.type == SDL_QUIT){
                running = false;
            } else if(event.type == SDL_KEYDOWN){
                if(event.key.keysym == SDLK_x)
                running == false;
            }               
            }
    }
    //SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();
}