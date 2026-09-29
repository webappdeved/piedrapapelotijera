/* 
   ====================================================================
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N° 999 "Österreichische Schule der Nationalökonomie" — Vicente López
   Archivo: src/main.cpp
   Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
   Docente: Mansilla Muñoz York
   Estudiante: Carl Menger
   ====================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Estructura de datos para modelar una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();
void limpiarBuffer();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int contadorID = 1;
    int opcion = 0;

    cout << "=====================================================" << endl;
    cout << "  LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA      " << endl;
    cout << "  Resolucion de Catedra - Modelo de Replicacion       " << endl;
    cout << "  Estudiante / Grupo: Carl Menger                     " << endl;
    cout << "=====================================================" << endl;

    do {
        cout << "\n--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---" << endl;
        cout << "1. Jugar (Piedra, Papel o Tijera)" << endl;
        cout << "2. Ver Partidas Guardadas en el Historial del Disco (.txt)" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingresa una opcion (1-3): ";
        
        if (!(cin >> opcion)) {
            cout << "\n[ERROR] Entrada invalida. Ingresa un numero valido de la lista." << endl;
            limpiarBuffer();
            continue;
        }

        if (opcion == 1) {
            jugarPartida(contadorID);
        } 
        else if (opcion == 2) {
            leerHistorialDisco();
        } 
        else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo del juego... Los Datos estan resguardados en disco." << endl;
        } 
        else {
            cout << "\n[ERROR] Opcion fuera de rango (1-3). Reintenta." << endl;
        }

    } while (opcion != 3);

    return 0;
}

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void jugarPartida(int& contadorID) {
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;
    cout << "Ingresa tu Nombre / Apodo / Nickname: ";
    limpiarBuffer();
    getline(cin, p.jugador);

    int opcJugador = 0;
    do {
        cout << "\nEleji tu jugada:" << endl;
        cout << "1. Piedra" << endl;
        cout << "2. Papel" << endl;
        cout << "3. Tijera" << endl;
        cout << "Opcion (1-3): ";
        cin >> opcJugador;

        if (cin.fail() || opcJugador < 1 || opcJugador > 3) {
            cout << "[ERROR] Seleccion invalida. Elija 1, 2 o 3." << endl;
            limpiarBuffer();
        } else {
            break;
        }
    } while (true);

    if (opcJugador == 1) p.eleccionJugador = "Piedra";
    else if (opcJugador == 2) p.eleccionJugador = "Papel";
    else p.eleccionJugador = "Tijera";

    int opcIA = (rand() % 3) + 1;
    if (opcIA == 1) p.eleccionIA = "Piedra";
    else if (opcIA == 2) p.eleccionIA = "Papel";
    else p.eleccionIA = "Tijera";

    cout << "\n[JUGADA] " << p.jugador << " eligio: " << p.eleccionJugador << endl;
    cout << "[JUGADA] La IA eligio: " << p.eleccionIA << endl;

    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empataste!";
    } 
    else if ((p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
             (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
             (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")) {
        p.resultado = "Ganaste!";
    } 
    else {
        p.resultado = "Perdiste!";
    }

    cout << "=> RESULTADO: " << p.resultado << "!" << endl;

    guardarEnDisco(p);
}

void guardarEnDisco(const Partida& p) {
    // Intenta abrir primero en la subcarpeta src/
    ofstream archivo("src/historial_partidas.txt", ios::app);

    // Si no existe la carpeta relativa src/, guarda directamente en el directorio actual
    if (!archivo.is_open()) {
        archivo.open("historial_partidas.txt", ios::app);
    }

    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir el archivo para guardar la partida." << endl;
        return;
    }

    archivo << p.idPartida << ","
            << p.jugador << ","
            << p.eleccionJugador << ","
            << p.eleccionIA << ","
            << p.resultado << endl;

    archivo.close();
    cout << "[DISCO] Partida resguardada con exito en el historial del disco." << endl;
}

void leerHistorialDisco() {
    // Intenta abrir primero desde src/
    ifstream archivo("src/historial_partidas.txt");

    // Si falla, busca en la raíz local
    if (!archivo.is_open()) {
        archivo.open("historial_partidas.txt");
    }

    if (!archivo.is_open()) {
        cout << "\n[AVISO] Aun no existen partidas guardadas en disco." << endl;
        return;
    }

    cout << "\n=====================================================" << endl;
    cout << "  HISTORIAL DE PARTIDAS RECUPERADO DESDE DISCO       " << endl;
    cout << "=====================================================" << endl;

    string idStr, jugador, elJug, elIA, resultado;
    int total = 0;

    while (getline(archivo, idStr, ',') &&
           getline(archivo, jugador, ',') &&
           getline(archivo, elJug, ',') &&
           getline(archivo, elIA, ',') &&
           getline(archivo, resultado)) {
        
        total++;
        cout << "Partida #" << idStr 
             << " | Jugador: " << jugador 
             << " | " << elJug << " vs " << elIA 
             << " | Resultado: " << resultado << endl;
    }

    archivo.close();

    if (total == 0) {
        cout << "[AVISO] El archivo de historial esta vacio." << endl;
    } else {
        cout << "\n[SISTEMA] Total de registros leidos desde el disco: " << total << endl;
    }
    cout << "=====================================================" << endl;
}