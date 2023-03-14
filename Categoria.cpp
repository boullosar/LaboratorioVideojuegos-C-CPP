#include "Categoria.h"
#include <iostream>

Categoria::Categoria(TipoGenero genero, TipoPlataforma plataforma){
    this->genero=genero;
    this->plataforma=plataforma;
}

Categoria::Categoria(){}

void Categoria::setGenero(TipoGenero genero){
    this->genero=genero;
}

void Categoria::setPlataforma(TipoPlataforma plataforma){
    this->plataforma=plataforma;
}

TipoGenero Categoria::getGenero(){
    return this->genero;
}

TipoPlataforma Categoria::getPlataforma(){
    return this->plataforma;
}

Categoria::~Categoria(){}
