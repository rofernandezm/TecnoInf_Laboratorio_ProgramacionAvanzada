#include "Fabrica.h"
#include "ControladorAltaCine.h"
#include "ControladorAltaFuncion.h"
#include "ControladorAltaPelicula.h"
#include "ControladorAltaUsuario.h"
#include "ControladorComentarioPelicula.h"
#include "ControladorPuntuarPelicula.h"
#include "ControladorVerReservaPelicula.h"
#include "ControladorSesion.h"
#include "ControladorVerInformacionPelicula.h"
#include "ControladorCrearReserva.h"
#include "ControladorReloj.h"
#include "ControladorEliminarPelicula.h"
#include "ControladorVerComentariosPuntajes.h"

Fabrica *Fabrica::instancia = nullptr;

Fabrica *Fabrica::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorSesion *Fabrica::getIControladorSesion()
{
    return ControladorSesion::getInstancia();
}
IControladorAltaUsuario *Fabrica::getIControladorAltaUsuario()
{
    return ControladorAltaUsuario::getInstancia();
}
IControladorAltaPelicula *Fabrica::getIControladorAltaPelicula()
{
    return ControladorAltaPelicula::getInstancia();
}
IControladorAltaCine *Fabrica::getIControladorAltaCine()
{
    return ControladorAltaCine::getInstancia();
}
IControladorAltaFuncion *Fabrica::getIControladorAltaFuncion()
{
    return ControladorAltaFuncion::getInstancia();
}
IControladorPuntuarPelicula *Fabrica::getIControladorPuntuarPelicula()
{
    return ControladorPuntuarPelicula::getInstancia();
}
IControladorComentarioPelicula *Fabrica::getIControladorComentarioPelicula()
{
    return ControladorComentarioPelicula::getInstancia();
}
IControladorVerReservaPelicula *Fabrica::getIControladorVerReservaPelicula()
{
    return ControladorVerReservaPelicula::getInstancia();
}

IControladorVerInformacionPelicula *Fabrica::getIControladorVerInformacionPelicula()
{
    return ControladorVerInformacionPelicula::getInstancia();
}

IControladorEliminarPelicula *Fabrica::getIControladorEliminarPelicula()
{
    return ControladorEliminarPelicula::getInstancia();
}

IControladorCrearReserva *Fabrica::getIControladorCrearReserva()
{
    return ControladorCrearReserva::getInstancia();
}


IControladorReloj *Fabrica::getIControladorReloj()
{
    return ControladorReloj::getInstancia();
}

IControladorVerComentariosPuntajes *Fabrica::getIControladorVerComentariosPuntajes(){
    
    return ControladorVerComentariosPuntajes::getInstancia();
}

Fabrica::~Fabrica() {}

Fabrica::Fabrica() {}