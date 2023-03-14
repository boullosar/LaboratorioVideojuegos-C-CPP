#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(){}
PartidaIndividual::PartidaIndividual(int id, DtFechaHora* dtFechaHora, int duracion, Usuario* usuario, bool conPartida):Partida(id, dtFechaHora, duracion, usuario){
    this->conPartida=conPartida;
}

bool PartidaIndividual::getConPartida(){
    return this->conPartida;
}

void PartidaIndividual::setConPartida(bool conPartida){
    this->conPartida=conPartida;
}

PartidaIndividual::~PartidaIndividual(){}