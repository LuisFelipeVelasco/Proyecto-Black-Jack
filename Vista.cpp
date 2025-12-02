
#include "Vista.h"
#include <iostream>
#include "Juego.h"
/*
=================================================================================================================
                                 Implementacion de la clase vista
=================================================================================================================
Implementa la interfaz textual del programa. Contiene todos los métodos encargados de mostrar menús, 
mensajes y resultados al usuario, así como recibir entradas. Actúa como el componente de la vista dentro del 
modelo MVC del proyecto.
=================================================================================================================

*/


Vista::Vista() : juego(nullptr) {}

void Vista::setJuego(Juego* j) {
    juego = j;
}

int Vista::InterfazInicial() {
    int opcion;
    std::cout << "\n"
           "██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗\n"
           "██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝\n"
           "██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝\n"
           "██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗\n"
           "██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗\n"
           "╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝\n";

    std::cout << "\n          === VERSIÓN BETA - CASO ESPECÍFICO ===\n";
    std::cout << "\n Jugador: " << juego->obtenerJugador().obtenerNombre()
              << " |  Saldo: $" << juego->obtenerJugador().obtenerSaldo() << "\n";
    std::cout << "\n1. Jugar partida\n";
    std::cout << "2. Mirar reglas\n";
    std::cout << "3. Salir\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}

void Vista::MostrarReglas() {
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════════════════\n";
    std::cout << "                    REGLAS DEL BLACKJACK                      \n";
    std::cout << "═══════════════════════════════════════════════════════════════\n\n";

    std::cout << " OBJETIVO:\n";
    std::cout << "  Acercarse lo más posible a 21 puntos sin pasarse.\n\n";

    std::cout << " VALORES DE LAS CARTAS:\n";
    std::cout << "  • Números del 2 al 10 valen su número.\n";
    std::cout << "  • J, Q y K valen 10 puntos.\n";
    std::cout << "  • El As vale 11 o 1, según convenga (automático).\n\n";

    std::cout << " INICIO DEL JUEGO:\n";
    std::cout << "  • Cada jugador y el crupier reciben dos cartas.\n";
    std::cout << "  • El crupier muestra una carta boca arriba y otra boca abajo.\n\n";

    std::cout << " TURNO DEL JUGADOR:\n";
    std::cout << "  • Puede pedir carta (Hit) o plantarse (Stand).\n";
    std::cout << "  • Si supera los 21 puntos, pierde automáticamente (Bust).\n\n";

    std::cout << " TURNO DEL CRUPIER:\n";
    std::cout << "  • Debe pedir cartas hasta tener al menos 17 puntos.\n";
    std::cout << "  • Si se pasa de 21, pierde.\n\n";

    std::cout << " GANADOR:\n";
    std::cout << "  • Gana quien tenga más puntos sin pasarse de 21.\n";
    std::cout << "  • Si ambos tienen el mismo valor, es empate (Push).\n\n";

    std::cout << " BLACKJACK NATURAL:\n";
    std::cout << "  • Si un jugador obtiene 21 con sus dos primeras cartas\n";
    std::cout << "    (As + 10/J/Q/K), gana 1.5x su apuesta.\n\n";

    std::cout << " PAGOS:\n";
    std::cout << "  • Victoria normal: Ganas tu apuesta (2x total)\n";
    std::cout << "  • Blackjack: Ganas 1.5x tu apuesta (2.5x total)\n";
    std::cout << "  • Empate: Recuperas tu apuesta\n";
    std::cout << "  • Derrota: Pierdes tu apuesta\n\n";

    std::cout << "═══════════════════════════════════════════════════════════════\n";
}

int Vista::IngresarApuesta(Jugador& jugador) {
    int monto;
    std::cout << "\n Saldo actual: $" << jugador.obtenerSaldo() << std::endl;
    std::cout << " Ingrese su apuesta: $";
    std::cin >> monto;

    while(monto <= 0 || monto > jugador.obtenerSaldo()) {
        if(monto <= 0) {
            std::cout << " La apuesta debe ser mayor a $0\n";
        } else {
            std::cout << " No tienes suficiente saldo\n";
        }
        std::cout << " Ingrese su apuesta: $";
        std::cin >> monto;
    }

    return monto;
}

void Vista::MostrarMano() {
    const std::vector<Carta>& cartas = juego->obtenerMano().obtenerCartas();
    for(const auto& carta : cartas) {
        std::cout << "  - ";
        std::cout<<carta.obtenerNombre();
    }
}


void Vista::MostrarManoCompleta(){
    std::cout << "\nMano del Crupier:\n";
    const std::vector<Carta>& cartas =juego->obtenerMano().obtenerCartas();
    for(const auto& carta : cartas) {
        std::cout << "  - ";
        std::cout << carta.obtenerNombre();
    }
    std::cout << "Total: " << juego->obtenerCrupier().suma() << " puntos\n";
}

void Vista::MostrarMensaje(std::string mensaje) {
    std::cout << mensaje;
}
std::string Vista::MostrarMensajeYRecibirRespuesta(std:: string mensaje) {
    std::string respuesta;
    std::cout << mensaje;
    std::cin >> respuesta;
    return respuesta;
}

bool Vista::EsperarEnter(std::string Mensaje) {
    std::cout<<Mensaje;
    std::cout<<"\nPresione Enter para salir...";
    std::cin.ignore();
    std::cin.get();
    return true;
}
