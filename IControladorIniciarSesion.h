#ifndef ICONTROLADORINICIARSESION
#define ICONTROLADORINICIARSESION
#include <string>

using namespace std;

class IControladorIniciarSesion
{
public:
    virtual bool datosComunes(string, string)=0;
    virtual void iniciarSesion()=0;
    virtual void cancelar()=0;
};

#endif