#include "Lugar.h"
Lugar::Lugar() {
    this->Nombre = "";//Se inicializa la clase con el nombre vacio, constructor vacio
}
//Constructor enviando un parametro
Lugar::Lugar(string Nombre_) {
    this->Nombre = Nombre_;
}
//Funcion get Nombre : Retona el nombre
TipoString Lugar::get_Nombre() {
    return this->Nombre;
}
//Funcion set Nombre : Se puede modificar el nombre
void Lugar::set_Nombre(TipoString Nombre_) {
    this->Nombre = Nombre_;
}
