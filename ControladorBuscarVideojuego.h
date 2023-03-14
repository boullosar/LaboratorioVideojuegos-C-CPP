#ifndef CONTROLADORBUSCARVIDEOJUEGO
#define CONTROLADORBUSCARVIDEOJUEGO
#include <string>
#include <list>
#include "IControladorBuscarVideojuego.h"
#include "DtCategoria.h"
#include "Categoria.h"

class ControladorBuscarVideojuego : public IControladorBuscarVideojuego
{
private:   
    Categoria* categoria;
public:
    ControladorBuscarVideojuego();
    list<DtCategoria*> listarCategorias();
    void seleccionaCategoria(DtCategoria*);
    list<DtVideojuego*> listarVideojuegos();
    ~ControladorBuscarVideojuego();
};

#endif