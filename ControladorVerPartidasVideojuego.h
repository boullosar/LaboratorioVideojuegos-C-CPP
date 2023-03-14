#ifndef CONTROLADORVERPARTIDASVIDEOJUEGO
#define CONTROLADORVERPARTIDASVIDEOJUEGO
#include "IControladorVerPartidasVideojuego.h"
#include <string>
#include <list>


class ControladorVerPartidasVideojuego : public IControladorVerPartidasVideojuego {
    private:

    public:
        ControladorVerPartidasVideojuego();

        list<string> listarVideojuegos();
        list<DtPartida*> verPartidasVideojuego(string);

        ~ControladorVerPartidasVideojuego();

};

#endif