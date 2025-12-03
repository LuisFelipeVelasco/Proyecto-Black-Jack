#include "Carta.h"
#include <iostream>
#include <cassert>

/*
=================================================================================================================
                                 Implementacion de la clase Carta
=================================================================================================================
Este archivo implementa los metodos de la clase Carta, define el comportamiento de una carta individual dentro 
del juego del BlackJack, incluyendo su valor, su representacion de texto y su comportamiento. La clase maneja el
numero y el palo de cada carta, y permite obtener valores segun las reglas del juego.
=================================================================================================================
*/

Carta::Carta(int nominal, const std::string& palo, const std::string& nombre)
    : Valornominal(nominal), Palo(palo), Nombre(nombre)
{
    // ===================== ASSERTS IMPORTANTES =====================
    assert(nominal >= 1 && nominal <= 11); // Verifica que el valor nominal sea válido
    assert(!palo.empty());                 // El palo no debe estar vacío
    assert(!nombre.empty());               // El nombre no debe estar vacío
}

Carta::Carta()
    : Valornominal(1), Palo("N/A"), Nombre("Carta vacía")
{
    // Carta por defecto válida para evitar errores
    assert(Valornominal >= 1 && Valornominal <= 11);
}

int Carta::obtenerNominal() const {
    assert(Valornominal >= 1 && Valornominal <= 11);
    return Valornominal;
}

std::string Carta::obtenerPalo() const {
    assert(!Palo.empty());
    return Palo;
}

std::string Carta::obtenerNombre() const {
    assert(!Nombre.empty());
    return Nombre;
}

void Carta::MostrarCarta() const {
    std::cout << Nombre << " de " << Palo << " (Valor: " << Valornominal << ")\n";
}
