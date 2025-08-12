#ifndef ICONTROLADORVERINFORMACIONPELICULA_H
#define ICONTROLADORVERINFORMACIONPELICULA_H

#include "DtDireccion.h"
#include "DtCine.h"
#include "DtPelicula.h"
#include "DtSala.h"
#include "Pelicula.h"
using namespace std;

class IControladorVerInformacionPelicula
{
public:
    virtual ~IControladorVerInformacionPelicula(){};
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual DtPelicula seleccionarPelicula(string titulo) = 0;
    virtual map<int, DtCine> listarCines() = 0;
    virtual map<int, DtFuncion> listarFunciones(int idCine, DtFecha fechaActual) = 0;
    virtual void cancelarCU() = 0;
    virtual void seleccionarCine(int idCine) = 0;

};

#endif