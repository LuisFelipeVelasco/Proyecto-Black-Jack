#include "Usuario.h"
#include <iostream>
#include <cassert>

/*
=================================================================================================================
                                 Implementacion de la clase Usuario
=================================================================================================================
Implementa la clase Usuario, que representa un usuario registrado en el juego. Se encarga de almacenar y 
gestionar la información del jugador, como su nombre, identificador o datos relacionados al juego según la implementación actual.
=================================================================================================================

*/
Usuario::Usuario() {}

Usuario::~Usuario() {}

void Usuario::recibirCarta(const Carta& carta) {
    assert(carta.obtenerNominal() >= 1 && carta.obtenerNominal() <= 11 && 
           "Error: carta inválida recibida por usuario");

    mano.agregarCarta(carta);
}

int Usuario::suma() const {
    assert(mano.contarCartas() > 0 && "No se puede obtener suma de una mano vacía");
    return mano.obtenerSuma();
}

int Usuario::contarCartas() const {
    return mano.contarCartas();
}

void Usuario::limpiarMano() {
    mano.limpiar();
    assert(mano.contarCartas() == 0 && "Error: la mano no quedó vacía después de limpiar");
}

const Mano& Usuario::obtenerMano() const {
    return mano;
}
