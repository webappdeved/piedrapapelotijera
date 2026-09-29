#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para contar el número de victorias, derrotas y empates de cada jugador
int victoriasJugador = 0;
int derrotasJugador = 0;
int empatesJugador = 0;

// Función para determinar el resultado de una ronda
int determinarResultado(int eleccionJugador, int eleccionComputadora) {
    int resultado;

    if (eleccionJugador == eleccionComputadora) {
        empatesJugador++;
        resultado = 0;
    } else if ((eleccionJugador == 1 && eleccionComputadora == 3) ||
               (eleccionJugador == 2 && eleccionComputadora == 1) ||
               (eleccionJugador == 3 && eleccionComputadora == 2)) {
        victoriasJugador++;
        resultado = 1;
    } else {
        derrotasJugador++;
        resultado = -1;
    }

    return resultado;
}

// Función para mostrar el número de victorias, derrotas y empates de cada jugador
void mostrarResultado() {
    printf("Victorias jugador: %d\n", victoriasJugador);
    printf("Derrotas jugador: %d\n", derrotasJugador);
    printf("Empates jugador: %d\n", empatesJugador);
}

int main() {
    char opciones[3][10] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario1, eleccionUsuario2;

    // Inicializar el generador de números aleatorios
    srand(time(0));

    // Obtener la elección del primer jugador
    printf("Jugador 1, elige una opción:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    scanf("%d", &eleccionUsuario1);

    // Obtener la elección del segundo jugador
    printf("Jugador 2, elige una opción:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    scanf("%d", &eleccionUsuario2);

    // Determinar el resultado
    int resultado = determinarResultado(eleccionUsuario1, eleccionUsuario2);

    // Mostrar el resultado
    if (resultado == 0) {
        printf("Empate\n");
    } else if (resultado == 1) {
        printf("Jugador 1 gana\n");
    } else {
        printf("Jugador 2 gana\n");
    }

    // Mostrar el número de victorias, derrotas y empates de cada jugador
    mostrarResultado();

    // Pausa antes de finalizar
    system("pause");

    return 0;
}