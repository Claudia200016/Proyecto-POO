#include "Viaje.h"
Viaje::Viaje() {
    this->realizado = false;
}

Viaje::Viaje(TipoString Nombre_Viaje_, TipoEntero numero_viaje_, Transporte *transporte1, Lugar *Lugar_Partida_, Lugar *Lugar_Destino_,
             TipoDecimal Precio_Base_, TipoDecimal Porcentaje_primera_clase_, TipoDecimal Porcentaje_tursita_,
             TipoString fecha_) {
    this->Nombre_Viaje = Nombre_Viaje_;
    this->numero_viaje = numero_viaje_;
    this->transporte = transporte1;
    this->Lugar_Partida = Lugar_Partida_;
    this->Lugar_Destino = Lugar_Destino_;
    this->Precio_Base = Precio_Base_;
    this->porcentaje_primera_clase = Porcentaje_primera_clase_;
    this->porcentaje_turista = Porcentaje_tursita_;
    this->fecha = fecha_;
    this->realizado = false;
}

TipoDecimal Viaje::get_ganancia_total() {
    TipoDecimal total = 0; //Guardara la ganancia
    for(auto &pasaje :pasajes){//Recorremos el vector pasajes, y nombraremos a la variable pasaje, cada elemento del vector pasajes
        total += pasaje->CalcularTarifa(); //A la ganacia se le suma cada pasaje llamando a su funcion calcular tarifa
        //pasaje es un puntero, es por eso la ->
        //luego llamamos a su funcion calcular tarifa
    }
    return total;//Por ultimo retornamos el total
}

TipoEntero Viaje::get_cantidad_clientes() {
    return this->pasajes.size();
}

void Viaje::imprimir_clientes() {
    cout<<"Clientes : "<<endl<<endl;
    TipoEntero contador = 1;
    for(auto &pasaje :pasajes){
        cout<<contador<<". Cliente"<<endl;
        pasaje->Informacion_Cliente();
        cout<<endl;
    }

}

TipoString Viaje::get_Nombre() {
    return this->Nombre_Viaje;
}

TipoEntero Viaje::get_Numero_Viaje() {
    return this->numero_viaje;
}

void Viaje::imprimir_informacion_viaje() {
    cout<<"Nombre del Viaje : "<<this->Nombre_Viaje<<endl;
    cout<<"Numero del Viaje : "<<this->numero_viaje<<endl;
    cout<<"Transporte "<<endl;
    transporte->informacion_transporte();
    cout<<"Lugar Partida : "<<this->Lugar_Partida<<endl;
    cout<<"Lugar Destino : "<<this->Lugar_Destino<<endl;
    cout<<"Precio Base   : "<<this->Precio_Base<<endl;
    cout<<"Porcentaje de primera clase : "<<this->porcentaje_primera_clase<<endl;
    cout<<"Porcentaje de la clase turista : "<<this->porcentaje_turista<<endl;
    cout<<"Fecha : "<<this->fecha;
    TipoEntero eleccion;
    cout << "Imprimir los pasajes :" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese una opcion : ";cin>>eleccion;
    if (eleccion == 1){
        for(auto &pasaje : pasajes){
            pasaje->Informacion_Cliente();
        }
    }
}

TipoBoleano Viaje::get_realizado() {
    return this->realizado;
}

void Viaje::set_realizado(TipoBoleano realizado_) {
    this->realizado = realizado_;
    cout<<"El transporte "<<transporte->get_Nombre()<<" de tipo "<<transporte->get_Tipo_Transporte()<<" llevara "<<pasajes.size()<<" clientes"<<endl;
}

void Viaje::agregar_pasajes(vector<Cliente *> &clientes) {
    if(this->transporte->get_Numero_Asientos() > this->pasajes.size()){//Si en caso el numero de asientos es mayor a la cantidad total de pasajes
        TipoString eleccion_tipo_pasaje;
        cout<<"Desea agregar pasajes por : "<<endl;
        cout<<"1. Primera clase "<<endl;
        cout<<"2. Turista"<<endl;
        cout<<"Opcion : ";cin>>eleccion_tipo_pasaje;
        if(eleccion_tipo_pasaje == "1"){
            TipoString dni;
            cout<<"Ingrese el DNI del Cliente : ";cin>>dni;
            Cliente *cliente = nullptr;
            for(auto &cl : clientes){
                if(cl->GetDni() == dni){
                    cliente = cl;
                    break;
                }
            }
            if(cliente == nullptr){
                cout<<"El cliente no existe";
            }else{
                TipoString seccion;
                cout<<"Seccion (Texto): ";cin>>seccion;
                TipoEntero numero_asiento;
                cout<<"Numero de Asiento (Numero): ";cin>>numero_asiento;
                while(existe_seccion_numero_asiento(seccion, numero_asiento)){
                    cout<<"Error, seccion y numero de asientos ya ocupados.";
                    cout<<"Seccion (Texto): ";cin>>seccion;
                    cout<<"Numero de Asiento (Numero): ";cin>>numero_asiento;
                }
                TipoString eleccionbuffet;
                TipoBoleano incluyeBuffet;
                TipoEntero cantidadMaletas;
                cout<<"Incluye Buffet : "<<endl<<"1. Si"<<endl<<"2.No"<<endl<<"Opcion : ";cin>>eleccionbuffet;
                if(eleccionbuffet=="1"){
                    incluyeBuffet = true;
                }else{
                    incluyeBuffet = false;
                }
                cout<<"Cantidad de maletas : ";cin>>cantidadMaletas;
                auto *pasajePrimeraClase = new PasajePrimeraClase(cliente, seccion, numero_asiento, (Precio_Base + Precio_Base*porcentaje_turista/100) , incluyeBuffet, cantidadMaletas);
                pasajes.push_back(pasajePrimeraClase);
            }
        }else if(eleccion_tipo_pasaje == "2"){
            TipoString dni;
            cout<<"Ingrese el DNI del Cliente : ";cin>>dni;
            Cliente *cliente = nullptr;
            for(auto &cl : clientes){
                if(cl->GetDni() == dni){
                    cliente = cl;
                    break;
                }
            }
            if(cliente == nullptr){
                cout<<"El cliente no existe";
            }else {
                TipoString seccion;
                cout << "Seccion (Texto): ";
                cin >> seccion;
                TipoEntero numero_asiento;
                cout << "Numero de Asiento (Numero): ";
                cin >> numero_asiento;
                while (existe_seccion_numero_asiento(seccion, numero_asiento)) {
                    cout << "Error, seccion y numero de asientos ya ocupados.";
                    cout << "Seccion (Texto): ";
                    cin >> seccion;
                    cout << "Numero de Asiento (Numero): ";
                    cin >> numero_asiento;
                }
                TipoString eleccion_cerca_asiento;
                TipoBoleano cerca_asiento = false;
                cout << "Desea estar cerca del asiento : " << endl << "1.Si" << endl << "2.No" << endl << "Opcion : ";
                cin >> eleccion_cerca_asiento;
                if (eleccion_cerca_asiento == "1") {
                    cerca_asiento = true;
                }
                auto * pasajeTurista = new PasajeTurista(cliente, seccion, numero_asiento, (Precio_Base + Precio_Base*porcentaje_turista), cerca_asiento);
                pasajes.push_back(pasajeTurista);
            }

        }

    }
}

void Viaje::realizar_viaje(vector<Cliente *> clientes) {
    if(transporte->get_Disponible()){

    }
}

TipoBoleano Viaje::existe_seccion_numero_asiento(TipoString seccion, TipoEntero numero_asiento) {
    for(auto &pas : pasajes){
        if(pas->get_seccion() == seccion && pas->get_numero_Asiento() == numero_asiento){
            return true;
        }
    }
    return false;
}

