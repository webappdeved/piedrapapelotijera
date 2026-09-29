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

int cargarPuntuacion() {
    // Declaración de la variable archivo en el alcance de la función
    FILE *archivo;

    // Abrir el archivo
    archiv = fopen("puntuacion.txt", "rb");

    // Comprobar si el archivo existe
    if (archiv == NULL) {
        // El archivo no existe, establecer la puntuación en 0
        return 0;
    }

    // Leer la puntuación del archivo
    int puntuacion;
    fread(&puntuacion, sizeof(puntuacion), 1, archivo);

    // Cerrar el archivo
    fclose(archivo);

    // Devolver la puntuación
    return puntuacion;
}

int main()
{
    mostrarTildes();

    // Declarar las variables eleccionJugador, eleccionComputadora, respuesta y puntuacion
    int eleccionJugador;
    int eleccionComputadora;
    char respuesta;
    int puntuacion;

    // Preguntar al usuario si quiere cargar la puntuación
    printf("¿Quieres cargar tu puntuación? (s/n)\n");
    scanf(" %c", &respuesta);

    // Cargar la puntuación si el usuario responde "s"
    if (respuesta == 's')
    {
        puntuacion = cargarPuntuacion();
    }

    // ...

    // ...

    // Pausar la ejecución del código
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}