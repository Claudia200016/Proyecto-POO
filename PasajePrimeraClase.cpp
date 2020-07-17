
#include "PasajePrimeraClase.h"
PasajePrimeraClase::PasajePrimeraClase()
{
}


TipoDecimal PasajePrimeraClase::CalcularTarifa()
{
    return precio;
}

void PasajePrimeraClase::Informacion_Cliente() {
    cliente->informacion_cliente();
    cout<<"Tipo Pasaje : Primera Clase "<<endl;
    cout<<"Seccion : "<<this->seccion<<endl;
    cout<<"Numero Asiento : "<<this->numeroAsiento<<endl;
    cout<<"Incluye buffet : "<<this->incluyeBuffet<<endl;
}

PasajePrimeraClase::PasajePrimeraClase(Cliente *cliente, TipoString seccion, TipoEntero numeroAsiento,
                                       TipoDecimal precio, TipoBoleano incluyeBuffet,
                                       TipoEntero cantidadMaletas_):Pasaje(cliente, seccion, numeroAsiento, precio){
    this->incluyeBuffet = incluyeBuffet;
    this->cantidadMaletas = cantidadMaletas_;
}