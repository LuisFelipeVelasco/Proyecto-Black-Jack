//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar ,
//Jeronimo Imbachi , Leonardo Rosero

#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Vista.h"
#include "Juego.h"
#include <iostream>
#include <cassert>   // <<<<<<<<<<<< SE AGREGA ESTO

int main() {
    std::string nombre;
    int saldo;
    Crupier crupier;
    Mazo mazo;
    Mano mano;

    Vista vista;
    
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;

    // Verificación básica del nombre
    assert(!nombre.empty() && "El nombre del jugador NO puede estar vacío");
    
    std::cout << "Ingrese su saldo inicial: $";
    std::cin >> saldo;

    // Validar saldo inicial
    while(saldo <= 0) {
        std::cout << "⚠️ El saldo debe ser mayor a $0\n";
        std::cout << "Ingrese su saldo inicial: $";
        std::cin >> saldo;
    }

    // Assert para asegurar que el saldo es válido ANTES de iniciar el juego
    assert(saldo > 0 && "Saldo inválido: debe ser mayor que 0");

    Juego juego(nombre, saldo, vista, mazo, crupier, mano);
    vista.setJuego(&juego);

    // Verificación de integridad
    assert(juego.obtenerJugador().obtenerSaldo() == saldo &&
           "El saldo inicial no se asignó correctamente al jugador");

    juego.InterfazPrograma();

    return 0;
}
