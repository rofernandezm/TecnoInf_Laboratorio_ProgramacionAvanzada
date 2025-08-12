#include "ControladorPuntuarPelicula.h"
#include "ControladorSesion.h"
#include "ManejadorPelicula.h"
#include "Sesion.h"

ControladorPuntuarPelicula *ControladorPuntuarPelicula::instancia = nullptr;

ControladorPuntuarPelicula *ControladorPuntuarPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorPuntuarPelicula();
    }
    return instancia;
}

ControladorPuntuarPelicula::ControladorPuntuarPelicula()
{
    this->peliculaSeleccionada = nullptr;
    this->puntaje = nullptr;
}

ControladorPuntuarPelicula::~ControladorPuntuarPelicula() {}

map<string, DtPelicula> ControladorPuntuarPelicula::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}

DtPuntaje ControladorPuntuarPelicula::seleccionarPelicula(string titulo)
{
    instancia->peliculaSeleccionada = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (!instancia->peliculaSeleccionada)
    {
        throw invalid_argument("\n#### [ERROR] - La película no está disponible o no existe. ####\n");
    }

    instancia->puntaje = instancia->peliculaSeleccionada->obtenerPuntaje();
    return DtPuntaje(instancia->puntaje->getValor(), (instancia->puntaje->getValor() > 0));
}

void ControladorPuntuarPelicula::ingresarPuntaje(int puntaje)
{
    if (!instancia->peliculaSeleccionada)
    {
        throw invalid_argument("\n#### [ERROR] - Primero debe seleccionar una película. ####\n");
    }
    instancia->puntaje->setValor(puntaje);
}

void ControladorPuntuarPelicula::cancelarCU()
{
    instancia->peliculaSeleccionada = nullptr;
    instancia->puntaje = nullptr;
}

void ControladorPuntuarPelicula::cargarDatos()
{
    // Obtener el manejador de películas
    auto manejador = ManejadorPelicula::getInstancia();
    auto peliculas = manejador->listarPeliculas();
    for (const auto &p : peliculas)
    {

        auto peli = manejador->buscarPelicula(p.first);
        string nameuser = "user" + to_string(getRandomInRange(1, 4));
        auto c = ControladorSesion::getInstancia()->getUsuario(nameuser);
        auto puntajeNuevo = new Puntaje(5, peli, c);
        peli->agregarPuntaje(puntajeNuevo);
    }
}
