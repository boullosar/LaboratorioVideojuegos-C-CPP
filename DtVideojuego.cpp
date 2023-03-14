#include "DtVideojuego.h"

DtVideojuego::DtVideojuego(){}

DtVideojuego::DtVideojuego(string nombre, string descripcion){
    this->nombre=nombre;
    this->descripcion=descripcion;
}

string DtVideojuego::getNombre(){
    return this->nombre;
}

string DtVideojuego::getDescripcion(){
    return this->descripcion;
}

DtVideojuego::~DtVideojuego(){}

ostream &operator << (ostream& salida, const DtVideojuego& dtv){
    cout << "Nombre: " << dtv.nombre << "\nDescripcion: " << dtv.descripcion << endl;
    return salida;
}