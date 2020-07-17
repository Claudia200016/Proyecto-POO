#ifndef PROYECTO_POO_EMPRESA_H
#define PROYECTO_POO_EMPRESA_H


#include "Cliente.h"
#include "Lugar.h"
#include "Viaje.h"
#include "Transporte.h"

class Empresa {
private:
    vector<Cliente*> clientes;
    vector<Viaje*>viajes;
    vector<Transporte*>Transportes;
    vector<Lugar*> Lugares;
public:
    void Iniciar_Programa();
    void Buscar_Viaje();//Funcion buscar Viaje
    void Buscar_Cliente();//
    //Buscar cliente enviando un nombre
    Cliente* get_cliente(TipoString nombre_cliente);
    TipoBoleano encontro_cliente_nombre(TipoString nombre_cliente);
    void Buscar_Transporte();
    //Buscador de transporte por el nombre
    Transporte *get_Transporte_Nombre(TipoString nombre_transporte_);
    TipoBoleano encontro_transporte_nombre(TipoString nombre_transporte_);
    void Agregar_viaje();
    //Agregar un viaje
    TipoBoleano encontro_viaje_nombre(TipoString nombre_viaje);
    TipoBoleano encontro_viaje_numero(TipoEntero numero_viaje);

    TipoBoleano encontro_Lugar_nombre(TipoString nombre_lugar);
    TipoBoleano encontro_Lugar_nombre(TipoString nombre_lugar, vector<Lugar*> vector_lugar);
    void Agregar_Cliente();
    void Agregar_Varios_Clientes();
    void Agregar_Transporte();
    void Salir_Programa();
    void Ver_Transportes();
    ///
    void Buscar_Viaje_Nombre();
    Viaje * get_Viaje_por_Nombre(TipoString nombre_viaje);
    void Buscar_Viaje_Numero_Viaje();
    Viaje * get_Viaje_por_Numero_Viaje(TipoEntero Numero_Viaje);
    //Funciones de ver Transporte
    void ver_Todos_Los_Transportes();
    void ver_Transportes_Disponibles();
    //Get todos los transportes disponibles
    vector<Transporte*> get_Transportes_Disponibles();
    void ver_Transportes_No_Disponibles();
    vector<Transporte*> get_Transportes_no_Disponibles();
    TipoBoleano encontro_cliente_dni(TipoString dni);

    void Realizar_Viaje();
    void Ver_Viajes_Realizados();
    void Ver_Viajes_Pendientes();
    void Ver_Lugares();
    void Agregar_Lugares();
    void Agregar_Pasajes_Viaje();
};


#endif
