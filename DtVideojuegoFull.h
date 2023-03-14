#ifndef DTVIDEOJUEGOFULL
#define DTVIDEOJUEGOFULL
#include "DtCategoria.h"
#include <list>
#include <string>

using namespace std;

class DtVideojuegoFull
{
private:
    string nombre;
    list<DtCategoria*> categorias;
    string empresa;
    int horasTotal;
    float puntajePromedio;
    string descripcion;
    int costo;
public:
    DtVideojuegoFull();
    DtVideojuegoFull(string,list<DtCategoria*>,string,int,float,string,int);
    string getNombre();
    list<DtCategoria*> getCategoria();
    string getEmpresa();
    int getHorasTotal();
    float getPuntajePromedio();
    string getDescripcion();
    int getCosto();
    ~DtVideojuegoFull();

    friend ostream& operator << (ostream&, const DtVideojuegoFull&);
};

#endif