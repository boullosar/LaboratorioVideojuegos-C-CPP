#include "DtVideojuegoFull.h"

DtVideojuegoFull::DtVideojuegoFull(){}
DtVideojuegoFull::DtVideojuegoFull(string nombre,list<DtCategoria*> categorias,string empresa,int horasTotal,float puntajePromedio,string descripcion,int costo){
    this->nombre=nombre;
    this->categorias=categorias;
    this->empresa=empresa;
    this->horasTotal=horasTotal;
    this->puntajePromedio=puntajePromedio;
    this->descripcion=descripcion;
    this->costo=costo;
}
string DtVideojuegoFull::getNombre(){
    return this->nombre;
}

list<DtCategoria*> DtVideojuegoFull::getCategoria(){
    return this->categorias;
}
string DtVideojuegoFull::getEmpresa(){
    return this->empresa;
}

int DtVideojuegoFull::getHorasTotal(){
    return this->horasTotal;
}

float DtVideojuegoFull::getPuntajePromedio(){
    return this->puntajePromedio;
}

string DtVideojuegoFull::getDescripcion(){
    return this->descripcion;
}

int DtVideojuegoFull::getCosto(){
    return this->costo;
}

DtVideojuegoFull::~DtVideojuegoFull(){}

ostream& operator << (ostream& salida, const DtVideojuegoFull& dtvf){
    cout << "Nombre: " << dtvf.nombre << "\n" << endl;

    for(auto c : dtvf.categorias){
        cout << "Categorías: " << *c << "\n" << endl;
    }

    cout << "Empresa: " << dtvf.empresa << "\n" 
    << "Horas totales: " << dtvf.horasTotal << "\n" 
    << "Puntaje promedio: " << dtvf.puntajePromedio << "\n" 
    << "Descripción: " << dtvf.descripcion << "\n" 
    << "Costo: " << dtvf.costo << "\n" << endl;
    return salida;
}