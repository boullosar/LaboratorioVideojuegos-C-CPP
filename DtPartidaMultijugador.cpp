#include "DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(){}
DtPartidaMultijugador::DtPartidaMultijugador(int id, DtFechaHora* fechaHora, Usuario* usuario, int duracion, bool seTransmite, int cantJug):DtPartida(id, fechaHora, usuario, duracion){
    this->seTransmite=seTransmite;
    this->cantJug=cantJug;
}
bool DtPartidaMultijugador::getSeTransmite(){
    return this->seTransmite;
}
int DtPartidaMultijugador::getCantJug(){
    return this->cantJug;
}

ostream& operator << (ostream& salida, const DtPartidaMultijugador& dtpm){
    if(dtpm.seTransmite){
        cout << "La partida SI se transmite" << endl;
    }
    else {
        cout << "La partida NO se transmite" << endl;
    }
    cout << "Cantidad de jugadores: " << dtpm.cantJug << endl;

    return salida;
}