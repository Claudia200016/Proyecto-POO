#ifndef PROYECTO_POO_VIAJE_H
#define PROYECTO_POO_VIAJE_H


#include "Variables.h"
#include "Lugar.h"
#include "Transporte.h"
#include "Pasaje.h"
#include "PasajePrimeraClase.h"
#include "PasajeTurista.h"
class Viaje {
private:
    TipoString Nombre_Viaje;
    TipoEntero numero_viaje;
    Transporte *transporte;
    vector<Pasaje*>pasajes;
    Lugar *Lugar_Partida;
    Lugar *Lugar_Destino;
    TipoDecimal Precio_Base;
    TipoDecimal porcentaje_primera_clase;
    TipoDecimal porcentaje_turista;
    TipoString fecha;
    TipoBoleano realizado;
public:
    Viaje();
    Viaje(TipoString Nombre_Viaje_, TipoEntero numero_viaje_, Transporte *transporte1, Lugar *Lugar_Partida_ , Lugar *Lugar_Destino_, TipoDecimal Precio_Base_, TipoDecimal Porcentaje_primera_clase_, TipoDecimal Porcentaje_tursita_, TipoString fecha_);
    TipoDecimal get_ganancia_total();
    TipoEntero get_cantidad_clientes();
    void imprimir_clientes();
    void imprimir_informacion_viaje();
    TipoString get_Nombre();
    TipoEntero get_Numero_Viaje();
    TipoBoleano get_realizado();
    void set_realizado(TipoBoleano realizado_);
    void realizar_viaje(vector <Cliente*> clientes);
    void agregar_pasajes(vector <Cliente*> &clientes);
    TipoBoleano existe_seccion_numero_asiento(TipoString seccion, TipoEntero numero_asiento);
};


#endif
