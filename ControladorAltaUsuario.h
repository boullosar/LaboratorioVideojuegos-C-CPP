#ifndef CONTROLADORALTAUSUARIO
#define CONTROLADORALTAUSUARIO
#include "IControladorAltaUsuario.h"
#include "ManejadorUsuario.h"
using namespace std;

class ControladorAltaUsuario : public IControladorAltaUsuario
{
private:
    string email;
    string pass;
    string nomEmpresa;
    string nickname;
    string descripcion;
public:
    ControladorAltaUsuario();

    void datosComunes(string, string);
    void datosEmpresa(string);
    bool datosJugador(string, string);
    bool ingresarNickname(string);
    void altaUsuario();
    void cancelar();

    ~ControladorAltaUsuario();
};

#endif