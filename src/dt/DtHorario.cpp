#include "DtHorario.h"

#include <sstream>
#include <iomanip>


DtHorario::DtHorario() {}

DtHorario::DtHorario(string horaComienzo, string horaFin) : horaComienzo(horaComienzo), horaFin(horaFin) {}

DtHorario::~DtHorario() {}

// Getters
string DtHorario::getHoraComienzo()
{
    return this->horaComienzo;
}
string DtHorario::getHoraFin()
{
    return this->horaFin;
}

string DtHorario::toString(){
   ostringstream oss;
    oss << "Hora comienzo: " << horaComienzo << ", Hora fin: " << horaFin;
    return oss.str();
}