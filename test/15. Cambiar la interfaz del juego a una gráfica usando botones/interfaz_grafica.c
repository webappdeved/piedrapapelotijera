#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error inicializando SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* ventana = SDL_CreateWindow("Piedra, Papel o Tijera",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    
    if (ventana == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Event evento;
    int corriendo = 1;

    // Bucle principal
    while (corriendo) {
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                corriendo = 0;
            }
            // Aquí podrías capturar eventos de clic en botones para seleccionar piedra, papel o tijera
        }
    }

    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}