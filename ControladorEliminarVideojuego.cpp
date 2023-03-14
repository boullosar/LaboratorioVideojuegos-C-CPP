  #include "ControladorEliminarVideojuego.h"

ControladorEliminarVideojuego::ControladorEliminarVideojuego(){}

list<string> ControladorEliminarVideojuego::listarVideojuegosDesarrollador(){
    list<string> nomJuegos;
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Sesion* sesion = Sesion::getSesion();
    if (mv->listarVideojuegos().empty())
    {
        throw invalid_argument("No hay juegos");
    }
    
    for (auto videojuego : mv->listarVideojuegos())
    {
        if (videojuego->getUsuario()->getEmail() == sesion->getUsuario()->getEmail())
        {
            nomJuegos.push_back(videojuego->getNombre());
        }
    }
    if (nomJuegos.empty())
    {
        throw invalid_argument("Este desarrollador no tiene juegos creados");
    }
    return nomJuegos;
}

void ControladorEliminarVideojuego::seleccionarVideojuego(string nombre){
    this->nombre=nombre;
}

void ControladorEliminarVideojuego::confirmarEliminacion(){
    //paso1
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = mv->find(this->nombre);
    //paso2
    mv->remove(this->nombre);
    //paso3
    videojuego->~Videojuego();
}

void ControladorEliminarVideojuego::cancelar(){
    this->nombre="";
}

ControladorEliminarVideojuego::~ControladorEliminarVideojuego(){}