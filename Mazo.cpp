#include "Mazo.h"
#include <algorithm>
#include <random>
#include <chrono>

Mazo::Mazo() : indiceActual(0) {
    inicializar();
}

void Mazo::inicializar() {
    cartas.clear();
    indiceActual = 0;
    
    char palos[] = {'C', 'D', 'P', 'T'};
    std::string nombresPalos[] = {"Corazones", "Diamantes", "Picas", "Trebol"};
    std::string nombres[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int valores[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    
    for(int p = 0; p < 4; p++) {
        for(int n = 0; n < 13; n++) {
            std::string nombreCompleto = nombres[n] + " de " + nombresPalos[p];
            cartas.push_back(Carta(valores[n], palos[p], nombreCompleto));
        }
    }
}

void Mazo::barajar() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(seed));
    indiceActual = 0;
}

Carta Mazo::repartirCarta() {
    if(indiceActual >= cartas.size()) {
        inicializar();
        barajar();
    }
    return cartas[indiceActual++];
}

int Mazo::tamano() const {
    return cartas.size() - indiceActual;
}

bool Mazo::mazoCorto() const {
    return tamano() < 15;
}

void Mazo::limpiar() {
    cartas.clear();
    indiceActual = 0;
}