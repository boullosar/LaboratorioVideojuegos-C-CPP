#include "Estadisticas.h"

using namespace std;

Estadisticas::Estadisticas(){}
Estadisticas::Estadisticas(int puntaje){
    this->puntaje=puntaje;
}

int Estadisticas::getPuntaje(){
    return this->puntaje;
}

void Estadisticas::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}

Estadisticas::~Estadisticas(){}