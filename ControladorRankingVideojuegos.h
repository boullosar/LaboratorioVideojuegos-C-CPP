#ifndef CONTROLADORRANKINGVIDEOJUEGOS
#define CONTROLADORRANKINGVIDEOJUEGOS
#include "IControladorRankingVideojuegos.h"
#include "DtVideojuegoRanking.h"
#include "ManejadorVideojuego.h"
#include <list>

using namespace std;

class ControladorRankingVideojuegos : public IControladorRankingVideojuegos{
    private:
    public:
        ControladorRankingVideojuegos();
        list<DtVideojuegoRanking*> comoListar(int);
        ~ControladorRankingVideojuegos();
        bool moM(float, float);
};


#endif