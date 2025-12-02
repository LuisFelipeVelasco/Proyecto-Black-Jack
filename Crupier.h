//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 16/11/2025


#ifndef CRUPIER_H
#define CRUPIER_H

#include "Usuario.h"


/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Cupier

RESPONSABILIDADES:
     - Administrar la mano del crupier
     - Robar cartas del mazo
     - Mostrar su mano
     - seguir las reglas del crupier (pedir hasta 17 cartas)
COlABORADORES:
     - Mazo
     - Mano
     - Carta        


*/
class Crupier : public Usuario {
private:
     bool cartaOcultaRevelada= false;
public:
    Crupier();

    void RevelarCartaOculta() ;
    void MostrarManoCompleta() ;
    void MostrarMano();
};

#endif // CRUPIER_H