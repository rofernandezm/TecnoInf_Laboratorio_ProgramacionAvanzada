#include "Sala.h"
#include "Cine.h"

Sala::Sala(int id, int capacidad) : id(id), capacidad(capacidad) {}

Sala::Sala(DtSala dtSala) : id(dtSala.getId()), capacidad(dtSala.getCapacidad()) {}

Sala::~Sala()
{
    this->cine = nullptr;
}

// Getters
int Sala::getId()
{
    return this->id;
}

int Sala::getCapacidad()
{
    return this->capacidad;
}

Cine *Sala::getCine()
{
    return this->cine;
}

// Setters
void Sala::setId(int id)
{
    this->id = id;
}

void Sala::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

void Sala::setCine(Cine* cine)
{
    this->cine = cine;
}

// Other methods
DtSala Sala::obtenerDtSala()
{
    return DtSala(this->id, this->capacidad);
}

bool Sala::proyectaEnCine(int idCine)
{
    return this->cine != nullptr && this->cine->getId() == idCine;
}

void Sala::agregarFuncion(unique_ptr<Funcion> funcion){

}