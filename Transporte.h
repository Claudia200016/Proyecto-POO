#ifndef PROYECTO_POO_TRANSPORTE_H
#define PROYECTO_POO_TRANSPORTE_H


#include "Variables.h"

class Transporte {
private:
    TipoString Tipo_Transporte;
    TipoString Nombre;
    TipoEntero Numero_Asientos;
    TipoBoleano Disponible;
    TipoEntero Numero_Viajes;
public:
    //Constructores
    Transporte();
    Transporte(TipoString Nombre_, TipoEntero Numero_Asientos_, TipoBoleano Disponible_, TipoString Tipo_Transporte_);
    //Metodos get y set para cada atributo
    //Metodos set
    void set_Nombre(TipoString Nombre_);
    void set_Numero_Asientos(TipoEntero Numero_Asientos_);
    void set_Disponible(TipoBoleano Disponible_);
    void set_Tipo_Transporte(TipoString Tipo_Transporte_);
    //Metodos get
    TipoString get_Nombre();
    TipoEntero get_Numero_Asientos();
    TipoBoleano get_Disponible();
    TipoString get_Tipo_Transporte();
    //
    void informacion_transporte();
};


#endif //PROYECTO_POO_TRANSPORTE_H
