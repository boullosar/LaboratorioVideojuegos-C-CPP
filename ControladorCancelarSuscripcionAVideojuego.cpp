#include "ControladorCancelarSuscripcionAVideojuego.h"

ControladorCancelarSuscripcionAVideojuego::ControladorCancelarSuscripcionAVideojuego(){}

list<DtSuscripciones*> ControladorCancelarSuscripcionAVideojuego::listarSubsActivas(){
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

void ControladorCancelarSuscripcionAVideojuego::cancelarSuscripcion(string nombre){    
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(nombre);
    if (videojuego == NULL)
    {
        throw invalid_argument("El videojuego no existe");
    }
    Sesion* sesion = Sesion::getSesion();
    int cont=1;
    bool tieneSub = false;
    list<Suscripcion*> suscripciones = videojuego->getSuscripciones();
    if(!suscripciones.empty()){
        list<Suscripcion*>::iterator it = suscripciones.begin();
        while (cont <= suscripciones.size()){
            if(sesion->getUsuario()->getEmail() == (*it)->getUsuario()->getEmail()){
                suscripciones.erase(it);
                (*it)->~Suscripcion();
                videojuego->setSuscripcion(suscripciones);
                tieneSub = true;
            }
            ++it;
            ++cont;
        }
        if (!tieneSub){
            throw invalid_argument("No esta suscripto a este videojuego");
        }
    }
}

ControladorCancelarSuscripcionAVideojuego::~ControladorCancelarSuscripcionAVideojuego(){}