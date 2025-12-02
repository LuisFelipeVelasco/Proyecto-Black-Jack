//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar ,
//Jeronimo Imbachi , Leonardo Rosero
#ifndef CARTA_H
#define CARTA_H

#include <string>

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Carta

RESPONSABILIDADES:
     - Representar una carta individual de la baraja
     - Almacenar su valor numerico
     - Almacenar su simbolo (palo)
     - Convertir la carta en texto para mostrarla en pantalla

COlABORADORES:
     - Colabora con Mazo para formar el conjunto de cartas disponibles.
     - Colabora con Mano para formar la mano de jugador o crupier.

*/

class Carta {
private:
  int Valornominal;
  std::string Palo;
  std::string Nombre;

public:
  Carta();
  Carta(int numero, std::string& palo, const std::string &nombre);



  int obtenerNominal() const;
  std::string obtenerPalo() const;
  std::string obtenerNombre() const;
    void MostrarCarta() const;



};

#endif // CARTA_H
