#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Vista.h"
#include "Juego.h"
#include <iostream>

int main() {
    std::string nombre;
    int saldo;
    Vista vista;
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese su saldo inicial: $";
    std::cin >> saldo;
    Jugador jugador(nombre, saldo);
    Crupier crupier;
    Mazo mazo;
    Juego juego(jugador.obtenerNombre(), jugador.obtenerSaldo());
    vista.IniciarPrograma(crupier , jugador, mazo, juego);
    return 0;
}