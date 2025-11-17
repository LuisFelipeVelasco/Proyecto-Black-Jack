#include "Crupier.h"
#include <iostream>

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