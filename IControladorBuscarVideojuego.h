#ifndef ICONTROLADORBUSCARVIDEOJUEGO
#define ICONTROLADORBUSCARVIDEOJUEGO
#include <list>
#include <string>
#include "DtVideojuego.h"
#include "DtCategoria.h"

using namespace std;

class IControladorBuscarVideojuego
{
public:
    virtual list<DtCategoria*> listarCategorias()=0;
    virtual void seleccionaCategoria(DtCategoria*)=0;
    virtual list<DtVideojuego*> listarVideojuegos()=0;
};

#endif