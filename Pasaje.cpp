#include "Pasaje.h"

Pasaje::Pasaje()
{

}

Pasaje::Pasaje(Cliente *cliente_, TipoString seccion_, TipoEntero numero_asiento_, TipoDecimal precio) {
    this->cliente = cliente_;
    this->seccion = seccion_;
    this->numeroAsiento = numero_asiento_;
    this->precio = precio;
}

