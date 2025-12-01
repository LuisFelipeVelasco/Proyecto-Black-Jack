//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025



#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"


/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Mano

RESPONSABILIDADES:
     - Almacenar un conjunto de cartas
     - Calcular el valor total de la mano
     - Maejar el valor total de la mano
     - Mostrar cartas

COlABORADORES:
     - Carta
     - Jugador
     - Crupier


*/
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
    void mostrarMano() const;

};

#endif // MANO_H