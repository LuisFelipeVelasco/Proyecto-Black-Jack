cmake_minimum_required(VERSION 4.0)
project(BLACKJACK_1_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BLACKJACK_1_2
        Carta.cpp
        Carta.h
        Crupier.cpp
        Crupier.h
        Juego.cpp
        Juego.h
        Jugador.cpp
        Jugador.h
        main
        main.cpp
        Mano.cpp
        Mano.h
        Mazo.cpp
        Mazo.h
        Usuario.cpp
        Usuario.h
        Vista.cpp
        Vista.h)
