#ifndef CATEGORIA
#define CATEGORIA
#include "TipoGenero.h"
#include "TipoPlataforma.h"
#include <iostream>

class Categoria
{
private:
    TipoGenero genero;
    TipoPlataforma plataforma;

public:
    Categoria(TipoGenero, TipoPlataforma);
    Categoria();
    void setGenero(TipoGenero);
    void setPlataforma(TipoPlataforma);
    TipoGenero getGenero();
    TipoPlataforma getPlataforma();
    ~Categoria();

};


#endif