#include "DtVideojuegoRanking.h"

DtVideojuegoRanking::DtVideojuegoRanking(){}

DtVideojuegoRanking::DtVideojuegoRanking(string nombre,string descripcion,float puntaje,int tiempoJugado){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->puntaje = puntaje;
    this->tiempoJugado = tiempoJugado;
}

string DtVideojuegoRanking::getNombre(){
    return this->nombre;
}

string DtVideojuegoRanking::getDescripcion(){
    return this->descripcion;
}

float DtVideojuegoRanking::getPuntaje(){
    return this->puntaje;
}

int DtVideojuegoRanking::getTiempoJugado(){
    return this->tiempoJugado;
}

DtVideojuegoRanking::~DtVideojuegoRanking(){}


ostream& operator << (ostream& salida, const DtVideojuegoRanking& dtvran){
    cout << "Nombre: " << dtvran.nombre << endl;
    cout << "Descripción: " << dtvran.descripcion << endl;
    cout << "Puntaje: " << dtvran.puntaje << endl;
    cout << "Tiempo jugado: " << dtvran.tiempoJugado << endl;

    return salida;
}

bool operator <(const DtVideojuegoRanking& f1, const DtVideojuegoRanking& f2){
  bool retorno;
  if (f1.puntaje < f2.puntaje){
    retorno=true;
  } else if (f1.puntaje == f2.puntaje){
    retorno=true;
  } else if (f1.puntaje > f2.puntaje){
    retorno=false;
  }
  return retorno;
}