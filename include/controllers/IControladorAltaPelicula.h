
#ifndef ICONTROLADORALTAPELICULA_H
#define ICONTROLADORALTAPELICULA_H

#include "DtDireccion.h"
#include "DtCine.h"
#include "DtPelicula.h"
#include "DtSala.h"
using namespace std;

class IControladorAltaPelicula
{
public:
    virtual ~IControladorAltaPelicula(){};

    // Controller
    virtual bool ingresoTitulo(string) = 0;
    virtual void ingresoSinopsis(string) = 0;
    virtual void ingresoPoster(string) = 0;
    virtual void cancelarCU() = 0;
    virtual void altaPelicula() = 0;
    virtual void cargarDatos() = 0;
};

#endif // ICONTROLADORALTAPELICULA_H
