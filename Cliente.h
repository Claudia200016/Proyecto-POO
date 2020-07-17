

#ifndef PROYECTO_POO_CLIENTE_H
#define PROYECTO_POO_CLIENTE_H

#include "Variables.h"
class Cliente {
private:
    TipoString dni;//Aributo dni tipo string
    TipoString nombre;//Atributo nombre tipo nombre
    TipoString apellido;//Atributo apellido tipo string
    Tipocaracter genero; // 'M' o 'F'
    TipoEntero numero_viajes_pedientes;
    TipoEntero numero_vaijes_realizados;
public:
    //Constructor cliente, desde 0
    Cliente();
    //Constructor cliente enviando valores
    Cliente(TipoString dni, TipoString nombre, TipoString apellido, Tipocaracter genero);
//Metodos set y get
//Metodos set y get para dni
    TipoString GetDni();
    void SetDni(TipoString dni);
//Metodos set y get para nombre
    TipoString GetNombre();
    void SetNombre(TipoString nombre);
//Metodos set y get apellido
    TipoString GetApellido();
    void SetApellido(TipoString apellido);
//Metodos set y get para genero
    Tipocaracter GetGenero();
    void SetGenero(Tipocaracter genero);
    //
    void informacion_cliente();
};


#endif //PROYECTO_POO_CLIENTE_H
