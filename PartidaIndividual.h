#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL
#include "Partida.h"

class PartidaIndividual :public Partida
{
private:
    bool conPartida;
public:
    PartidaIndividual();
    PartidaIndividual(int, DtFechaHora*, int, Usuario*, bool);
    bool getConPartida();
    void setConPartida(bool);
    ~PartidaIndividual();
};

#endif