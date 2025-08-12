#include "DtFuncion.h"

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(int id, DtFecha dia, DtHorario horario) : id(id), dia(dia), horario(horario){}
DtFuncion::~DtFuncion(){}

// Getters
int DtFuncion::getId(){
    return this->id;
}
DtFecha DtFuncion::getDia(){
    return this->dia;
}
DtHorario DtFuncion::getHorario(){
    return this->horario;
}