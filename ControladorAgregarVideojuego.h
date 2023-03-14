#ifndef CONTROLADORAGREGARVIDEOJUEGO
#define CONTROLADORAGREGARVIDEOJUEGO
#include "IControladorAgregarVideojuego.h"
#include <string>
#include <list>
#include "DtCategoria.h"
#include "DtVideojuegoIngresado.h"
#include "ManejadorCategoria.h"
#include "ManejadorVideojuego.h"
#include "TipoGenero.h"
#include "TipoPlataforma.h"
#include "Usuario.h"
#include "Sesion.h"
#include "Videojuego.h"

using namespace std;

class ControladorAgregarVideojuego : public IControladorAgregarVideojuego{
    private:
        string nombre;
        string descripcion;
        int costoSub;
        list<DtCategoria*> categorias;
    public:
        ControladorAgregarVideojuego();

        void ingresaDatosVideojuego(string, string, float);
        list<DtCategoria*> listarCategorias();
        void seleccionaCategoria(DtCategoria*);
        DtVideojuegoIngresado* listarInfo();
        void AltaVideojuego();
        void cancelar();

        ~ControladorAgregarVideojuego();
};


#endif