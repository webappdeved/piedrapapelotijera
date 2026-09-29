#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guardar_partida(int victorias, int derrotas) {
    FILE *archivo = fopen("partida_guardada.txt", "w");
    if (archivo == NULL) {
        printf("Error al guardar la partida.\n");
        return;
    }
    fprintf(archivo, "%d %d\n", victorias, derrotas);
    fclose(archivo);
    printf("Partida guardada exitosamente.\n");
}

void cargar_partida(int *victorias, int *derrotas) {
    FILE *archivo = fopen("partida_guardada.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró una partida guardada.\n");
        return;
    }
    fscanf(archivo, "%d %d", victorias, derrotas);
    fclose(archivo);
    printf("Partida cargada exitosamente.\n");
}

int main() {
    int victorias = 0, derrotas = 0, opcion;

    printf("¿Deseas cargar una partida guardada? (1. Sí, 2. No): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        cargar_partida(&victorias, &derrotas);
    }

    printf("Tienes %d victorias y %d derrotas.\n", victorias, derrotas);

    // Aquí iría el juego principal, después se puede guardar la partida
    printf("¿Deseas guardar la partida? (1. Sí, 2. No): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        guardar_partida(victorias, derrotas);
    }

    return 0;
}