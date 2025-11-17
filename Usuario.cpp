#include "Usuario.h"
#include <iostream>

Usuario::Usuario() {}

Usuario::~Usuario() {}

void Usuario::recibirCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

int Usuario::suma() const {
    return mano.obtenerSuma();
}

int Usuario::contarCartas() const {
    return mano.contarCartas();
}

void Usuario::limpiarMano() {
    mano.limpiar();
}

const Mano& Usuario::obtenerMano() const {
    return mano;
}