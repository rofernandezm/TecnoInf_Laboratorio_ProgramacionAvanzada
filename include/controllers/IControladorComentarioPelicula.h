#ifndef ICONTROLADORCOMENTARIOPELICULA_H
#define ICONTROLADORCOMENTARIOPELICULA_H

#include <map>
#include <string>
#include "DtPelicula.h"
#include "DtComentario.h"

using namespace std;

class IControladorComentarioPelicula
{
public:
    virtual map<string, DtPelicula> listarPeliculas() = 0;
    virtual map<int, DtComentario> seleccionarPelicula(string) = 0;
    virtual void seleccionarComentario(int) = 0;
    virtual void ingresarComentario(string) = 0;
    virtual void responderComentario(string) = 0;
    virtual void cancelarCU() = 0;
    virtual void cargarDatos() = 0;
    virtual ~IControladorComentarioPelicula() {};
};

#endif
