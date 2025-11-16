#include "Crupier.h"
#include <iostream>

Crupier::Crupier() {}

void Crupier::recibirCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

int Crupier::suma() const {
    return mano.obtenerSuma();
}

int Crupier::contarCartas() const {
    return mano.contarCartas();
}

void Crupier::limpiarMano() {
    mano.limpiar();
}


const Mano& Crupier::obtenerMano() const {
    return mano;
}