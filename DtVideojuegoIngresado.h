#ifndef DTVIDEOJUEGOINGRESADO
#define DTVIDEOJUEGOINGRESADO
#include <string>
#include "DtCategoria.h"
#include "Sesion.h"
#include <iostream>
#include <list>

using namespace std;

class DtVideojuegoIngresado
{
private:
    string email;
    string nombre;
    string descripcion;
    int costoSub;
    list<DtCategoria*> categorias;
public:
    DtVideojuegoIngresado();
    DtVideojuegoIngresado(string,string,string,int,list<DtCategoria*>);
    string getEmail();
    string getNombre();
    string getDescripcion();
    int getCostoSub();
    list<DtCategoria*> getCategorias();
    ~DtVideojuegoIngresado();

    friend ostream& operator << (ostream&, const DtVideojuegoIngresado&);

};

#endif