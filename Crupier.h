#ifndef CRUPIER_H
#define CRUPIER_H

#include "Usuario.h"
#include <cassert>

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Crupier

RESPONSABILIDADES:
     - Administrar la mano del crupier
     - Robar cartas del mazo
     - Mostrar su mano
     - Seguir las reglas del crupier (pedir hasta 17 cartas)
COLABORADORES:
     - Mazo
     - Mano
     - Carta
*/

class Crupier : public Usuario {
private:
    bool cartaOcultaRevelada = false;

public:
    Crupier();  // Solo la declaración

    void RevelarCartaOculta();
    void MostrarManoCompleta();
    void MostrarMano();
};

#endif // CRUPIER_H
