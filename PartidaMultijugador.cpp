#include "PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(){}

PartidaMultijugador::PartidaMultijugador(int id, DtFechaHora* dtFechaHora, int duracion, Usuario* usuario, int cantJugadores, bool enVivo):Partida(id, dtFechaHora,duracion, usuario){
    this->cantJugadores=cantJugadores;
    this->enVivo=enVivo;
}

int PartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;
}

void PartidaMultijugador::setCantJugadores(int cantJugadores){
    this->cantJugadores=cantJugadores;
}

bool PartidaMultijugador::getEnVivo(){
    return this->enVivo;
}

void PartidaMultijugador::setEnVivo(bool enVivo){
    this->enVivo=enVivo;
}

PartidaMultijugador::~PartidaMultijugador(){}