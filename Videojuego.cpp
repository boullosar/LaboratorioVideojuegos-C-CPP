#include "Videojuego.h"

Videojuego::Videojuego(){}

Videojuego::Videojuego(string nombre, string descripcion, int costo, Usuario* usuario, list<Categoria*> categorias){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->usuario = usuario;

    ManejadorCategoria* mc = ManejadorCategoria::getInstancia();
    for (auto c : categorias)
    {
        this->categorias.push_back(mc->find(c));
    }   
}

string Videojuego::getNombre(){
    return this->nombre;
}

void Videojuego::setNombre(string nombre){
    this->nombre = nombre;
}

string Videojuego::getDescripcion(){
    return this->descripcion;
}

void Videojuego::setDescripcion(string){
    this->descripcion = descripcion;
}

int Videojuego::getCosto(){
    return this->costo;
}

void Videojuego::setCosto(int costo){
    this->costo = costo;
}

Usuario* Videojuego::getUsuario(){
    return this->usuario;
}

void Videojuego::setUsuario(Usuario* usuario){
   this->usuario=usuario;
}

list<Categoria*> Videojuego::getCategorias(){
    return this->categorias;
}

void Videojuego::setCategorias(list<Categoria*> categorias){
    this->categorias=categorias;
}

list<Suscripcion*> Videojuego::getSuscripciones(){
    return this->suscripciones;
}

void Videojuego::setSuscripcion(list<Suscripcion*> suscripciones){
    this->suscripciones=suscripciones;
}


list<Partida*> Videojuego::getPartidas(){
    return this->partidas;
}


void Videojuego::setPartida(list<Partida*> partidas){
    this->partidas=partidas;
}

Videojuego::~Videojuego(){
    //3.1
    if(!suscripciones.empty()){
        list<Suscripcion*>::iterator it = suscripciones.begin();
        while (it != suscripciones.end()){
            suscripciones.erase(it);
            (*it)->~Suscripcion();
            it = suscripciones.begin();
        }
    }

    //3.4
    if(!est.empty()){
        list<Estadisticas*>::iterator it = est.begin();
        while (it != est.end()){
            est.erase(it);
            (*it)->~Estadisticas();
            it = est.begin();
        }
    }

    //3.7
    if(!partidas.empty()){
        list<Partida*>::iterator it = partidas.begin();
        while (it != partidas.end()){
            partidas.erase(it);
            (*it)->~Partida();
            it = partidas.begin();
        } 
    }
    
}

void Videojuego::agregarSuscripcion(Suscripcion* suscripcion){
    suscripciones.push_back(suscripcion);
}

void Videojuego::agregarPartida(Partida* partida){
    partidas.push_back(partida);
}

DtVideojuegoFull* Videojuego::getDatosVideojuego(){

    //paso 2.1
    string nomEmpresa;
    Desarrollador* des = dynamic_cast<Desarrollador*>(this->usuario);
    if(des != NULL){
        nomEmpresa=des->getNomEmpresa();
    }

    //paso2.2 y 2.3
    list<DtCategoria*> cats;
    DtCategoria* catAct;

    for (auto c : categorias)
    {
        catAct = new DtCategoria(c->getGenero(), c->getPlataforma()); 
        cats.push_back(catAct);
    }   

    //2.4 y 2.5 son opcionales
    float puntajePromedio = 0;
    int cant = 0;
    for (auto estat : est)
    {
        puntajePromedio = puntajePromedio + estat->getPuntaje();
        cant++;
    }
    if (cant !=0)
    {
        puntajePromedio = puntajePromedio / cant;
    }else{
        puntajePromedio = 0;
    }

    //2.6 2.7
    int horasTotales = 0;

    for (auto p : partidas)
    {
        PartidaIndividual* par = dynamic_cast<PartidaIndividual*>(p);
        if(par!=NULL){
            horasTotales = horasTotales + p->getDuracion();
        }
        else{
            PartidaMultijugador* par = dynamic_cast<PartidaMultijugador*>(p);
            if(par!=NULL){
                horasTotales = horasTotales + (par->getDuracion() * par->getCantJugadores());
            }
        }
    }   

    //fin paso 2

    DtVideojuegoFull* dtvf = new DtVideojuegoFull(this->nombre,cats,nomEmpresa,horasTotales,puntajePromedio,this->descripcion,this->costo);
    return dtvf;
}

void Videojuego::agregarEstadistica(Estadisticas* est){
    this->est.push_back(est);
}