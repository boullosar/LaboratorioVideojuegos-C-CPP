#ifndef DTVIDEOJUEGORANKING
#define DTVIDEOJUEGORANKING
#include <iostream>
#include <string>

using namespace std; 

class DtVideojuegoRanking{
    private:
        string nombre;
        string descripcion;
        float puntaje;
        int tiempoJugado;
    public:
        DtVideojuegoRanking();
        DtVideojuegoRanking(string,string,float,int);
        string getNombre();
        string getDescripcion();
        float getPuntaje();
        int getTiempoJugado();
        ~DtVideojuegoRanking();

        friend ostream& operator << (ostream&, const DtVideojuegoRanking&);
        friend bool operator <(const DtVideojuegoRanking&,const DtVideojuegoRanking&);
};

#endif