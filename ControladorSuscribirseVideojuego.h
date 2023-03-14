#ifndef CONTROLADORSUSCRIBIRSEVIDEOJUEGO
#define CONTROLADORSUSCRIBIRSEVIDEOJUEGO
#include <string>
#include <list>
#include "TipoPago.h" 
#include "DtFechaHora.h"
#include "DtSuscripciones.h"
#include "IControladorSuscribirseVideojuego.h"
#include "ManejadorVideojuego.h"
#include "Sesion.h"

using namespace std;

class ControladorSuscribirseVideojuego : public IControladorSuscribirseVideojuego
{
private:
    string nomVideojuego;
    TipoPago tipoPago;
public:
    ControladorSuscribirseVideojuego();

    list<DtSuscripciones*> listarSubsActivas();
    list<DtSuscripciones*> listarSubsInactivas();
    void ingresarVideojuego(string);
    void suscripcionInactiva(TipoPago);
    void altaSuscripcion(DtFechaHora*);
    void cancelar();

    ~ControladorSuscribirseVideojuego();
};

#endif