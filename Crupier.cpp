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


//   Mostrar la mano del crupier (carta oculta aún no revelada)

void Crupier::MostrarMano() {
    std::cout << "\nMano del crupier:\n";

    if (!cartaOcultaRevelada) {

        // Mostrar solo la primera carta
        if (mano.contarCartas() > 0) {
            const Carta &c = mano.obtenerCartas()[0];
            std::cout << "  carta: " << c.obtenerNombre()
                      << " (valor: " << c.obtenerNominal() << ")\n";
        } else {
            std::cout << "  [Sin cartas]\n";
        }

        // Mostrar la carta oculta
        std::cout << "[Carta oculta]\n";

    } else {
        MostrarManoCompleta();
    }
}


//        Revelar la carta oculta

void Crupier::RevelarCartaOculta() {
    cartaOcultaRevelada = true;
}


//   Mostrar TODA la mano completa del crupier

void Crupier::MostrarManoCompleta() {
    std::cout << "\nMano del crupier:\n";

    // Recorrer las cartas reales de la mano
    for (const Carta &c : mano.obtenerCartas()) {
        std::cout << "  🂠 " << c.obtenerNombre()
                  << " (valor: " << c.obtenerNominal() << ")\n";
    }

    std::cout << "Valor total: " << mano.calcularSuma() << "\n";
}



