#ifndef DESARROLLADOR
#define DESARROLLADOR
#include "Usuario.h"

class Desarrollador : public Usuario
{
private:
    string nomEmpresa;
public:
    Desarrollador();
    Desarrollador(string, string, string);
    string getNomEmpresa();
    void setNomEmpresa(string);
    ~Desarrollador();
};

#endif