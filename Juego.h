//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 7/10/2025


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
#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Mano.h"



class Vista;
class Juego {
private:
     Jugador jugador;
     Crupier crupier;
     Vista& vista;
     Mazo& mazo;
     Mano& mano;

public:
     Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista, Mazo& mazo, Crupier& crupier , Mano& mano );

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