#ifndef ICONTROLADORVERRESERVAPELICULA_H
#define ICONTROLADORVERRESERVAPELICULA_H
#include <set>
#include "../dt/DtReserva.h"
#include "../dt/DtPelicula.h"
#include <string.h>
using namespace std;

class IControladorVerReservaPelicula
{
public:
    virtual ~IControladorVerReservaPelicula() {}
    virtual map<int, DtReserva*> listarFuncionesConReserva() = 0;
    virtual void seleccionarPelicula(string) = 0;
    virtual map<string, DtPelicula> listarPeliculas() = 0;
};
#endif