#include "Juego.h"
#include "Mazo.h"
#include "Juego.h"
#include <iostream>


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
   std::cout << "El crupier recibe: ";


     std::cout << carta1.obtenerNombre() << " de " << carta1.obtenerPalo() << " (valor: " << carta1.obtenerNominal() << ")\n";

     crupier.recibirCarta(carta1);

     Carta carta2 = mazoGlobal.repartirCarta();
     std::cout << "El crupier tiene una carta oculta\n";
     crupier.recibirCarta(carta2);

     jugador.mostrarMano();

     if(jugador.obtenerMano().tieneBlackjack()) {
         std::cout << "\n¡¡¡BLACKJACK NATURAL!!!\n";
     }
 }

 void Juego::turnoJugador(char comando) {
     if(comando == 'P' || comando == 'p') {
         std::cout << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
         jugador.recibirCarta(mazoGlobal.repartirCarta());
         jugador.mostrarMano();

         if(jugador.obtenerMano().estaPasado()) {
             std::cout << "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() << " PIERDE.\n";
         }
     }
     else if(comando == 'S' || comando == 's') {
         std::cout << "\n" << jugador.obtenerNombre() << " se planta con "
                   << jugador.suma() << " puntos.\n";
     }
 }

 bool Juego::turnoCrupier() {

     crupier.MostrarManoCompleta();

     while(crupier.suma() < 17) {
         std::cout << "\nEl crupier debe pedir (menos de 17)...\n";
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
void Jugador::mostrarMano() const {
     std::cout << "Mano del jugador " << nombre << ":\n";
     mano.mostrarMano();
     // Mano::mostrarMano() sí está implementada
 }


