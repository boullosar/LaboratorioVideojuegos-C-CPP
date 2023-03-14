#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR
#include "DtPartida.h"

class DtPartidaMultijugador : public DtPartida{
    private:
        bool seTransmite;
        int cantJug;
    public:
        DtPartidaMultijugador();
        DtPartidaMultijugador(int, DtFechaHora*, Usuario*, int, bool, int);
        bool getSeTransmite();
        int getCantJug();

        friend ostream& operator << (ostream&, const DtPartidaMultijugador&);
};


#endif