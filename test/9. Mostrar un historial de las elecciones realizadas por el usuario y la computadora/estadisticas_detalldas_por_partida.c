#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char opciones[3][10] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario, eleccionComputadora, ronda = 1;
    char historial[10][30]; // Guardar las elecciones
    
    srand(time(0)); // Inicializa el generador de números aleatorios
    
    for (ronda = 1; ronda <= 3; ronda++) { // Jugar 3 rondas
        printf("\nRonda %d - Elige una opción:\n", ronda);
        printf("1. Piedra\n2. Papel\n3. Tijera\n");
        scanf("%d", &eleccionUsuario);
        eleccionComputadora = rand() % 3;
        
        // Guardar la elección en el historial
        sprintf(historial[ronda-1], "Ronda %d: Usuario -> %s, Computadora -> %s", ronda, opciones[eleccionUsuario-1], opciones[eleccionComputadora]);
        
        // Determinar el resultado
        if (eleccionUsuario == eleccionComputadora)
            printf("¡Empate!\n");
        else if ((eleccionUsuario == 1 && eleccionComputadora == 2) ||
                 (eleccionUsuario == 2 && eleccionComputadora == 3) ||
                 (eleccionUsuario == 3 && eleccionComputadora == 1))
            printf("¡Perdiste!\n");
        else
            printf("¡Ganaste!\n");
    }

    // Mostrar el historial
    printf("\nHistorial de las elecciones:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", historial[i]);
    }

    return 0;
}