#ifndef CONTROLADORELIMINARVIDEOJUEGO
#define CONTROLADORELIMINARVIDEOJUEGO
#include "IControladorEliminarVideojuego.h"
#include "ManejadorVideojuego.h"
#include "Sesion.h"
#include <list>
#include <string>

using namespace std;

class ControladorEliminarVideojuego : public IControladorEliminarVideojuego{
    private:
        string nombre;
    public: 
        ControladorEliminarVideojuego();
        
        list<string> listarVideojuegosDesarrollador();
        void seleccionarVideojuego(string);
        void confirmarEliminacion();
        void cancelar();
        ~ControladorEliminarVideojuego();
};

#endif