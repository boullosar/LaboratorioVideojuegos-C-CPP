#include "ControladorAgregarCategoria.h"

ControladorAgregarCategoria::ControladorAgregarCategoria(){}

list<DtCategoria*> ControladorAgregarCategoria::listarCategorias(){
    list<DtCategoria*> dtCategorias;
    ManejadorCategoria* mc = ManejadorCategoria::getInstancia();
    list<Categoria*> categorias = mc->listarCategorias();
    if (categorias.empty())
    {
        throw invalid_argument("No hay categorias");
    }

    list<Categoria*>::iterator it;
    for (it=categorias.begin(); it!=categorias.end(); ++it){
        DtCategoria* dtcat = new DtCategoria((*it)->getGenero(), (*it)->getPlataforma());
        dtCategorias.push_back(dtcat);
    }
    return dtCategorias;
}


void ControladorAgregarCategoria::datosNuevaCategoria(TipoGenero genero, TipoPlataforma plataforma){
    this->genero=genero;
    this->plataforma=plataforma;
}

void ControladorAgregarCategoria::confirmarCategoria(){
    ManejadorCategoria* mc = ManejadorCategoria::getInstancia();
    Categoria* cate = new Categoria(this->genero, this->plataforma);
    if (mc->find(cate) != NULL)
    {
        throw invalid_argument("Ya existe la categoría");   
    }
    mc->add(cate);
    cancelar();
}

void ControladorAgregarCategoria::cancelar(){

}

ControladorAgregarCategoria::~ControladorAgregarCategoria(){}