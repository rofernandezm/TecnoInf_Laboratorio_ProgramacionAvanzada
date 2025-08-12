#include "ControladorEliminarPelicula.h"
#include "../include/header/ManejadorPelicula.h"
#include <stdexcept>
#include <string>

ControladorEliminarPelicula *ControladorEliminarPelicula::instancia = nullptr;

ControladorEliminarPelicula *ControladorEliminarPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorEliminarPelicula();
    }
    return instancia;
}

ControladorEliminarPelicula::ControladorEliminarPelicula() {}

ControladorEliminarPelicula::~ControladorEliminarPelicula() {}

Pelicula *ControladorEliminarPelicula::getPeliculaSeleccionada()
{
    return this->peliculaSeleccionada;
}

void ControladorEliminarPelicula::setPeliculaSeleccionada(Pelicula *pelicula)
{
    this->peliculaSeleccionada = pelicula;
}

map<string, DtPelicula> ControladorEliminarPelicula::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}

void ControladorEliminarPelicula::seleccionarPelicula(string tituloDePelicula)
{
    if (!ManejadorPelicula::getInstancia()->existePelicula(tituloDePelicula))
        throw invalid_argument("\n#### [ERROR] - La película no está disponible o no existe. ####\n");

    this->peliculaSeleccionada = ManejadorPelicula::getInstancia()->buscarPelicula(tituloDePelicula);
}

bool ControladorEliminarPelicula::confirmarEliminacion()
{
    if (!this->peliculaSeleccionada)
    {
        throw invalid_argument("\n#### [ERROR] - Primero debe seleccionar una película. ####\n");
    }
    this->peliculaSeleccionada->eliminarFuncionesYReservas();
    ManejadorPelicula::getInstancia()->removerPelicula(this->peliculaSeleccionada->getTitulo());
    return true;
}

void ControladorEliminarPelicula::cancelarCU()
{
    this->peliculaSeleccionada = nullptr;
}