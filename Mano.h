//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025



#ifndef MANO_H
#define MANO_H

#include <vector>
#include <cassert>   // <-- agregado para habilitar assert
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
     - (usa assert para validar entradas y estados internos)   // <-- agregado SIN modificar nada

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

    void agregarCarta(const Carta& carta);   // assert en .cpp valida la carta
    void limpiar();
    
    int calcularSuma() const;                // assert en .cpp valida mano no vacía
    int contarCartas() const;
    bool tieneBlackjack() const;
    bool estaPasado() const;
    int obtenerSuma() const;
    const std::vector<Carta>& obtenerCartas() const;  // assert en .cpp evita mano vacía
    void mostrarMano() const;


};

#endif // MANO_H