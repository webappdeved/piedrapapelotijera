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

// Función para guardar la puntuación en un archivo
void guardarPuntuacion(int puntuacion) {
    // Abrir el archivo en modo escritura
    FILE *archivo = fopen("puntuacion.txt", "w");

    // Escribir la puntuación en el archivo
    fprintf(archivo, "%d\n", puntuacion);

    // Cerrar el archivo
    fclose(archivo);
}

// Función para cargar la puntuación desde un archivo
int cargarPuntuacion() {
    // Declarar una variable para almacenar la puntuación
    int puntuacion = 0;

    // Abrir el archivo en modo lectura
    FILE *archivo = fopen("puntuacion.txt", "r");

    // Comprobar si el archivo se abrió correctamente
    if (archivo != NULL) {
        // Leer la puntuación desde el archivo
        fscanf(archivo, "%d", &puntuacion);

        // Cerrar el archivo
        fclose(archivo);
    }

    return puntuacion;
}

int main() {
    mostrarTildes();

    // Declarar las variables eleccionJugador, eleccionComputadora, respuesta y puntuacion
    int eleccionJugador;
    int eleccionComputadora;
    char respuesta;
    int puntuacion = 0;

    // Cargar la puntuación desde el archivo
    puntuacion = cargarPuntuacion();

    // ...

    // ...

    // Preguntar al usuario si quiere guardar la puntuación
    printf("¿Quieres guardar tu puntuación? (s/n)\n");
    scanf(" %c", &respuesta);

    // Guardar la puntuación si el usuario responde "s"
    if (respuesta == 's') {
        // Guardar la puntuación en un archivo
        guardarPuntuacion(puntuacion);
    }

    // Pausar la ejecución del código
    system("pause");

    // Imprimir una leyenda
    printf("Presione enter para salir...\n");

    return 0;
}