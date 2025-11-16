//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025


// CRC: Clase Juego
// Responsabilidad:
//  - Controla el flujo completo del juego Blackjack.
//  - Administra ronda, turnos, apuestas y resultado final.

// Colaboración:
//  - Colabora con Jugador, Crupier, Mazo y Carta para orquestar el juego.

#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"

class Juego {
private:
    Mazo mazo;
    Jugador jugador;
    Crupier crupier;



public:
    Juego(const std::string& nombreJugador, int saldoInicial);

    bool prepararRonda(int apuesta);
    void repartirInicial();
    void turnoJugador(char comando);
    void turnoCrupier();
    int compararResultado() const;
    void liquidarResultado();
    void reiniciarRonda();
    bool mazoCorto() const;
    void rebarajarSiEsNecesario();
};

#endif // JUEGO_H
