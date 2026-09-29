#include <stdio.h>

int main() {
    char nombreJugador[30];
    
    // Solicitar el nombre del jugador
    printf("Por favor, introduce tu nombre: ");
    scanf("%s", nombreJugador);
    
    // Mostrar el nombre ingresado
    printf("Bienvenido, %s, al juego de Piedra, Papel o Tijera!\n", nombreJugador);

    // Aquí puede seguir el código del juego como el que ya tienen de base
    return 0;
}