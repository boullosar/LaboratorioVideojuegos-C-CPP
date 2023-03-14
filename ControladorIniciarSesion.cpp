#include "ControladorIniciarSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"

ControladorIniciarSesion::ControladorIniciarSesion(){}

bool ControladorIniciarSesion::datosComunes(string email, string pass){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if (!mu->member(email))
    {
        return false;
    }
    Usuario* user = mu->find(email);
    if ((user->getEmail() == email) && (user->getPass() == pass))
    {   
        this->email=email;
        this->pass=pass;
        return true;    
    }
    return false;
}

void ControladorIniciarSesion::cancelar(){
    this->email="";
    this->pass="";
}

void ControladorIniciarSesion::iniciarSesion(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Usuario* iniciar = mu->find(this->email);
    Sesion* sesion = Sesion::getSesion();
    sesion->setSesion(iniciar);
}

ControladorIniciarSesion::~ControladorIniciarSesion(){}
