#include "DtCine.h"

DtCine::DtCine(){}
DtCine::DtCine(int id, DtDireccion direccion): id(id), direccion(direccion){}

DtCine::~DtCine(){}

//Getters
int DtCine::getId(){
    return this-> id;
}

DtDireccion DtCine::getDireccion(){
    return this->direccion;
}