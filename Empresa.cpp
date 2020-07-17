#include "Empresa.h"
void limpiar(){
    //system("clear");
    cout << "\033[2J\033[0;0H";
    //system("CLS");
    //system("cls");
}
void Empresa::Iniciar_Programa() {
    TipoBoleano acabar_programa=false;
    while (!acabar_programa) {
        TipoEntero eleccion;
        cout << "Bienvenido a la Agencia de Transporte" << endl;
        cout << "1. Buscar un Viaje" << endl; //Busca viaje
        cout << "2. Buscar un cliente" << endl;//Busca el cliente y muestra su infomacion si en caso lo ha encontrado, caso contrario dire que no lo encontro
        cout << "3. Buscar un transporte" << endl;//Busca un transporte con el tipo de nombre que se le envia
        cout << "4. Agregar un viaje" << endl;//Agregaremos un viaje
        cout << "5. Agregar un cliente" << endl;//Agregas un nuevo cliente
        cout << "6. Agregar varios clientes" << endl;//Agregas varios clientes un while
        cout << "7. Agregar un transporte" << endl;//agregas un transporte
        cout << "8. Realizar Viaje" << endl;//Realizar un viaje
        cout << "9. Ver viajes realizados" << endl;//Ver viajes realizados
        cout << "10.Ver viajes pendientes " << endl;//Ver viajes pendientes
        cout << "11. Agregar Lugares"<<endl;//Agregar luga
        cout << "12. Ver Lugares"<<endl;
        cout << "13. Agregar Clientes a un viaje"<<endl;
        cout << "\n0. Salir"<<endl;//Salir
        cout<<"Ingrese la opcion que desea ingresar : ";cin>>eleccion;
        switch (eleccion){
            case 1:this->Buscar_Viaje();break;
            case 2:this->Buscar_Cliente();break;
            case 3:this->Buscar_Transporte();break;
            case 4:this->Agregar_viaje();break;
            case 5:this->Agregar_Cliente();break;
            case 6:this->Agregar_Varios_Clientes();break;
            case 7:this->Agregar_Transporte();break;
            case 8:this->Realizar_Viaje();break;
            case 9: this->Ver_Viajes_Realizados();break;
            case 10: this->Ver_Viajes_Pendientes();break;
            case 11: this->Agregar_Lugares();break;
            case 12: this->Ver_Lugares();break;
            case 13:this->Agregar_Pasajes_Viaje();break;
            case 0:this->Salir_Programa();acabar_programa=true;break;
            default:break;
        }
    }
}

//Funcion Buscar de la opcion 1
void Empresa::Buscar_Viaje() {
    limpiar();//Limpiamos la Pantalla
    TipoEntero eleccion; //Llamamos a una variable entero la eleccion del jugador
    cout<<"Como desea buscar su viaje : "<<endl;//Eleccion para que pueda buscar el viaje
    cout<<"1. Por Nombre de Viaje"<<endl;//Por nombre
    cout<<"2. Por Numero de Viaje"<<endl;//Por numero de viaje
    cout<<"Ingrese la opcion de busqueda (Numero): ";cin>>eleccion;//Ingrese la opcion puede ser 1 o 2
    switch (eleccion){//Recorremos la eleccion
        case 1:this->Buscar_Viaje_Nombre();break;//Si en caso es 1, vamos a la funcion, buscar viaje por nombre
        case 2:this->Buscar_Viaje_Numero_Viaje();break;//Si en caso es 2, vamos a la funcion buscar por numero de viaje
        default:break;//Si en caso es ningun sale
    }
    //Finalmente limpimos la pantalla
    limpiar();
}
//Funcion Buscar Cliente de la opcion 2
void Empresa::Buscar_Cliente() {
    limpiar();
    TipoString nombre;//Crear la variable buscar cliente
    cout<<"Ingrese el Nombre del Cliente (Texto): ";cin>>nombre;//Almacena el nombre del cliente con espacios
    Cliente *cliente_encontrado = get_cliente(nombre); //buscamos el cliente, con nuestra funcion get cliente, le pasamos como parametro el nombre ingreaso
    if(cliente_encontrado == nullptr){//Verificamos si es un puntero vacio osea de que ha encontrado un cliente
        cout<<"No se ha podido encontrar el cliente con ese nombre";//No se ha podido encontrar un cliente con ese nombre
    }else{
        cliente_encontrado->informacion_cliente();//el objeto de la clase cliente tiene como metodo la funcion mostrar su informacion
    }
    system("pause");
    limpiar();
}
//Funcion de la opcion 3
void Empresa::Buscar_Transporte() {
    limpiar();
    TipoString nombre_transporte;
    cout<<"Buscar Transporte: ";
    cout<<"Ingrese el nombre del tranporte (Texto): ";cin>>nombre_transporte;//Se guarda el nombre del transporte
    Transporte *transporte = get_Transporte_Nombre(nombre_transporte);//Llamamos a la funcion para que nos retorne el transporte, caso contrario nos retonara un puntero vacio
    if(transporte == nullptr){//Si en caso no se ha encontrado la funcion
        cout<<"No existe un tranporte con ese nombre "<<endl;//no existe el tranporte ya que la funcion retorno un puntero vacio
    }else{
        transporte->informacion_transporte();//El objeto tranporte tiene un atributo llamado informacion, mostrara la infomacion
    }
    system("pause");
    limpiar();
}
//Funcion de la opcion 4
void Empresa::Agregar_viaje() {
    limpiar();
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"|      Creacion de un Viaje   |"<<endl;
    cout<<"-------------------------------"<<endl;
    TipoString nombre_viaje;
    cout<<"Nombre del Viaje (Texto): ";cin>>nombre_viaje;//Guarda el nombre del viaje
    while(encontro_viaje_nombre(nombre_viaje)){//LLama a la funcion para ver si ha encontrado un nombre relacionado con ese nombre que se pasa como parametro
        cout<<"Nombre de viaje ya existe, escoja otro nombre"<<endl;//Entrara al while si es que ese nombre ya se repite y mostrara ete mensaje
        cout<<"Nombre del Viaje (Texto): ";
        cin>>nombre_viaje;
    }
    cout<<"-------------------------------"<<endl;
    //Verifica el numero del viaje y que no se repita sino pedira nuevamente
    TipoEntero numero_viaje;//Crear el numero del Viaje
    cout<<"Numero de Viaje (Numero): ";cin>>numero_viaje;
    while(encontro_viaje_numero(numero_viaje)){//Lama a la funcion que retornara un true, si en caso se encuentra un viaje con ese numero de viaje, osea que ya existe
        cout<<"Numero de viaje ya existe, escoja otro numero de viaje"<<endl;//Dice que el numero de viaje ya existe
        cout<<"Numero de Viaje (Numero): ";cin>>numero_viaje;//Pedira nuevamente el numero de viaje, volvera al while para poder verficar
    }
    cout<<"-------------------------------"<<endl;
    Transporte *transporte = nullptr;//Creamos el transporte
    cout<<"          Transporte           "<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Elija una opcion : "<<endl;
    cout<<"-------------------------------"<<endl;

    while(true){
        TipoEntero eleccion_transporte;
        //Se mostrararan todos los transportes relacionados a la empresa, transportes ya existentes
        for(TipoEntero i=0;i<Transportes.size();i++){
            cout<<i+1<<". "<<Transportes[i]->get_Tipo_Transporte()<<" : "<<Transportes[i]->get_Nombre(); //Se imprimen las opciones, i+1 poque comienza con 0
        }
        cout<<Transportes.size()+1<<". Crear un Nuevo Transporte"<<endl;//Como ultima opcion tenemos a crear un nuevo transporte
        cout<<"-------------------------------"<<endl;
        cout<<"Ingrese la opcion (Numero): ";cin>>eleccion_transporte;
        cout<<"-------------------------------"<<endl;

        if(eleccion_transporte>0 && eleccion_transporte<=Transportes.size()){//Si en caso esta dentro del rango
            transporte = Transportes[eleccion_transporte-1];//Transporte apunta a donde apunta el tranporte de la opcion que ingreso
            break;
        }else if(eleccion_transporte == Transportes.size()+1){ //Si en caso selecciona la utlima opcion
            TipoString tipo_transporte_nuevo, nombre_transporte_nuevo;//Variables para poder crear el transporte nuevo
            TipoEntero numero_asientos_transporte_nuevo;//variable del numero de asientos del tranporte
            TipoBoleano disponible_transporte_nuevo;
            //Creamos el nuevo transporte
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"Ingrese el tipo de Transporte (Texto): ";cin>>tipo_transporte_nuevo;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"Ingrese el nombre del transporte (Texto) :  ";cin>>nombre_transporte_nuevo;
            while(encontro_transporte_nombre(nombre_transporte_nuevo)){
                cout<<"Ya existe un transporte con este nombre"<<endl;//Ya existe el transporte con este nombre
                cout<<"Ingrese el nombre del transporte : ";cin>>nombre_transporte_nuevo;//El nombre del transporte se guarda
            }
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"Ingrese el numero de asientos (Numero): ";cin>>numero_asientos_transporte_nuevo;//Se almacena el numero de asientos
            cout<<"-----------------------------------------------------------"<<endl;
            TipoBoleano eleccion_disponible_transporte_nuevo;//si en caso o no el transporte no esta disponible , se guardara aca
            do {
                cout << "El transporte esta disponible : " << endl;
                cout << "1. Si" << endl;
                cout << "2. NO" << endl;
                cout << "Ingrese la opcion (Numero) : ";cin>>eleccion_disponible_transporte_nuevo;
            }while(eleccion_disponible_transporte_nuevo<1 || eleccion_disponible_transporte_nuevo>2);
            cout<<"-----------------------------------------------------------"<<endl;

            if(eleccion_disponible_transporte_nuevo == 1){//Si en caso la eleccion que elejiste es 1
                disponible_transporte_nuevo = true;//Entonces, el tranporte si esta disponible
            }else{
                disponible_transporte_nuevo = false;
            }
            //Se crea un transporte llenando como esta en el constructos
            auto * transporte1 = new Transporte(nombre_transporte_nuevo, numero_asientos_transporte_nuevo, disponible_transporte_nuevo, tipo_transporte_nuevo);
            transporte = transporte1;//La variable transporte es igual al transporte1, osea el nuevo objeto que recien hemos creado
            Transportes.push_back(transporte1);
            break;
        }
    }


    //Creamos el lugar de partida
    vector<Lugar*> lugares_partida = Lugares; //Copiamos los lugares de partida para poder ver que lugar desea colocar
    TipoEntero posicion_lugar_partida;
    Lugar * lugar_partida = nullptr;
    while(true){
        cout<<"-----------------------"<<endl;
        cout<<"    Lugar de Partida  "<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"Seleccione la opcion que desee."<<endl;
        cout<<"-----------------------"<<endl;
        TipoEntero eleccion_lugar;
        for(TipoEntero i=0;i<lugares_partida.size();i++){
            cout<<i+1<<". "<<lugares_partida[i]->get_Nombre()<<endl;
        }
        cout<<Lugares.size()+1<<". Crear nuevo Lugar"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Ingrese la opcion (Numero): ";cin>>eleccion_lugar;
        cout<<"--------------------------"<<endl;
        //Si en caso se encuentra dentro de las opciones disponibles del lugar
        if(eleccion_lugar>0 && eleccion_lugar<=Lugares.size()){//Si esta dentro del lugar
            posicion_lugar_partida = eleccion_lugar - 1;//La posicion del lugar en el vector es la elccion -1
            lugar_partida = lugares_partida[posicion_lugar_partida];//Llamamos a nuestro vector y le qutamos esa posicion para que no se habilite en el otro
            lugares_partida.erase(lugares_partida.begin() + posicion_lugar_partida);//Se elimina la poscion en donde se encuentra la posicion
            break;
        }else if(eleccion_lugar == lugares_partida.size() + 1){
            TipoString nuevo_lugar_nombre;//variable que almaena el nombre del lugar
            cout<<"--------------------------"<<endl;
            cout<<"| Creacion de un Lugar   |"<<endl;
            cout<<"--------------------------"<<endl;
            cout<<"Ingrese el nuevo lugar (Texto) : ";cin>>nuevo_lugar_nombre;//Inrese el nuevo lugar se almacenara en la variable
            while(encontro_Lugar_nombre(nuevo_lugar_nombre)){ //entrara al while siempre y cuando el nombre del lugar ya existe
                cout<<"Nombre del lugar ya existe"<<endl;
                cout<<"Ingrese el nombre del nuevo lugar (Texto): ";cin>>nuevo_lugar_nombre;//Se almacena en la variable nombre del lugar
            }
            auto * lugar1 = new Lugar(nuevo_lugar_nombre); //Se crea un nuevo lugar
            lugar_partida = lugar1; //El lugar de la partida es igual a ese puntero
            Lugares.push_back(lugar1);//A lugares se le agrega el nuevo objeto del lugar partida
            cout<<"--------------------------"<<endl;
            break;
        }
    }

    Lugar* lugar_llegada = nullptr;//lugar de la llegada es un puntero de la clase lugar
    //Creamos el siguiente lugar de la partida
    while (true){
        cout<<"--------------------------"<<endl;
        cout<<"|    Lugar de LLegada    |"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Ingrese la opcion que desee :"<<endl;
        cout<<"--------------------------"<<endl;
        TipoEntero eleccion_numero;
        for(TipoEntero i=0;i<lugares_partida.size();i++){//Se mostraran todas las opciones posibles
            cout<<i+1<<". "<<lugares_partida[i]->get_Nombre()<<endl;//Se muestran todas las opciones
        }
        cout<<lugares_partida.size() + 1<<". Crear nuevo lugar"<<endl;//Como ultima opcion se pone el crear una partida
        cout<<"--------------------------"<<endl;
        cout<<"Ingrese una opcion (Numero): ";cin>>eleccion_numero;
        cout<<"--------------------------"<<endl;
        if(eleccion_numero>0 && eleccion_numero <= lugares_partida.size()){//Si en caso ingresa uno de las opciones de los lugares
            lugar_llegada = lugares_partida[eleccion_numero-1];//lugar llegada sera igual a ese puntero
            break;
        }else if(eleccion_numero == lugares_partida.size()+1){//Si en caso ingresa la ultima opcion
            cout<<"--------------------------"<<endl;
            cout<<"|    Creacion del Lugar  |"<<endl;//Creacion del lugar
            cout<<"--------------------------"<<endl;
            TipoString nombre_lugar;
            cout<<"--------------------------"<<endl;
            cout<<"Nombre del Lugar (Texto): ";cin>>nombre_lugar;
            while(encontro_Lugar_nombre(nombre_lugar)){//Si en caso encontro el lugar
                cout<<"Error, nombre ya existe"<<endl;
                cout<<"Nombre del Lugar (Texto): ";cin>>nombre_lugar;//Pedira de nuevo que ingrese el nombre del lugar
            }
            auto *lugar = new Lugar(nombre_lugar);//Se crea un nuevo objeto de clase lugar, con el constructor
            lugar_llegada = lugar;//lugar llegada es igual al nuevo puntero objeto
            cout<<"--------------------------"<<endl;
            break;
        }
    }
    //Precio base
    TipoDecimal precio_base;
    cout<<"--------------------------"<<endl;
    cout<<"Precio base (S/.) : ";cin>>precio_base;//Se guarda el precio base
    TipoDecimal porcentaje_primera_clase;
    cout<<"--------------------------"<<endl;
    cout<<"Porcentaje de la primera clase (+%) : ";cin>>porcentaje_primera_clase; //Porcentaje de la primera clase
    TipoDecimal porcentaje_turista;
    cout<<"--------------------------"<<endl;
    cout<<"Porcentaje de la clase turista (+%)";cin>>porcentaje_turista;//Porcentaje del turista
    while(porcentaje_turista > porcentaje_primera_clase){//Verifica que el porcentaje adicional del turista siempre tiene que ser menos
        cout<<"Error, el porcentaje turista no puede ser mayor."<<endl;
        cout<<"Porcentaje de la clase turista (+%)";cin>>porcentaje_turista;//Porcentaje de la clase turista
    }
    TipoString fecha;
    cout<<"--------------------------"<<endl;
    cout<<"Ingrese la fecha ejm(dia/mes/anio)";cin>>fecha;//Se almaena la fecha
    cout<<"--------------------------"<<endl;
    //Se creea el viaje con el gran constructor de la clase Viaje
    auto * viaje = new Viaje(nombre_viaje, numero_viaje, transporte, lugar_partida, lugar_llegada, precio_base, porcentaje_primera_clase, porcentaje_turista, fecha);
    viajes.push_back(viaje);//Se le agrega el viaje al vector de viajes
    system("pause");
    limpiar();
}

void Empresa::Agregar_Cliente() {
    limpiar();
    TipoString nombre_cliente;
    cout<<"Nombre del Cliente : ";getline(cin,nombre_cliente);//Pide el nombre del cliente y lo guarda
    while(encontro_cliente_nombre(nombre_cliente)){//Si en caso el nombre del cliente se encuentra dentro del sistema
        cout<<"Error, nombre de cliente ya existe "<<endl;
        cout<<"Nombre del Cliente (Texto): ";cin>>nombre_cliente;//Se guaada el nombre del cliente
    }
    TipoString dni;
    //Verifica si el dni ya existe
    cout<<"DNI : ";getline(cin, dni);
    while(encontro_cliente_dni(dni)){
        cout<<"Error, ya existe un cliente con este DNI"<<endl;
        cout<<"DNI (Texto): ";getline(cin, dni);
    }
    TipoString apellidos;
    cout<<"Apellidos :";getline(cin, apellidos);//Se almacena los apellido del cliente
    Tipocaracter genero;
    cout<<"Genero (M F): ";cin>>genero;
    //Se crea un nuevo cliente, con el constructor del cliente
    auto *cliente = new Cliente(dni, nombre_cliente, apellidos, genero);
    //Se le agrega al vector de clientes, el nuevo objeto que hemos creado
    clientes.push_back(cliente);
    limpiar();
}

void Empresa::Agregar_Varios_Clientes() {
    limpiar();
    while(true){
        TipoString eleccion;
        cout<<"Desea Continuar : "<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. No"<<endl;
        cout<<"Opcion : ";cin>>eleccion;
        if(eleccion == "1"){//Si en caso selecciona 1 sale de la creacion de varios clientes
            break;
        }
        limpiar();
        Agregar_Cliente();
        limpiar();
    }
    system("pause");
    limpiar();
}

void Empresa::Agregar_Transporte() {
    limpiar();
    cout<<"Creacion del Transporte";
    TipoString nombre, tipo;
    TipoEntero numero_asientos;
    TipoBoleano disponible;
    TipoString disponible_str;
    cout<<"Nombre del Transporte (Texto): ";getline(cin, nombre);
    while (encontro_transporte_nombre(nombre)){
        cout<<"Error ya existe un transporte con este nombre"<<endl;
        cout<<"Nombre del Transporte (Texto): ";getline(cin, nombre);
    }
    cout<<"Tipo de Transporte (Texto): ";getline(cin, tipo);
    cout<<"Numero de Asientos (Numero): ";cin>>numero_asientos;
    cout<<"Disponible (si no) : ";cin>>disponible_str;
    if(disponible_str == "si"){
        disponible = true;
    }else{
        disponible = false;
    }
    //Agrega el nuevo transporte con su constructor
    auto * transporte = new Transporte(nombre, numero_asientos, disponible,tipo);
    //Luego se agrega al vector transportes el objeto transporte
    Transportes.push_back(transporte);
    system("pause");
    limpiar();
}

void Empresa::Salir_Programa() {
    cout<<"Muchas Gracias.";
    system("pause");
    limpiar();
}

//-------------------------------------------------------------------
//Funciones que estan la opcion 1
void Empresa::Buscar_Viaje_Nombre() {
    limpiar();
    TipoString nombre_viaje;//Variable que almacenara el nombre del viaje
    cout<<"Ingrese el nombre del Viaje (Palabra): ";cin>>nombre_viaje; // Pedimos que ingrese el nombre del viaje a buscar
    Viaje * viaje1 = get_Viaje_por_Nombre(nombre_viaje); //viaje1 es un puntero de tipo Viaje, llama a la funcion a la funcion get viaje nombre que retorn un puntero de clase Viaje
    if(viaje1 == nullptr){//Significa que no encontro ningun objeto con ese nombre
        cout<<"No se encontraron viajes relacionados con ese Nombre"<<endl; //No se encontraron viajes relacionados con este Nombre
    }else{
        cout<<"Informacion del Viaje : "<<endl;//Me dira la informacion del viaje
        viaje1->imprimir_informacion_viaje();//viaje1 llama a su metodo imprimir informacion viaje
    }
    cout<<endl;//Salto de linea
    system("pause");//System pause para poder continuar
    limpiar();//Por ultimo limpiamos la pantalla
}
//funcion get viaje nombre, que retorna un objeto de clase Viaje, un puntero
Viaje *Empresa::get_Viaje_por_Nombre(TipoString nombre_viaje) {
    for(auto &viaje:viajes){//Recorrera toda el vector de viaje
        if(viaje->get_Nombre() == nombre_viaje){//Verifica si el viaje es igual al nombre del viaje que le hemos enviado como parametro
            return viaje; //retorna el ojeto como tal si en caso encuentra un nombre
        }
    }
    return nullptr;//Retorna el objeto vacio, si en caso no encontro nigun objeto.
}

void Empresa::Buscar_Viaje_Numero_Viaje() {
    limpiar();
    TipoEntero numero_viaje; //Numero de viaje es un numero entero
    cout<<"Ingrese el numero del Viaje (Numero): ";cin>>numero_viaje;//Ingrese el numero de viaje para poder buscarlo
    Viaje * viaje1 = get_Viaje_por_Numero_Viaje(numero_viaje); //Llamamos a la funcion, para que nos retorne un puntero si en caso lo encuentre
    if(viaje1 == nullptr){//Significa que no encontro ningun objeot con ese nombre
        cout<<"No se encontro el viaje relacionado con ese Numero de Viaje"<<endl;//Imprimira que no se encontro ninun viaje relacionado
    }else{
        cout<<"Inforacion del Viaje : "<<endl;//Mostrara la informacion del viaje
        viaje1->imprimir_informacion_viaje();//el puntero llama a su metodo para que pueda imprimir los datos
    }
    cout<<endl;
    system("pause");
    limpiar();

}
Viaje *Empresa::get_Viaje_por_Numero_Viaje(TipoEntero Numero_Viaje) {
    for(auto &viaje:viajes){ //Recorre el vector viajes, que almacena todos los viajes disponibles
        if(viaje->get_Numero_Viaje() == Numero_Viaje){ //Luego el puntero viaje llama a su metodo get metodo de numero de viaje, verifica si es el mismo que se agrego
            return viaje;//Retorna el objero viaje
        }
    }
    return nullptr;//Retorna el objeto nullptr si en caso no encontro nada
}
//--------------------------------------------------------------------

//Funciones de la opcion 2
Cliente *Empresa::get_cliente(TipoString nombre_cliente) {
    for(auto &cliente:clientes){
        if(cliente->GetNombre() == nombre_cliente){
            return cliente;
        }
    }
    return nullptr;
}
Transporte *Empresa::get_Transporte_Nombre(TipoString Nombre_transporte_) {
    for(auto &transporte : Transportes){
        if(transporte->get_Nombre() == Nombre_transporte_){
            return transporte;
        }
    }
    return nullptr;
}
//--------------------------------------------------------------------
//Funciones la opcion 3

void Empresa::Ver_Transportes() {
    TipoBoleano regresar_menu =false;
    while(!regresar_menu) {
        TipoEntero eleccion;
        cout << "Transportes : " << endl;
        cout << "1. Transportes Disponibles" << endl;
        cout << "2. Transportes no Diponibles" << endl;
        cout << "3. Ver todos los transportes" << endl;
        cout << "4. Regresar al Menu" << endl;
        cout << "Ingrese una opcion : " << endl;cin>>eleccion;
        switch (eleccion){
            case 1: ver_Transportes_Disponibles();break;
            case 2: ver_Transportes_No_Disponibles();break;
            case 3: ver_Todos_Los_Transportes();break;
            case 4: regresar_menu=true;break;
            default:regresar_menu=true;break;
        }
    }
}

void Empresa::ver_Todos_Los_Transportes() {
    if(Transportes.size() == 0){//Vemos si el vector de transportes esta vacio
        cout<<"No hay transportes."<<endl;//Si en caso esta vacio mostrarara que no hay transportes
    }else{
        cout<<"Total de Transportes : "<<this->Transportes.size()<<endl;//La dimension de trasnportes
        for(auto &transporte :Transportes){
            transporte->informacion_transporte();
        }
    }
}

void Empresa::ver_Transportes_Disponibles() {
    vector<Transporte*> transportes_disponibles = get_Transportes_Disponibles();
    if(transportes_disponibles.size() == 0){
        cout<<"No hay transportes disponibles."<<endl;
    }else{
        cout<<"Transportes Disponibles : ";
        cout<<"Total de transportes disponibles : "<<transportes_disponibles.size()<<endl;
        for(auto &transporte : Transportes){
            transporte->informacion_transporte();
        }
    }

}

vector<Transporte *> Empresa::get_Transportes_Disponibles() {
    vector<Transporte*> transportes_vector; //Vector nuevo de transportes
    for(auto &transporte : Transportes){//Recorremos el vector de transportes
        if(transporte->get_Disponible()){//si esta disponible
            transportes_vector.push_back(transporte);//Se agregara el transporte al nuevo vector
        }
    }
    return transportes_vector;//Retornamos el nuevo vector, el nuevo, donde estan los transportes diponibles
}

vector<Transporte *> Empresa::get_Transportes_no_Disponibles() {
    vector<Transporte*>vector_transporte;
    for(auto &transporte : Transportes){
        if(!transporte->get_Disponible()){//Lo niega para que pueda entrar al if, cuando encuentre un tranporte que no esta disponible y lo agregara al nuevo vector
            vector_transporte.push_back(transporte);
        }
    }
    return vector_transporte;
}

void Empresa::ver_Transportes_No_Disponibles() {
    vector<Transporte*> transportes_no_disponibles = get_Transportes_no_Disponibles();
    if(transportes_no_disponibles.size() == 0){
        cout<<"No hay transportes no disponibles";
    }else {
        cout<<"Transportes no Disponibles : "<<endl;
        cout<<"El numero de transportes disponibles es : "<<transportes_no_disponibles.size()<<endl;
        for (auto &transporte : transportes_no_disponibles) {
            transporte->informacion_transporte();
        }
    }
}





TipoBoleano Empresa::encontro_viaje_nombre(TipoString nombre_viaje) {
    for(auto &viaje :viajes){
        if(viaje->get_Nombre() == nombre_viaje){
            return true;
        }
    }
    return false;
}

TipoBoleano Empresa::encontro_viaje_numero(TipoEntero numero_viaje) {
    for(auto &viaje:viajes){
        if(viaje->get_Numero_Viaje() == numero_viaje){
            return true;
        }
    }
    return false;
}

TipoBoleano Empresa::encontro_transporte_nombre(TipoString nombre_transporte_) {
    for(auto &transporte : Transportes){
        if(transporte->get_Nombre() == nombre_transporte_){
            return true;
        }
    }
    return false;
}

TipoBoleano Empresa::encontro_Lugar_nombre(TipoString nombre_lugar) {
    for(auto &lugar: Lugares){
        if(lugar->get_Nombre() == nombre_lugar){
            return true;
        }
    }
    return false;
}

TipoBoleano Empresa::encontro_Lugar_nombre(TipoString nombre_lugar, vector<Lugar *> vector_lugar) {
    for(auto &lugar : vector_lugar){
        if(lugar->get_Nombre() == nombre_lugar) {
            return true;
        }
    }
    return false;
}


TipoBoleano Empresa::encontro_cliente_nombre(TipoString nombre_cliente) {
    for(auto &cliente : clientes){
        if(cliente->GetNombre() == nombre_cliente){
            return true;
        }
    }
    return false;
}

TipoBoleano Empresa::encontro_cliente_dni(TipoString dni) {
    for(auto &cl : clientes){
        if(cl->GetDni() == dni){
            return true;
        }
    }
    return false;
}

void Empresa::Realizar_Viaje() {
    limpiar();
    string nombre;
    cout<<"Ingrese el nombre del viaje a buscar : ";cin>>nombre;//Ingresa el nombre del viaje a poder buscar
    Viaje *viaje1 = nullptr;
    for(auto &viaje : viajes){//recorre todos los viajes del programa y busca cual de todos tiene relacion con el nombre que se envio
        if(viaje->get_Nombre() == nombre){//Si en caso hay uno que tenga el mismo nombre
            viaje1 = viaje;//Obtenemos la direccion de ese puntero
            break;
        }
    }
    if(viaje1 == nullptr){//Si en caso el puntero no apunta a nada, es porque no se pudo haber encontrado
        cout<<"Viaje no Encontrado."<<endl;//El programa nos dira que no se pudo haber encontrado
    }else{
        if(viaje1->get_realizado()){//si en caso el viaje ya ha sido realizado , me diran de que ya se realizo el viaje
            cout<<"Viaje ya realizado"<<endl;//El viaje ya ha sido realizado
        }else{//Caso contrario
            viaje1->realizar_viaje(clientes);//Se realiza el viaje
            cout<<"Viaje Realizado con exito "<<endl;//Luego dira de que el viaje fue correcto
        }
    }
    system("pause");
    limpiar();
}

void Empresa::Ver_Viajes_Realizados() {
    limpiar();
    cout<<"------------------------"<<endl;
    cout<<"|   Viajes Realizados   |"<<endl;
    cout<<"------------------------"<<endl;
    TipoBoleano existe_viajes_realizados = false;//al principio dira que no hay viajes realizados
    for(auto &vi : viajes){//Recorremos todos los viajes y vemos si al menos hay uno
        if(vi->get_realizado()){//Vemos si el objeto de ahora ha sido realizado
            //Si en caso ha sido relizado mostrara de que si
            existe_viajes_realizados = true;
            break;
        }
    }
    if(existe_viajes_realizados){//Si en caso existen viajes realizados
        TipoEntero contador = 0;
        for(auto &vi : viajes){
            if(vi->get_realizado()) {
                cout << contador + 1 << ". Nombre : " << vi->get_Nombre()
                     << endl;//Se pondran todos los viajes que no han sido realizados
                contador++;
            }
        }
    }else{
        cout<<"No existen viajes relizados"<<endl;
    }
    system("pause");
    limpiar();
}

void Empresa::Ver_Viajes_Pendientes() {
    limpiar();
    cout<<"------------------------"<<endl;
    cout<<"|   Viajes Pendientes   |"<<endl;
    cout<<"------------------------"<<endl;
    TipoBoleano existe_viajes_pendientes = false;//al principio dira que no hay viajes pendientes
    for(auto &vi : viajes){//Recorremos todos los viajes y vemos si al menos hay uno que esta pendiente
        if(!vi->get_realizado()){//Vemos si el objeto de ahora es pendiente, se niega el get realizado
            //Si en caso ha sido relizado mostrara de que si
            existe_viajes_pendientes = true;
            break;
        }
    }
    if(existe_viajes_pendientes){//Si en caso existen viajes pendientes
        TipoEntero contador = 0;
        for(auto &vi : viajes){//Recorremos el vector
            if(!vi->get_realizado()) {//comprobamos que el objeto este pendiente, para eos tenemos que negar el get realizadp
                cout << contador + 1 << ". Nombre : " << vi->get_Nombre()
                     << endl;//Se pondran todos los viajes que no han sido pendientes
                contador++;
            }
        }
    }else{
        cout<<"No existen viajes pendientes"<<endl;
    }
    system("pause");
    limpiar();
}

void Empresa::Ver_Lugares() {
    limpiar();
    cout<<"--------------"<<endl;
    cout<<"|   Lugares   |"<<endl;
    cout<<"--------------"<<endl;
    if(Lugares.size() == 0){
        cout<<"No existen lugares";
    }else{
        TipoEntero contador = 0;//COntador inicializado en 0
        for(auto &lu :Lugares){//Recorremos los lugares
            cout<<contador+1<<". "<<lu->get_Nombre()<<endl;//Se muestran todo slos lugares , llamando a su metodo get nombre
            contador ++;//contado se aumenta en 1
        }
    }
    system("pause");
    limpiar();
}

void Empresa::Agregar_Lugares() {
    limpiar();
    cout<<"Agregar Lugar"<<endl;
    TipoString lugar_nombre;
    cout<<"Ingrese el nombre del lugar (Texto): ";cin>>lugar_nombre;//Pedimos y almacenamos el nombre del nuevo lugar
    while(encontro_Lugar_nombre(lugar_nombre)){//Pedira siempre y cuando el nombre ya exista
        cout<<"Error, el nombre ya existe "<<endl;
        cout<<"Ingrese el nombre del lugar (Texto): ";cin>>lugar_nombre;//Pide de nuevo datos, del nombre del nuevo lugar
    }
    auto *lugar = new Lugar(lugar_nombre);//Nuevo objeto de la clase lugar
    Lugares.push_back(lugar);//Se le agrega al vector lugares el nuevo lugar
    system("pause");
    limpiar();
}

void Empresa::Agregar_Pasajes_Viaje() {
    limpiar();
    TipoString nombre_viaje;
    cout<<"Ingrese el nombre del viaje (Texto): ";cin>>nombre_viaje;//Pide el nombre del viaje que desea agregar
    Viaje * viaje =get_Viaje_por_Nombre(nombre_viaje);//la funcion retorna un objeto, en caso de que no se encuentre el nombre, retorna un nullptr
    if(viaje == nullptr){//En caso que no apunte a ningun lado
        cout<<"No existe el viaje a buscar ";//No existe el viaje a buscar debido a que no lo encontro
    }else{
        while(true){//Se repite siempre
            TipoString eleccion;
            cout<<"Desea Salir : "<<endl;//Desea salir si o no
            cout<<"1. Si"<<endl;
            cout<<"2. No"<<endl;
            cout<<"Opcion : ";cin>>eleccion;
            if(eleccion == "2"){//Si en caso es no se agregara
                viaje->agregar_pasajes(clientes);
            }else{
                break;
            }
        }
    }
    system("pause");
    limpiar();
}
