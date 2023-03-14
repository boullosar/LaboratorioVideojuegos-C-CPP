#include "ManejadorCategoria.h"

using namespace std;

ManejadorCategoria *ManejadorCategoria::instancia=NULL;

ManejadorCategoria::ManejadorCategoria(){}

ManejadorCategoria* ManejadorCategoria::getInstancia(){
    if(instancia==NULL){
        instancia = new ManejadorCategoria();
    }
    return instancia;
}

void ManejadorCategoria::add(Categoria* categoria){
    categorias.push_back(categoria);
}

bool ManejadorCategoria::member(Categoria* categoria){
    bool member = false;
    list<Categoria*>::iterator it;
    for (it=categorias.begin(); it!=categorias.end(); ++it){
        if ((*it)->getGenero() == categoria->getGenero() && categoria->getPlataforma() == (*it)->getPlataforma())
            member = true;
    }
    return member;
}

list<Categoria*> ManejadorCategoria::listarCategorias(){
    return categorias;
}

Categoria* ManejadorCategoria::find(Categoria* categoria){
    Categoria* ret = NULL;
    list<Categoria*>::iterator it;
    for(it=categorias.begin(); it!=categorias.end(); ++it){
        if(categoria->getGenero() == (*it)->getGenero() && categoria->getPlataforma() == (*it)->getPlataforma()){
            ret = categoria; 
        }
    }
    return ret;
}

ManejadorCategoria::~ManejadorCategoria(){}
