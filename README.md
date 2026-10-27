# 🎮 ACTIVIDAD 7: MINI JUEGO "PIEDRA, PAPEL O TIJERA" CON PERSISTENCIA DE DATOS

**Asignatura:** Laboratorio de Programación (LPR) — 5° Año
**Institución:** E.E.S.T. N°999 "Österreichische Schule der Nationalökonomie" — Vicente López  
**Profesor:** Prof. Mansilla Muñoz York  
**Estudiante:** Carl Menger 
**Ciclo Lectivo:** 2026  

---

## 🎯 DESCRIPCIÓN DEL PROYECTO
Este repositorio contiene la implementación en C++ del mini juego interactivo **Piedra, Papel o Tijera** contra una Inteligencia Artificial en consola. El sistema demuestra la diferencia práctica entre la **Memoria RAM (volátil)** y el **Almacenamiento Secundario (persistente)** mediante el uso de estructuras de datos (`struct`) y flujos de archivos (`<fstream>`).

### 🚀 Funcionalidades Clave
1. **Modelado con `struct`:** Agrupación heterogénea de atributos de partida (`idPartida`, `jugador`, `eleccionJugador`, `eleccionIA`, `resultado`).
2. **Persistencia en Disco (`ofstream`):** Registro de jugadas en modo anexado (`ios::app`) en el archivo `historial_partidas.txt`.
3. **Recuperación de Historial (`ifstream`):** Lectura e interpretación de registros persistidos delimitados por comas (CSV).

---

## 🗂️ ESTRUCTURA OBLIGATORIA DEL REPOSITORIO

```text
piedrapapelotijera/
├── .gitattributes                  <-- Normalización de finales de línea
├── .gitignore                      <-- Reglas de exclusión de binarios y temporales
├── LICENSE                         <-- Licencia MIT de uso escolar
├── README.md                       <-- Portada técnica del proyecto
├── docs/                           <-- Entregables formales
│   ├── InformeEEST1_LPR2026_ACT07_G03_Informe_v1.0.0.pdf <-- Informe en PDF (APA v7)
│   └── manuales/                   <-- Documentación técnica y de usuario
│       ├── manualdelProgramadorv1.0.0.pdf
│       ├── manualdelProgramadorv1.0.0.md
│       └── manualdelUsuariov1.0.0.pdf
│       └── manualdelUsuariov1.0.0.md
├── CHANGELOG.md                <-- Bitácora de versionado SemVer
├── src/                            <-- Código fuente C++
│   ├── main.cpp                    <-- Programa principal del juego
├── data/                            <-- Para archivos persistentes
│   └── historial_partidas.txt      <-- Archivo de almacenamiento en disco
└── capturas/                       <-- Evidencias de ejecución (.png)
    ├── jugada_consola.png
    └── archivo_disco.png
