#ifndef ICONTROLADORRANKINGVIDEOJUEGOS
#define ICONTROLADORRANKINGVIDEOJUEGOS
#include "DtVideojuegoRanking.h"
#include <list>

using namespace std;

class IControladorRankingVideojuegos{
    private:
    public:
        virtual list<DtVideojuegoRanking*> comoListar(int) = 0;
};


#endif