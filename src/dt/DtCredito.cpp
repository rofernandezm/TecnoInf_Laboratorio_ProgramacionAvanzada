#include "DtCredito.h"

DtCredito::DtCredito(float costo, int cantEntradas, float porcentajeDescuento, string nombreFinanciera) : DtReserva(costo, cantEntradas), porcentajeDescuento(porcentajeDescuento), nombreFinanciera(nombreFinanciera) {}

DtCredito::~DtCredito() {}

float DtCredito::getPorcentajeDescuento()
{
    return this->porcentajeDescuento;
}

string DtCredito::getNombre()
{
    return this->nombreFinanciera;
}

TipoReserva DtCredito::getTipoReserva()
{
    return TipoReserva::CREDITO;
}