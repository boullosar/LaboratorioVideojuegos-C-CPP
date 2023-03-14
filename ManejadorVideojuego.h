#ifndef MANEJADORVIDEOJUEGO
#define MANEJADORVIDEOJUEGO
#include "Videojuego.h"
#include <map>

class ManejadorVideojuego
{
    private:
        map<string, Videojuego*> videojuegos;
        ManejadorVideojuego();
        static ManejadorVideojuego* instancia;
    public:
        static ManejadorVideojuego* getInstancia();

        void add(Videojuego*);
        bool member(string);
        Videojuego* find(string);
        bool existeVideojuego(string);
        list<Videojuego*> listarVideojuegos();
        void remove(string);
        ~ManejadorVideojuego();
};

#endif