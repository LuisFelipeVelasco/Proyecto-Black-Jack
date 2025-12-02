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

Crupier::Crupier() : Usuario() {}

void Crupier::MostrarMano() {
    std::cout << "\nMano del crupier:\n";

    if (!cartaOcultaRevelada) {
        // Mostrar primera carta (visible)
        if (mano.contarCartas() > 0) {
            mano.obtenerCartas()[0].MostrarCarta(); // ahora existe
        } else {
            std::cout << "  [sin cartas]\n";
        }
        // Carta oculta
        std::cout << "[Carta oculta]\n";
    } else {
        MostrarManoCompleta();
    }
}

void Crupier::RevelarCartaOculta()  {
    cartaOcultaRevelada = true;
}

void Crupier::MostrarManoCompleta() {
    std::cout << "\nMano del crupier:\n";

    // Itera el vector interno (no la Mano directamente)
    for (const auto &c : mano.obtenerCartas()) {
        c.MostrarCarta(); // ahora existe
    }

    std::cout << "Valor total: " << mano.calcularSuma() << "\n";
}




