#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para mostrar las tildes
void mostrarTildes() {
    // Deshabilita la codificación de caracteres por defecto
    setlocale(LC_ALL, "");
}

// Función para determinar el resultado de una ronda
int determinarResultado(int eleccionJugador, int eleccionComputadora) {
    int resultado;

    if (eleccionJugador == eleccionComputadora) {
        resultado = 0;
    } else if ((eleccionJugador == 1 && eleccionComputadora == 3) ||
               (eleccionJugador == 2 && eleccionComputadora == 1) ||
               (eleccionJugador == 3 && eleccionComputadora == 2)) {
        resultado = 1;
    } else {
        resultado = -1;
    }

    return resultado;
}

int main() {
    mostrarTildes();

    // Declarar las variables eleccionJugador y eleccionComputadora
    int eleccionJugador;
    int eleccionComputadora;

    // ...

    // Obtener la elección del jugador
    printf("Elige una opción:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    scanf("%d", &eleccionJugador);

    // Generar la elección de la computadora
    eleccionComputadora = rand() % 3;

    // Determinar el resultado
    int resultado = determinarResultado(eleccionJugador, eleccionComputadora);

    // Mostrar el resultado
    printf("Resultado: %s\n", resultado == 0 ? "Empate" : resultado == 1 ? "Ganaste" : "Perdiste");

    // Agregar una imagen
    if (resultado == 1) {
        // Jugador gana
        // Usar la función system() para abrir la imagen
        system("start trofeo.png");
    }

    // Pausar la ejecución del programa
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}