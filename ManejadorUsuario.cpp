#include "ManejadorUsuario.h"

ManejadorUsuario *ManejadorUsuario::instancia=NULL; //por singleton

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){//singleton
    if (instancia==NULL)
    {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

void ManejadorUsuario::add(Usuario* usuario){
    this->usuarios.insert(pair<string, Usuario*>(usuario->getEmail(), usuario));
}

bool ManejadorUsuario::member(string email){
    map<string, Usuario*>::iterator it = this->usuarios.find(email);
    return (it != this->usuarios.end());
}

ManejadorUsuario::~ManejadorUsuario(){}

bool ManejadorUsuario::existeNickname(string nickname){
    for (map<string, Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); it++){
        Jugador* ju = dynamic_cast<Jugador*>(it->second);
        if (ju != NULL){
            if (ju->getNickname() == nickname)
            {
                return true;
            }
        }
    }
    return false;
}

bool ManejadorUsuario::existeEmail(string email){
    for (map<string, Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); it++){
        Jugador* ju = dynamic_cast<Jugador*>(it->second);
        if (ju != NULL){
            if (ju->getEmail() == email)
            {
                return true;
            }
        }
    }
    return false;
}

Usuario* ManejadorUsuario::find(string email){
    map<string, Usuario*>::iterator it = this->usuarios.find(email);
    return it->second;
}