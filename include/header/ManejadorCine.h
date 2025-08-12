
#ifndef MANEJADORCINE_H
#define MANEJADORCINE_H

#include <map>
#include <memory>
#include "Cine.h"
#include "DtCine.h"

using namespace std;

class ManejadorCine
{
private:
    static ManejadorCine* instancia;
    ManejadorCine();
    ~ManejadorCine();

    map<int, unique_ptr<Cine>> cines;
    int idCine;

public:
    static ManejadorCine *getInstancia();

    void agregarCine(Cine *cine);
    bool existeCine(int id);
    Cine *buscarCine(int id);
    map<int, DtCine> listarCines();
};

#endif /* MANEJADORCINE_H */
