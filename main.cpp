//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar ,
//Jeronimo Imbachi , Leonardo Rosero

#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Vista.h"
#include "Juego.h"
#include <iostream>


int main() {
    std::string nombre;
    int saldo;
    Crupier crupier;
    Mazo mazo;
    Mano mano;

    Vista vista;
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese su saldo inicial: $";
    std::cin >> saldo;
    Juego juego(nombre, saldo, vista, mazo, crupier, mano);
    vista.setJuego(&juego);
    
    juego.InterfazPrograma();

    return 0;
}