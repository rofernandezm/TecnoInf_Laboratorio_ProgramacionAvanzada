#ifndef ICONTROLADORVERCOMENTARIOSPUNTAJES_H
#define ICONTROLADORVERCOMENTARIOSPUNTAJES_H

#include <map>
#include <string>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"

class IControladorVerComentariosPuntajes
{
public:
    virtual ~IControladorVerComentariosPuntajes() {};
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual void seleccionaPelicula(string) = 0;
    virtual void listarComentariosYPuntajes(const string& titulo) = 0;
};

#endif