//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 16/11/2025

// CRC: Clase Usuario (Superclase)
// Responsabilidad:
//  - Representa a cualquier participante del juego (Jugador o Crupier).
//  - Administra la mano y operaciones comunes.

// Colaboración:
//  - Colabora con Mano para manejar las cartas.
//  - Colabora con Carta para recibir y mostrar cartas.

#ifndef USUARIO_H
#define USUARIO_H

#include "Mano.h"
#include "Carta.h"
#include <cassert> 

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Usuario

RESPONSABILIDADES:
     - Contener la informacion del usuario y el jugador
     - Registar nombre o otas caracteristicas basicas
COlABORADORES:
     - Ninguno directo
      


*/
class Usuario {
protected:
    Mano mano;

public:
    Usuario();
    virtual ~Usuario();

    void recibirCarta(const Carta& carta);
    int suma() const;
    int contarCartas() const;
    void limpiarMano();
    const Mano& obtenerMano() const;
};

#endif // USUARIO_H