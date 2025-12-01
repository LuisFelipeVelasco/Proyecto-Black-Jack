#include "Usuario.h"
#include <iostream>


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

