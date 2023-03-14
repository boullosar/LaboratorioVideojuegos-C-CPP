#ifndef ICONTROLADORVERINFOVIDEOJUEGO
#define ICONTROLADORVERINFOVIDEOJUEGO
#include <list>
#include <string>
#include "DtVideojuegoFull.h"

using namespace std;

class IControladorVerInfoVideojuego
{
public:
    virtual list<string> listarVideojuegos()=0;
    virtual DtVideojuegoFull* verDatosJuego(string)=0;
};

#endif