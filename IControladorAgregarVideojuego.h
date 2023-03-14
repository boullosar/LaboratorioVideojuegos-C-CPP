#ifndef ICONTROLADORAGREGARVIDEOJUEGO
#define ICONTROLADORAGREGARVIDEOJUEGO
#include <list>
#include <string>
#include "DtCategoria.h"
#include "DtVideojuegoIngresado.h"


using namespace std;

class IControladorAgregarVideojuego
{
    public:
    virtual void ingresaDatosVideojuego(string, string, float)=0;
    virtual list<DtCategoria*> listarCategorias()=0;
    virtual void seleccionaCategoria(DtCategoria*)=0;
    virtual DtVideojuegoIngresado* listarInfo()=0;
    virtual void AltaVideojuego()=0;
    virtual void cancelar()=0;
};



#endif