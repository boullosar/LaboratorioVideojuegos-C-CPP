#ifndef MANEJADORCATEGORIA
#define MANEJADORCATEGORIA
#include "Categoria.h"
#include <list>

using namespace std;

class ManejadorCategoria
{
private:
    list<Categoria*> categorias;
    ManejadorCategoria();
    static ManejadorCategoria* instancia;
public:
    static ManejadorCategoria* getInstancia();

    void add(Categoria*);
    bool member(Categoria*);
    list<Categoria*> listarCategorias();
    Categoria* find(Categoria*);
    
    ~ManejadorCategoria();
};

#endif