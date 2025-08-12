#include "Reserva.h"
#include "../include/header/Funcion.h"

Reserva::Reserva()
{
}

Reserva::Reserva(float costo, int cantEntradas, Usuario *usuario, Funcion *funcion)
    : costo(costo), cantEntradas(cantEntradas), usuario(usuario), funcion(funcion) {}

// Getters
float Reserva::getCosto()
{
    return costo;
}
int Reserva::getCantEntradas()
{
    return cantEntradas;
}

// Setters
void Reserva::setCosto(float costo)
{
    this->costo = costo;
}
void Reserva::setCantEntradas(int cantEntradas)
{
    this->cantEntradas = cantEntradas;
}
void Reserva::setUsuario(Usuario *usuario)
{
    this->usuario = usuario;
}
void Reserva::setFuncion(Funcion *funcion)
{
    this->funcion = funcion;
}

Reserva::~Reserva()
{
}
