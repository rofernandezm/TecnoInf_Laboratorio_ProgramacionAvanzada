#include "DtUsuario.h"

DtUsuario::DtUsuario(string nombre, string contra, TipoUsuario tipoUsuario) : nombre(nombre), contra(contra), tipoUsuario(tipoUsuario) {}

DtUsuario::DtUsuario(string nombre, string contra, string urlFoto, TipoUsuario tipoUsuario) : nombre(nombre), contra(contra), urlFoto(urlFoto), tipoUsuario(tipoUsuario) {}

// Getters
string DtUsuario::getNombre()
{
    return this->nombre;
}

string DtUsuario::getContra()
{
    return this->contra;
}

string DtUsuario::getUrlFoto()
{
    return this->urlFoto;
}

TipoUsuario DtUsuario::getTipoUsuario()
{
    return this->tipoUsuario;
}

DtUsuario::~DtUsuario() {}