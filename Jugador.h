//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 16/11/2025


#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Usuario.h"


/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Jugador

RESPONSABILIDADES:
     - Administrar la mano del jugador
     - Robar cartas
     - Decidir si pedir o quedarse
     - Llevar del registro del estado del jugador
     
COlABORADORES:
     - Mazo
     - Mano
     - Carta        


*/
class Jugador : public Usuario {
private:
    std::string nombre;
    int saldo;
    int apuestaActual;

public:
    Jugador();
    Jugador(const std::string& nombre, int saldoInicial);

    std::string obtenerNombre() const;

    int obtenerSaldo() const;
    void establecerSaldo(int saldo);
    int obtenerApuestaActual() const;

    bool puedeApostar(int monto) const;
    int ingresarApuesta() const;
    bool colocarApuesta(int monto);
    void limpiarApuesta();

    int pagarVictoria(bool blackjack);
    void pagarEmpate();
    void pagarDerrota();

    void mostrarMano() const;
};

#endif // JUGADOR_H