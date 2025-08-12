#include "ControladorComentarioPelicula.h"
#include "ControladorSesion.h"
#include "ManejadorPelicula.h"
#include "Sesion.h"
#include <random>

ControladorComentarioPelicula *ControladorComentarioPelicula::instancia = nullptr;

ControladorComentarioPelicula *ControladorComentarioPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorComentarioPelicula();
    }
    return instancia;
}

ControladorComentarioPelicula::ControladorComentarioPelicula()
{
    this->peliculaSeleccionada = nullptr;
    this->comentarioSeleccionado = nullptr;
}

ControladorComentarioPelicula::~ControladorComentarioPelicula() {}

map<string, DtPelicula> ControladorComentarioPelicula::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}

map<int, DtComentario> ControladorComentarioPelicula::seleccionarPelicula(string titulo)
{
    instancia->peliculaSeleccionada = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (!instancia->peliculaSeleccionada)
        throw invalid_argument("\n#### [ERROR] - La película no está disponible o no existe. ####\n");

    return instancia->peliculaSeleccionada->listarComentarios();
}

void ControladorComentarioPelicula::seleccionarComentario(int idComentario)
{
    if (!instancia->peliculaSeleccionada)
    {
        throw invalid_argument("\n#### [ERROR] - Primero debe seleccionar una película. ####\n");
    }

    instancia->comentarioSeleccionado = instancia->peliculaSeleccionada->buscarComentario(idComentario);

    if (!instancia->comentarioSeleccionado)
    {
        throw invalid_argument("\n#### [ERROR] - Comentario solicitado no encontrado. ####\n");
    }
}

void ControladorComentarioPelicula::ingresarComentario(string texto)
{
    if (!instancia->peliculaSeleccionada)
        throw invalid_argument("Primero debe seleccionar una película.");

    instancia->peliculaSeleccionada->agregarComentario(texto);
}

void ControladorComentarioPelicula::responderComentario(string texto)
{
    if (!instancia->comentarioSeleccionado)
    {
        throw invalid_argument("\n#### [ERROR] - Comentario solicitado no encontrado. ####\n");
    }
    unique_ptr<Comentario> respuesta = make_unique<Comentario>(texto, Sesion::getInstanciaSesion()->getUsuario(), instancia->peliculaSeleccionada);
    instancia->comentarioSeleccionado->agregarRespuesta(move(respuesta));
}

void ControladorComentarioPelicula::cancelarCU()
{
    instancia->peliculaSeleccionada = nullptr;
    instancia->comentarioSeleccionado = nullptr;
}

void ControladorComentarioPelicula::cargarDatos()
{
    // Obtener el manejador de películas
    auto peliculas = ManejadorPelicula::getInstancia()->listarPeliculas();
    for (const auto &p : peliculas)
    {
        auto peli = ManejadorPelicula::getInstancia()->buscarPelicula(p.first);
        string nameuser = "user" + to_string(getRandomInRange(1, 4));
        auto c = ControladorSesion::getInstancia()->getUsuario(nameuser);
        peli->agregarComentarioConUsuario("Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...", c, peli);
    }
}
