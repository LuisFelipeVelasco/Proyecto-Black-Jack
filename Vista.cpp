
#include "Vista.h"
#include <iostream>



Vista::Vista() {}

void Vista::IniciarPrograma(Crupier& crupier , Jugador& jugador, Mazo& mazo) {

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
            std::string nombre;
            int saldo;
            std::cout << "\nIngrese su nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese su saldo inicial: $";
            std::cin >> saldo;
            Jugador jugador(nombre,saldo);
            casoEspecificoBeta(crupier,jugador,mazo);
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


void Vista::casoEspecificoBeta(Crupier& crupier , Jugador& jugador, Mazo& mazo) {
    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║          BLACKJACK - DEMO BETA (CASO ESPECÍFICO)          ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";


    std::cout << "\n¡Bienvenido " << jugador.obtenerNombre() << " a Blackjack!\n";
    std::cout << "Saldo inicial: $" << jugador.obtenerSaldo() << "\n";

    std::cout << "\n[Sistema] Mazo inicializado con " << mazo.tamano() << " cartas.\n";
    mazo.barajar();
    std::cout << "[Sistema] Mazo barajado.\n";

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "INICIO DE LA RONDA\n";
    std::cout << std::string(60, '=') << "\n";

    int apuesta = IngresarApuesta(jugador);

    if(!jugador.colocarApuesta(apuesta)) {
        std::cout << "No se pudo realizar la apuesta.\n";
        return;
    }
    else {
        std::cout << "Apuesta de $" << apuesta << " colocada.\n";
        std::cout << "Saldo restante: $" << jugador.obtenerSaldo()<< std::endl;
    }

    std::cout << "\n--- REPARTO INICIAL ---\n";


    // se pasan cartas
    Carta carta1Jugador(6, 'T', "6 de Trebol");
    Carta carta2Jugador(4, 'C', "4 de Corazones");

    Carta carta1Crupier(9, 'P', "9 de Picas");
    Carta carta2Crupier(6, 'D', "6 de Diamantes");

    std::cout << "\nJugador recibe:\n";
    std::cout << jugador.obtenerNombre() << " recibe: ";
    jugador.recibirCarta(carta1Jugador);
    std::cout<<carta1Jugador.obtenerNombre();
    std::cout << jugador.obtenerNombre() << " recibe: ";
    std::cout<<carta2Jugador.obtenerNombre();


    std::cout << "\nCrupier recibe:\n";
    std::cout << "Crupier muestra: ";
    std::cout<<carta1Crupier.obtenerNombre();

    crupier.recibirCarta(carta1Crupier);

    std::cout << "Crupier tiene una carta oculta (boca abajo)\n";
    crupier.recibirCarta(carta2Crupier);

    MostrarMano();
    std::cout << "\nMano de " << jugador.obtenerNombre() << ":\n";
    std::cout << "Total: " << jugador.suma() << " puntos\n";


    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TURNO DEL JUGADOR\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\n¿Qué deseas hacer?\n";
    std::cout << "  [P] Pedir carta\n";
    std::cout << "  [S] Plantarse\n";
    std::cout << "Opción: ";
    char opcion1;
    std::cin >> opcion1;

    if(opcion1 == 'P' || opcion1 == 'p') {
        Carta carta3Jugador(9, 'D', "9 de Diamantes");
        std::cout << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
        jugador.recibirCarta(carta3Jugador);
        MostrarMano();
        std::cout << "\nMano de " << jugador.obtenerNombre() << ":\n";
        std::cout << "Total: " << jugador.suma() << " puntos\n";
    }

    if(!jugador.obtenerMano().estaPasado()) {
        std::cout << "\n¿Qué deseas hacer?\n";
        std::cout << "  [P] Pedir carta\n";
        std::cout << "  [S] Plantarse\n";
        std::cout << "Opción: ";
        char opcion2;
        std::cin >> opcion2;

        if(opcion2 == 'P' || opcion2 == 'p') {
            Carta carta4Jugador(2, 'P', "2 de Picas");
            std::cout << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
            jugador.recibirCarta(carta4Jugador);
            MostrarMano();
            std::cout << "\nMano de " << jugador.obtenerNombre() << ":\n";
            std::cout << "Total: " << jugador.suma() << " puntos\n";

            if(jugador.suma() == 21) {
                std::cout << "\n¡¡¡PERFECTO!!! Has llegado a 21 puntos.\n";
            }
        }
    }

    std::cout << "\n¿Qué deseas hacer?\n";
    std::cout << "  [P] Pedir carta\n";
    std::cout << "  [S] Plantarse\n";
    std::cout << "Opción: ";
    char opcion3;
    std::cin >> opcion3;

    if(opcion3 == 'S' || opcion3 == 's') {
        std::cout << "\n" << jugador.obtenerNombre() << " se planta con " << jugador.suma() << " puntos.\n";
    }

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TURNO DEL CRUPIER\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\nEl crupier revela su carta oculta: ";
    std::cout<<carta2Crupier.obtenerNombre();


    MostrarManoCompleta();

    if(crupier.suma() < 17) {
        std::cout << "\nEl crupier tiene menos de 17, debe pedir carta...\n";
        Carta cartaCrupier(8, 'C', "8 de Corazones");
        crupier.recibirCarta(cartaCrupier);
        MostrarManoCompleta();

        if(crupier.obtenerMano().estaPasado()) {
            std::cout << "\n¡¡¡EL CRUPIER SE PASÓ DE 21!!!\n";
        }
    }

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "RESULTADO FINAL\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\n" << jugador.obtenerNombre() << ": " << jugador.suma() << " puntos\n";
    std::cout << "Crupier: " << crupier.suma() << " puntos";

    if(crupier.obtenerMano().estaPasado()) {
        std::cout << " (SE PASÓ)\n";
    } else {
        std::cout << "\n";
    }

    if(jugador.obtenerMano().estaPasado()) {
        std::cout << "\n❌ " << jugador.obtenerNombre() << " SE PASÓ - PIERDE\n";
        jugador.pagarDerrota();
        std::cout << "\n" << jugador.obtenerNombre() << " PIERDE. Apuesta perdida: $" << jugador.obtenerApuestaActual() << std::endl;
        std::cout << "Saldo restante: $" << jugador.obtenerSaldo()<< std::endl;
    }
    else if(crupier.obtenerMano().estaPasado()) {
        std::cout << "\n✅ ¡" << jugador.obtenerNombre() << " GANA! - El crupier se pasó\n";
        bool esBlackjack = jugador.obtenerMano().tieneBlackjack();
        int ganancia=jugador.pagarVictoria(esBlackjack);
        std::cout << "\n¡" <<jugador.obtenerNombre() << " GANA!";
        if(esBlackjack) {
            std::cout << " ¡BLACKJACK! Pago 3:2";
        }
        std::cout << "\nGanancia: $" << ganancia<< std::endl;
        std::cout << "Nuevo saldo: $" << jugador.obtenerSaldo() << std::endl;
    }
    else if(jugador.suma() > crupier.suma()) {
        std::cout << "\n✅ ¡" << jugador.obtenerNombre() << " GANA!\n";
        bool esBlackjack = jugador.obtenerMano().tieneBlackjack();
        int ganancia=jugador.pagarVictoria(esBlackjack);
        if(esBlackjack) {
            std::cout << " ¡BLACKJACK! Pago 3:2";
        }
        std::cout << "\nGanancia: $" << ganancia<< std::endl;
        std::cout << "Nuevo saldo: $" << jugador.obtenerSaldo() << std::endl;

    }
    else if(jugador.suma() < crupier.suma()) {
        std::cout << "\n❌ El crupier GANA\n";
        jugador.pagarDerrota();
        std::cout << "\n" << jugador.obtenerNombre() << " PIERDE. Apuesta perdida: $" << jugador.obtenerApuestaActual() << std::endl;
        std::cout << "Saldo restante: $" << jugador.obtenerSaldo()<< std::endl;
    }
    else {
        std::cout << "\n🤝 EMPATE (Push)\n";
        jugador.pagarEmpate();
        std::cout << "\nEMPATE - Se devuelve la apuesta de $" << jugador.obtenerApuestaActual()<< std::endl;
        std::cout << "Saldo actual: $" << jugador.obtenerSaldo()<< std::endl;
    }

    std::cout << "\n[Sistema] Cartas restantes en el mazo: " << mazo.tamano() << "\n";
    if(mazo.mazoCorto()) {
        std::cout << "[Sistema] ⚠️  El mazo tiene pocas cartas, se recomienda rebarajar.\n";
    }

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "FIN DE LA RONDA BETA\n";
    std::cout << "Saldo final de " << jugador.obtenerNombre() << ": $" << jugador.obtenerSaldo() << "\n";
    std::cout << std::string(60, '=') << "\n";
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



