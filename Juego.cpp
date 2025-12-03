#include "Juego.h"
#include "Mazo.h"
#include <iostream>
#include "Vista.h"
#include <sstream>
#include "Jugador.h"
#include <cctype>
#include <cassert>

static Mazo mazoGlobal;

Juego::Juego(const std::string& nombreJugador, int saldoInicial, Vista& vista, Mazo& mazo, Crupier& crupier, Mano& mano)
    : jugador(nombreJugador, saldoInicial), vista(vista), mazo(mazo), crupier(crupier), mano(mano) {
    #ifndef NDEBUG
    assert(saldoInicial >= 0 && "El saldo inicial no puede ser negativo");
    #endif
}

bool Juego::prepararRonda(int apuesta) {
    reiniciarRonda();

    #ifndef NDEBUG
    assert(apuesta > 0 && "La apuesta debe ser mayor que 0");
    #endif

    if(!jugador.colocarApuesta(apuesta)) {
        return false;
    }
    return true;
}

void Juego::Barajar() {
    jugador.recibirCarta(mazoGlobal.repartirCarta());
    jugador.recibirCarta(mazoGlobal.repartirCarta());
    std::cout << "\n";

    #ifndef NDEBUG
    assert(jugador.contarCartas() == 2 && "El jugador debe tener 2 cartas iniciales");
    #endif

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

    #ifndef NDEBUG
    assert(crupier.contarCartas() == 2 && "El crupier debe recibir 2 cartas iniciales");
    #endif

    jugador.mostrarMano();

    if(jugador.obtenerMano().tieneBlackjack()) {
        vista.MostrarMensaje("¡¡¡BLACKJACK NATURAL!!!\n");
    }
}

// Método mejorado para validar comandos
bool Juego::validarComando(const std::string& comando) {
    #ifndef NDEBUG
    assert(!comando.empty() && "El comando no puede estar vacío");
    #endif

    std::string cmd = comando;
    for(auto& c : cmd) c = toupper(c);
    
    return (cmd == "P" || cmd == "PEDIR" || cmd == "HIT" ||
            cmd == "S" || cmd == "PLANTARSE" || cmd == "STAND" ||
            cmd == "D" || cmd == "DOBLAR" || cmd == "DOUBLE");
}

// Método mejorado del turno del jugador con soporte para Doblar
void Juego::turnoJugador(std::string comando) {
    // Convertir a mayúscula para simplificar comparaciones
    for(auto& c : comando) c = toupper(c);

    #ifndef NDEBUG
    assert(!comando.empty() && "El comando no puede estar vacío en turnoJugador");
    #endif
    
    if(comando == "P" || comando == "PEDIR" || comando == "HIT") {
        std::ostringstream mensaje;
        mensaje << "\n" << jugador.obtenerNombre() << " pide una carta.\n";
        vista.MostrarMensaje(mensaje.str());
        
        jugador.recibirCarta(mazoGlobal.repartirCarta());
        
        mensaje.str("");
        mensaje << "Mano del jugador " << jugador.obtenerNombre() << ":\n";
        vista.MostrarMensaje(mensaje.str());
        jugador.mostrarMano();

        #ifndef NDEBUG
        { 
            int suma = jugador.suma();
            assert(suma >= 0 && suma <= 31 && "Suma del jugador fuera de rango después de pedir");
        }
        #endif

        if(jugador.obtenerMano().estaPasado()) {
            std::ostringstream msg;
            msg << "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() 
                << " PIERDE.\n";
            vista.MostrarMensaje(msg.str());
        }
    }
    else if(comando == "S" || comando == "PLANTARSE" || comando == "STAND") {
        std::ostringstream mensaje;
        mensaje << "\n" << jugador.obtenerNombre() << " se planta con "
                << jugador.suma() << " puntos.\n";
        vista.MostrarMensaje(mensaje.str());
    }
    else if(comando == "D" || comando == "DOBLAR" || comando == "DOUBLE") {
        // Doblar solo si es la primera jugada (2 cartas)
        if(jugador.contarCartas() != 2) {
            vista.MostrarMensaje("\n⚠️ Solo puedes doblar con tus dos primeras cartas.\n");
            return;
        }

        #ifndef NDEBUG
        assert(jugador.contarCartas() == 2 && "Solo se puede doblar con dos cartas");
        #endif
        
        // Verificar que tiene suficiente saldo
        if(!jugador.puedeApostar(jugador.obtenerApuestaActual())) {
            vista.MostrarMensaje("\n⚠️ No tienes suficiente saldo para doblar.\n");
            return;
        }

        #ifndef NDEBUG
        assert(jugador.puedeApostar(jugador.obtenerApuestaActual()) && "Saldo insuficiente para doblar apuesta");
        #endif
        
        int apuestaOriginal = jugador.obtenerApuestaActual();
        
        std::ostringstream mensaje;
        mensaje << "\n💰 " << jugador.obtenerNombre() << " dobla su apuesta de $" 
                << apuestaOriginal << " a $" 
                << (apuestaOriginal * 2) << ".\n";
        vista.MostrarMensaje(mensaje.str());
        
        // Correccion de usar el método doblarApuesta() que maneja correctamente el saldo
        if(!jugador.doblarApuesta()) {
            #ifndef NDEBUG
            assert(false && "Error inesperado al ejecutar doblarApuesta()");
            #endif
            vista.MostrarMensaje("\n⚠️ Error al doblar la apuesta.\n");
            return;
        }
        
        // Recibir exactamente una carta más
        vista.MostrarMensaje("\nRecibiendo una carta final...\n");
        jugador.recibirCarta(mazoGlobal.repartirCarta());
        
        #ifndef NDEBUG
        assert(jugador.contarCartas() == 3 && "Al doblar, el jugador debe tener 3 cartas en total");
        #endif

        mensaje.str("");
        mensaje << "Mano del jugador " << jugador.obtenerNombre() << ":\n";
        vista.MostrarMensaje(mensaje.str());
        jugador.mostrarMano();

        #ifndef NDEBUG
        {
            int suma = jugador.suma();
            assert(suma >= 0 && suma <= 31 && "Suma del jugador fuera de rango después de doblar");
        }
        #endif

        if(jugador.obtenerMano().estaPasado()) {
            std::ostringstream msg;
            msg << "\n¡¡¡SE PASÓ DE 21!!! " << jugador.obtenerNombre() 
                << " PIERDE.\n";
            vista.MostrarMensaje(msg.str());
        }
    }
    else {
        vista.MostrarMensaje("\n⚠️ Opción no válida. Usa: [P]edir, [S]Plantarse, [D]oblar\n");
    }
}


bool Juego::turnoCrupier() {
    vista.MostrarManoCompleta();

    #ifndef NDEBUG
    assert(crupier.contarCartas() >= 1 && "El crupier debe tener al menos 1 carta al iniciar su turno");
    #endif

    while(crupier.suma() < 17) {
        vista.MostrarMensaje("\nEl crupier debe pedir (menos de 17)...\n");
        crupier.recibirCarta(mazoGlobal.repartirCarta());
        vista.MostrarManoCompleta();

        #ifndef NDEBUG
        {
            int sumaC = crupier.suma();
            assert(sumaC >= 0 && sumaC <= 31 && "Suma del crupier fuera de rango después de pedir");
        }
        #endif

        if(crupier.obtenerMano().estaPasado()) {
            return false;
        }
    }

    #ifndef NDEBUG
    assert(crupier.suma() >= 17 && "Regla del crupier: debe plantarse con 17 o más");
    #endif

    if(crupier.suma() >= 17 && !crupier.obtenerMano().estaPasado()) {
        return true;
    }
    return false;
}

int Juego::compararResultado() const {
    int sumaJugador = jugador.suma();
    int sumaCrupier = crupier.suma();

    #ifndef NDEBUG
    assert(sumaJugador >= 0 && sumaJugador <= 31 && "Suma del jugador fuera de rango en compararResultado");
    assert(sumaCrupier >= 0 && sumaCrupier <= 31 && "Suma del crupier fuera de rango en compararResultado");
    #endif

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

    #ifndef NDEBUG
    assert((resultado == -1 || resultado == 0 || resultado == 1 || resultado == 2) && "Resultado inválido en compararResultado");
    #endif

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

    #ifndef NDEBUG
    assert(jugador.obtenerApuestaActual() == 0 && "La apuesta debe haber sido limpiada al final de la liquidación");
    #endif
}

void Juego::reiniciarRonda() {
    jugador.limpiarMano();
    crupier.limpiarMano();
    jugador.limpiarApuesta();

    #ifndef NDEBUG
    assert(jugador.contarCartas() == 0 && "La mano del jugador no se reinició correctamente");
    assert(crupier.contarCartas() == 0 && "La mano del crupier no se reinició correctamente");
    #endif
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
        opcion = vista.InterfazInicial();

        if (opcion == 1) {
            if(jugador.obtenerSaldo() <= 0) {
                bool Acabar = vista.EsperarEnter("💔 Te has quedado sin dinero! Game Over.\n");
                if (Acabar == true) break;
            }
            Ronda();
            vista.EsperarEnter("\nPresione Enter para volver al menú...");
        }
        else if (opcion == 2) {
            vista.MostrarReglas();
            vista.EsperarEnter(" ");
        }
        else if (opcion == 3) {
            std::ostringstream mensaje;
            mensaje << "\n👋 ¡Gracias por jugar! Saldo final: $" << jugador.obtenerSaldo() << "\n"
                    << "Hasta luego.\n";
            vista.EsperarEnter(mensaje.str());
        }
        else {
            vista.MostrarMensaje("\n⚠️ Opción no válida. Intente nuevamente.\n");
        }

    } while (opcion != 3);
}

void Juego::Ronda() {
    std::ostringstream mensaje;
    mensaje << "\n¡Bienvenido " << jugador.obtenerNombre() << "!\n"
            << "💵 Saldo actual: $" << jugador.obtenerSaldo() << "\n";
    vista.MostrarMensaje(mensaje.str());
    
    bool rebarajar = rebarajarSiEsNecesario();
    if (rebarajar) vista.MostrarMensaje("🔄 ¡Quedan pocas cartas! Rebarajando el mazo...\n");
    
    mensaje.str("");
    mensaje << "\n" << std::string(60, '=') << "\n" << " INICIO DE LA RONDA\n" 
            << std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());
    
    int apuesta = vista.IngresarApuesta(jugador);

    #ifndef NDEBUG
    assert(apuesta > 0 && "Apuesta inválida en Ronda");
    #endif

    if(!prepararRonda(apuesta)) {
        vista.MostrarMensaje("❌ No se pudo ingresar la apuesta");
        return;
    }

    vista.MostrarMensaje("\n🎲 INICIANDO RONDA\n");
    vista.MostrarMensaje("\n📇 Repartiendo cartas iniciales...\n\n");
    Barajar();
    
    if(jugador.obtenerMano().tieneBlackjack()) {
        vista.MostrarMensaje("\n⭐ ¡BLACKJACK NATURAL! Fin de la ronda.\n");
        mensaje.str("");
        mensaje << "\n" << std::string(50, '=') << "\n" << "RESULTADO FINAL\n" 
                << std::string(50, '=') << "\n";
        vista.MostrarMensaje(mensaje.str());
        liquidarResultado();
        return;
    }
    
    mensaje.str("");
    mensaje << "\n" << std::string(60, '=') << "\n" << " TURNO DEL JUGADOR\n" 
            << std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());

    std::string opcion;
    bool turnoTerminado = false;
    bool doblado = false;

    while(!turnoTerminado) {
        // Mostrar opciones disponibles
        std::string menuOpciones = "\n¿Qué deseas hacer?\n [P] Pedir carta (Hit)\n [S] Plantarse (Stand)\n";
        
        // Doblar solo disponible con 2 cartas y saldo suficiente
        if(jugador.contarCartas() == 2 && 
           jugador.puedeApostar(jugador.obtenerApuestaActual())) {
            menuOpciones += " [D] Doblar apuesta (Double)\n";
        }
        
        menuOpciones += " Opción: ";
        opcion = vista.MostrarMensajeYRecibirRespuesta(menuOpciones);
        
        // Convertir a mayúscula
        for(auto& c : opcion) c = toupper(c);
        
        // Validar entrada
        if(!validarComando(opcion)) {
            vista.MostrarMensaje("\n⚠️ Opción no válida. Intenta de nuevo.\n");
            continue;
        }
        
        // Si dobla, solo puede pedir una carta y termina su turno
        if(opcion == "D" || opcion == "DOBLAR" || opcion == "DOUBLE") {
            if(jugador.contarCartas() != 2) {
                vista.MostrarMensaje("\n⚠️ Solo puedes doblar con tus dos primeras cartas.\n");
                continue;
            }
            if(!jugador.puedeApostar(jugador.obtenerApuestaActual())) {
                vista.MostrarMensaje("\n⚠️ No tienes suficiente saldo para doblar.\n");
                continue;
            }
            doblado = true;
        }
        
        // Ejecutar la acción
        turnoJugador(opcion);
        
        // Verificar condiciones de finalización
        if(opcion == "S" || opcion == "PLANTARSE" || opcion == "STAND") {
            turnoTerminado = true;
        }
        else if(jugador.obtenerMano().estaPasado()) {
            turnoTerminado = true;
        }
        else if(doblado) {
            // Al doblar, solo se recibe una carta y termina el turno
            std::ostringstream msg;
            msg << "\n✋ " << jugador.obtenerNombre() 
                << " termina su turno después de doblar.\n";
            vista.MostrarMensaje(msg.str());
            turnoTerminado = true;
        }
    }

    // Si el jugador se pasó, no continuar con el crupier
    if(jugador.obtenerMano().estaPasado()) {
        liquidarResultado();
        return;
    }
    
    mensaje.str("");
    mensaje << "\n" << std::string(60, '=') << "\n TURNO DEL CRUPIER\n" 
            << std::string(60, '=') << "\n";
    vista.MostrarMensaje(mensaje.str());

    bool EstadoCrupier = turnoCrupier();
    if (!EstadoCrupier) {
        vista.MostrarMensaje("\n💥 ¡El crupier se pasó de 21!\n");
    }
    else {
        mensaje.str("");
        mensaje << "\n✋ El crupier se planta con " << obtenerCrupier().suma() << " puntos.\n";
        vista.MostrarMensaje(mensaje.str());
    }

    // FINAL
    liquidarResultado();
}
