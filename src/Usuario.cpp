#include "Usuario.h"
#include "Puntaje.h"
#include "Comentario.h"

Usuario::Usuario()
{
}

Usuario::Usuario(string nombre, string contra, TipoUsuario tipoUsuario) : nombre(nombre), contra(contra), tipoUsuario(tipoUsuario) {}

Usuario::Usuario(string nombre, string contra, string url, TipoUsuario tipoUsuario) : nombre(nombre), contra(contra), urlFoto(url), tipoUsuario(tipoUsuario) {}

Usuario::~Usuario()
{
}

// Métodos getters

string Usuario::getNombre()
{
    return nombre;
}

string Usuario::getContra()
{
    return contra;
}

string Usuario::getUrlFoto()
{
    return urlFoto;
}

TipoUsuario Usuario::getTipoUsuario()
{
    return this->tipoUsuario;
}

// Métodos setters

void Usuario::setNombre(string n)
{
    nombre = n;
}

void Usuario::setContra(string c)
{
    contra = c;
}

void Usuario::setUrlFoto(string f)
{
    urlFoto = f;
}

void Usuario::setTipoUsuario(TipoUsuario tipoUsuario)
{
    this->tipoUsuario = tipoUsuario;
}

bool Usuario::validarContra(string c)
{
    return contra == c;
}
