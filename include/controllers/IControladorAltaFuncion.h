#ifndef ICONTROLADORALTAFUNCION_H
#define ICONTROLADORALTAFUNCION_H

#include <map>
#include <string>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"

using namespace std;

class IControladorAltaFuncion
{
public:
    virtual ~IControladorAltaFuncion() {};
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual map<int, DtCine> elegirPelicula(string) = 0;
    virtual map<int, DtSala> elegirCine(int) = 0;
    virtual void elegirSala(int, DtFecha, DtHorario) = 0;
    virtual void confirmarAlta() = 0;
    virtual void cancelarCU() = 0;
    virtual void cargarDatos() = 0;
};

#endif
