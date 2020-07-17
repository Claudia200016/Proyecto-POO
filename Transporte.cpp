
#include "Transporte.h"
//Constructor Vacio : De forma pretederminada
Transporte::Transporte() {
    this->Nombre = "";//Nombre del personaje inicializado como un string vacio
    this->Numero_Asientos = 0;//Numero de asientos inicializado en 0
    this->Disponible = false;//Disponible inicializado en false
}
//Constructos con parametros, inicializando el objeto con valores
Transporte::Transporte(TipoString Nombre_, TipoEntero Numero_Asientos_, TipoBoleano Disponible_, TipoString Tipo_Transporte_) {
    this->Nombre = Nombre_;//Se guarda en el atributo el nombre que hemos enviado al constructor
    this->Numero_Asientos = Numero_Asientos_;//Se guarda en el numero de asientos, el numero que hemos enviado al constructor
    this->Disponible = Disponible_;//Se guarda en el atributo disponible, el boleano que hemos enviado a nuestro constructor
    this->Tipo_Transporte = Tipo_Transporte_;
}

//Metodos set
//Metodo set de nombre, para poder modificar el nombre del transporte
void Transporte::set_Nombre(TipoString Nombre_) {
    this->Nombre = Nombre_;
}
//Metodo set del numero de asientos, para moder modificar el numero de asientos
void Transporte::set_Numero_Asientos(TipoEntero Numero_Asientos_) {
    this->Numero_Asientos =Numero_Asientos_;
}
//Metodo sert del si esta disponible, para poder modificar si esta habilitado o no el transporte
void Transporte::set_Disponible(TipoBoleano Disponible_) {
    this->Disponible = Disponible_;
}

//Metodos get
//Retorna el atributo nombre que es tipo TipoString que esta en la capsula privada
TipoString Transporte::get_Nombre() {
    return this->Nombre;
}
//Retorna el atributo numero de asientos , que es tipo TipoEntero , que esta en la capsula privada
TipoEntero Transporte::get_Numero_Asientos() {
    return this->Numero_Asientos;
}
//Retorna el atributo Disponible que es tipo_Boleano , que esta en la capsula privada
TipoBoleano Transporte::get_Disponible() {
    return this->Disponible;
}

void Transporte::informacion_transporte() {
    cout<<"Tipo del Transporte   : "<<Tipo_Transporte<<endl;
    cout<<"Nombre del Transporte : "<<Nombre<<endl;
    cout<<"Numero de Asientos    : "<<Numero_Asientos<<endl;
    cout<<"Numero de Viajes      : "<<Numero_Viajes<<endl;
    cout<<"Disponible            : "<<(Disponible?"Si":"NO")<<endl;
}

TipoString Transporte::get_Tipo_Transporte() {
    return this->Tipo_Transporte;
}

void Transporte::set_Tipo_Transporte(TipoString Tipo_Transporte_) {
    this->Tipo_Transporte = Tipo_Transporte_;
}
