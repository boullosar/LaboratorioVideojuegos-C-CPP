#include "ControladorAgregarVideojuego.h"

ControladorAgregarVideojuego::ControladorAgregarVideojuego(){}

void ControladorAgregarVideojuego::ingresaDatosVideojuego(string nombre, string descripcion, float costoSub){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    if (!mv->existeVideojuego(nombre))
    {
        this->nombre=nombre;
        this->descripcion=descripcion;
        this->costoSub=costoSub;
    }else{
        throw invalid_argument("El videojuego ya existe");
    }
}

list<DtCategoria*> ControladorAgregarVideojuego::listarCategorias(){
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

void ControladorAgregarVideojuego::ControladorAgregarVideojuego::seleccionaCategoria(DtCategoria* categoria){
    this->categorias.push_back(categoria);
}

DtVideojuegoIngresado* ControladorAgregarVideojuego::listarInfo(){
    if (categorias.empty())
    {
        throw invalid_argument("No se seleccionaron categorías para este juego");
    }
    
    categorias.unique();
    Sesion* ses = Sesion::getSesion();
    DtVideojuegoIngresado* dtvji = new DtVideojuegoIngresado(ses->getUsuario()->getEmail(), this->nombre,this->descripcion,this->costoSub, this->categorias);
    return dtvji;
}

void ControladorAgregarVideojuego::AltaVideojuego(){
    //paso 1
    Sesion* ses = Sesion::getSesion();
    //paso auxiliar
    list<Categoria*> categoriasClas;
    for (auto categoria : categorias)
    {
        Categoria* cat = new Categoria(categoria->getGenero(),categoria->getPlataforma());
        categoriasClas.push_back(cat);
    }
    //paso 2
    Videojuego* videojuego = new Videojuego(this->nombre,this->descripcion,this->costoSub,ses->getUsuario(),categoriasClas);
    
    //paso 3
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    mv->add(videojuego);
    cancelar();
}

void ControladorAgregarVideojuego::cancelar(){
    this->nombre="";
    this->descripcion="";
    this->costoSub=0;
    this->categorias.clear();
}

ControladorAgregarVideojuego::~ControladorAgregarVideojuego(){}