#include "DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual(){}
DtPartidaIndividual::DtPartidaIndividual(int id, DtFechaHora* fechaHora, Usuario* usuario, int duracion, bool continuaPartida):DtPartida(id, fechaHora, usuario, duracion){
    this->continuaPartida=continuaPartida;
}
bool DtPartidaIndividual::getContinuaPartida(){
    return this->continuaPartida;
}
DtPartidaIndividual::~DtPartidaIndividual(){}

ostream& operator << (ostream& salida, const DtPartidaIndividual& dtpi){
    if (dtpi.continuaPartida){
        cout << "Sí continua partida anterior" << endl;
    }
    else {
        cout << "No continua partida anterior" << endl;
    }
    return salida;
}