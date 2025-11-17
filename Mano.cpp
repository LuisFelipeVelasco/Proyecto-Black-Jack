#include "Mano.h"
#include "Carta.h"
#include <iostream>

Mano::Mano() {}

void Mano::agregarCarta(const Carta& carta){
    cartas.push_back(carta);
}

void Mano::limpiar(){
    cartas.clear();
}

int Mano::calcularSuma() const{
    int suma = 0;
    for(const auto& carta : cartas){
        suma += carta.obtenerNominal();
    }
    return suma;
}

int Mano::contarCartas() const{
    return cartas.size();
}

bool Mano::tieneBlackjack() const{
    if(cartas.size() == 2 && calcularSuma() == 21){
        return true;
    }
    return false;
}

bool Mano::estaPasado() const{
    if(calcularSuma() > 21){
        return true;
    }
    return false;
}

int Mano::obtenerSuma() const{
    return calcularSuma();
}

const std::vector<Carta>& Mano::obtenerCartas() const{
    return cartas;
}
void Mano::mostrarMano() const {
    for (const auto& carta : cartas) {
        carta.mostrarCarta();
    }
}
