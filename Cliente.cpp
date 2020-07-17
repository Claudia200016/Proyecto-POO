#include "Cliente.h"
Cliente::Cliente()
{
}

Cliente::Cliente(string dni, string nombre, string apellido, char genero)
{
    this->dni = dni;
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;

}

string Cliente::GetDni()
{
    return this->dni;
}

void Cliente::SetDni(string dni)
{
    this->dni = dni;
}

string Cliente::GetNombre()
{
    return this->nombre;
}

void Cliente::SetNombre(string nombre)
{
    this->nombre = nombre;
}

string Cliente::GetApellido()
{
    return this->apellido;
}

void Cliente::SetApellido(string apellido)
{
    this->apellido = apellido;
}

char Cliente::GetGenero()
{
    return this->genero;
}

void Cliente::SetGenero(char genero)
{
    this->genero = genero;
}

void Cliente::informacion_cliente() {
    cout<<"Nombre : "<<nombre<<endl;
    cout<<"Apellido : "<<apellido<<endl;
    cout<<"DNI : "<<dni<<endl;
    cout<<"Genero : "<<genero<<endl;
    cout<<"Numero de Viajes Realizados : "<<numero_vaijes_realizados<<endl;
    cout<<"Numero de Viajes Pendientes : "<<numero_viajes_pedientes<<endl;
}