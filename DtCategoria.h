#ifndef DTCATEGORIA
#define DTCATEGORIA
#include "TipoGenero.h"
#include "TipoPlataforma.h"
#include <iostream>

using namespace std;

class DtCategoria {
private:
    TipoGenero genero;
    TipoPlataforma plataforma;

public:
    DtCategoria(TipoGenero, TipoPlataforma);
    DtCategoria();
    TipoGenero getGenero();
    TipoPlataforma getPlataforma();
    ~DtCategoria();

    friend ostream& operator << (ostream&, const DtCategoria&);

};

#endif