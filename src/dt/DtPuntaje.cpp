#include "DtPuntaje.h"

DtPuntaje::DtPuntaje(int puntaje, bool usuarioPuntuo) : puntaje(puntaje), usuarioPuntuo(usuarioPuntuo) {}
DtPuntaje::~DtPuntaje() {}

// Getters
int DtPuntaje::getPuntaje()
{
    return this->puntaje;
}

bool DtPuntaje::yaPuntuo(){
    return this->usuarioPuntuo;
}