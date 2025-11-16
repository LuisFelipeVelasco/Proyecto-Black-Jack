//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero 
//@fecha: 7/10/2025

// CRC: Clase Jugador
// Responsabilidad:
//  - Representa al jugador humano.
//  - Permite apostar, recibir cartas y mostrar su estado.

// Colaboración:
//  - Colabora con Mano para manejar las cartas del jugador.
//  - Colabora con Carta y Juego.

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Mano.h"
#include "Carta.h"

class Jugador {
private:
    std::string nombre;
    Mano mano;
    int saldo;
    int apuestaActual;

public:
    Jugador();
    Jugador(const std::string& nombre, int saldoInicial = 0);

    const std::string& obtenerNombre() const;
    void establecerNombre(const std::string& nombre);

    int obtenerSaldo() const;
    void establecerSaldo(int saldo);

    bool puedeApostar(int monto) const;
    int ingresarApuesta() const;
    bool colocarApuesta(int monto);
    void limpiarApuesta();

    void recibirCarta(const Carta& carta);
    int suma() const;
    int contarCartas() const;
    void limpiarMano();

    const Mano& obtenerMano() const;

    void pagarVictoria(bool blackjack);
    void pagarEmpate();
    void pagarDerrota();

    void mostrarMano() const;
};

#endif // JUGADOR_H
