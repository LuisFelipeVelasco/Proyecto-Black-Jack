#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Vista.h"

int main() {
    Vista vista;
    Jugador jugador;
    Crupier crupier;
    Mazo mazo;
    vista.IniciarPrograma(crupier , jugador, mazo);
    return 0;
}