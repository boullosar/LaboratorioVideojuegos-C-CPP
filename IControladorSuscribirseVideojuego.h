#ifndef ICONTROLADORSUSCRIBIRSEVIDEOJUEGO
#define ICONTROLADORSUSCRIBIRSEVIDEOJUEGO
#include <string>
#include <list>
#include "TipoPago.h" 
#include "DtFechaHora.h"
#include "DtSuscripciones.h"

using namespace std;

class IControladorSuscribirseVideojuego
{

public:
    virtual list<DtSuscripciones*> listarSubsActivas()=0;
    virtual list<DtSuscripciones*> listarSubsInactivas()=0;
    virtual void ingresarVideojuego(string)=0;
    virtual void suscripcionInactiva(TipoPago)=0;
    virtual void altaSuscripcion(DtFechaHora*)=0;
    virtual void cancelar()=0;
};

#endif