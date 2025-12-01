//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 7/10/2025

#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Crupier.h"


/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Juego

RESPONSABILIDADES:
     - Cordinar el flujo del juego
     - Gestionar al jugador, crupier, mazo, y vista
     - Inicar y reiniciar partidas
     - COntrolar turnos y resultados
     - Robar cartas del mazo

COlABORADORES:
     - Jugador
     - Crupier
     - Mazo
     - Vista


*/
class Vista;

class Juego {
private:
    Jugador jugador;
    Crupier crupier;
    Vista& vista;

public:
    Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista);
    Juego();

    bool prepararRonda(int apuesta);
    void Barajar();
    void turnoJugador(char comando);
    bool turnoCrupier();
    int compararResultado() const;
    void liquidarResultado();
    void reiniciarRonda();
    bool mazoCorto() const;
    bool rebarajarSiEsNecesario();
    std::string MensajeVista(std::string mensaje);

    Jugador& obtenerJugador() { return jugador; }
    Crupier& obtenerCrupier() { return crupier; }
};

#endif // JUEGO_H