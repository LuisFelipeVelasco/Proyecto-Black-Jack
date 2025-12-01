#ifndef SEGUNDO_PROYECTO_VISTA_H
#define SEGUNDO_PROYECTO_VISTA_H

#include "Carta.h"
#include "Mano.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Crupier.h"
#include "Juego.h"

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Vista

RESPONSABILIDADES:
     - Mostrar infomacion en pantalla
     - Interactuar con el usuario (entradas y salidas)
     - mostrar reglas, manos, resultados, etc


COlABORADORES:
     - Jugador 
     - Crupier
     - Carta       
     - Mano

     
*/

class Vista {
private:
    Mano mano;
    Crupier crupier;
public:
     Vista();
     void MostrarReglas();
     void IniciarPrograma(Crupier& crupier , Jugador& jugador, Mazo& mazo, Juego& juego);
     void casoEspecificoBeta(Crupier& crupier , Jugador& jugador, Mazo& mazo,Juego& juego);
     int IngresarApuesta(Jugador& jugador);
     void MostrarMano();
     void MostrarManoCompleta() const;
     void MostrarMensaje(std::string mensaje);


};


#endif //SEGUNDO_PROYECTO_VISTA_H