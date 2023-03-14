#include "DtCategoria.h"

DtCategoria::DtCategoria(TipoGenero genero, TipoPlataforma plataforma){
    this->genero=genero;
    this->plataforma=plataforma;
}

DtCategoria::DtCategoria(){}

TipoGenero DtCategoria::getGenero(){
    return this->genero;
}

TipoPlataforma DtCategoria::getPlataforma(){
    return this->plataforma;
}

DtCategoria::~DtCategoria(){}

ostream &operator << (ostream& salida, const DtCategoria& dtcat){
    string genero[4] = {"ACCION", "AVENTURA", "ESTRATEGIA", "DEPORTE"};
    string plataforma[6] = {"PC", "SWITCH", "PS4", "XBOX_ONE", "XBOX_X", "PS5"};
    cout << genero[dtcat.genero] << " - " << plataforma[dtcat.plataforma] << endl;
    return salida;
}