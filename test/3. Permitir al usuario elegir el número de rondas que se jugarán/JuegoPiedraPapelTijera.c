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

    // ...

    // Eliminar la funcionalidad de permitir al usuario elegir entre jugar contra la computadora o contra otro jugador
    // ...

    // Obtener la elección del número de rondas
    printf("¿Cuántas rondas quieres jugar?\n");
    int numeroRondas;
    scanf("%d", &numeroRondas);

    // ...

    // Procesar la elección del número de rondas
    for (int i = 0; i < numeroRondas; i++)
    {
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

    // Pausar la ejecución del programa
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}