#ifndef ICONTROLADORVERPARTIDASVIDEOJUEGO
#define ICONTROLADORVERPARTIDASVIDEOJUEGO
#include <list>
#include <string>
#include "DtPartida.h"

using namespace std;

class IControladorVerPartidasVideojuego {
        public:
            virtual list<string> listarVideojuegos() = 0;
            virtual list<DtPartida*> verPartidasVideojuego(string) = 0;
};

#endif