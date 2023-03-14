#include "ControladorVerPartidasVideojuego.h"
#include "ManejadorVideojuego.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include <list>

ControladorVerPartidasVideojuego::ControladorVerPartidasVideojuego(){}

list<string> ControladorVerPartidasVideojuego::listarVideojuegos(){
    list<string> nomVideojuegos;
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos = mv->listarVideojuegos();
    if (videojuegos.empty())
    {
        throw invalid_argument("No hay videojuegos");
    }
    for (auto v : videojuegos){
        nomVideojuegos.push_back(v->getNombre());
    }
    return nomVideojuegos;
}

list<DtPartida*> ControladorVerPartidasVideojuego::verPartidasVideojuego(string nomVideojuego){
    list<DtPartida*> DtPartidas;
    bool seEncontroVJ=false;
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos = mv->listarVideojuegos();
    for (auto v : videojuegos){
        if(nomVideojuego == v->getNombre()){
            seEncontroVJ=true;
            if (v->getPartidas().empty()){
                throw invalid_argument ("No hay partidas");
            }
            else{
                for(auto p : v->getPartidas()){
                    PartidaIndividual* pi = dynamic_cast <PartidaIndividual*> (p);
                    if (pi != NULL){
                        DtPartidaIndividual* dtp = new DtPartidaIndividual(pi->getId(), pi->getDtFechaHora(), pi->getUsuario(), pi->getDuracion(), pi->getConPartida());
                        DtPartidas.push_back(dtp);
                    }
                    else{
                        PartidaMultijugador* pm = dynamic_cast <PartidaMultijugador*> (p);
                        if (pm != NULL){
                            DtPartidaMultijugador* dtp = new DtPartidaMultijugador(p->getId(), pm->getDtFechaHora(), pm->getUsuario(), pm->getDuracion() * pm->getCantJugadores(), pm->getEnVivo(), pm->getCantJugadores());
                            DtPartidas.push_back(dtp);
                        }
                    }
                }
            }
        }
    }
    if (!seEncontroVJ){
        throw invalid_argument ("No se encontro el videojuego");
    }
    return DtPartidas;
}

ControladorVerPartidasVideojuego::~ControladorVerPartidasVideojuego(){}