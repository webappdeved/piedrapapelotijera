# 📘 MANUAL DEL PROGRAMADOR — v1.0.0
**Proyecto:** Mini Juego Piedra, Papel o Tijera con Persistencia  
**Asignatura:** Laboratorio de Programación (LPR) — 5° Año  
**Institución:** E.E.S.T. N° 100 "Toy Story" — Vicente López  
**Docente:** Prof. Mansilla Muñoz York  
**Estudiante:** Slinky Dog  (Grupo 99\)

---

## 1. Arquitectura de Código y Estructura de Datos

El programa está diseñado bajo un paradigma modular en C++11, separando la lógica del juego del flujo de entrada/salida a disco.

### Estructura Principal (`struct Partida`)
```cpp
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};