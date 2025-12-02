#include "Carta.h"
#include <iostream>


/*
=================================================================================================================
                                 Implementacion de la clase carta
=================================================================================================================
Este archivo implementa los metodos de la clase carta, deifine el comportamiento de una carta individual dentro 
del juego del BlackJack, incluyendo su valor, su representacion de texto y su comportamiento. La clase maneja el
numero y el palo de cada carta, y premite obtener valores segun las reglas del juego 
=================================================================================================================

*/

Carta::Carta(int nominal, std::string& palo, const std::string& nombre):
    Valornominal(nominal), Palo(palo), Nombre(nombre){}

Carta::Carta():
    Valornominal(0), Palo(""), Nombre("") {}

int Carta::obtenerNominal() const {
    return Valornominal;
}

std::string Carta::obtenerPalo() const {
    return Palo;
}

std::string Carta::obtenerNombre() const {
    return Nombre;
}