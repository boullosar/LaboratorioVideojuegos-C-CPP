#ifndef CONTROLADORAGREGARCATEGORIA
#define CONTROLADORAGREGARCATEGORIA
#include "IControladorAgregarCategoria.h"
#include "ManejadorCategoria.h"
#include "Categoria.h"
#include "DtCategoria.h"
#include <string>

using namespace std;

class ControladorAgregarCategoria : public IControladorAgregarCategoria{
    private:
        TipoGenero genero;
        TipoPlataforma plataforma;
    public:
        ControladorAgregarCategoria();

        list<DtCategoria*> listarCategorias();
        void datosNuevaCategoria(TipoGenero, TipoPlataforma);
        void confirmarCategoria();
        void cancelar();
        
        ~ControladorAgregarCategoria();
};

#endif