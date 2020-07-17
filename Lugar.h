#ifndef PROYECTO_POO_LUGAR_H
#define PROYECTO_POO_LUGAR_H

#include "Variables.h"

class Lugar {
private:
    string Nombre;
public:
    Lugar();//Constructor de la clase Lugar
    Lugar(string Nombre_);//Constructor con la clase Lugar enviando un parametro de tipo String
    //Metodos get y set
    void set_Nombre(TipoString Nombre_);
    TipoString get_Nombre();
};


#endif
