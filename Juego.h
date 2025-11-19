//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 7/10/2025


// CRC: Clase Juego
// Responsabilidad:
//  - Controla el flujo completo del juego Blackjack.
//  - Administra ronda, turnos, apuestas y resultado final.

// Colaboración:
//  - Colabora con Jugador, Crupier, Mazo y Carta para orquestar el juego.
//  - Colabora con Mano para manejar las cartas del jugador.

#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Crupier.h"

class Juego {
private:
    Jugador jugador;
    Crupier crupier;

public:
    Juego() {}
    Juego(const std::string& nombreJugador, int saldoInicial)
        : jugador(nombreJugador, saldoInicial) {}

    bool prepararRonda(int apuesta);
    void Barajar();
    void turnoJugador(char comando);
    bool turnoCrupier();
    int compararResultado() const;
    void liquidarResultado();
    void reiniciarRonda();
    bool mazoCorto() const;
    bool rebarajarSiEsNecesario();

    Jugador& obtenerJugador() { return jugador; }
    Crupier& obtenerCrupier() { return crupier; }
};

#endif // JUEGO_H