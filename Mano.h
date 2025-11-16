//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025

// CRC: Clase Mano
// Responsabilidad:
//  - Representa la mano de un jugador o crupier.
//  - Permite agregar cartas, calcular suma y verificar estado de la mano.

// Colaboración:
//  - Colabora con Carta para calcular el valor de la mano.
//  - Colabora con Jugador y Crupier.


#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"

class Mano {
private:
    std::vector<Carta> cartas;

public:
    Mano();

    void agregarCarta(const Carta& carta);
    void limpiar();
    
    int calcularSuma() const;
    int contarCartas() const;
    bool tieneBlackjack() const;
    bool estaPasado() const;
    int obtenerSuma() const;
    const std::vector<Carta>& obtenerCartas() const;
};

#endif // MANO_H