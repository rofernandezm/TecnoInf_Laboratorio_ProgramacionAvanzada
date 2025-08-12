#include "DtDebito.h"

DtDebito::DtDebito(float costo, int cantEntradas, string nombreBanco) : DtReserva(costo, cantEntradas), nombreBanco(nombreBanco) {}

DtDebito::~DtDebito() {}

string DtDebito::getNombre()
{
    return this->nombreBanco;
}

TipoReserva DtDebito::getTipoReserva()
{
    return TipoReserva::DEBITO;
}