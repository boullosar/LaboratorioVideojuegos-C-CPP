#ifndef ICONTROLADORINICIARPARTIDA_H
#define ICONTROLADORINICIARPARTIDA_H
#include <list>
#include <string>
#include "DtSuscripciones.h"
#include "DtFechaHora.h"

using namespace std;

class IControladorIniciarPartida{
    public:
    virtual list<DtSuscripciones*> listarSubsActivas()=0;
    virtual void crearPartidaIndividual(string, bool, DtFechaHora*)=0;
    virtual void crearPartidaMultijugador(string, bool, int, int, DtFechaHora*)=0;
    virtual void cancelarPartida()=0;
};

#endif