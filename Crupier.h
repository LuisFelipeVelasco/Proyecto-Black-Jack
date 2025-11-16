//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025

// CRC: Clase Crupier
// Responsabilidad:
//  - Representa al crupier que reparte y juega según reglas.
//  - Administra su mano y lógica de turno.

// Colaboración:
//  - Colabora con Mazo para robar cartas.
//  - Colabora con Mano y Carta para controlar su mano.

#ifndef CRUPIER_H
#define CRUPIER_H

#include "Mano.h"
#include "Carta.h"
#include "Mazo.h"

class Crupier {
private:
    Mano mano;

public:
    Crupier();

    void recibirCarta(const Carta& carta);
    int suma() const;
    int contarCartas() const;
    void jugarTurno(Mazo& mazo);
    void limpiarMano();

    void mostrarPrimeraCarta() const;
    void mostrarManoCompleta() const;

    const Mano& obtenerMano() const;
};

#endif // CRUPIER_H
