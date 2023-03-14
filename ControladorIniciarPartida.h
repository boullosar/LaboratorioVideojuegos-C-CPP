#ifndef CONTROLADORINICIARPARTIDA
#define CONTROLADORINICIARPARTIDA
#include "IControladorIniciarPartida.h"
#include "Sesion.h"
#include "ManejadorVideojuego.h"
#include "ManejadorUsuario.h"
#include "Videojuego.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "DtFechaHora.h"

class ControladorIniciarPartida : public IControladorIniciarPartida
{
private:
    int contador=100;
public:
    ControladorIniciarPartida();

    list<DtSuscripciones*> listarSubsActivas();
    void crearPartidaIndividual(string, bool, DtFechaHora*);
    void crearPartidaMultijugador(string, bool, int, int, DtFechaHora*);
    void cancelarPartida();

    int getId();

    ~ControladorIniciarPartida();
};

#endif