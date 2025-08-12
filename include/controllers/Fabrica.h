#ifndef FABRICA_H
#define FABRICA_H

#include <memory>
#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"
#include "IControladorAltaPelicula.h"
#include "IControladorAltaCine.h"
#include "IControladorAltaFuncion.h"
#include "IControladorPuntuarPelicula.h"
#include "IControladorComentarioPelicula.h"
#include "IControladorCrearReserva.h"
#include "IControladorVerReservaPelicula.h"
#include "IControladorVerInformacionPelicula.h"
#include "IControladorReloj.h"
#include "IControladorEliminarPelicula.h"
#include "IControladorVerComentariosPuntajes.h"

using namespace std;

class Fabrica
{
private:
    static Fabrica* instancia;
    Fabrica();
    ~Fabrica();
    
public:
    static Fabrica* getInstancia();
    
    IControladorSesion* getIControladorSesion();
    IControladorAltaUsuario* getIControladorAltaUsuario();
    IControladorAltaPelicula* getIControladorAltaPelicula();
    IControladorAltaCine* getIControladorAltaCine();
    IControladorAltaFuncion* getIControladorAltaFuncion();
    IControladorPuntuarPelicula* getIControladorPuntuarPelicula();
    IControladorComentarioPelicula* getIControladorComentarioPelicula();
    IControladorVerReservaPelicula* getIControladorVerReservaPelicula();
    IControladorVerInformacionPelicula* getIControladorVerInformacionPelicula();
    IControladorCrearReserva* getIControladorCrearReserva();
    IControladorReloj * getIControladorReloj();
    IControladorEliminarPelicula* getIControladorEliminarPelicula();
    IControladorVerComentariosPuntajes* getIControladorVerComentariosPuntajes();
    
};

#endif