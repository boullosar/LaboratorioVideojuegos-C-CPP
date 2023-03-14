#ifndef CONTROLADORASIGNARPUNTAJEVIDEOJUEGO
#define CONTROLADORASIGNARPUNTAJEVIDEOJUEGO
#include "IControladorAsignarPuntajeVideojuego.h"
#include "ManejadorVideojuego.h"
#include "Estadisticas.h"
#include <string>

using namespace std;

class ControladorAsignarPuntajeVideojuego : public IControladorAsignarPuntajeVideojuego
{
private:
public:
    ControladorAsignarPuntajeVideojuego();
    list<DtVideojuego*> listarVideojuegos();
    void asignarPuntaje(string, int);
    ~ControladorAsignarPuntajeVideojuego();
};

#endif