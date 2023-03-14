#ifndef DTVIDEOJUEGO
#define DTVIDEOJUEGO
#include <iostream>
#include <string>

using namespace std;

class DtVideojuego
{
private:
    string nombre;
    string descripcion;
public:
    DtVideojuego();
    DtVideojuego(string, string);
    string getNombre();
    string getDescripcion();
    ~DtVideojuego();

    friend ostream& operator << (ostream&, const DtVideojuego&);
};

#endif