
#include "Vista.h"
#include <iostream>



Vista::Vista() {}

void Vista::IniciarPrograma(Crupier& crupier, Jugador& jugador, Mazo& mazo, Juego& juego) {
    int opcion;
    do {
        std::cout << "\n"
           "██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗\n"
           "██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝\n"
           "██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝\n"
           "██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗\n"
           "██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗\n"
           "╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝\n";

        std::cout << "\n          === VERSIÓN BETA - CASO ESPECÍFICO ===\n";
        std::cout << "\n1. Jugar partida (Caso Beta Específico)\n";
        std::cout << "2. Mirar reglas\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {

            casoEspecificoBeta(crupier,jugador,mazo, juego);
            std::cout << "\nPresione Enter para volver al menú...";
            std::cin.ignore();
            std::cin.get();
        }
        else if (opcion == 2) {
            MostrarReglas();
            std::cout << "\nPresione Enter para volver al menú...";
            std::cin.ignore();
            std::cin.get();
        }
        else if (opcion == 3) {
            std::cout << "\n¡Gracias por jugar! Hasta luego.\n";
        }
        else {
            std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }

    } while (opcion != 3);

}


void Vista::casoEspecificoBeta(Crupier& crupier, Jugador& jugador, Mazo& mazo, Juego& juego) {




    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                BLACKJACK - MODO BETA REAL                  ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";



    std::cout << "¡Bienvenido " << jugador.obtenerNombre() << "!\n";
    std::cout << "Saldo inicial: $" << jugador.obtenerSaldo() << "\n";
    juego = Juego(jugador.obtenerNombre(), jugador.obtenerSaldo());

    juego.rebarajarSiEsNecesario();

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "INICIO DE LA RONDA\n";
    std::cout << std::string(60, '=') << "\n";

    int apuesta = IngresarApuesta(jugador);

    if(!juego.prepararRonda(apuesta)) {
        std::cout << "No se pudo colocar la apuesta.\n";
        return;
    }

    // repartir
    juego.Barajar();

    // si el jugador tiene blackjack natural termina la ronda
    if(jugador.obtenerMano().tieneBlackjack()) {
        std::cout << "\n¡BLACKJACK! Fin de la ronda.\n";
        juego.liquidarResultado();
        return;
    }

    // TURNO DEL JUGADOR
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TURNO DEL JUGADOR\n";
    std::cout << std::string(60, '=') << "\n";

    char opcion = ' ';

    while(true) {

        std::cout << "\n¿Qué deseas hacer?\n";
        std::cout << "  [P] Pedir carta\n";
        std::cout << "  [S] Plantarse\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        juego.turnoJugador(opcion);

        if(opcion == 'S' || opcion == 's') break;
        if(jugador.obtenerMano().estaPasado()) break;
    }

    // si el jugador se pasó termina la ronda
    if(jugador.obtenerMano().estaPasado()) {
        juego.liquidarResultado();
        return;
    }

    // TURNO DEL CRUPIER
    juego.turnoCrupier();

    // FINAL
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "RESULTADO FINAL\n";
    std::cout << std::string(60, '=') << "\n";

    juego.liquidarResultado();
}




void Vista::MostrarReglas() {
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════════════════\n";
    std::cout << "                    REGLAS DEL BLACKJACK                      \n";
    std::cout << "═══════════════════════════════════════════════════════════════\n\n";

    std::cout << "OBJETIVO:\n";
    std::cout << "  Acercarse lo más posible a 21 puntos sin pasarse.\n\n";

    std::cout << "VALORES DE LAS CARTAS:\n";
    std::cout << "  • Números del 2 al 10 valen su número.\n";
    std::cout << "  • J, Q y K valen 10 puntos.\n";
    std::cout << "  • El As vale 1 o 11, según convenga al jugador.\n\n";

    std::cout << "INICIO DEL JUEGO:\n";
    std::cout << "  • Cada jugador y el crupier reciben dos cartas.\n";
    std::cout << "  • El crupier muestra una carta boca arriba y otra boca abajo.\n\n";

    std::cout << "TURNO DEL JUGADOR:\n";
    std::cout << "  • Puede pedir carta (Hit) o plantarse (Stand).\n";
    std::cout << "  • Si supera los 21 puntos, pierde automáticamente (Bust).\n\n";

    std::cout << "TURNO DEL CRUPIER:\n";
    std::cout << "  • Debe pedir cartas hasta tener al menos 17 puntos.\n";
    std::cout << "  • Si se pasa de 21, pierde.\n\n";

    std::cout << "GANADOR:\n";
    std::cout << "  • Gana quien tenga más puntos sin pasarse de 21.\n";
    std::cout << "  • Si ambos tienen el mismo valor, es empate (Push).\n\n";

    std::cout << "BLACKJACK NATURAL:\n";
    std::cout << "  • Si un jugador obtiene 21 con sus dos primeras cartas\n";
    std::cout << "    (As + 10/J/Q/K), gana automáticamente, a menos que el\n";
    std::cout << "    crupier también lo tenga.\n\n";

    std::cout << "═══════════════════════════════════════════════════════════════\n";

}
int Vista::IngresarApuesta(Jugador& jugador) {

        int monto;
        std::cout << "\nSaldo actual: $" << jugador.obtenerSaldo() << std::endl;
        std::cout << "Ingrese su apuesta: $";
        std::cin >> monto;
        return monto;

}

void Vista::MostrarMano() {
    const std::vector<Carta>& cartas = mano.obtenerCartas();
    for(const auto& carta : cartas) {
        std::cout << "  - ";
        std::cout<<carta.obtenerNombre();
    }
}
void Vista::MostrarManoCompleta() const {
    std::cout << "\nMano del Crupier:\n";
    const std::vector<Carta>& cartas = mano.obtenerCartas();
    for(const auto& carta : cartas) {
        std::cout << "  - ";
        std::cout<<carta.obtenerNombre();
    }
    std::cout << "Total: " << crupier.suma()<< " puntos\n";
}



