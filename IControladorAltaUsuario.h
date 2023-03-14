#ifndef ICONTROLADORALTAUSUARIO
#define ICONTROLADORALTAUSUARIO
#include <string>

using namespace std;

class IControladorAltaUsuario
{
public:
    virtual void datosComunes(string, string)=0;
    virtual void datosEmpresa(string)=0;
    virtual bool datosJugador(string, string)=0;
    virtual bool ingresarNickname(string)=0;
    virtual void altaUsuario()=0;
    virtual void cancelar()=0;
};

#endif