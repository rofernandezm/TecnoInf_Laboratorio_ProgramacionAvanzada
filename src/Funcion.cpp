#include "../include/header/Funcion.h"
#include "../include/header/Sala.h"
#include "../include/header/Reserva.h"

Funcion::Funcion() : dia(DtFecha()), horario(DtHorario())
{
    this->id = static_cast<int>(time(nullptr));
}

Funcion::Funcion(DtFecha dia, DtHorario horario, Sala *sala) : dia(dia), horario(horario), sala(sala)
{
    this->id = static_cast<int>(time(nullptr));
}
Funcion::~Funcion()
{
    this->dia.~DtFecha();
    for (Reserva *r : reservas)
    {
        delete r;
    }
    reservas.clear();
}

// Getters
int Funcion::getId()
{
    return this->id;
}

DtFecha Funcion::getDia()
{
    return this->dia;
}

Sala *Funcion::getSala()
{
    return this->sala;
}

DtSala Funcion::obtenerSala()
{
    return this->sala->obtenerDtSala();
}

DtFuncion Funcion::obtenerFuncion()
{
    return DtFuncion(this->id, this->dia, this->horario);
}

// Setters
void Funcion::setDia(DtFecha dia)
{
    this->dia = dia;
}

void Funcion::setHorario(DtHorario horario)
{
    this->horario = horario;
}

void Funcion::setSala(Sala *sala)
{
    this->sala = sala;
}
void Funcion::eliminarReservas()
{
    for (Reserva *r : reservas)
    {
        delete r;
    }
    reservas.clear();
}

void Funcion::agregarReserva(Reserva *reserva)
{
    reservas.insert(reserva);
}

set<Reserva *> Funcion::obtenerReservas()
{
    return this->reservas;
}

bool Funcion::tieneReservas()
{
    return this->reservas.size() > 0;
}