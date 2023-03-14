#include "ControladorVerInfoVideojuego.h"
#include "ManejadorVideojuego.h"
#include "Videojuego.h"
#include <map>

ControladorVerInfoVideojuego::ControladorVerInfoVideojuego(){}

list<string> ControladorVerInfoVideojuego::listarVideojuegos(){
        list<string> nomVideojuegos;
        list<Videojuego*> videoj;
        ManejadorVideojuego* manVid = ManejadorVideojuego::getInstancia();
        videoj = manVid->listarVideojuegos();
    if(!videoj.empty()){
        for (auto videojuego : videoj){
            nomVideojuegos.push_back(videojuego->getNombre());
        }
        return nomVideojuegos;
    }
    else {
        throw invalid_argument("No hay videojuegos ingresados");
    }
}

DtVideojuegoFull* ControladorVerInfoVideojuego::verDatosJuego(string nomVideojuego){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(nomVideojuego);
    if (videojuego == NULL)
    {
        throw invalid_argument("No existe el videojuego");
    }
    return videojuego->getDatosVideojuego();
}

ControladorVerInfoVideojuego::~ControladorVerInfoVideojuego(){}