#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL
#include "DtPartida.h"

class DtPartidaIndividual : public DtPartida
{
private:
    bool continuaPartida;
public:
    DtPartidaIndividual();
    DtPartidaIndividual(int, DtFechaHora*, Usuario*, int, bool);
    bool getContinuaPartida();
    ~DtPartidaIndividual();

    friend ostream& operator << (ostream&, const DtPartidaIndividual&);
};

#endif