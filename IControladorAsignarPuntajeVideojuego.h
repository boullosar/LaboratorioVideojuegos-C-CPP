#ifndef ICONTROLADORASIGNARPUNTAJEVIDEOJUEGO
#define ICONTROLADORASIGNARPUNTAJEVIDEOJUEGO
#include "DtVideojuego.h"
#include <string>
#include <list>

class IControladorAsignarPuntajeVideojuego
{
public:
    virtual list<DtVideojuego*> listarVideojuegos()=0;
    virtual void asignarPuntaje(string, int)=0;
};
#endif