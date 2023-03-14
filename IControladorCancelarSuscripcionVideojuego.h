#ifndef ICONTROLADORCANCELARSUSCRIPCIONVIDEOJUEGO
#define ICONTROLADORCANCELARSUSCRIPCIONVIDEOJUEGO
#include <list>
#include <string>
#include "DtSuscripciones.h"

using namespace std;

class IControladorCancelarSuscripicionVideojuego{
    public:
    virtual list<DtSuscripciones*> listarSubsActivas()=0;
    virtual void cancelarSuscripcion(string)=0;

};

#endif
