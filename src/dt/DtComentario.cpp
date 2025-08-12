#include "DtComentario.h"

DtComentario::DtComentario(){}

DtComentario::DtComentario(int id, string comentario) : id(id), comentario(comentario) {}

DtComentario::~DtComentario(){}

//Getters
int DtComentario::getId(){
    return this->id;
}
string DtComentario::getComentario(){
    return this->comentario;
}