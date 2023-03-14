#include "ControladorRankingVideojuegos.h"

ControladorRankingVideojuegos::ControladorRankingVideojuegos(){}

list<DtVideojuegoRanking*> ControladorRankingVideojuegos::comoListar(int tipoListado){
    list<DtVideojuegoRanking*> videojuegos;
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Videojuego*> videojuegos2 = mv->listarVideojuegos();
    bool insertado = false;
    if(videojuegos2.empty()){
        throw invalid_argument("No hay videojuegos ingresados en el sistema");
    }
    list<Videojuego*>::iterator vj = videojuegos2.begin();
    DtVideojuegoFull* dtvf = (*vj)->getDatosVideojuego();

    DtVideojuegoRanking* dtvr = new DtVideojuegoRanking(dtvf->getNombre(),dtvf->getDescripcion(),dtvf->getPuntajePromedio(),dtvf->getHorasTotal());
    videojuegos.push_back(dtvr);
    ++vj;
    for(vj;vj!=videojuegos2.end(); ++vj){
        dtvf = (*vj)->getDatosVideojuego();

        dtvr = new DtVideojuegoRanking(dtvf->getNombre(),dtvf->getDescripcion(),dtvf->getPuntajePromedio(),dtvf->getHorasTotal());
        list<DtVideojuegoRanking*>::iterator vjr = videojuegos.begin();
        insertado = false;
        for (vjr; vjr!=videojuegos.end() || (vjr==videojuegos.end() && videojuegos.end()==videojuegos.begin()); ++vjr)
        {
            if(tipoListado == 1){                           //Por puntuación
                if(!videojuegos.empty() && moM((*vjr)->getPuntaje(), dtvr->getPuntaje()) && !insertado){
                    videojuegos.insert(vjr, dtvr);
                    insertado = true;
                }
            }
            else if(tipoListado == 2){                      //Por horas jugadas        
                if(!videojuegos.empty() && moM((*vjr)->getTiempoJugado(), dtvr->getTiempoJugado()) && !insertado){
                    videojuegos.insert(vjr, dtvr);
                    insertado = true;
                }
            }
        }

        if(vjr==videojuegos.end() && !insertado){
            videojuegos.push_front(dtvr);
        }
    }

return videojuegos;
}

ControladorRankingVideojuegos::~ControladorRankingVideojuegos(){}

bool ControladorRankingVideojuegos::moM(float f1, float f2){
    bool retorno;
    if (f1 < f2){
        retorno=true;
    } else if (f1 == f2){
        retorno=true;
    } else if (f1 > f2){
        retorno=false;
    }
    return retorno;
}
