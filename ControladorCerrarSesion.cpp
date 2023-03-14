#include "ControladorCerrarSesion.h"

ControladorCerrarSesion::ControladorCerrarSesion(){}

void ControladorCerrarSesion::cerrarSesion(){
    Sesion* sesion = Sesion::getSesion();
    if (sesion->getUsuario() != NULL){
        sesion->setSesion(NULL);
    }else{
        throw invalid_argument("No hay una sesion iniciada");
    }
}

ControladorCerrarSesion::~ControladorCerrarSesion(){}