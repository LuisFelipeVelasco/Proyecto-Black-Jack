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
        saldo -= monto;
        return true;
    }
    return false;
}

void Jugador::limpiarApuesta() {
    apuestaActual = 0;
}

int Jugador::pagarVictoria(bool blackjack) {
    int ganancia = blackjack ? (apuestaActual * 2.5) : (apuestaActual * 2);
    saldo += ganancia;
    return ganancia;
}

void Jugador::pagarEmpate() {
    saldo += apuestaActual;
}

void Jugador::pagarDerrota() {
    saldo -= apuestaActual;
}

int Jugador::obtenerApuestaActual() const {
    return apuestaActual;
}