#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char opciones[5][10] = {"Piedra", "Papel", "Tijera", "Lagarto", "Spock"};
    int eleccionUsuario, eleccionComputadora;

    srand(time(0));
    
    // Obtener la elección del usuario
    printf("Elige una opción:\n1. Piedra\n2. Papel\n3. Tijera\n4. Lagarto\n5. Spock\n");
    scanf("%d", &eleccionUsuario);
    
    // Generar la elección de la computadora
    eleccionComputadora = rand() % 5;
    
    // Mostrar las elecciones
    printf("Tu elección: %s\n", opciones[eleccionUsuario - 1]);
    printf("Elección de la computadora: %s\n", opciones[eleccionComputadora]);
    
    // Determinar el resultado
    if (eleccionUsuario == eleccionComputadora)
        printf("¡Empate!\n");
    else if ((eleccionUsuario == 1 && (eleccionComputadora == 3 || eleccionComputadora == 4)) ||  // Piedra vence a Tijera o Lagarto
             (eleccionUsuario == 2 && (eleccionComputadora == 1 || eleccionComputadora == 5)) ||  // Papel vence a Piedra o Spock
             (eleccionUsuario == 3 && (eleccionComputadora == 2 || eleccionComputadora == 4)) ||  // Tijera vence a Papel o Lagarto
             (eleccionUsuario == 4 && (eleccionComputadora == 2 || eleccionComputadora == 5)) ||  // Lagarto vence a Papel o Spock
             (eleccionUsuario == 5 && (eleccionComputadora == 1 || eleccionComputadora == 3)))    // Spock vence a Piedra o Tijera
        printf("¡Ganaste!\n");
    else
        printf("¡Perdiste!\n");

    return 0;
}