#ifndef ESTADISTICAS
#define ESTADISTICAS
#include <iostream>

using namespace std;

class Estadisticas{
    private:
        int puntaje;
    public:
        Estadisticas();
        Estadisticas(int);
        int getPuntaje();
        void setPuntaje(int);
        ~Estadisticas();
};

#endif