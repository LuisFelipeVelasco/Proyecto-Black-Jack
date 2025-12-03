//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 7/10/2025

#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Mano.h"
#include <cassert>

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Juego

RESPONSABILIDADES:
     - Coordinar el flujo del juego
     - Gestionar al jugador, crupier, mazo, y vista
     - Iniciar y reiniciar partidas
     - Controlar turnos y resultados
     - Robar cartas del mazo

COLABORADORES:
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
     Mazo& mazo;
     Mano& mano;

     // Métodos auxiliares privados
     bool validarComando(const std::string& comando);

public:
     Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista, Mazo& mazo, Crupier& crupier, Mano& mano);

     bool prepararRonda(int apuesta);
     void Barajar();
     void turnoJugador(std::string comando);
     bool turnoCrupier();
     int compararResultado() const;
     void liquidarResultado();
     void reiniciarRonda();
     bool mazoCorto() const;
     bool rebarajarSiEsNecesario();
     void MensajeVista(std::string mensaje);

     Jugador& obtenerJugador() { return jugador; }
     Crupier& obtenerCrupier() { return crupier; }
     Mano& obtenerMano(){return mano;}
     
     void InterfazPrograma();
     void Ronda();
};

#endif // JUEGO_H