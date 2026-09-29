#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char opciones[3][10] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario, eleccionComputadora;
    
    // Inicializa el generador de números aleatorios
    srand(time(0)); 
    
    // Obtener la elección del usuario
    printf("Elige una opción:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    scanf("%d", &eleccionUsuario);
    
    // Generar la elección de la computadora
    eleccionComputadora = rand() % 3;
    
    // Mostrar las elecciones
    printf("Tu elección: %s\n", opciones[eleccionUsuario - 1]);
    printf("Elección de la computadora: %s\n", opciones[eleccionComputadora]);
    
    // Determinar el resultado
    if (eleccionUsuario == eleccionComputadora + 1)
        printf("¡Empate!\n");
    else if ((eleccionUsuario == 1 && eleccionComputadora == 1) ||
             (eleccionUsuario == 2 && eleccionComputadora == 2) ||
             (eleccionUsuario == 3 && eleccionComputadora == 3))
        printf("¡Perdiste!\n");
    else
        printf("¡Ganaste!\n");
        
    return 0;
}