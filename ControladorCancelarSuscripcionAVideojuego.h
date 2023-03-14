#ifndef CONTROLADORCANCELARSUSCRIPCIONVIDEOJUEGO
#define CONTROLADORCANCELARSUSCRIPCIONVIDEOJUEGO
#include "IControladorCancelarSuscripcionVideojuego.h"
#include <list>
#include <string>
#include <iostream>
#include "DtSuscripciones.h"
#include "ManejadorVideojuego.h"
#include "Sesion.h"

using namespace std;

class ControladorCancelarSuscripcionAVideojuego : public IControladorCancelarSuscripicionVideojuego{
    public:
    ControladorCancelarSuscripcionAVideojuego();
    list<DtSuscripciones*> listarSubsActivas();
    void cancelarSuscripcion(string);
    ~ControladorCancelarSuscripcionAVideojuego();
};

#endif

