#include "Crupier.h"
#include <iostream>


/*
=================================================================================================================
                                 Implementacion de la clase Crupier
=================================================================================================================
Este archivo implementa la logica del crupier. Se encarga de gestionar las acciones especificas del durpier
dento del BlackJack, como pedir cartas hasta llegar al minimo permitido, mostrar su mano y tomar decisiones
automaticas basadas en la reglas del juego
=================================================================================================================

*/
Crupier::Crupier() : Usuario() {}

void Crupier::mostrarPrimeraCarta() const {
    const std::vector<Carta>& cartas = mano.obtenerCartas();
    if(!cartas.empty()) {
        std::cout << "Crupier muestra: " << cartas[0].obtenerNombre() << "\n";
    }
}

void Crupier::MostrarManoCompleta() const {
    std::cout << "\nMano del Crupier:\n";
    const std::vector<Carta>& cartas = mano.obtenerCartas();
    for(const auto& carta : cartas) {
        std::cout << "  - " << carta.obtenerNombre() << "\n";
    }
    std::cout << "Total: " << suma() << " puntos\n";
}