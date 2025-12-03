#include "Mano.h"
#include "Carta.h"
#include <iostream>
#include <cassert>

/*
=================================================================================================================
                                 Implementacion de la clase mano
=================================================================================================================
Implementa las operaciones relacionadas con una mano de cartas: agregar cartas, calcular el valor total
siguiendo las reglas del BlackJack (incluyendo manejo de Ases), reiniciar la mano y obtener representaciones 
de texto de las cartas.
=================================================================================================================
*/

Mano::Mano() {
    // Verificación opcional: una mano empieza vacía
    assert(cartas.size() == 0 && "La mano debe inicializarse vacía");
}

void Mano::agregarCarta(const Carta& carta){
    // Validar entrada (carta válida)
    assert(carta.obtenerNominal() >= 1 && carta.obtenerNominal() <= 11 && 
           "Error: carta agregada con valor fuera de rango");

    // Validar estado interno
    assert(cartas.size() < 12 && "Error: intentando agregar más de 11 cartas");

    cartas.push_back(carta);

    // Verificar post-condición
    assert(cartas.size() > 0 && "Error: la carta no fue agregada correctamente");
}

void Mano::limpiar(){
    cartas.clear();
    assert(cartas.empty() && "Error: no se limpio la mano correctamente");
}

int Mano::calcularSuma() const{
    assert(!cartas.empty() && "No se puede calcular la suma de una mano vacía");

    int suma = 0;
    int ases = 0;

    for(const auto& carta : cartas){
        assert(carta.obtenerNominal() >= 1 && carta.obtenerNominal() <= 11 &&
               "Error: valor inválido de carta dentro de la mano");

        suma += carta.obtenerNominal();
        
        if(carta.obtenerNominal() == 11){
            ases++;
        }
    }

    while(suma > 21 && ases > 0){
        suma -= 10;
        ases--;
    }

    // Verificar resultado esperado
    assert(suma >= 1 && suma <= 31 && "Error crítico: suma inválida calculada");

    return suma;
}

int Mano::contarCartas() const{
    assert(cartas.size() >= 0 && "Error lógico: la cantidad de cartas es negativa");
    return cartas.size();
}

bool Mano::tieneBlackjack() const{
    assert(cartas.size() <= 10 && "Una mano no puede tener más de 10 cartas");
    return cartas.size() == 2 && calcularSuma() == 21;
}

bool Mano::estaPasado() const{
    int suma = calcularSuma();
    assert(suma >= 1 && suma <= 31 && "Suma fuera del rango lógico");
    return suma > 21;
}

int Mano::obtenerSuma() const{
    return calcularSuma();
}

const std::vector<Carta>& Mano::obtenerCartas() const{
    assert(!cartas.empty() && "Intentando obtener cartas de una mano vacía");
    return cartas;
}

void Mano::mostrarMano() const {
    assert(!cartas.empty() && "Intento de mostrar una mano vacía");

    for (const auto& carta : cartas) {
        std::cout << "  🂠 " << carta.obtenerNombre()
                  << " (valor: " << carta.obtenerNominal() << ")\n";
    }

    std::cout << "   Total: " << calcularSuma() << " puntos\n";
}
