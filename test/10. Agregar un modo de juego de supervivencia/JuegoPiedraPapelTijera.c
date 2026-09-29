#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de la variable archivo en el alcance global
FILE *archiv;

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

// Función para agregar un modo de juego de supervivencia
void agregarModoSupervivencia()
{
    // Declarar las variables eleccionJugador, eleccionComputadora, respuesta y puntuacion
    int eleccionJugador;
    int eleccionComputadora;
    char respuesta;
    int puntuacion = 0;

    // Imprimir un mensaje de bienvenida
    printf("Bienvenido al modo de juego de supervivencia\n");

    // Bucle principal del juego
    while (1)
    {
        // Obtener la elección del jugador
        printf("Elige tu jugada: 1 (piedra), 2 (papel) o 3 (tijeras)\n");
        scanf(" %d", &eleccionJugador);

        // Obtener la elección de la computadora
        eleccionComputadora = rand() % 3 + 1;

        // Determinar el resultado de la ronda
        int resultado = determinarResultado(eleccionJugador, eleccionComputadora);

        // Imprimir el resultado de la ronda
        if (resultado == 0)
        {
            printf("Empate!\n");
        }
        else if (resultado == 1)
        {
            printf("Ganaste!\n");
            puntuacion++;
        }
        else
        {
            printf("Perdiste!\n");
        }

        // Preguntar al usuario si quiere continuar
        printf("¿Quieres continuar? (s/n)\n");
        scanf(" %c", &respuesta);

        // Si el usuario no quiere continuar, terminar el juego
        if (respuesta == 'n')
        {
            break;
        }
    }

    // Imprimir la puntuación final
    printf("Tu puntuación final es %d\n", puntuacion);
}

int main()
{
    mostrarTildes();

    // Agregar el modo de juego de supervivencia
    agregarModoSupervivencia();

    // Pausar la ejecución del código
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}