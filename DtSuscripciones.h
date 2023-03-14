#ifndef DTSUSCRIPCIONES
#define DTSUSCRIPCIONES
#include <string>

using namespace std;

class DtSuscripciones
{
private:
    string nomVideojuego;
    int costo;
public:
    DtSuscripciones();
    DtSuscripciones(string, int);
    string getNomVideojuego();
    int getCosto();
    ~DtSuscripciones();

    friend ostream& operator << (ostream&, const DtSuscripciones&);
};


#endif