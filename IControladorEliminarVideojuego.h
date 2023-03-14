#ifndef ICONTROLADORELIMINARVIDEOJUEGO
#define ICONTROLADORELIMINARVIDEOJUEGO
#include <list>
#include <string>

using namespace std;


class IControladorEliminarVideojuego{
    public:
        virtual list<string> listarVideojuegosDesarrollador() = 0;
        virtual void seleccionarVideojuego(string) = 0;
        virtual void confirmarEliminacion() = 0;
        virtual void cancelar() = 0;

};

#endif