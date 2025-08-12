#include "Banco.h"

Banco::Banco() {}

Banco::Banco(string nombre) : nombre(nombre) {}

Banco::~Banco() {}

// Getters
string Banco::getNombre()
{
    return this->nombre;
}

// Setters
void Banco::setNombre(string nombre)
{
    this->nombre = nombre;
}