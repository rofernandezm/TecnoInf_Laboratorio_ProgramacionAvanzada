#ifndef ICONTROLADORRESERVA_PELICULA_H
#define ICONTROLADORRESERVA_PELICULA_H

#include <map>
#include "DtPelicula.h"

using namespace std;

class IControladorReservaPelicula {
public:
    virtual ~IControladorReservaPelicula() {}
    virtual map<string, DtPelicula> obtenerFuncionesConReserva() = 0;
};

#endif
