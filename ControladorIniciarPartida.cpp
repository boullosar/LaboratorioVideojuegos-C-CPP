#include "ControladorIniciarPartida.h"

ControladorIniciarPartida::ControladorIniciarPartida(){}

list<DtSuscripciones*> ControladorIniciarPartida::listarSubsActivas(){
    list<DtSuscripciones*> subActivas;
    Sesion* sesion = Sesion::getSesion();
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos = mv->listarVideojuegos();
    if (videojuegos.empty())
    {
        throw invalid_argument("No hay videojuegos");
    }
    for (auto videojuego : videojuegos)
    {
        if (!videojuego->getSuscripciones().empty())
        {
            for (auto suscripcion : videojuego->getSuscripciones())
            {   
                if (sesion->getUsuario()->getEmail() == suscripcion->getUsuario()->getEmail())
                {
                    DtSuscripciones* dtsub = new DtSuscripciones(videojuego->getNombre(), suscripcion->getCosto());
                    subActivas.push_back(dtsub);
                }   
            }
        }   
    }
    if (subActivas.empty())
    {
        throw invalid_argument("No hay suscripciones activas");
    }
    return subActivas;

}

void ControladorIniciarPartida::crearPartidaIndividual(string nomVideojuego, bool partidaAnterior, DtFechaHora* dtFechaHora){
    //paso 1
    Sesion* sesion = Sesion::getSesion();
    Usuario* usuario = sesion->getUsuario();

    //paso 2
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(nomVideojuego);
    bool estaSuscripto=false;
    if (videojuego == NULL)
    {
        throw invalid_argument("No existe el videojuego");
    }
    for (auto sub : videojuego->getSuscripciones())
    {
        if (usuario->getEmail() == sub->getUsuario()->getEmail())
        {    
            //paso 3b
            PartidaIndividual* pi = new PartidaIndividual(this->getId(), dtFechaHora, 0, usuario, partidaAnterior);
            //paso 4
            videojuego->agregarPartida(pi);
            estaSuscripto = true;
        }
    }
    if (!estaSuscripto)
    {
        throw invalid_argument("No esta suscripto a este videojuego");
    }
}

void ControladorIniciarPartida::crearPartidaMultijugador(string nomVideojuego, bool seTrasmite, int cantJugadores, int duracion, DtFechaHora* dtFechaHora){
    //paso 1
    Sesion* sesion = Sesion::getSesion();
    Usuario* usuario = sesion->getUsuario();

    //paso 2
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(nomVideojuego);
    bool estaSuscripto=false;
    if (videojuego == NULL)
    {
        throw invalid_argument("No existe el videojuego");
    }
    for (auto sub : videojuego->getSuscripciones())
    {
        if (usuario->getEmail() == sub->getUsuario()->getEmail())
        {    
            //paso 3
            PartidaMultijugador* match = new PartidaMultijugador(this->getId(), dtFechaHora, duracion, usuario, cantJugadores, seTrasmite);
            
            //paso 4
        
            videojuego->agregarPartida(match);
            estaSuscripto = true;
        }
    }
    if (!estaSuscripto)
    {
        throw invalid_argument("No esta suscripto a este videojuego");
    }

}

void ControladorIniciarPartida::cancelarPartida(){}

ControladorIniciarPartida::~ControladorIniciarPartida(){}

int ControladorIniciarPartida::getId(){
    return this->contador++;
}