#include "DtPartida.h"

DtPartida::DtPartida(){}
DtPartida::DtPartida(int id, DtFechaHora* fechaHora, Usuario* usuario, int duracion){
    this->id=id;
    this->fechaHora=fechaHora;
    this->usuario=usuario;
    this->duracion=duracion;
}

int DtPartida::getId(){
    return this->id;
}
DtFechaHora* DtPartida::getFechaHora(){
    return this->fechaHora;
}
Usuario* DtPartida::getUsuario(){
    return this->usuario;
}
int DtPartida::getDuracion(){
    return this->duracion;
}

DtPartida::~DtPartida(){}

ostream& operator << (ostream& salida, const DtPartida& dtp){
    cout << "Id = " << dtp.id << endl;
    cout << "Fecha = " << *dtp.fechaHora;
    cout << "Usuario = " << dtp.usuario->getEmail() << endl;
    cout << "Duracion = " << dtp.duracion << endl;
    return salida;
}