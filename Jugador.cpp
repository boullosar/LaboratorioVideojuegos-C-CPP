#include "Jugador.h"

Jugador::Jugador(){}
Jugador::Jugador(string email,string pass,string nickname,string descripcion):Usuario(email,pass){
    this->nickname=nickname;
    this->descripcion=descripcion;
}

string Jugador::getNickname(){
    return this->nickname;
}

void Jugador::setNickname(string nickname){
    this->nickname=nickname;
}

string Jugador::getDescripcion(){
    return this->descripcion;
}

void Jugador::setDescripcion(string descripcion){
    this->descripcion;
}
Jugador::~Jugador(){}