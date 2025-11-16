#include "Carta.h"
#include <iostream>

Carta::Carta(int nominal , char palo, const std::string& nombre ):
    Valornominal(nominal), Palo(palo), Nombre(nombre){}

Carta::Carta():
    Valornominal(0), Palo(' '), Nombre(""){}

int Carta::obtenerNominal() const{
    return Valornominal;
}

char Carta::obtenerPalo() const{
    return Palo;
}

std::string Carta::obtenerNombre() const{
    return Nombre;
}

