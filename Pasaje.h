
#ifndef PROYECTO_POO_PASAJE_H
#define PROYECTO_POO_PASAJE_H


#include "Cliente.h"

class Pasaje {
protected:
    Cliente* cliente;//
    TipoString seccion; // A,G, AB
    TipoEntero numeroAsiento;
    TipoDecimal precio;
public:
    Pasaje();
    Pasaje(Cliente *cliente_, TipoString seccion_, TipoEntero numero_asiento_, TipoDecimal precio);
    virtual void Informacion_Cliente() = 0;
    virtual TipoDecimal CalcularTarifa()=0;
    TipoString get_seccion(){
        return this->seccion;
    }
    TipoEntero get_numero_Asiento(){
        return this->numeroAsiento;
    }
};


#endif
