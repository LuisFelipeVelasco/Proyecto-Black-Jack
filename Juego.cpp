#include "Juego.h"
#include "Mazo.h"
#include <iostream>
#include "Vista.h"
#include <sstream>
#include "Jugador.h"

static Mazo mazoGlobal;

Juego::Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista, Mazo& mazo, Crupier& crupier , Mano& mano )
    : jugador(nombreJugador, saldoInicial), vista(vista), mazo(mazo), crupier(crupier) , mano(mano) {
}

bool Juego::prepararRonda(int apuesta) {
    reiniciarRonda();

    if(!jugador.colocarApuesta(apuesta)) {
        return false;
    }
    return true;
}

void Juego::Barajar() {
    jugador.recibirCarta(mazoGlobal.repartirCarta());
    jugador.recibirCarta(mazoGlobal.repartirCarta());
    std::cout << "\n";

    Carta carta1 = mazoGlobal.repartirCarta();
    vista.MostrarMensaje("El crupier recibe ");
    std::ostringstream mensaje;
    mensaje << carta1.obtenerNombre() << " de " << carta1.obtenerPalo()
            << " (valor: " << carta1.obtenerNominal() << ")\n";
    vista.MostrarMensaje(mensaje.str());
    crupier.recibirCarta(carta1);

    Carta carta2 = mazoGlobal.repartirCarta();
    vista.MostrarMensaje("El crupier tiene una carta oculta\n");
    crupier.recibirCarta(carta2);

    jugador.mostrarMano();

    if(jugador.obtenerMano().tieneBlackjack()) {
        vista.MostrarMensaje("¡¡¡BLACKJACK NATURAL!!!\n");
    }
}

void Juego::turnoJugador(std::string comando) {
    if(comando == "P" || comando == "p") {
        std::ostringstream mensaje;
        mensaje << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
        vista.MostrarMensaje(mensaje.str());
        jugador.recibirCarta(mazoGlobal.repartirCarta());
        mensaje.str("");
        mensaje << "Mano del jugador " << jugador.obtenerNombre() << ":\n";
        vista.MostrarMensaje(mensaje.str());
        jugador.mostrarMano();

        if(jugador.obtenerMano().estaPasado()) {
            std::ostringstream msg;
            msg << "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() << " PIERDE.\n";
            vista.MostrarMensaje(msg.str());
        }
    }
    else if(comando == "S" || comando == "s") {
        std::ostringstream mensaje;
        mensaje << "\n" << jugador.obtenerNombre() << " se planta con "
                << jugador.suma() << " puntos.\n";
        vista.MostrarMensaje(mensaje.str());
    }
}

bool Juego::turnoCrupier() {
    vista.MostrarManoCompleta();

    while(crupier.suma() < 17) {
        vista.MostrarMensaje("\nEl crupier debe pedir (menos de 17)...\n");
        crupier.recibirCarta(mazoGlobal.repartirCarta());
        vista.MostrarManoCompleta();

        if(crupier.obtenerMano().estaPasado()) {
            return false;
        }
    }

    if(crupier.suma() >= 17 && !crupier.obtenerMano().estaPasado()) {
        return true;
    }
    return false;
}

int Juego::compararResultado() const {
    int sumaJugador = jugador.suma();
    int sumaCrupier = crupier.suma();

    if(jugador.obtenerMano().estaPasado()) {
        return -1;
    }

    if(crupier.obtenerMano().estaPasado()) {
        return jugador.obtenerMano().tieneBlackjack() ? 2 : 1;
    }

    if(sumaJugador > sumaCrupier) {
        return jugador.obtenerMano().tieneBlackjack() ? 2 : 1;
    }
    else if(sumaJugador < sumaCrupier) {
        return -1;
    }
    else {
        return 0;
    }
}

void Juego::liquidarResultado() {
    int resultado = compararResultado();
    std::ostringstream mensaje;

    mensaje << "\n" << std::string(60, '=') << "\n" << " COMPARACIÓN FINAL:\n"
    << "   Jugador: " << jugador.suma() << " puntos\n"
    << "   Crupier: " << crupier.suma() << " puntos\n"
    << std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());

    if(resultado == 2) {
        jugador.pagarVictoria(true);  // Blackjack
    }
    else if(resultado == 1) {
        jugador.pagarVictoria(false);  // Victoria normal
    }
    else if(resultado == 0) {
        jugador.pagarEmpate();  // Empate
    }
    else {
        jugador.pagarDerrota();  // Derrota
    }

    jugador.limpiarApuesta();
}

void Juego::reiniciarRonda() {
    jugador.limpiarMano();
    crupier.limpiarMano();
    jugador.limpiarApuesta();
}
bool Juego::mazoCorto() const {
    return mazoGlobal.mazoCorto();
}

bool Juego::rebarajarSiEsNecesario() {
    if(mazoCorto()) {
        mazoGlobal.inicializar();
        mazoGlobal.barajar();
        return true;
    }
    return false;
}

void Juego::MensajeVista(std::string mensaje) {
    vista.MostrarMensaje(mensaje);
}

void Juego::InterfazPrograma() {
   int opcion;
    do {
        int opcion=vista.InterfazInicial();


        if (opcion == 1) {
            if(jugador.obtenerSaldo() <= 0) {
                bool Acabar= vista.EsperarEnter("Te has quedado sin dinero! Game Over.\n");
                if (Acabar==true) break;
            }
           Ronda();

            vista.EsperarEnter("Presione Enter para volver al menu...");
        }
        else if (opcion == 2) {
            vista.MostrarReglas();
            vista.EsperarEnter(" ");
        }
        else if (opcion == 3) {
            std::ostringstream mensaje;
            mensaje<<"\n ¡Gracias por jugar! Saldo final: $"<< jugador.obtenerSaldo() << "\n"<< "Hasta luego.\n";
            vista.EsperarEnter(mensaje.str());
        }
        else {
            vista.MostrarMensaje("\n⚠ Opción no válida. Intente nuevamente.\n");
        }

    } while (opcion != 3);
}

void Juego::Ronda() {
    std::ostringstream mensaje;
    mensaje << "¡Bienvenido " << jugador.obtenerNombre() << "!\n"
            << " Saldo actual: $" << jugador.obtenerSaldo() << "\n";
    vista.MostrarMensaje(mensaje.str());
    bool rebarajar =rebarajarSiEsNecesario();
    if (rebarajar) vista.MostrarMensaje("¡Quedan pocas cartas! Rebarajando el mazo...\n");
    mensaje << "\n" << std::string(60, '=') << "\n"<< " INICIO DE LA RONDA\n"<< std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());
    int apuesta = vista.IngresarApuesta(jugador);

    if(!prepararRonda(apuesta)) {
        vista.MostrarMensaje("No se pudo ingresar la apuesta");
        return;
    }

    vista.MostrarMensaje("\n INICIANDO RONDA ===\n");
    vista.MostrarMensaje("\n Repartiendo cartas iniciales...\n\n");
    Barajar();
    if(jugador.obtenerMano().tieneBlackjack()) {
        vista.MostrarMensaje( "\n ¡BLACKJACK NATURAL! Fin de la ronda.\n");
        mensaje << "\n" << std::string(50, '=') << "\n"<< "RESULTADO FINAL\n"<< std::string(50, '=') << "\n";
        vista.MostrarMensaje(mensaje.str());
        liquidarResultado();
        return;
    }
    mensaje << "\n" << std::string(60, '=') << "\n"<< " TURNO DEL JUGADOR\n"<< std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());

    std::string opcion;

    while(true) {
        opcion=vista.MostrarMensajeYRecibirRespuesta( "\n¿Qué deseas hacer?\n [P] Pedir carta\n [S] Plantarse\n Opcion:");
        std::cout << "Opción: ";
        std::cin >> opcion;

        turnoJugador(opcion);

        if(opcion == "S" || opcion == "s") break;
        if(jugador.obtenerMano().estaPasado()) break;
    }

    if(jugador.obtenerMano().estaPasado()) {
        liquidarResultado();
        return;
    }
    mensaje << "\n" << std::string(60, '=') << "\n TURNO DEL CRUPIER\n"<< std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());

    bool EstadoCrupier = turnoCrupier();
    if (!EstadoCrupier)
        vista.MostrarMensaje( "\n ¡El crupier se pasó de 21!\n");
    else
        mensaje<<"\n El crupier se planta con " << obtenerCrupier().suma() << " puntos.\n";
        vista.MostrarMensaje(mensaje.str());

    // FINAL
    liquidarResultado();
}