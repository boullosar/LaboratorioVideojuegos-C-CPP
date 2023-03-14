#include "ControladorAuxiliar.h"

ControladorAuxiliar::ControladorAuxiliar(){}

int ControladorAuxiliar::esDesarrollador(){
    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();
    if (user == NULL)
    {
        return 1;
    }
    Desarrollador* des = dynamic_cast<Desarrollador*>(user);
    if (des!=NULL){
        return 2;
    }else{
        return 3;
    } 
}

ControladorAuxiliar::~ControladorAuxiliar(){}