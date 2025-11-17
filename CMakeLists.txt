cmake_minimum_required(VERSION 4.0)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJack main.cpp
        Juego.cpp
        Juego.h
        Carta.cpp
        Carta.h
        Crupier.cpp
        Crupier.h
        Jugador.cpp
        Jugador.h
        Mano.cpp
        Mano.h
        Mazo.cpp
        Mazo.h
        Usuario.cpp
        Usuario.h
        Vista.cpp
        Vista.h)
