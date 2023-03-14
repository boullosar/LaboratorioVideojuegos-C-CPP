#include "Usuario.h"

Usuario::Usuario(){}
Usuario::Usuario(string email, string pass){
    this->email=email;
    this->pass=pass;
}

string Usuario::getEmail(){
    return this->email;
}

void Usuario::setEmail(string email){
    this->email=email;
}

string Usuario::getPass(){
    return this->pass;
}

void Usuario::setPass(string pass){
    this->pass=pass;
}

Usuario::~Usuario(){}