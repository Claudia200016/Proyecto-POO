cmake_minimum_required(VERSION 3.15)
project(proyecto_poo)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto_poo main.cpp Cliente.cpp Cliente.h Variables.h Lugar.cpp Lugar.h Empresa.cpp Empresa.h Viaje.cpp Viaje.h Transporte.cpp Transporte.h Pasaje.cpp Pasaje.h PasajePrimeraClase.cpp PasajePrimeraClase.h PasajeTurista.cpp PasajeTurista.h)