#include "ControladorBuscarVideojuego.h"
#include "ManejadorVideojuego.h"
#include "Videojuego.h"
#include <map>

ControladorBuscarVideojuego::ControladorBuscarVideojuego(){}

list<DtCategoria*> ControladorBuscarVideojuego::listarCategorias(){
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

void ControladorBuscarVideojuego::ControladorBuscarVideojuego::seleccionaCategoria(DtCategoria* categoria){
    ManejadorCategoria* mc = ManejadorCategoria::getInstancia();
    Categoria* cat = new Categoria(categoria->getGenero(),categoria->getPlataforma());
    if (mc->member(cat))
    {
        this->categoria=cat;
    }else{
        throw invalid_argument("La categoría no existe");
    }    
}

list<DtVideojuego*> ControladorBuscarVideojuego::listarVideojuegos(){
    list<DtVideojuego*> VideojuegosEnc;
    ManejadorVideojuego* manVid = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos = manVid->listarVideojuegos();
    if(!videojuegos.empty()){
        for (auto videojuego : videojuegos){
            if (!videojuego->getCategorias().empty())
            {
                for (auto cat : videojuego->getCategorias())
                {
                    if (cat->getGenero() == this->categoria->getGenero() && cat->getPlataforma() == this->categoria->getPlataforma())
                    {
                        DtVideojuego* dtv = new DtVideojuego(videojuego->getNombre(), videojuego->getDescripcion());
                        VideojuegosEnc.push_back(dtv);
                    }
                }
            }
        }
        if (VideojuegosEnc.empty())
        {
            throw invalid_argument("No hay videojuegos con esa categoría");
        }
        return VideojuegosEnc;
    }else{
        throw invalid_argument("No hay videojuegos ingresados");
    }
}

ControladorBuscarVideojuego::~ControladorBuscarVideojuego(){}