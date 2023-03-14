#ifndef CONTROLADORAUXILIAR
#define CONTROLADORAUXILIAR
#include "IControladorAuxiliar.h"
#include "Sesion.h"
#include "Desarrollador.h"

class ControladorAuxiliar : public IControladorAuxiliar{
    public:
        //si es usuario (no esta logeado) devuelve 1, si es Desarrollador devuelve 2 y si es jugador devuelve 3
        ControladorAuxiliar();
        int esDesarrollador();
        ~ControladorAuxiliar();
};

#endif