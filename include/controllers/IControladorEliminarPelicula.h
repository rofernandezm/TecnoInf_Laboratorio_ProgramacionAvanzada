#ifndef ICONTROLADORELIMINARP_PELICULA_H
#define ICONTROLADORELIMINARP_PELICULA_H

#include <map>
#include "DtPelicula.h"

using namespace std;

class IControladorEliminarPelicula
{
public:
    virtual ~IControladorEliminarPelicula() {}

    // virtual map<string, DtPelicula> obtenerFuncionesConReserva() = 0;
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual void seleccionarPelicula(string) = 0;
    virtual bool confirmarEliminacion() = 0;
    virtual void cancelarCU() = 0;
};

#endif
