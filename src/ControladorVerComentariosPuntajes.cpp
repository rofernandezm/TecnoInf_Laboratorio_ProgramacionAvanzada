#include "../include/controllers/ControladorVerComentariosPuntajes.h"
#include "../include/controllers/ControladorAltaFuncion.h"
#include "ManejadorPelicula.h"
#include <functional>

ControladorVerComentariosPuntajes *ControladorVerComentariosPuntajes::instancia = nullptr;

ControladorVerComentariosPuntajes *ControladorVerComentariosPuntajes::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorVerComentariosPuntajes();
    }
    return instancia;
}

ControladorVerComentariosPuntajes::ControladorVerComentariosPuntajes() {}
ControladorVerComentariosPuntajes::~ControladorVerComentariosPuntajes() {}

map<string, DtPelicula> ControladorVerComentariosPuntajes::listarPeliculas()
{
    return ControladorAltaFuncion::getInstancia()->listarPeliculas();
}

void ControladorVerComentariosPuntajes::seleccionaPelicula(string titulo)
{

    listarComentariosYPuntajes(titulo);
}

void printPathSymbol(bool lastValid)
{
    if (!lastValid)
    {
        cout << "├── ";
    }
    else
    {
        cout << "└── ";
    }
}

// Función recursiva para imprimir comentarios en árbol
void imprimirComentarios(Comentario *comentario, int nivel, bool ultimoValido)
{
    if (nivel > 0)
    {
        if (nivel == 1)
        {
            printPathSymbol(ultimoValido);
        }
        else
        {
            cout << "│ ";
            for (int ind = 1; ind < nivel; ind++)
            {
                cout << "  ";
            }
            printPathSymbol(ultimoValido);
        }
    }

    cout << comentario->getAutor()->getNombre() << ": " << comentario->getTexto() << endl;
    for (const auto &par : comentario->getRespuestas())
    {
        auto lastValid = --comentario->getRespuestas().end();
        imprimirComentarios(par.second.get(), nivel + 1, (par.second == lastValid->second));
    }
}

void ControladorVerComentariosPuntajes::listarComentariosYPuntajes(const string &titulo)
{
    auto pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (!pelicula)
    {
        cout << "Pelicula no encontrada." << endl;
        return;
    }

    // Título y puntaje promedio
    double promedio = pelicula->obtenerPromedioPuntajes();
    auto puntajes = pelicula->getPuntajes();
    cout << "##### " << pelicula->getTitulo() << " #####" << endl;
    cout << "Puntaje promedio: " << promedio << " (" << puntajes.size() << " usuarios)" << endl
         << endl;
    cout << "[Comentarios]" << endl;

    // Imprimir comentarios raíz
    for (const auto &par : pelicula->getComentarios())
    {
        auto lastValid = --pelicula->getComentarios().end();
        imprimirComentarios(par.second.get(), 0, (par.second == lastValid->second));
    }

    // Puntajes
    cout << "\n[Puntajes]" << endl;
    for (const auto &puntajePtr : puntajes)
    {
        cout << puntajePtr->getUsuario()->getNombre() << ": " << puntajePtr->getValor() << endl;
    }
}
