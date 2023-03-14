#ifndef DTPARTIDA
#define DTPARTIDA
#include <string>
#include "DtFechaHora.h"
#include "Usuario.h"

using namespace std;

class DtPartida {
    private:
        int id;
        DtFechaHora* fechaHora;
        Usuario* usuario;
        int duracion;

    public:
        DtPartida();
        DtPartida(int, DtFechaHora*, Usuario*, int);

        virtual int getId();
        DtFechaHora* getFechaHora();
        Usuario* getUsuario();
        int getDuracion();

        virtual ~DtPartida();

        friend ostream& operator << (ostream&, const DtPartida&);
};

#endif