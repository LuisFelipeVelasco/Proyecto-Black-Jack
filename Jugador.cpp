#include "Jugador.h"
#include <iostream>

Jugador::Jugador() : nombre(""), saldo(0), apuestaActual(0) {}

Jugador::Jugador(const std::string& nombre, int saldoInicial):
    nombre(nombre), saldo(saldoInicial), apuestaActual(0) {}

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

void Jugador::recibirCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

int Jugador::suma() const {
    return mano.obtenerSuma();
}

int Jugador::contarCartas() const {
    return mano.contarCartas();
}

void Jugador::limpiarMano() {
    mano.limpiar();
}

const Mano& Jugador::obtenerMano() const {
    return mano;
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
    saldo-= apuestaActual;
}


int Jugador::obtenerApuestaActual() const {
    return apuestaActual;
}
