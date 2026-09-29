#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string opciones[3] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario, eleccionComputadora;
    
    srand(time(0)); // Inicializa el generador de números aleatorios
    
    // Obtener la elección del usuario
    cout << "Elige una opción:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;
    cin >> eleccionUsuario;
    
    // Generar la elección de la computadora
    eleccionComputadora = rand() % 3;
    
    // Mostrar las elecciones
    cout << "Tu elección: " << opciones[eleccionUsuario - 1] << endl;
    cout << "Elección de la computadora: " << opciones[eleccionComputadora] << endl;
    
    // Determinar el resultado
    if (eleccionUsuario == eleccionComputadora + 1)
        cout << "¡Empate!" << endl;
    else if ((eleccionUsuario == 1 && eleccionComputadora == 1) ||
             (eleccionUsuario == 2 && eleccionComputadora == 2) ||
             (eleccionUsuario == 3 && eleccionComputadora == 3))
        cout << "¡Perdiste!" << endl;
    else
        cout << "¡Ganaste!" << endl;
        
    return 0;
}