#include "ControladorAltaUsuario.h"
#include "Desarrollador.h"

ControladorAltaUsuario::ControladorAltaUsuario(){}

void ControladorAltaUsuario::datosComunes(string email, string pass){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if (!mu->existeEmail(email))
    {
        this->email=email;
        this->pass=pass;   
    }else{
        throw invalid_argument("Ya existe el email");
    }
}

void ControladorAltaUsuario::datosEmpresa(string nomEmpresa){
    this->nomEmpresa=nomEmpresa;
}

bool ControladorAltaUsuario::datosJugador(string nickname, string descripcion){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if (!mu->existeNickname(nickname))
    {
        this->nickname=nickname;
        this->descripcion=descripcion;
        return false;
    }
    return true;
}

bool ControladorAltaUsuario::ingresarNickname(string nickname){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if (!mu->existeNickname(nickname))
    {
        this->nickname=nickname;
        return false;
    }
    return true;   
}

void ControladorAltaUsuario::altaUsuario(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Usuario* user;    
    if(nomEmpresa != ""){
        user = new Desarrollador(this->email, this->pass, this->nomEmpresa);
    }
    else{
        user = new Jugador(email, pass, nickname, descripcion);
    }
    mu->add(user);
    cancelar();
}

void ControladorAltaUsuario::cancelar(){
    this->email="";
    this->pass="";
    this->nomEmpresa="";
    this->nickname="";
    this->descripcion="";
}

ControladorAltaUsuario::~ControladorAltaUsuario(){}