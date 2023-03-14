#include "ManejadorVideojuego.h"

ManejadorVideojuego *ManejadorVideojuego::instancia=NULL;

ManejadorVideojuego::ManejadorVideojuego(){}

ManejadorVideojuego* ManejadorVideojuego::getInstancia(){
    if(instancia==NULL){
        instancia = new ManejadorVideojuego();
    }
    return instancia;
}

void ManejadorVideojuego::add(Videojuego* videojuego){
    this->videojuegos.insert(pair<string, Videojuego*>(videojuego->getNombre(), videojuego));
}

bool ManejadorVideojuego::member(string nombre){
    map<string, Videojuego*>::iterator it = this->videojuegos.find(nombre);
    return (it != this->videojuegos.end());
}

Videojuego* ManejadorVideojuego::find(string nombre){
    map<string, Videojuego*>::iterator it = this->videojuegos.find(nombre);
    return it->second;
}


bool ManejadorVideojuego::existeVideojuego(string nombre){
    Videojuego* vj;
    for (map<string, Videojuego*>::iterator it = this->videojuegos.begin(); it != this->videojuegos.end(); it++){
        vj = it->second;
        if(vj->getNombre() == nombre){
            return true;
        }
    }
    return false;
}

list<Videojuego*> ManejadorVideojuego::listarVideojuegos(){
    list<Videojuego*> videojuegos;
    for (map<string, Videojuego*>::iterator it = this->videojuegos.begin(); it != this->videojuegos.end(); it++){
        videojuegos.push_back(it->second);
    }
    return videojuegos;
}

void ManejadorVideojuego::remove(string videojuego){
    videojuegos.erase(videojuego);
}

ManejadorVideojuego::~ManejadorVideojuego(){}