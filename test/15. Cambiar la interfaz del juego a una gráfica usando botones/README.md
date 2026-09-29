# Funcionalidad 15: Cambiar la interfaz del juego a una gráfica usando botones

## Descripción
Esta funcionalidad cambia la interfaz del juego de texto a una gráfica utilizando botones para seleccionar "Piedra", "Papel" o "Tijera".

## Cómo Ejecutar
1. Asegúrate de tener el archivo `interfaz_grafica.c` en el mismo directorio que el archivo base del juego.
2. Asegúrate de tener una biblioteca gráfica instalada, como SDL, SFML o Qt.
3. Compila el código fuente con el siguiente comando:
   ```bash
   gcc -o piedra_papel_tijera piedra_papel_tijera.c interfaz_grafica.c -l<nombre_biblioteca>
