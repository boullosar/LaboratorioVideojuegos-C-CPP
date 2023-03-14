#include "ControladorSuscribirseVideojuego.h"

ControladorSuscribirseVideojuego::ControladorSuscribirseVideojuego(){}

list<DtSuscripciones*> ControladorSuscribirseVideojuego::listarSubsActivas(){
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

list<DtSuscripciones*> ControladorSuscribirseVideojuego::listarSubsInactivas(){
    list<DtSuscripciones*> subInactivas;
    bool sub = false;
    Sesion* sesion = Sesion::getSesion();
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos = mv->listarVideojuegos();
    if (videojuegos.empty())
        throw invalid_argument("No hay videojuegos");
    for (auto videojuego : videojuegos)
    {
        sub = false;
        if (videojuego->getSuscripciones().empty())
        {
            DtSuscripciones* dtsub = new DtSuscripciones(videojuego->getNombre(), videojuego->getCosto());
            subInactivas.push_back(dtsub);
        }else{
            for (auto suscripcion : videojuego->getSuscripciones())
            {   
                if (sesion->getUsuario()->getEmail() == suscripcion->getUsuario()->getEmail())
                {
                    sub = true;
                }
            }
            if (!sub)
            {
                DtSuscripciones* dtsub = new DtSuscripciones(videojuego->getNombre(), videojuego->getCosto());
                subInactivas.push_back(dtsub);
            }
        }
    }
    if (subInactivas.empty())
        throw invalid_argument("No hay suscripciones inactivas. Felicidades, se a suscripto a todos los juegos de nuestro catálogo");
    return subInactivas;
}

void ControladorSuscribirseVideojuego::ingresarVideojuego(string nomVideojuego){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    if (mv->existeVideojuego(nomVideojuego))
    {
        this->nomVideojuego=nomVideojuego;
    }else{
        throw invalid_argument("El videojuego ingresado no existe");
    }
}

void ControladorSuscribirseVideojuego::suscripcionInactiva(TipoPago tipoPago){
    this->tipoPago=tipoPago;
}

void ControladorSuscribirseVideojuego::altaSuscripcion(DtFechaHora* dtFechaHora){
    //paso 1
    Sesion* sesion = Sesion::getSesion();
    Usuario* usuario = sesion->getUsuario();

    //paso 2
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(this->nomVideojuego);
    
    //paso 3
    Suscripcion* sub = new Suscripcion(this->tipoPago,videojuego->getCosto(), dtFechaHora, usuario);

    //paso 4
    videojuego->agregarSuscripcion(sub);
}

void ControladorSuscribirseVideojuego::cancelar(){
    this->nomVideojuego="";
}

ControladorSuscribirseVideojuego::~ControladorSuscribirseVideojuego(){}