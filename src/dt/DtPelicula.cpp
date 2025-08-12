#include "DtPelicula.h"

DtPelicula::DtPelicula() {}
DtPelicula::DtPelicula(string titulo, string sinopsis, string poster) : titulo(titulo), sinopsis(sinopsis), poster(poster) {}
DtPelicula::~DtPelicula() {}

// Getters
string DtPelicula::getTitulo()
{
    return this->titulo;
}

string DtPelicula::getSinopsis()
{
    return this->sinopsis;
}

string DtPelicula::getPoster()
{
    return this->poster;
}

// float DtPelicula::getPuntajePromedio() {} // Pendiente evaluacion