#include "DtReserva.h"

DtReserva::DtReserva() : costo(0.0f), cantEntradas(0) {}

DtReserva::DtReserva(float costo, int cantEntradas) : costo(costo), cantEntradas(cantEntradas) {}

DtReserva::~DtReserva() {}

float DtReserva::getCosto()
{
    return this->costo;
}

int DtReserva::getCantEntradas()
{
    return this->cantEntradas;
}