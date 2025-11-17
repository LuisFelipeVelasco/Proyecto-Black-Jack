//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar ,
//Jeronimo Imbachi , Leonardo Rosero
//@fecha: 7/10/2025

// CRC: Clase Carta
// Responsabilidad:
//  - Representa una carta individual con valor nominal, tipo y nombre.
//  - Permite consultar y modificar sus atributos.

// Colaboración:
//  - Colabora con Mazo para formar el conjunto de cartas disponibles.
//  - Colabora con Mano para formar la mano de jugador o crupier.


#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
private:
    int Valornominal;
    char Palo;
    std::string Nombre;

public:
    Carta();
    Carta(int numero, char palo, const std::string &nombre);

    int obtenerNominal() const;
    char obtenerPalo() const;
    std::string obtenerNombre() const;
    void mostrarCarta() const;
};

#endif // CARTA_H
