#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
#include <map>
#include "Usuario.h"
#include "Jugador.h"
#include "Desarrollador.h"

class ManejadorUsuario
{
private:
    map<string,Usuario*> usuarios;
    ManejadorUsuario();//singleton
    static ManejadorUsuario* instancia;//singleton
public:
    static ManejadorUsuario* getInstancia();//singleton
    void add(Usuario*);
    bool member(string);
    ~ManejadorUsuario();
    Usuario* find(string);

    bool existeNickname(string);
    bool existeEmail(string);
};

#endif