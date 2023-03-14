#include "Desarrollador.h"

Desarrollador::Desarrollador(){}
Desarrollador::Desarrollador(string email, string pass, string nomEmpresa):Usuario(email, pass){
    this->nomEmpresa=nomEmpresa;
}

string Desarrollador::getNomEmpresa(){
    return this->nomEmpresa;
}

void Desarrollador::setNomEmpresa(string nomEmpresa){
    this->nomEmpresa=nomEmpresa;
}

Desarrollador::~Desarrollador(){}