#include "Credito.h"

Credito::Credito()
{
    this->setCosto(0.0f);
    this->setCantEntradas(0);
    this->setUsuario(nullptr);
    this->setFuncion(nullptr);
    this->setFinanciera(nullptr);
}
Credito::Credito(float costo, int cantEntradas, Usuario *usuario, Funcion *funcion, Financiera *financiera) : Reserva(costo, cantEntradas, usuario, funcion), financiera(financiera) {}

Credito::~Credito() {}

Financiera *Credito::getFinanciera()
{
    return this->financiera;
}

void Credito::setFinanciera(Financiera *financiera)
{
    this->financiera = financiera;
}

TipoReserva Credito::getTipoReserva()
{
    return TipoReserva::CREDITO;
}

string Credito::getNombre()
{
    return this->financiera->getNombre();
}