#ifndef FABRICA
#define FABRICA
#include "IControladorAltaUsuario.h"
#include "ControladorAltaUsuario.h"
#include "IControladorIniciarSesion.h"
#include "ControladorIniciarSesion.h"
#include "IControladorCerrarSesion.h"
#include "ControladorCerrarSesion.h"
#include "IControladorAgregarCategoria.h"
#include "ControladorAgregarCategoria.h"
#include "IControladorAgregarVideojuego.h"
#include "ControladorAgregarVideojuego.h"
#include "IControladorSuscribirseVideojuego.h"
#include "ControladorSuscribirseVideojuego.h"
#include "IControladorIniciarPartida.h"
#include "ControladorIniciarPartida.h"
#include "IControladorVerInfoVideojuego.h"
#include "ControladorVerInfoVideojuego.h"
#include "IControladorEliminarVideojuego.h"
#include "ControladorEliminarVideojuego.h"
#include "IControladorAsignarPuntajeVideojuego.h"
#include "ControladorAsignarPuntajeVideojuego.h"
#include "IControladorVerPartidasVideojuego.h"
#include "ControladorVerPartidasVideojuego.h"
#include "IControladorRankingVideojuegos.h"
#include "ControladorRankingVideojuegos.h"
#include "IControladorAuxiliar.h"
#include "ControladorAuxiliar.h"
#include "IControladorBuscarVideojuego.h"
#include "ControladorBuscarVideojuego.h"
#include "IControladorCancelarSuscripcionVideojuego.h"
#include "ControladorCancelarSuscripcionAVideojuego.h"

class Fabrica
{
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstancia();

    IControladorAltaUsuario* getControladorAltaUsuario();
    IControladorIniciarSesion* getControladorIniciarSesion();
    IControladorCerrarSesion* getControladorCerrarSesion();
    IControladorAgregarCategoria* getControladorAgregarCategoria();
    IControladorAgregarVideojuego* getControladorAgregarVideojuego();
    IControladorSuscribirseVideojuego* getControladorSuscribirseVideojuego();
    IControladorIniciarPartida* getControladorIniciarPartida();
    IControladorVerInfoVideojuego* getControladorVerInfoVideojuego();
    IControladorEliminarVideojuego* getControladorEliminarVideojuego();
    IControladorAsignarPuntajeVideojuego* getControladorAsignarPuntajeVideojuego();
    IControladorVerPartidasVideojuego* getControladorVerPartidasVideojuego();
    IControladorRankingVideojuegos* getControladorRankingVideojuegos();
    IControladorAuxiliar* getControladorAuxiliar();
    IControladorBuscarVideojuego* getControladorBuscarVideojuego();
    IControladorCancelarSuscripicionVideojuego* getControladorCancelarSuscripcionAVideojuego();
    ~Fabrica();
};

#endif