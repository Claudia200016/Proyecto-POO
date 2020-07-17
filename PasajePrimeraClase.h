
#ifndef PROYECTO_POO_PASAJEPRIMERACLASE_H
#define PROYECTO_POO_PASAJEPRIMERACLASE_H


#include "Variables.h"
#include "Cliente.h"
#include "Pasaje.h"

class PasajePrimeraClase : public Pasaje {
private:
    TipoBoleano incluyeBuffet;
    TipoEntero cantidadMaletas;
public:
    PasajePrimeraClase();
    PasajePrimeraClase( Cliente* cliente,  TipoString seccion, TipoEntero numeroAsiento,TipoDecimal precio, TipoBoleano incluyeBuffet_, TipoEntero cantidadMaletas_);
    void Informacion_Cliente()override;
    TipoDecimal CalcularTarifa()override ;
};


#endif
