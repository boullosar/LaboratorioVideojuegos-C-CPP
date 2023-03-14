#include "DtSuscripciones.h"
#include <iostream>

DtSuscripciones::DtSuscripciones(){}
DtSuscripciones::DtSuscripciones(string nomVideojuego, int costo){
    this->nomVideojuego=nomVideojuego;
    this->costo=costo;
}

string DtSuscripciones::getNomVideojuego(){
    return this->nomVideojuego;
}

int DtSuscripciones::getCosto(){
    return this->costo;
}

DtSuscripciones::~DtSuscripciones(){}

ostream &operator << (ostream& salida, const DtSuscripciones& dts){
    cout << dts.nomVideojuego << " - " << dts.costo << endl;
    return salida;
}