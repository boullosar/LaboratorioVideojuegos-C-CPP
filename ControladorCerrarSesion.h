#ifndef CONTROLADORCERRARSESION
#define CONTROLADORCERRARSESION
#include "IControladorCerrarSesion.h"
#include <iostream>
#include "Sesion.h"

class ControladorCerrarSesion : public IControladorCerrarSesion {
    public:
        ControladorCerrarSesion();

        void cerrarSesion();

        ~ControladorCerrarSesion();
};

#endif