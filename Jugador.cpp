#include "Jugador.h"
#include <iostream>

/*
=================================================================================================================
                                 Implementacion de la clase Jugador
=================================================================================================================
Implementa el comportamiento del jugador humano dentro del BlackJack. Maneja su mano, su estado dentro del 
juego, decisiones como pedir o quedarse, y controla su apuesta o puntos según la implementación. También 
contiene utilidades para mostrar la mano y calcular el puntaje.
=================================================================================================================
*/

Jugador::Jugador() : Usuario(), nombre(""), saldo(0), apuestaActual(0) {}

Jugador::Jugador(const std::string& nombre, int saldoInicial):
    Usuario(), nombre(nombre), saldo(saldoInicial), apuestaActual(0) {}

std::string Jugador::obtenerNombre() const {
    return nombre;
}

int Jugador::obtenerSaldo() const {
    return saldo;
}

void Jugador::establecerSaldo(int nuevoSaldo) {
    saldo = nuevoSaldo;
}

bool Jugador::puedeApostar(int monto) const {
    return saldo >= monto && monto > 0;
}

bool Jugador::colocarApuesta(int monto) {
    if(puedeApostar(monto)) {
        apuestaActual = monto;
        saldo -= monto;  // Se resta al apostar
        return true;
    }
    return false;
}

// NUEVO: Método específico para doblar la apuesta
bool Jugador::doblarApuesta() {
    // Verificar que hay suficiente saldo para la apuesta adicional
    if(saldo >= apuestaActual) {
        saldo -= apuestaActual;      // Restar la apuesta adicional del saldo
        apuestaActual *= 2;          // Duplicar la apuesta total
        return true;
    }
    return false;
}

void Jugador::limpiarApuesta() {
    apuestaActual = 0;
}

int Jugador::pagarVictoria(bool blackjack) {
    // Blackjack: recuperas tu apuesta + ganas 1.5x (total = 2.5x)
    // Victoria normal: recuperas tu apuesta + ganas 1x (total = 2x)
    int ganancia = blackjack ? (apuestaActual * 1.5) : apuestaActual;
    int total = apuestaActual + ganancia;  // Lo que recuperas en total
    saldo += total;

    std::cout << "\n🎉 ¡¡¡GANASTE!!! ";
    if(blackjack) {
        std::cout << "¡BLACKJACK! ";
    }
    std::cout << "\n   Apuesta: $" << apuestaActual;
    std::cout << "\n   Ganancia: +$" << ganancia;
    std::cout << "\n   Saldo actual: $" << saldo << "\n";

    return total;
}

void Jugador::pagarEmpate() {
    saldo += apuestaActual;  // Devuelve la apuesta
    std::cout << "\n🤝 EMPATE  ";
    std::cout << "\n   Se devuelve tu apuesta: $" << apuestaActual;
    std::cout << "\n   Saldo actual: $" << saldo << "\n";
}

void Jugador::pagarDerrota() {
    std::cout << "\n❌ PERDISTE ";
    std::cout << "\n   Pierdes: -$" << apuestaActual;
    std::cout << "\n   Saldo actual: $" << saldo << "\n";
}

int Jugador::obtenerApuestaActual() const {
    return apuestaActual;
}

void Jugador::mostrarMano() const {
    mano.mostrarMano();
}