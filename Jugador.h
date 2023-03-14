#ifndef JUGADOR
#define JUGADOR
#include "Usuario.h"

class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
public:
    Jugador();
    Jugador(string,string,string,string);
    string getNickname();
    void setNickname(string);
    string getDescripcion();
    void setDescripcion(string);
    ~Jugador();
};



#endif