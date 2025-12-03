#include "Crupier.h"
#include "Usuario.h"
#include "Juego.h"
#include <iostream>
#include "Mano.h"




/*
=================================================================================================================
                                 Implementacion de la clase Crupier
=================================================================================================================
Este archivo implementa la logica del crupier. Se encarga de gestionar las acciones especificas del durpier
dento del BlackJack, como pedir cartas hasta llegar al minimo permitido, mostrar su mano y tomar decisiones
automaticas basadas en la reglas del juego
=================================================================================================================

*/


Crupier::Crupier() : Usuario() {
    assert(cartaOcultaRevelada == false);
}

void Crupier::MostrarMano() {
    std::cout << "\nMano del crupier:\n";

    assert(mano.contarCartas() >= 0);

    if (!cartaOcultaRevelada) {
        if (mano.contarCartas() > 0) {
            mano.obtenerCartas()[0].MostrarCarta();
        } else {
            std::cout << "  [sin cartas]\n";
        }
        std::cout << "[Carta oculta]\n";
    }
    else {
        MostrarManoCompleta();
    }
}

void Crupier::RevelarCartaOculta() {
    assert(cartaOcultaRevelada == false);
    cartaOcultaRevelada = true;
}

void Crupier::MostrarManoCompleta() {
    std::cout << "\nMano del crupier:\n";

    assert(mano.contarCartas() > 0);

    for (const auto& c : mano.obtenerCartas()) {
        assert(c.obtenerNominal() >= 1 && c.obtenerNominal() <= 11);
        c.MostrarCarta();
    }

    int total = mano.calcularSuma();
    assert(total >= 0 && total <= 31);

    std::cout << "Valor total: " << total << "\n";
}