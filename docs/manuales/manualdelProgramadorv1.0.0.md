# **📘 MANUAL TÉCNICO DEL PROGRAMADOR Y ARQUITECTURA DE CÓDIGO**

**Proyecto:** Mini Juego "Piedra, Papel o Tijera" con Persistencia en Disco (juegopiedra)

**Institución:** E.E.S.T. N° 999 "Österreichische Schule der Nationalökonomie" — Vicente López

**Asignatura:** Laboratorio de Programación (LPR) — 5° Año

**Docente:** Mansilla Muñoz York Elías (Grupo 99\)

**Autor / Grupo:** Carl Menger (Grupo 99\)

**Fecha:** 9 de octubre de 2026 | **Versión:** v1.0.0

## 

## **📄 CONTROL DE VERSIONES Y CHANGELOG**

| Versión | Fecha | Autor | Descripción de Cambios |
| :---- | :---- | :---- | :---- |
| **v1.0.0** | 09/10/2026 | Prof. York | Versión inicial de la suite modular de C++ con soporte Dual-Remote. |

## 

## **🏗️ 1\. ARQUITECTURA DEL SISTEMA Y ENTORNO DE DESARROLLO**

### **Requisitos del Entorno**

* **Compilador:** g++ (MinGW-w64 GCC v8.1.0 o superior con soporte C++11).  
* **Entorno Integrado:** Visual Studio Code o terminal PowerShell 5.1+.  
* **Librerías Estándar C++:** \<iostream\>, \<fstream\>, \<string\>, \<cstdlib\>, \<ctime\>.

### **Estructura del Repositorio (juegopiedra)**

piedrapapelotijera/  
├── .gitattributes  
├── .gitignore  
├── LICENSE  
├── README.md  
├── docs/  
│   └── InformeEEST1\_LPR2026\_ACT07\_G03\_Informe\_v1.0.0.pdf  
│   ├── CHANGELOG.md  
│   └── manuales/  
│       ├── manual\_programador\_v1.0.0.pdf  
│       └── manual\_usuario\_v1[.0.0.](http://.0.0.md)pdf  
│       ├── manual\_programador\_v1[.0.0.](http://.0.0.md)[md](http://.0.0.md)  
│       └── manual\_usuario\_v1.0.0.md  
├── src/  
│   ├── main.cpp  
│   └── historial\_partidas.txt  
└── capturas/  
    ├── jugada\_consola.png  
    └── archivo\_disco.png

## 

## **🧩 2\. ESPECIFICACIÓN DE TIPOS Y MÓDULOS (src/main.cpp)**

### **2.1 Estructura de Datos Partida**

Agrupa los atributos heterogéneos de cada evento de juego:

struct Partida {  
    int idPartida;  
    string jugador;  
    string eleccionJugador;  
    string eleccionIA;  
    string resultado;  
};

* **Alineación en memoria:** Los miembros residen contiguos en memoria volatil (RAM) durante la ejecucion de la partida.  
* **Complejidad espacial:** O(1) por cada objeto instanciado en el ámbito de la función.

### **2.2 Módulo void jugarPartida(int& contadorID)**

* **Parámetro:** Pass-by-reference (int& contadorID) para autoincrementar secuencialmente el identificador global de partidas1,2,3, . . . , N.  
* **Manejo de Búfer:** Invoca cin.ignore() para limpiar el carácter de salto de línea pendientes (\\n) acumulados por el cin \>\> opcion previo.  
* **Generación de IA:** Genera un valor pseudoaleatorio en el rango |1,3\]:

opcIA \= (rand()  (mod 3)) \+ 1  
**Evaluación de Reglas:** Mapea enteros a cadenas ("Piedra", "Papel", "Tijera") y determina la victoria, empate o derrota mediante comparaciones condicionales.

### **2.3 Módulo void guardarEnDisco(const Partida& p)**

* **Flujo de Salida:** ofstream archivo("historial\_partidas.txt", ios::app);  
* **Modo de Apertura:** ios::app (*Append*) ubica el puntero de escritura al final de la secuencia de bytes del archivo en disco.  
* **Formato de Salida:** CSV separado por comas:

idPartida, jugador, eleccionJugador, eleccionIA, resultado\\n

* **Tratamiento de Errores:** Valida \!archivo.is\_open() imprimiendo un mensaje de fallo en el flujo de error estándar cerr.

### **2.4 Módulo void leerHistorialDisco()**

* **Flujo de Entrada:** ifstream archivo("historial\_partidas.txt");  
* **Lectura Secuencial:** Utiliza la sobrecarga de getline(stream, variable, delimitador) especificando ',' como delimitador de campo.  
* **Complejidad Temporal:** O(N) donde N es la cantidad total de registros grabados en disco.

## 

## **⚙️ 3\. COMPILACIÓN Y DEPURACIÓN DESDE POWERSHELL**

\# Compilación con estándar C++11  
g++ \-std=c++11 src/main.cpp \-o src/piedrapapelotijera.exe

\# Ejecución directa del binario  
.\\src\\piedrapapelotijera.exe

## **📚 4\. REFERENCIAS**

* Stroustrup, B. (2013). *The C++ programming language* (4th ed.). Addison-Wesley.  
* Microsoft Corporation. (2026). *basic\_ofstream Class*. https\://learn.microsoft.com/cpp/standard-library/basic-ofstream-class