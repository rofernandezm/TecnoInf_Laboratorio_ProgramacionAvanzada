#ifndef DTRESERVA_H
#define DTRESERVA_H
#include "Utils.h"

class DtReserva
{
private:
    float costo;
    int cantEntradas;

public:
    DtReserva();
    DtReserva(float, int);
    virtual ~DtReserva();

    //Getters
    float getCosto();
    int getCantEntradas();

    // Others
    virtual string getNombre() = 0;
    virtual TipoReserva getTipoReserva() = 0;
};

#endif