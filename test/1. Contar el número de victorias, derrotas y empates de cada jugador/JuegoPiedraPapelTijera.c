#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para mostrar las tildes
void mostrarTildes()
{
    // Deshabilita la codificación de caracteres por defecto
    setlocale(LC_ALL, "");
}

// Función para contar el número de victorias, derrotas y empates de cada jugador
int victoriasJugador = 0;
int derrotasJugador = 0;
int empatesJugador = 0;

// Función para determinar el resultado de una ronda
int determinarResultado(int eleccionJugador, int eleccionComputadora)
{
    int resultado;

    if (eleccionJugador == eleccionComputadora)
    {
        empatesJugador++;
        resultado = 0;
    }
    else if ((eleccionJugador == 1 && eleccionComputadora == 3) ||
             (eleccionJugador == 2 && eleccionComputadora == 1) ||
             (eleccionJugador == 3 && eleccionComputadora == 2))
    {
        victoriasJugador++;
        resultado = 1;
    }
    else
    {
        derrotasJugador++;
        resultado = -1;
    }

    // Imprimir la elección de la computadora
    switch (eleccionComputadora)
    {
    case 1:
        printf("La elección de la computadora fue: Piedra\n");
        break;
    case 2:
        printf("La elección de la computadora fue: Papel\n");
        break;
    case 3:
        printf("La elección de la computadora fue: Tijera\n");
        break;
    }

    return resultado;
}

// Función para mostrar el número de victorias, derrotas y empates de cada jugador
void mostrarResultado()
{
    printf("Victorias jugador: %d\n", victoriasJugador);
    printf("Derrotas jugador: %d\n", derrotasJugador);
    printf("Empates jugador: %d\n", empatesJugador);
}

int main()
{
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

    // ...

    // Determinar el resultado
    int resultado = determinarResultado(eleccionJugador, eleccionComputadora);

    // ...

    // Mostrar el resultado
    printf("Resultado: %s\n", resultado == 0 ? "Empate" : resultado == 1 ? "Ganaste"
                                                                         : "Perdiste");

    // ...

    // Mostrar el número de victorias, derrotas y empates de cada jugador
    mostrarResultado();

    // Imprimir una leyenda
    printf("Presiona cualquier tecla para salir del juego...\n");

    // Pausar la ejecución del programa
    system("pause");

    return 0;
}