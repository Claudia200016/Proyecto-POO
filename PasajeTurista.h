
#ifndef PROYECTO_POO_PASAJETURISTA_H
#define PROYECTO_POO_PASAJETURISTA_H


#include "Variables.h"
#include "Cliente.h"
#include "Pasaje.h"

class PasajeTurista : public Pasaje{
private:
    TipoBoleano cercaSalida;
public:
    PasajeTurista();
    PasajeTurista(Cliente *cliente_, TipoString seccion_, TipoEntero numero_asiento_, TipoDecimal precio, TipoBoleano cerca_salida);
    TipoDecimal CalcularTarifa() override;
    void Informacion_Cliente()override ;
};


#endif