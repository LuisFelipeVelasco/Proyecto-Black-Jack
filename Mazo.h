//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025

#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

class Mazo {
private:
    std::vector<Carta> cartas;
    int indiceActual;

public:
    Mazo();
    
    void inicializar();
    void barajar();
    Carta repartirCarta();
    int tamano() const;
    bool mazoCorto() const;
    void limpiar();
};

#endif // MAZO_H