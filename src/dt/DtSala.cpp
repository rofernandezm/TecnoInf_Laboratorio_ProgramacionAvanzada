#include "DtSala.h"
#include <sstream>

DtSala::DtSala() : id(-1), capacidad(0){}
DtSala::DtSala(int id, int capacidad) : id(id), capacidad(capacidad) {}
DtSala::~DtSala() {}

// Getters
int DtSala::getId()
{
    return this->id;
}

int DtSala::getCapacidad()
{
    return this->capacidad;
}

string DtSala::toString() {
    ostringstream oss;
    oss << "Sala ID: " << id << ", Capacidad: " << capacidad;
    return oss.str();
}