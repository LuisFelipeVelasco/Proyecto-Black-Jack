#include "Juego.h"
#include "Mazo.h"
#include <iostream>
#include "Vista.h"
#include <sstream>


/*
=================================================================================================================
                                 Implementacion de la clase Juego
=================================================================================================================
Este archivo implementa la lógica principal de la partida de BlackJack. Controla el flujo del juego: 
iniciar ronda, repartir cartas, gestionar turnos del jugador y del crupier, determinar el ganador y 
reiniciar el estado para nuevas partidas.También coordina la interacción entre Mazo, Jugador, Crupier y Vista.
=================================================================================================================

*/

static Mazo mazoGlobal;

Juego::Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista)
    : jugador(nombreJugador, saldoInicial) , vista(vista) {
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
    vista.MostrarMensaje("El crupier recibe");
    std::ostringstream mensaje;
     mensaje << carta1.obtenerNombre() << " de " << carta1.obtenerPalo() << " (valor: " << carta1.obtenerNominal() << ")\n";
    vista.MostrarMensaje(mensaje.str());
     crupier.recibirCarta(carta1);
     Carta carta2 = mazoGlobal.repartirCarta();
    vista.MostrarMensaje("El crupier tiene una carta oculta\n");
     crupier.recibirCarta(carta2);

     jugador.mostrarMano();

     if(jugador.obtenerMano().tieneBlackjack()) {
         vista.MostrarMensaje("¡¡¡BLACKJACK NATURAL¡¡¡\n");
     }
 }

 void Juego::turnoJugador(char comando) {
     if(comando == 'P' || comando == 'p') {
         std::ostringstream mensaje;
         mensaje<< "\n" << jugador.obtenerNombre() << " pide una carta.\n";
         vista.MostrarMensaje(mensaje.str());
         jugador.recibirCarta(mazoGlobal.repartirCarta());
         mensaje<<"Mano del jugador " << jugador.obtenerNombre()<< ":\n";
         vista.MostrarMensaje(mensaje.str());
         jugador.mostrarMano();

         if(jugador.obtenerMano().estaPasado()) {
             std::ostringstream mensaje;
             mensaje<< "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() << " PIERDE.\n";
             vista.MostrarMensaje(mensaje.str());
         }
     }
     else if(comando == 'S' || comando == 's') {
         std::ostringstream mensaje;
         mensaje<< "\n" << jugador.obtenerNombre() << " se planta con "
                   << jugador.suma() << " puntos.\n";
         vista.MostrarMensaje(mensaje.str());
     }
 }

 bool Juego::turnoCrupier() {

     crupier.MostrarManoCompleta();

     while(crupier.suma() < 17) {
         vista.MostrarMensaje("\nEl crupier debe pedir (menos de 17)...\n");
         crupier.recibirCarta(mazoGlobal.repartirCarta());
         crupier.MostrarManoCompleta();

         if(crupier.obtenerMano().estaPasado()) {
             return false;
         }
     }

     if(crupier.suma() >= 17 && !crupier.obtenerMano().estaPasado()) {
         return true;
     }
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

     if(resultado == 2) {
         jugador.pagarVictoria(true);
     }
     else if(resultado == 1) {
         jugador.pagarVictoria(false);
     }
     else if(resultado == 0) {
         jugador.pagarEmpate();
     }
     else {
         jugador.pagarDerrota();
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
     else return false;
 }


std::string Juego::MensajeVista(std::string mensaje) {
    vista.MostrarMensaje(mensaje);
}


