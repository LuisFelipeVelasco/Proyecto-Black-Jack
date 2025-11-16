#include "Juego.h"
#include "Mazo.h"
#include <iostream>

// static Mazo mazoGlobal;
//
// bool Juego::prepararRonda(int apuesta) {
//     reiniciarRonda();
//
//     if(!jugador.colocarApuesta(apuesta)) {
//         return false;
//     }
//
//     std::cout << "\n=== INICIANDO RONDA ===\n";
//     return true;
// }
//
// void Juego::Barajar() {
//     std::cout << "\nRepartiendo cartas iniciales...\n\n";
//
//     jugador.recibirCarta(mazoGlobal.repartirCarta());
//     jugador.recibirCarta(mazoGlobal.repartirCarta());
//
//     std::cout << "\n";
//     Carta carta1 = mazoGlobal.repartirCarta();
//     std::cout << "El crupier recibe: ";
//     carta1.mostrarCarta();
//     crupier.recibirCarta(carta1);
//
//     Carta carta2 = mazoGlobal.repartirCarta();
//     std::cout << "El crupier tiene una carta oculta\n";
//     crupier.recibirCarta(carta2);
//
//     jugador.mostrarMano();
//
//     if(jugador.obtenerMano().tieneBlackjack()) {
//         std::cout << "\n¡¡¡BLACKJACK NATURAL!!!\n";
//     }
// }
//
// void Juego::turnoJugador(char comando) {
//     if(comando == 'P' || comando == 'p') {
//         std::cout << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
//         jugador.recibirCarta(mazoGlobal.repartirCarta());
//         jugador.mostrarMano();
//
//         if(jugador.obtenerMano().estaPasado()) {
//             std::cout << "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() << " PIERDE.\n";
//         }
//     }
//     else if(comando == 'S' || comando == 's') {
//         std::cout << "\n" << jugador.obtenerNombre() << " se planta con "
//                   << jugador.suma() << " puntos.\n";
//     }
// }
//
// void Juego::turnoCrupier() {
//     std::cout << "\n=== TURNO DEL CRUPIER ===\n";
//     crupier.mostrarManoCompleta();
//
//     while(crupier.suma() < 17) {
//         std::cout << "\nEl crupier debe pedir (menos de 17)...\n";
//         crupier.recibirCarta(mazoGlobal.repartirCarta());
//         crupier.mostrarManoCompleta();
//
//         if(crupier.obtenerMano().estaPasado()) {
//             std::cout << "\n¡El crupier se pasó de 21!\n";
//             break;
//         }
//     }
//
//     if(crupier.suma() >= 17 && !crupier.obtenerMano().estaPasado()) {
//         std::cout << "\nEl crupier se planta con " << crupier.suma() << " puntos.\n";
//     }
// }
//
// int Juego::compararResultado() const {
//     int sumaJugador = jugador.suma();
//     int sumaCrupier = crupier.suma();
//
//     if(jugador.obtenerMano().estaPasado()) {
//         return -1;
//     }
//
//     if(crupier.obtenerMano().estaPasado()) {
//         return jugador.obtenerMano().tieneBlackjack() ? 2 : 1;
//     }
//
//     if(sumaJugador > sumaCrupier) {
//         return jugador.obtenerMano().tieneBlackjack() ? 2 : 1;
//     }
//     else if(sumaJugador < sumaCrupier) {
//         return -1;
//     }
//     else {
//         return 0;
//     }
// }
//
// void Juego::liquidarResultado() {
//     std::cout << "\n" << std::string(50, '=') << "\n";
//     std::cout << "RESULTADO FINAL\n";
//     std::cout << std::string(50, '=') << "\n";
//
//     int resultado = compararResultado();
//
//     if(resultado == 2) {
//         jugador.pagarVictoria(true);
//     }
//     else if(resultado == 1) {
//         jugador.pagarVictoria(false);
//     }
//     else if(resultado == 0) {
//         jugador.pagarEmpate();
//     }
//     else {
//         jugador.pagarDerrota();
//     }
//
//     jugador.limpiarApuesta();
// }
//
// void Juego::reiniciarRonda() {
//     jugador.limpiarMano();
//     crupier.limpiarMano();
//     jugador.limpiarApuesta();
// }
//
// bool Juego::mazoCorto() const {
//     return mazoGlobal.mazoCorto();
// }
//
// void Juego::rebarajarSiEsNecesario() {
//     if(mazoCorto()) {
//         std::cout << "\n¡Quedan pocas cartas! Rebarajando el mazo...\n";
//         mazoGlobal.inicializar();
//         mazoGlobal.barajar();
//     }
// }
//


