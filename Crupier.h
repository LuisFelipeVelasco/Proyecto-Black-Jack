//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 16/11/2025

// CRC: Clase Crupier (hereda de Usuario)
// Responsabilidad:
//  - Representa al crupier que reparte y juega según reglas.
//  - Administra su mano y lógica de turno.

// Colaboración:
//  - Hereda de Usuario para manejar la mano.
//  - Colabora con Mazo para robar cartas.
//  - Colabora con Jugador para jugar.

#ifndef CRUPIER_H
#define CRUPIER_H

#include "Usuario.h"

class Crupier : public Usuario {
public:
    Crupier();

    void mostrarPrimeraCarta() const;
    void MostrarManoCompleta() const;
};

#endif // CRUPIER_H