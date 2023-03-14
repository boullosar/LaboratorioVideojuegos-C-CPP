#include "ControladorAsignarPuntajeVideojuego.h"


ControladorAsignarPuntajeVideojuego::ControladorAsignarPuntajeVideojuego(){}


list<DtVideojuego*> ControladorAsignarPuntajeVideojuego::listarVideojuegos(){
    list<DtVideojuego*> videojuegos;
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    if (mv->listarVideojuegos().empty())
    {
        throw invalid_argument("No hay juegos en el sistema");
    }
    
    for (auto videojuego : mv->listarVideojuegos())
    {
        DtVideojuego* dtv = new DtVideojuego(videojuego->getNombre(),videojuego->getDescripcion());
        videojuegos.push_back(dtv);
    }
    return videojuegos;
}

void ControladorAsignarPuntajeVideojuego::asignarPuntaje(string nomJuego, int puntaje){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(nomJuego);
    if (videojuego == NULL)
    {
        throw invalid_argument("No existe el juego");
    }
    Estadisticas* est = new Estadisticas(puntaje);
    videojuego->agregarEstadistica(est);
}

ControladorAsignarPuntajeVideojuego::~ControladorAsignarPuntajeVideojuego(){}
