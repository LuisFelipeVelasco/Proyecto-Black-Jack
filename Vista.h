//
// Created by luisf on 15/11/2025.
//

#ifndef SEGUNDO_PROYECTO_VISTA_H
#define SEGUNDO_PROYECTO_VISTA_H

#include "Carta.h"
#include "Mano.h"
#include "Juego.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Crupier.h"

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

};


#endif //SEGUNDO_PROYECTO_VISTA_H