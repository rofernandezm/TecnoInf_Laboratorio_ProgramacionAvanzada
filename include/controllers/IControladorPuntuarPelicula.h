#ifndef ICONTROLADORPUNTUARPELICULA_H
#define ICONTROLADORPUNTUARPELICULA_H

#include <map>
#include <string>
#include "DtPelicula.h"
#include "DtPuntaje.h"

using namespace std;

class IControladorPuntuarPelicula {
public:
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual DtPuntaje seleccionarPelicula(string) = 0;
    virtual void ingresarPuntaje(int) = 0;
    virtual void cancelarCU() = 0;
    virtual ~IControladorPuntuarPelicula() {};
    virtual void cargarDatos() = 0;
};

#endif
