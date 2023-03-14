#include "Partida.h"

Partida::Partida(){}
Partida::Partida(int id, DtFechaHora* dtFechaHora, int duracion, Usuario* usuario){
    this->id=id;
    this->dtFechaHora=dtFechaHora;
    this->duracion=duracion;
    this->usuario=usuario;
}

int Partida::getId(){
    return this->id;
}

void Partida::setId(int id){
    this->id=id;
}

DtFechaHora* Partida::getDtFechaHora(){
    return this->dtFechaHora;
}

void Partida::setDtFechaHora(DtFechaHora* dtFechaHora){
    this->dtFechaHora=dtFechaHora;
}

Usuario* Partida::getUsuario(){
    return this->usuario;
}

void Partida::setUsuario(Usuario* usuario){
    this->usuario=usuario;
}


int Partida::getDuracion(){
    return this->duracion;
}

void Partida::setDuracion(int duracion){
    this->duracion=duracion;
}

Partida::~Partida(){}