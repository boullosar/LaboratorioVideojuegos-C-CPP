#include "Suscripcion.h"

Suscripcion::Suscripcion(){}
Suscripcion::Suscripcion(TipoPago tipoPago, int costo, DtFechaHora* dtFechaHora, Usuario* usuario){
    this->tipoPago=tipoPago;
    this->costo=costo;
    this->dtFechaHora=dtFechaHora;
    this->usuario=usuario;
}

TipoPago Suscripcion::getTipoPago(){
    return this->tipoPago;
}

void Suscripcion::setTipoPago(TipoPago tipoPago){
    this->tipoPago=tipoPago;
}

int Suscripcion::getCosto(){
    return this->costo;
}

void Suscripcion::setCosto(int costo){
    this->costo=costo;
}

DtFechaHora* Suscripcion::getDtFechaHora(){
    return this->dtFechaHora;
}

void Suscripcion::setDtFechaHora(DtFechaHora* dtFechaHora){
    this->dtFechaHora=dtFechaHora;
}

Usuario* Suscripcion::getUsuario(){
    return this->usuario;
}

void Suscripcion::setUsuario(Usuario* usuario){
    this->usuario=usuario;
}

Suscripcion::~Suscripcion(){}

void Suscripcion::Suscribirse(TipoPago tipoPago, int costo, DtFechaHora* dtFechaHora, Usuario* usuario){
    throw "no implementada";
}
