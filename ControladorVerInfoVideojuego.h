#ifndef CONTROLADORVERINFOVIDEOJUEGO
#define CONTROLADORVERINFOVIDEOJUEGO
#include "IControladorVerInfoVideojuego.h"

class ControladorVerInfoVideojuego : public IControladorVerInfoVideojuego
{
private:
    
public:
    ControladorVerInfoVideojuego();
    list<string> listarVideojuegos();
    DtVideojuegoFull* verDatosJuego(string);
    ~ControladorVerInfoVideojuego();
};

#endif