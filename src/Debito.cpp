#include "Debito.h"

Debito::Debito()
{
    this->setCosto(0.0f);
    this->setCantEntradas(0);
    this->setUsuario(nullptr);
    this->setFuncion(nullptr);
    this->setBanco(nullptr);
}

Debito::Debito(float costo, int cantEntradas, Usuario *usuario, Funcion *funcion, Banco *banco) : Reserva(costo, cantEntradas, usuario, funcion), banco(banco) {}

Debito::~Debito() {}

// Getters
Banco *Debito::getBanco()
{
    return banco;
}

// Setters
void Debito::setBanco(Banco *banco)
{
    this->banco = banco;
}

TipoReserva Debito::getTipoReserva()
{
    return TipoReserva::DEBITO;
}

string Debito::getNombre()
{
    return this->banco->getNombre();
}