#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char opciones[3][10] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario, eleccionComputadora, dificultad;
    
    srand(time(0)); // Inicializa el generador de números aleatorios

    // Elegir la dificultad
    printf("Elige el nivel de dificultad:\n");
    printf("1. Fácil (50%% de ganar)\n");
    printf("2. Medio (33%% de ganar)\n");
    printf("3. Difícil (25%% de ganar)\n");
    scanf("%d", &dificultad);
    
    // Obtener la elección del usuario
    printf("Elige una opción:\n1. Piedra\n2. Papel\n3. Tijera\n");
    scanf("%d", &eleccionUsuario);
    
    // Generar la elección de la computadora según la dificultad
    if (dificultad == 1) { // Fácil: 50% de ganar
        eleccionComputadora = (rand() % 2 == 0) ? (eleccionUsuario % 3) : (rand() % 3); 
    } else if (dificultad == 2) { // Medio: 33% de ganar
        eleccionComputadora = rand() % 3;
    } else { // Difícil: 25% de ganar (la computadora intenta ganar más seguido)
        eleccionComputadora = (rand() % 4 == 0) ? ((eleccionUsuario % 3) + 1) % 3 : rand() % 3;
    }
    
    // Mostrar las elecciones
    printf("Tu elección: %s\n", opciones[eleccionUsuario - 1]);
    printf("Elección de la computadora: %s\n", opciones[eleccionComputadora]);
    
    // Determinar el resultado
    if (eleccionUsuario == eleccionComputadora)
        printf("¡Empate!\n");
    else if ((eleccionUsuario == 1 && eleccionComputadora == 2) ||
             (eleccionUsuario == 2 && eleccionComputadora == 3) ||
             (eleccionUsuario == 3 && eleccionComputadora == 1))
        printf("¡Perdiste!\n");
    else
        printf("¡Ganaste!\n");
    
    return 0;
}