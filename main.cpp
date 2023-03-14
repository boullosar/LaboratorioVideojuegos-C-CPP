
#include <iostream>
#include <ctime>
#include "string.h"
#include "DtFechaHora.h"
#include "DtCategoria.h"
#include "DtVideojuegoIngresado.h"
#include "DtVideojuegoFull.h"
#include "DtVideojuego.h"
#include "DtSuscripciones.h"
#include "DtVideojuegoRanking.h"
#include "DtPartida.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "TipoPago.h"
#include "IControladorAltaUsuario.h"
#include "IControladorIniciarSesion.h"
#include "IControladorCerrarSesion.h"
#include "IControladorAgregarCategoria.h"
#include "IControladorAgregarVideojuego.h"
#include "IControladorSuscribirseVideojuego.h"
#include "IControladorIniciarPartida.h"
#include "IControladorVerInfoVideojuego.h"
#include "IControladorEliminarVideojuego.h"
#include "IControladorAsignarPuntajeVideojuego.h"
#include "IControladorVerPartidasVideojuego.h"
#include "IControladorRankingVideojuegos.h"
#include "IControladorAuxiliar.h"
#include "IControladorBuscarVideojuego.h"
#include "IControladorCancelarSuscripcionVideojuego.h"
#include "Fabrica.h"

using namespace std;

Fabrica* fabrica;
IControladorAltaUsuario* iConAltaUsuario;
IControladorIniciarSesion* iConIniciarSesion;
IControladorCerrarSesion* iConCerrarSesion;
IControladorAgregarCategoria* iConAgregarCategoria;
IControladorAgregarVideojuego* iConAgregarVideojuego;
IControladorSuscribirseVideojuego* iConSuscribirseVideojuego;
IControladorIniciarPartida* iConIniciarPartida;
IControladorVerInfoVideojuego* iConVerInfoVideojuego;
IControladorEliminarVideojuego* iConEliminarVideojuego;
IControladorAsignarPuntajeVideojuego* iConAsignarPuntajeVideojuego;
IControladorVerPartidasVideojuego* IConVerPartidasVideojuego;
IControladorRankingVideojuegos* IConRankingVideojuegos;
IControladorAuxiliar* iConAuxiliar;
IControladorBuscarVideojuego* iConBusVid;
IControladorCancelarSuscripicionVideojuego* iConCancelarSuscripcionaVideojuego;


void aniadirDatos();
DtFechaHora* fechaHoraActual();

void altaUsuario();
bool iniciarSesion();
void cerrarSesion();
void agregarCategoria();
void agregarVideojuego();
void suscribirseVideojuego();
void iniciarPartida();
void verInfoVideojuegos();
void eliminarVideojuego();
void asignarPuntaje();
void verPartidasVideojuego();
void rankingVideojuegos();
void cancelarSuscripcionAVideojuego();
void buscarVideojuego();

int main(){
	fabrica = Fabrica::getInstancia();
    iConAltaUsuario = fabrica->getControladorAltaUsuario();
    iConIniciarSesion = fabrica->getControladorIniciarSesion();
    iConCerrarSesion = fabrica->getControladorCerrarSesion();
    iConAgregarCategoria = fabrica->getControladorAgregarCategoria();
    iConAgregarVideojuego = fabrica->getControladorAgregarVideojuego();
    iConSuscribirseVideojuego = fabrica->getControladorSuscribirseVideojuego();
    iConIniciarPartida = fabrica->getControladorIniciarPartida();
    iConVerInfoVideojuego = fabrica->getControladorVerInfoVideojuego();
    iConEliminarVideojuego = fabrica->getControladorEliminarVideojuego();
    iConAsignarPuntajeVideojuego = fabrica->getControladorAsignarPuntajeVideojuego();
    IConVerPartidasVideojuego = fabrica->getControladorVerPartidasVideojuego();
    IConRankingVideojuegos = fabrica->getControladorRankingVideojuegos();
    iConAuxiliar = fabrica->getControladorAuxiliar();
    iConBusVid = fabrica->getControladorBuscarVideojuego();
    iConCancelarSuscripcionaVideojuego = fabrica->getControladorCancelarSuscripcionAVideojuego();
    
    aniadirDatos();

    int opcion;
    bool exit = false;
    bool sesion = false;
    bool inicio = false;
    while (!exit && !sesion)  
    {
        cout << "_________________MENU INICIAL____________________" << endl;
        cout << endl;
        cout << "1 - Alta usuario" << endl;
        cout << "2 - Iniciar sesión" << endl;
        cout << "3 - Salir" << endl;
        cout << "_________________________________________________" << endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                altaUsuario();
                break;
            case 2:
                inicio = iniciarSesion();
                if(inicio)
                    sesion = true;
                break;
            case 3:
                exit = true;
                break;
        }
        if(!exit && iConAuxiliar->esDesarrollador()==3){
            while (sesion){
                cout << "________________MENÚ JUGADOR_____________________" << endl;
                cout << endl;
                cout << "1 - Suscribirse a videojuego" << endl;//jugador
                cout << "2 - Iniciar partida" << endl;//jugador
                cout << "3 - Ver información de videojuego" << endl;//usuario
                cout << "4 - Asignar puntaje a videojuego" << endl;//jugador opcional
                cout << "5 - Cancelar suscripcion a videojuego" << endl;//jugador opcional
                cout << "6 - Buscar videojuego por categoría" << endl;//usuario opcional
                cout << "7 - Cerrar sesión" << endl;
                cout << "8 - Salir" << endl;
                cout << "_________________________________________________" << endl;
                cout << "\n Elija una opción" << endl;
                cin >> opcion;
                switch (opcion){
                    case 1:
                        suscribirseVideojuego();
                        break;
    
                    case 2:
                        iniciarPartida();
                        break;
    
                    case 3:
                        verInfoVideojuegos();
                        break;
    
                    case 4:
                        asignarPuntaje();
                        break;
                    
                    case 5:
                        cancelarSuscripcionAVideojuego();
                        break;
    
                    case 6:
                        buscarVideojuego();
                        break;
                    
                    case 7:
                        cerrarSesion();
                        sesion = false;
                        break;
    
                    case 8:
                        sesion = false;
                        exit = true;
                        break;
    
                }
            }
        }
        else if (!exit && iConAuxiliar->esDesarrollador()==2){
            while (sesion){
                cout << "_______________MENU DESARROLLADOR__________________" << endl;
                cout << endl;
                cout << "1 - Agregar categoría" << endl;//desarrollador
                cout << "2 - Agregar videojuego" << endl;//desarrollador
                cout << "3 - Ver información de videojuego" << endl;//usuario
                cout << "4 - Eliminar videojuego" << endl;//desarrollador
                cout << "5 - Buscar videojuego por categoría" << endl;//usuario opcional
                cout << "6 - Ranking de videojuego" << endl;//desarrollador opcional
                cout << "7 - Ver partidas de un videojuego" << endl;//desarrollador opcional
                cout << "8 - Cerrar sesión" << endl;
                cout << "9 - Salir" << endl;
                cout << "___________________________________________________" << endl;
                cout << "\n Elija una opción" << endl;
                cin >> opcion;
                switch (opcion){
                    case 1:
                        agregarCategoria();
                        break;
    
                    case 2:
                        agregarVideojuego();
                        break;
    
                    case 3:
                        verInfoVideojuegos();
                        break;
    
                    case 4:
                        eliminarVideojuego();
                        break;
                    
                    case 5:
                        buscarVideojuego();
                        break;
    
                    case 6:
                        rankingVideojuegos();
                        break;
                    
                    case 7:
                        verPartidasVideojuego();
                        break;

                    case 8:
                        cerrarSesion();
                        sesion = false;
                        break;
    
                    case 9:
                        sesion = false;
                        exit = true;
                        break;
    
                    default:
                        cout << "Opción incorrecta, por favor seleccione una opción de la lista" << endl;
                        opcion = 0;
                        break;
                }
            }
        }
    }
    cout << "Finalizando programa..." <<endl;
}

//operaciones

void altaUsuario(){
    string email, pass, nombre, nickname, descripcion;
    int opt;
    bool exist = true;
    cout << "Ingrese email:" << endl;
    cin >> email; 
    cout << "Ingrese contraseña:" << endl;
    cin >> pass; 
    try
    {        
        iConAltaUsuario->datosComunes(email, pass);

        cout << "¿Es jugador(1) o desarrollador(2)?" << endl;
        cin >> opt;
        if(opt == 1){
            cout << "Ingrese el nickname:" << endl;
            cin >> nickname;
            cout << "Ingrese la descripción:" << endl;
            cin >> descripcion;
            //Se llama a la función datosjugador de IControladorUsuario, con la variable exist 
            exist=iConAltaUsuario->datosJugador(nickname, descripcion);
            if(exist){
                cout << "El nickname ya existe. ¿Quiere volver a intentar? 1: Sí - 2: No" << endl;
                cin >> opt;
                if(opt == 1){
                    while(exist){
                        cout << "Ingrese el nickname:" << endl;
                        cin >> nickname;
                        //Se llama a la función datosjugador de IControladorUsuario, con la variable exist 
                        exist=iConAltaUsuario->ingresarNickname(nickname);
                    }
                }
                else if(opt == 2){
                    //Se llama a la función cancelar de IControladorUsuario
                    iConAltaUsuario->cancelar();
                }else{
                    throw invalid_argument("Opcion incorrecta");
                }
            }
        }
        else if(opt == 2){
            cout << "Ingrese el nombre de la empresa:" << endl;
            cin >> nombre;
            //Se llama a la función datosEmpresa de IControladorAltaUsuario
            iConAltaUsuario->datosEmpresa(nombre);
        }else{
            throw invalid_argument("Opcion incorrecta");
        }

        cout << "¿Confirmar(1) o cancelar(2)?" << endl;
        cin >> opt;
        if(opt == 1){
            //Se llama a la función altaUsuario de IControladorAltaUsuario
            iConAltaUsuario->altaUsuario();
        }
        else if (opt == 2){
            //Se llama a la función Cancelar de IControladorAltaUsuario
            iConAltaUsuario->cancelar();
        }else{
            throw invalid_argument("Opcion incorrecta");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool iniciarSesion(){
    string email, pass;
    bool exist = false;
    int opcion;
    cout << "Ingrese su email" <<endl;
    cin >> email;
    cout << "Ingrese su contraseña" <<endl;
    cin >> pass;

    exist = iConIniciarSesion->datosComunes(email, pass);
    if (exist)
    {
        iConIniciarSesion->iniciarSesion();
        return true;
    }else{
        cout << "¿desea reintentar?, 1 - Si | 2 - No" <<endl;
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "Ingrese su email" <<endl;
            cin >> email;
            cout << "Ingrese su contraseña" <<endl;
            cin >> pass;

            exist = iConIniciarSesion->datosComunes(email, pass);   
            if (exist)
            {
                iConIniciarSesion->iniciarSesion();
                return true;
            }else{
                cout << "No existe el usuario o los datos son incorrectos" <<endl;
            }
        }else if (opcion == 2){
            iConIniciarSesion->cancelar();
            return false;
        }else{
            cout << "Opcion incorrecta" <<endl;
        }
        return false;
    }
}

void cerrarSesion(){
    try
    {
        iConCerrarSesion->cerrarSesion();
    }
    catch(invalid_argument e)
    {
        std::cerr << e.what() << '\n';
    }
}

void agregarCategoria(){
    TipoGenero genero;
    TipoPlataforma plataforma;    
    int opt;
    int opcion1, opcion2;
    try
    {
        list<DtCategoria*> categorias = iConAgregarCategoria->listarCategorias();
        for (auto dtc : categorias) {
            cout << *dtc << endl;
        }
        //forma alternativa de hacer lo de arriba
        /*list<DtCategoria*>::iterator it = categorias.begin();
        for (it; it!=categorias.end(); ++it){
            cout << *(*it) <<endl;
        }*/
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        cout << endl;
        cout << "Seleccione un genero" <<endl;
        cout << "1 - ACCION, 2 - AVENTURA, 3 - ESTRATEGIA, 4 - DEPORTE" <<endl;
        cin >> opcion1;
        switch (opcion1)
        {
        case 1:
            genero = ACCION;
            break;
        case 2:
            genero = AVENTURA;
            break;
        case 3:
            genero = ESTRATEGIA;
            break;
        case 4:
            genero = DEPORTE;
            break;
        default:
            throw invalid_argument("Género incorrecto");
            break;
        }
        cout << "Seleccione una plataforma" <<endl;
        cout << "1 - PC, 2 - SWITCH, 3 - PS4, 4 - XBOX_ONE, 5 - XBOX_X, 6 - PS5"<<endl;
        cin >> opcion2;
        switch (opcion2)
        {
        case 1:
            plataforma = PC;
            break;
        case 2:
            plataforma = SWITCH;
            break;
        case 3:
            plataforma = PS4;
            break;
        case 4:
            plataforma = XBOX_ONE;
            break;
        case 5:
            plataforma = XBOX_X;
            break;
        case 6:
            plataforma = PS5;
            break;
        default:
            throw invalid_argument("Plataforma incorrecta");
            break;
        }
        iConAgregarCategoria->datosNuevaCategoria(genero,plataforma); 
        cout << "¿Confirmar(1) o cancelar(2)?" << endl;
        cin >> opt;
        if(opt == 1){
            iConAgregarCategoria->confirmarCategoria();
        }
        else if (opt == 2){
            iConAgregarCategoria->cancelar();
        }else{
            throw invalid_argument("Opcion incorrecta");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void agregarVideojuego(){
    string nombre;
    string descripcion;
    int costoSub, cont=1, auxCont=0;  
    list<DtCategoria*> categorias; 

    cout << "Ingrese el nombre del videojuego" <<endl;
    cin >> nombre;
    cout << "Ingrese la descripcion del videojuego" <<endl;
    cin >> descripcion;
    cout << "Ingrese el costo de suscripcion" <<endl;
    cin >> costoSub;

    try
    {
        iConAgregarVideojuego->ingresaDatosVideojuego(nombre, descripcion, costoSub);
        categorias = iConAgregarVideojuego->listarCategorias();
        cout << "Categorías: " << "\n" <<endl;
        list<DtCategoria*>::iterator it = categorias.begin();
        for(it; it!=categorias.end(); ++it){
            auxCont++;
            cout << auxCont << ":" << *(*it) << endl;
        }
        bool tieneCategoria = false;
        do{
            cout << "Seleccione una categoría, o presione 0 para continuar: " << endl;
            cin >> cont;
            if (categorias.size() < cont)
            {
                cout << "Debe seleccionar una categoria existente" <<endl;
            }else if (cont == 0 && !tieneCategoria)
            {
                cout << "Debe añadir un categoría como mínimo"<<endl;
            }else if(cont>0 && cont <= categorias.size()){
                list<DtCategoria*>::iterator it = categorias.begin();
                for(auxCont=1;auxCont<cont;auxCont++){
                    ++it;
                }
                iConAgregarVideojuego->seleccionaCategoria(*it);
                tieneCategoria = true;
            }
        }while(cont!=0 || !tieneCategoria);

        DtVideojuegoIngresado* dtvji = iConAgregarVideojuego->listarInfo();
        cout << *dtvji << endl;

        do{
            cout << "Confirma o cancela la operación? \n 1 - Confirmar \n 2 - Cancelar" << endl;
            cin >> cont;
            if(cont==1){
                iConAgregarVideojuego->AltaVideojuego();
            }
            else if(cont==2){
                iConAgregarVideojuego->cancelar();
            }
            else{
                cout << "Opción incorrecta, ingrese de nuevo.\n";
            }
        }while(cont!=1 && cont!=2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void suscribirseVideojuego(){
    string nomVideojuego;
    int opcion, opt, opcion2;
    list <DtSuscripciones*> suscActivas;
    TipoPago pago;
    cout << "\n" << "Suscripciones activas" <<endl; 
    try
    {
        suscActivas = iConSuscribirseVideojuego->listarSubsActivas();
        for (auto dtsa : suscActivas) {
            cout << *dtsa << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "\n" << "Suscripciones inactivas" <<endl; 
    try
    {
        list <DtSuscripciones*> suscInactivas = iConSuscribirseVideojuego->listarSubsInactivas();
        for (auto dtsi : suscInactivas) {
            cout << *dtsi << endl;
        }
        /*
        cout << "Desea buscar un videojuego por su categoría \n1 - Buscar \n2 - No buscar"<<endl;
        cin >> opcion2;
        if (opcion2==1)
        {
            buscarVideojuego();   
        }else{
            cout << "A elejido no buscar" << endl;
        }
        */
        cout <<endl;
        cout << "Ingrese el nombre del videojuego a suscribirse" <<endl;
        cin >> nomVideojuego;  
        for (auto sub : suscActivas)
        {
            if (nomVideojuego == sub->getNomVideojuego())
            {
                throw invalid_argument("Ya tiene una suscripcion activa a este videojuego");
            }
        }       
        iConSuscribirseVideojuego->ingresarVideojuego(nomVideojuego);
        cout << "Por favor, ingrese el metodo de pago. \n 1 - Crédito \n 2 - Débito"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            pago = CREDITO;
            break;
        case 2:
            pago = DEBITO;
            break;
        default:
            throw invalid_argument("Método de pago incorrecto");
            break;
        }
        iConSuscribirseVideojuego->suscripcionInactiva(pago);
        cout << "¿Desea confirmar la compra? \n 1 - Sí \n 2 - No"<<endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
            break;
        case 2:
            iConSuscribirseVideojuego->cancelar();
            break;
        default:
            throw invalid_argument("Opción incorrecta");
            break;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

void iniciarPartida(){
    string nomVideojuego;
    int indivMulti=0, partidaAnterior=0, seTransmite=0, cantJug=0, duracion=0, confirmar=0;
    try
    {    
        list <DtSuscripciones*> suscActivas;
        suscActivas = iConIniciarPartida->listarSubsActivas();
        for (auto dtsa : suscActivas) {
            cout << *dtsa << endl;
        }
        cout << "Ingrese videojuego para iniciar partida" << endl;
        cin >> nomVideojuego;
        cout << "¿Sera una partida individual o multijugador?\n 1 - Individual \n 2 - Multijugador" << endl;
        cin >> indivMulti;
        if (indivMulti == 1){
            cout << "¿Es continuación de una partida anterior? \n 1 - Sí \n 2 - No" << endl;
            cin >> partidaAnterior;
            if (partidaAnterior!=1 && partidaAnterior !=2)
            {
                throw invalid_argument("opcion incorrecta");
            }   
        }
        else if (indivMulti == 2){
            cout << "Se transmite en vivo?\n 1 - Sí \n 2 - No" << endl;
            cin >> seTransmite;
            if (seTransmite!=1 && seTransmite!=2){
                throw invalid_argument("Opción incorrecta");
            }
            cout << "¿Cuántos jugadores pueden unirse a la partida?" << endl;
            cin >> cantJug;
            cout << "¿Cuál es la duración de la partida?" << endl;
            cin >> duracion;
        }
        else{
            throw invalid_argument("Opción incorrecta");            
        }
        cout << "¡Desea confirmar el inicio de partida? \n 1 - Confirmar \n 2 - Cancelar" << endl;
        cin >> confirmar;
        if (confirmar == 1){
            if (indivMulti == 1){
                iConIniciarPartida->crearPartidaIndividual(nomVideojuego, partidaAnterior==1, fechaHoraActual());
            }else if (indivMulti == 2)
            {
                iConIniciarPartida->crearPartidaMultijugador(nomVideojuego, seTransmite==1, cantJug, duracion, fechaHoraActual());
            }
        }
        else if (confirmar == 2){
            iConIniciarPartida->cancelarPartida();
        }
        else{
            throw invalid_argument("Opción incorrecta");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void verInfoVideojuegos(){
    string nomVideojuego;
    try
    {
        list<string> videojuegos = iConVerInfoVideojuego->listarVideojuegos();
        for (auto videojuego : videojuegos)
        {
            cout << videojuego << endl;
        }
        cout <<"Ingrese el nombre del videojuego que desee ver su información" <<endl;
        cin >> nomVideojuego;
        DtVideojuegoFull* videojuegoFull = iConVerInfoVideojuego->verDatosJuego(nomVideojuego);
        cout << *videojuegoFull <<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void eliminarVideojuego(){
    string videojuego;
    int eliminar;
    list<string> videojuegos;
    try
    {    
        cout << "Ingrese el nombre del videojuego que desea eliminar" << endl;
        videojuegos=iConEliminarVideojuego->listarVideojuegosDesarrollador();
        for (auto vid : videojuegos){
            cout << vid << endl;
        }
        cin >> videojuego;
        iConEliminarVideojuego->seleccionarVideojuego(videojuego);
        cout << "Desea eliminar el videojuego? CONFIRMAR (1) o CANCELAR (2)" << endl;
        cin >> eliminar;
        if (eliminar == 1){
            iConEliminarVideojuego->confirmarEliminacion();
        }
        else if (eliminar == 2){
            iConEliminarVideojuego->cancelar();
        }
        else{
            cout << "Opcion incorrecta" << endl;
        }
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       
}

//opcionales---------------------------------------

void asignarPuntaje(){
    int puntaje;
    string nomJuego;
    try
    {    
        list<DtVideojuego*> videojuegos = iConAsignarPuntajeVideojuego->listarVideojuegos();
        for (auto videojuego : videojuegos)
        {
            cout << *videojuego <<endl;
        }
        cout << "Ingrese el nombre del videojuego a puntuar" <<endl;
        cin >> nomJuego;
        cout << "Ingrese un puntaje (1,2,3,4 o 5) para el videojuego" <<endl;
        cin >>puntaje;
        if(puntaje <6 && puntaje > 0)
        {
            iConAsignarPuntajeVideojuego->asignarPuntaje(nomJuego,puntaje);
        }else{
            cout << "Puntaje inválido" <<endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void cancelarSuscripcionAVideojuego(){
    string nombre;
    try{    
        list<DtSuscripciones*> suscActivas = iConCancelarSuscripcionaVideojuego->listarSubsActivas();
        for (auto dtsa : suscActivas) {
            cout << *dtsa << endl;
        }
        cout << "Indicar el nombre del videojuego que quiera cancelar la suscripcion: "<<endl;
        cin >> nombre;
        iConCancelarSuscripcionaVideojuego->cancelarSuscripcion(nombre);
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}


void buscarVideojuego(){
    int cont=1, auxCont=0; 
    list<DtCategoria*> categorias; 
    try
    {
        categorias = iConBusVid->listarCategorias(); 
        cout << "Categorías: " << "\n" <<endl;
        list<DtCategoria*>::iterator it = categorias.begin();
        for(it; it!=categorias.end(); ++it){
            auxCont++;
            cout << auxCont << " - " << *(*it);
        }
        bool tieneCategoria = false;
        do{
            cout << endl;
            cout << "Seleccione una categoría, o presione 0 para continuar: " << endl;
            cin >> cont;
            if (categorias.size() < cont){
                cout << "Debe seleccionar una categoria existente" <<endl;
            }else if (cont == 0 && !tieneCategoria){
                cout << "Debe elegir un categoría"<<endl;
            }else if(cont>0 && cont <= categorias.size()){
                list<DtCategoria*>::iterator it = categorias.begin();
                for(auxCont=1;auxCont<cont;auxCont++){
                    ++it;
                }
                iConBusVid->seleccionaCategoria(*it);
                tieneCategoria = true;
                list<DtVideojuego*> videojuegos = iConBusVid->listarVideojuegos();
                for (auto videojuegoDes : videojuegos) 
                {
                    cout << *videojuegoDes <<endl;
                }
            }   
        }while(!tieneCategoria);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void verPartidasVideojuego(){
    string nomVideojuego;
    try {
        list<string> videojuegos = IConVerPartidasVideojuego->listarVideojuegos();
        for (auto videojuego : videojuegos){
            cout << videojuego << endl;
        }
        cout << "Ingrese el nombre del videojuego que desea ver sus partidas" << endl;
        cin >> nomVideojuego;
        list<DtPartida*> DtPartidas = IConVerPartidasVideojuego->verPartidasVideojuego(nomVideojuego);
        for (auto dtp : DtPartidas){
            cout << "-------------" << endl;
            cout << *dtp ;
            DtPartidaIndividual* dtpi = dynamic_cast <DtPartidaIndividual*> (dtp);
            if (dtpi != NULL){
                cout << *dtpi;
            }
            DtPartidaMultijugador* dtpm = dynamic_cast <DtPartidaMultijugador*> (dtp);
            if (dtpm != NULL){
                cout << *dtpm << endl;
            }
        }
    }
    catch (const std:: exception& e) {
        std:: cerr << e.what() << endl;
    }
}

void rankingVideojuegos(){
    int opcion = 0;
    cout << "¿Quiere listarlos por puntuación(1) o por horas jugadas totales(2)?:" << endl;

    cin >> opcion;
    try
    { 
        list<DtVideojuegoRanking*> videojuegos = IConRankingVideojuegos->comoListar(opcion);
        for(auto videojuego : videojuegos){
            cout << *videojuego << endl;
        }
    }catch (const std:: exception& e) {
        std:: cerr << e.what() << endl;
    }
}


//Fecha y hora actual
DtFechaHora* fechaHoraActual(){
    time_t now = time(0);

    tm *ltm = localtime(&now);

    DtFechaHora* dtFechaHora = new DtFechaHora(ltm->tm_mday,(1+ltm->tm_mon),(1900+ltm->tm_year),(ltm->tm_hour),(ltm->tm_min));
    return dtFechaHora;
}

//Añadir datos de prueba
void aniadirDatos(){
    iConAltaUsuario->datosComunes("pedro@", "123");
    iConAltaUsuario->datosJugador("pedro", "Jugador_pro");
    iConAltaUsuario->altaUsuario();

    iConAltaUsuario->datosComunes("maria@", "12345");
    iConAltaUsuario->datosJugador("maria", "Streamer");
    iConAltaUsuario->altaUsuario();
        
    iConAltaUsuario->datosComunes("pepe@", "12345");
    iConAltaUsuario->datosJugador("pepe", "Money money");
    iConAltaUsuario->altaUsuario();

    iConAltaUsuario->datosComunes("juan@", "123");
    iConAltaUsuario->datosEmpresa("SoftInc");
    iConAltaUsuario->altaUsuario();
        
    iConAltaUsuario->datosComunes("yo@", "12345");
    iConAltaUsuario->datosEmpresa("Ubisoft");
    iConAltaUsuario->altaUsuario();

    iConAltaUsuario->datosComunes("programador@", "12345");
    iConAltaUsuario->datosEmpresa("Electronic Arts");
    iConAltaUsuario->altaUsuario();

    iConAltaUsuario->datosComunes("testP@", "123");
    iConAltaUsuario->datosEmpresa("TestInformation");
    iConAltaUsuario->altaUsuario();
        
    //añadir categorias
    iConAgregarCategoria->datosNuevaCategoria(ACCION,PC);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(ESTRATEGIA,PC);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(DEPORTE,PC);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(AVENTURA,PC);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(ACCION,PS4);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(AVENTURA,PS4);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(ESTRATEGIA,PS4);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(DEPORTE,PS4);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(AVENTURA,SWITCH);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(DEPORTE,XBOX_ONE);
    iConAgregarCategoria->confirmarCategoria();
    iConAgregarCategoria->datosNuevaCategoria(DEPORTE,PS5);
    iConAgregarCategoria->confirmarCategoria();
    
    iConIniciarSesion->datosComunes("testP@", "123");
    iConIniciarSesion->iniciarSesion();
    //1
    iConAgregarVideojuego->ingresaDatosVideojuego("COD","Corre y dispara",50);
    DtCategoria* dtCat = new DtCategoria(ACCION,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ACCION,PS4);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    //2
    iConAgregarVideojuego->ingresaDatosVideojuego("LOL","Vamos a jugar e insultar",10);
    dtCat = new DtCategoria(ACCION,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ESTRATEGIA,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    iConCerrarSesion->cerrarSesion();
    //3
    iConIniciarSesion->datosComunes("programador@", "12345");
    iConIniciarSesion->iniciarSesion();
    iConAgregarVideojuego->ingresaDatosVideojuego("fifa","Futbol y pasión",100);
    dtCat = new DtCategoria(DEPORTE,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(DEPORTE,PS4);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(DEPORTE,PS5);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(DEPORTE,XBOX_ONE);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    iConCerrarSesion->cerrarSesion();
    //4
    iConIniciarSesion->datosComunes("testP@", "123");
    iConIniciarSesion->iniciarSesion();
    iConAgregarVideojuego->ingresaDatosVideojuego("DBD","Corre, escondete y escapa",50);
    dtCat = new DtCategoria(ACCION,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ACCION,PS4);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ESTRATEGIA,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    //5
    iConAgregarVideojuego->ingresaDatosVideojuego("Fortnite","Dispara, construye un hotel 5 estrellas y gana",20);
    dtCat = new DtCategoria(ACCION,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ACCION,PS4);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    iConCerrarSesion->cerrarSesion();
    //6
    iConIniciarSesion->datosComunes("yo@", "12345");
    iConIniciarSesion->iniciarSesion();
    iConAgregarVideojuego->ingresaDatosVideojuego("R6","Entra estrategicamente y gana",150);
    dtCat = new DtCategoria(ACCION,PC);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    dtCat = new DtCategoria(ACCION,PS4);
    iConAgregarVideojuego->seleccionaCategoria(dtCat);
    iConAgregarVideojuego->AltaVideojuego();
    iConCerrarSesion->cerrarSesion();
    
    iConIniciarSesion->datosComunes("pepe@", "12345");
    iConIniciarSesion->iniciarSesion();
    iConSuscribirseVideojuego->ingresarVideojuego("COD");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("LOL");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("fifa");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("DBD");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("Fortnite");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("R6");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());

    iConCerrarSesion->cerrarSesion();
        
    iConIniciarSesion->datosComunes("maria@", "12345");
    iConIniciarSesion->iniciarSesion();
    iConSuscribirseVideojuego->ingresarVideojuego("COD");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("DBD");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("R6");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
        
    iConCerrarSesion->cerrarSesion();

    iConIniciarSesion->datosComunes("pedro@", "123");
    iConIniciarSesion->iniciarSesion();
    iConSuscribirseVideojuego->ingresarVideojuego("LOL");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
    iConSuscribirseVideojuego->ingresarVideojuego("fifa");
    iConSuscribirseVideojuego->suscripcionInactiva(CREDITO);
    iConSuscribirseVideojuego->altaSuscripcion(fechaHoraActual());
        
    iConCerrarSesion->cerrarSesion();
    iConIniciarSesion->datosComunes("pepe@", "12345");
    iConIniciarSesion->iniciarSesion();
    iConIniciarPartida->crearPartidaIndividual("LOL", 1, fechaHoraActual());    
    iConIniciarPartida->crearPartidaMultijugador("LOL", 1, 10, 5, fechaHoraActual());
    iConIniciarPartida->crearPartidaIndividual("DBD", 0, fechaHoraActual());    
    iConIniciarPartida->crearPartidaMultijugador("R6", 1, 5, 10, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("LOL", 1, 2, 20, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("Fortnite", 1, 30, 5, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("Fortnite", 1, 10, 5, fechaHoraActual());
    iConIniciarPartida->crearPartidaIndividual("Fortnite", 1, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("fifa", 1, 10, 5, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("fifa", 0, 5, 2, fechaHoraActual());
    iConIniciarPartida->crearPartidaMultijugador("fifa", 1, 5, 5, fechaHoraActual());
    iConIniciarPartida->crearPartidaIndividual("fifa", 0, fechaHoraActual());
        
    iConAsignarPuntajeVideojuego->asignarPuntaje("LOL",3);//3
    iConAsignarPuntajeVideojuego->asignarPuntaje("R6",2);
    iConAsignarPuntajeVideojuego->asignarPuntaje("LOL",2);
    iConAsignarPuntajeVideojuego->asignarPuntaje("Fortnite",2);//3
    iConAsignarPuntajeVideojuego->asignarPuntaje("Fortnite",5);
    iConAsignarPuntajeVideojuego->asignarPuntaje("Fortnite",4);
    iConAsignarPuntajeVideojuego->asignarPuntaje("Fortnite",3);
    iConAsignarPuntajeVideojuego->asignarPuntaje("Fortnite",1);
    iConAsignarPuntajeVideojuego->asignarPuntaje("LOL",4);
    
    iConCerrarSesion->cerrarSesion();
    
        /*
        TOTAL HORAS
        LOL = 90 = 0 + 50 + 40 
        DBD = 0
        R6 = 50
        Fortnite = 200 = 150 + 50 + 0
        fifa = 85 = 50 + 10 + 25 + 0

        PUNTAJE
        LOL = 3 = (3 + 2 + 4) / 3
        R6 = 2 = 2 / 1
        Fortnite = 3 = (2 + 5 + 4 + 3 + 1) / 5
        */

        // Si agregamos un usuario que ya existe no lo ingresa pero no sale error "El usuario ingresado ya existe"
        // No controla si la categoria a ingresar ya existe (la agrega 2 veces)

}

/* ඞ */
