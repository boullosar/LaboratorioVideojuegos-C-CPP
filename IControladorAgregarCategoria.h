#ifndef ICONTROLADORAGREGARCATEGORIA
#define ICONTROLADORAGREGARCATEGORIA
#include <list>
#include <string>
#include "TipoGenero.h"
#include "TipoPlataforma.h"
#include "DtCategoria.h"

using namespace std;

class IControladorAgregarCategoria
{
    public:
    virtual list<DtCategoria*> listarCategorias()=0;
    virtual void datosNuevaCategoria(TipoGenero, TipoPlataforma)=0;
    virtual void confirmarCategoria()=0;
    virtual void cancelar()=0;
};



#endif