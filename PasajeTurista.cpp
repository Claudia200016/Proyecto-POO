

#include "PasajeTurista.h"
PasajeTurista::PasajeTurista()
{
}




TipoDecimal PasajeTurista::CalcularTarifa()
{
    return precio;
}

PasajeTurista::PasajeTurista(Cliente *cliente_, TipoString seccion_, TipoEntero numero_asiento_, TipoDecimal precio,
                             TipoBoleano cerca_salida) :Pasaje(cliente_, seccion_, numero_asiento_, precio){
    this->cercaSalida = cerca_salida;
}

void PasajeTurista::Informacion_Cliente() {
    cliente->informacion_cliente();
    cout<<"Tipo Pasaje : Primera Clase "<<endl;
    cout<<"Seccion : "<<this->seccion<<endl;
    cout<<"Numero Asiento : "<<this->numeroAsiento<<endl;

}