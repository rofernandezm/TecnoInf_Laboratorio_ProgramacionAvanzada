#ifndef DTCINE_H
#define DTCINE_H
#include "DtDireccion.h"

class DtCine
{
private:
    int id;
    DtDireccion direccion;

public:
    DtCine();
    DtCine(int, DtDireccion);
    ~DtCine();

    //Getters
    int getId();
    DtDireccion getDireccion();
};

#endif