#include "DtVideojuegoIngresado.h"


DtVideojuegoIngresado::DtVideojuegoIngresado(string email, string nombre, string descripcion, int costoSub, list<DtCategoria*> categorias){
    this->email=email;
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costoSub=costoSub;
    this->categorias=categorias;
}

DtVideojuegoIngresado::DtVideojuegoIngresado(){}

string DtVideojuegoIngresado::getEmail(){
    return this->email;
}

string DtVideojuegoIngresado::getNombre(){
    return this->nombre;
}

string DtVideojuegoIngresado::getDescripcion(){
    return this->descripcion;
}

int DtVideojuegoIngresado::getCostoSub(){
    return this->costoSub;
}

list<DtCategoria*> DtVideojuegoIngresado::getCategorias(){
    return this->categorias;
}

DtVideojuegoIngresado::~DtVideojuegoIngresado(){}

ostream &operator << (ostream& salida, const DtVideojuegoIngresado& dtagrvd){
    cout << "Email: " << dtagrvd.email << endl;
    cout << "Nombre: " << dtagrvd.nombre << endl;
    cout << "Descripcion: " << dtagrvd.descripcion << endl;
    cout << "Costo Sub: " << dtagrvd.costoSub << endl;
    for (auto categoria : dtagrvd.categorias)
    {
        cout << "Categoria: " << *categoria << endl;
    }
    
    return salida;
}