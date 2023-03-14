#include "Fabrica.h"

Fabrica *Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia()
{
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IControladorAltaUsuario* Fabrica::getControladorAltaUsuario(){
    return new ControladorAltaUsuario();
}

IControladorIniciarSesion* Fabrica::getControladorIniciarSesion(){
    return new ControladorIniciarSesion();
}

IControladorCerrarSesion* Fabrica::getControladorCerrarSesion(){
    return new ControladorCerrarSesion();
}

IControladorAgregarCategoria* Fabrica::getControladorAgregarCategoria(){
    return new ControladorAgregarCategoria();
}

IControladorAgregarVideojuego* Fabrica::getControladorAgregarVideojuego(){
    return new ControladorAgregarVideojuego();
}

IControladorSuscribirseVideojuego* Fabrica::getControladorSuscribirseVideojuego(){
    return new ControladorSuscribirseVideojuego();
}

IControladorIniciarPartida* Fabrica::getControladorIniciarPartida(){
    return new ControladorIniciarPartida();
}

IControladorVerInfoVideojuego* Fabrica::getControladorVerInfoVideojuego(){
    return new ControladorVerInfoVideojuego();
}

IControladorEliminarVideojuego* Fabrica::getControladorEliminarVideojuego(){
    return new ControladorEliminarVideojuego();
}

IControladorAsignarPuntajeVideojuego* Fabrica::getControladorAsignarPuntajeVideojuego(){
    return new ControladorAsignarPuntajeVideojuego();
}

IControladorVerPartidasVideojuego* Fabrica::getControladorVerPartidasVideojuego(){
    return new ControladorVerPartidasVideojuego();
}

IControladorRankingVideojuegos* Fabrica::getControladorRankingVideojuegos(){
    return new ControladorRankingVideojuegos();
}

IControladorAuxiliar* Fabrica::getControladorAuxiliar(){
    return new ControladorAuxiliar();
}

IControladorBuscarVideojuego* Fabrica::getControladorBuscarVideojuego(){
    return new ControladorBuscarVideojuego();
}

IControladorCancelarSuscripicionVideojuego* Fabrica::getControladorCancelarSuscripcionAVideojuego(){
    return new ControladorCancelarSuscripcionAVideojuego();
}

Fabrica::~Fabrica(){}