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

// Función para determinar el resultado de una ronda
int determinarResultado(int eleccionJugador, int eleccionComputadora)
{
    int resultado;

    if (eleccionJugador == eleccionComputadora)
    {
        resultado = 0;
    }
    else if ((eleccionJugador == 1 && eleccionComputadora == 3) ||
             (eleccionJugador == 2 && eleccionComputadora == 1) ||
             (eleccionJugador == 3 && eleccionComputadora == 2))
    {
        resultado = 1;
    }
    else
    {
        resultado = -1;
    }

    return resultado;
}

int main()
{
    mostrarTildes();

    // Declarar las variables eleccionJugador y eleccionComputadora
    int eleccionJugador;
    int eleccionComputadora;

    // Declarar la variable modoJuego
    int modoJuego;

    // ...

    // Obtener la elección del modo de juego
    printf("Elige un modo de juego:\n");
    printf("1. Contra la computadora\n");
    printf("2. Contra otro jugador\n");
    scanf("%d", &modoJuego);

    // ...

    // Procesar la elección del modo de juego
    if (modoJuego == 1)
    {
        // Jugar contra la computadora

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
        printf("Resultado: %s\n", resultado == 0 ? "Empate" : resultado == 1 ? "Ganaste"
                                                                             : "Perdiste");
    }
    else if (modoJuego == 2)
    {
        // Jugar contra otro jugador

        // Obtener la elección del jugador 1
        printf("Jugador 1, elige una opción:\n");
        printf("1. Piedra\n");
        printf("2. Papel\n");
        printf("3. Tijera\n");
        int eleccionJugador1;
        scanf("%d", &eleccionJugador1);

        // Obtener la elección del jugador 2
        printf("Jugador 2, elige una opción:\n");
        printf("1. Piedra\n");
        printf("2. Papel\n");
        printf("3. Tijera\n");
        int eleccionJugador2;
        scanf("%d", &eleccionJugador2);

        // Determinar el resultado
        int resultado = determinarResultado(eleccionJugador1, eleccionJugador2);

        // Mostrar el resultado
        printf("Resultado: %s\n", resultado == 0 ? "Empate" : resultado == 1 ? "Gana el jugador 1"
                                                                             : "Gana el jugador 2");
    }
    else
    {
        // Modo de juego no válido
        printf("Modo de juego no válido.\n");
    }

    // Pausar la ejecución del programa
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}