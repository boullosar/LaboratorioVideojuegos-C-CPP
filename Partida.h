#ifndef PARTIDA
#define PARTIDA
#include "DtFechaHora.h"
#include "Usuario.h"

class Partida
{
private:
    int id;
    DtFechaHora* dtFechaHora;
    int duracion;
    Usuario* usuario;
public:
    Partida();
    Partida(int, DtFechaHora*, int, Usuario*);
    int getId();
    void setId(int);
    DtFechaHora* getDtFechaHora();
    void setDtFechaHora(DtFechaHora*);
    int getDuracion();
    void setDuracion(int);
    Usuario* getUsuario();
    void setUsuario(Usuario*);
    virtual ~Partida();
};

#endif