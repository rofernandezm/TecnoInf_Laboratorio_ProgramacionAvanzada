
#ifndef ICONTROLADORALTACINE_H
#define ICONTROLADORALTACINE_H

#include "DtDireccion.h"
#include "DtCine.h"
#include "DtPelicula.h"
#include "DtSala.h"
using namespace std;

class IControladorAltaCine
{
public:
    virtual ~IControladorAltaCine() {};
    virtual void ingresoDirCine(DtDireccion) = 0;
    virtual void ingresarSala(int) = 0;
    virtual void crearCine() = 0;
    virtual void cancelarAlta() = 0;
    virtual void cancelarCU() = 0;
    virtual void cargarDatos() = 0;
};

#endif // ICONTROLADORALTACINE_H
