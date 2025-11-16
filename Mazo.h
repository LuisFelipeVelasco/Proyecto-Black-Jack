//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025


// CRC: Clase Mazo
// Responsabilidad:
//  - Representa un conjunto de cartas disponible para repartir.
//  - Permite inicializar, barajar y repartir cartas.

// Colaboración:
//  - Colabora con Carta para construir el mazo.
//  - Colabora con Crupier, Jugador y Juego para repartir cartas.

#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

class Mazo {
private:
    std::vector<Carta> cartas;

public:
    Mazo();

    void inicializar();
    void barajar();
    Cartarepartir();
    int tamaño() const;
    bool vacío() const;
};

#endif // MAZO_H
