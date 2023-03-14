#ifndef CONTROLADORINICIARSESION
#define CONTROLADORINICIARSESION
#include "IControladorIniciarSesion.h"

#include <string>

using namespace std;

class ControladorIniciarSesion : public IControladorIniciarSesion {
    private:
        string email;
        string pass;

    public:
        ControladorIniciarSesion();

        bool datosComunes(string, string);
        void cancelar();
        void iniciarSesion();

        ~ControladorIniciarSesion();
};

#endif