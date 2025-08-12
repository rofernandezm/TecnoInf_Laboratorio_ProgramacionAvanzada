
#ifndef CONTROLADORVERRESERVAPELICULA_H
#define CONTROLADORVERRESEVAPELICULA_H

#include <set>
#include <map>
#include <memory>
#include "../dt/DtReserva.h"
#include "../dt/DtPelicula.h"
#include "../header/Pelicula.h"
#include "IControladorVerReservaPelicula.h"
#include "../include/controllers/ControladorAltaFuncion.h"
#include "../include/dt/DtDebito.h"
#include "../include/dt/DtCredito.h"
#include "../include/header/ManejadorPelicula.h"


using namespace std;

class ControladorVerReservaPelicula : public IControladorVerReservaPelicula
{
private:
    static ControladorVerReservaPelicula *instancia;
    ControladorVerReservaPelicula();
    ~ControladorVerReservaPelicula();
    Pelicula *pelicula;

public:
    static ControladorVerReservaPelicula* getInstancia();
    map<int, DtReserva*> listarFuncionesConReserva();
    void seleccionarPelicula(string);
    map<string, DtPelicula> listarPeliculas();
};

#endif