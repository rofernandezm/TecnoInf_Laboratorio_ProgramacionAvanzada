#include "ControladorVerInformacionPelicula.h"
#include "../include/header/ManejadorPelicula.h"
#include "ManejadorCine.h"
#include <stdexcept>

ControladorVerInformacionPelicula *ControladorVerInformacionPelicula::instancia = nullptr;

ControladorVerInformacionPelicula *ControladorVerInformacionPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorVerInformacionPelicula();
    }
    return instancia;
}


ControladorVerInformacionPelicula::ControladorVerInformacionPelicula()
{
    this->peliculaSeleccionada = nullptr;
}


ControladorVerInformacionPelicula::~ControladorVerInformacionPelicula() {}

map<string, DtPelicula> ControladorVerInformacionPelicula::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}

DtPelicula ControladorVerInformacionPelicula::seleccionarPelicula(string titulo)
{
    if (!ManejadorPelicula::getInstancia()->existePelicula(titulo))
        throw invalid_argument("La película no existe.");

    peliculaSeleccionada = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    return DtPelicula(peliculaSeleccionada->getTitulo(), peliculaSeleccionada->getSinopsis(), peliculaSeleccionada->getPoster());
}

map<int, DtCine> ControladorVerInformacionPelicula::listarCines()
{
    if (!peliculaSeleccionada)
        throw invalid_argument("No hay película seleccionada.");

    // return peliculaSeleccionada->listarCinesConFunciones();
    return {};
}

map<int, DtFuncion> ControladorVerInformacionPelicula::listarFunciones(int idCine, DtFecha fechaActual)
{
    if (!peliculaSeleccionada)
        throw invalid_argument("No hay película seleccionada.");

    Cine *cine = ManejadorCine::getInstancia()->buscarCine(idCine);
    if (!cine)
        throw invalid_argument("No existe un cine con ese ID.");

    // return peliculaSeleccionada->listarFuncionesDeCineDesdeFecha(idCine, fechaActual);
    return {};
}
void ControladorVerInformacionPelicula::seleccionarCine(int idCine) {
    if (!peliculaSeleccionada)
        throw invalid_argument("No hay película seleccionada.");

    // Buscar SOLO entre los cines de la película seleccionada
    for (auto cine : peliculaSeleccionada->getCines()) {
        if (cine && cine->getId() == idCine) {
            cineSeleccionado = cine;
            return;
        }
    }
    throw invalid_argument("No existe un cine con ese ID para la película seleccionada.");
}

void ControladorVerInformacionPelicula::cancelarCU()
{
    peliculaSeleccionada = nullptr;
}
