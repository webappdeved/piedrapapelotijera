# 📜 Bitácora de Cambios (CHANGELOG) — Actividad 7

Todos los cambios notables en el proyecto **piedrapapelotijera** se documentan en este archivo siguiendo el formato [Keep a Changelog](https://keepachangelog.com/es-ES/1.0.0/) y el estándar de versionado semántico [SemVer](https://semver.org/).

## [1.0.0] - 2026-09-29

### Agregado
- Implementación de la estructura `struct Partida` para empaquetar variables del juego.
- Redirección y soporte flexible de persistencia para la subcarpeta `src/historial_partidas.txt` o la raíz.
- Módulo `guardarEnDisco()` utilizando `ofstream` con bandera `ios::app` para almacenamiento no volátil.
- Módulo `leerHistorialDisco()` con `ifstream` y procesamiento de cadenas con `getline()` delimitado por comas.
- Función `jugarPartida()` con selección aleatoria mediante `rand()` y `srand(time(0))`.
- Limpieza de búfer de teclado con `limpiarBuffer()` (`cin.ignore()`) para prevenir saltos de lectura de nombres.
- Documentación formal APA v7 y manuales de usuario/programador en formato editable.