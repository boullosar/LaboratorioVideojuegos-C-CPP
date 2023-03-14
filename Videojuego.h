#ifndef VIDEOJUEGO
#define VIDEOJUEGO
#include <string>
#include <list>
#include "Categoria.h"
#include "Usuario.h"
#include "Estadisticas.h"
#include "ManejadorCategoria.h"
#include "Suscripcion.h"
#include "Partida.h"
#include "DtVideojuegoFull.h"
#include "DtCategoria.h"
#include "Desarrollador.h"
#include "PartidaMultijugador.h"
#include "PartidaIndividual.h"

using namespace std;

class Videojuego
{
private:
    string nombre;
    string descripcion;
    int costo;
    Usuario* usuario;
    list<Categoria*> categorias;
    list<Suscripcion*> suscripciones;
    list<Partida*> partidas;
    list<Estadisticas*> est;
public:
    Videojuego();
    Videojuego(string, string, int, Usuario*,list<Categoria*>);
    string getNombre();
    void setNombre(string);
    string getDescripcion();
    void setDescripcion(string);
    int getCosto();
    void setCosto(int);
    Usuario* getUsuario();
    void setUsuario(Usuario*);
    list<Categoria*> getCategorias();
    void setCategorias(list<Categoria*>);
    list<Suscripcion*> getSuscripciones();
    void setSuscripcion(list<Suscripcion*>);
    list<Partida*> getPartidas();
    void setPartida(list<Partida*>);
    virtual ~Videojuego();

    void agregarSuscripcion(Suscripcion*);
    void agregarPartida(Partida*);
    void agregarEstadistica(Estadisticas*);
    DtVideojuegoFull* getDatosVideojuego();
};

#endif