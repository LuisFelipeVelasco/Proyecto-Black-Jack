#ifndef SEGUNDO_PROYECTO_VISTA_H
#define SEGUNDO_PROYECTO_VISTA_H

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
     Juego* juego;
public:
     Vista();
     void setJuego(Juego* j);
     void MostrarReglas();
     int InterfazInicial();
     int IngresarApuesta(Jugador& jugador);
     void MostrarMano();
     void MostrarManoCompleta();
     void MostrarMensaje(std::string mensaje);
     std::string MostrarMensajeYRecibirRespuesta(std:: string mensaje);
     bool EsperarEnter(std::string Mensaje);


};


#endif //SEGUNDO_PROYECTO_VISTA_H
