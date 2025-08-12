#ifndef CINE_H
#define CINE_H

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <set>
#include <memory>
#include <ctime>
#include <map>
#include "DtCine.h"
#include "DtDireccion.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include "Sala.h"

using namespace std;

class Cine
{
private:
    int id;
    DtDireccion direccion;
    set<unique_ptr<Sala>> salas;

public:
    Cine();
    Cine(DtDireccion);
    Cine(DtCine);

    // Getters
    int getId();
    DtDireccion getDireccion();
    Sala* getSala(int);

    // Setters
    void setId(int);
    void setDireccion(DtDireccion);

    // Metodos
    void agregarSala(unique_ptr<Sala>);
    DtSala devolverSala(int);
    map<int, DtSala> listarSalas();
    DtCine obtenerInfo();

    ~Cine();
};

#endif