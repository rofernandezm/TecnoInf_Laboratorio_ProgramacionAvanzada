#include "DtDireccion.h"

DtDireccion::DtDireccion(){}
DtDireccion::DtDireccion(int numero, string calle): numero(numero), calle(calle){}
DtDireccion::~DtDireccion(){}

//Getters
int DtDireccion::getNumero(){
    return this->numero;
}
string DtDireccion::getCalle(){
    return this->calle;
}

string DtDireccion::toString(){
    stringstream ss;
    ss << calle << " " << numero << ", esquina " << numero;
    return ss.str();
}
