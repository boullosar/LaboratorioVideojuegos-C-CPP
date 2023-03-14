#ifndef SUSCRIPCION
#define SUSCRIPCION
#include "Usuario.h"
#include "DtFechaHora.h"
#include "TipoPago.h"
#include "Jugador.h"

class Suscripcion
{
private:
    TipoPago tipoPago;
    int costo;
    DtFechaHora* dtFechaHora;
    Usuario* usuario;
public:
    Suscripcion();
    Suscripcion(TipoPago, int, DtFechaHora*, Usuario*);

    TipoPago getTipoPago();
    void setTipoPago(TipoPago);
    int getCosto();
    void setCosto(int);
    DtFechaHora* getDtFechaHora();
    void setDtFechaHora(DtFechaHora*);
    Usuario* getUsuario();
    void setUsuario(Usuario*);
    ~Suscripcion();

    void Suscribirse(TipoPago, int, DtFechaHora*, Usuario*);
};

#endif