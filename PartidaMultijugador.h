#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR
#include "Partida.h"

class PartidaMultijugador : public Partida
{
private:
    int cantJugadores;
    bool enVivo;
public:
    PartidaMultijugador();
    PartidaMultijugador(int, DtFechaHora*, int, Usuario*, int, bool);
    int getCantJugadores();
    void setCantJugadores(int);
    bool getEnVivo();
    void setEnVivo(bool);
    ~PartidaMultijugador();
};

#endif