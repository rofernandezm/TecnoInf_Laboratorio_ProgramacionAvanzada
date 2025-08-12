#include "ManejadorPelicula.h"
#include <map>
ManejadorPelicula *ManejadorPelicula::instancia = nullptr;

ManejadorPelicula *ManejadorPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ManejadorPelicula();
    }
    return instancia;
}

ManejadorPelicula::ManejadorPelicula() {}

ManejadorPelicula::~ManejadorPelicula()
{
    instancia->peliculas.clear();
}

bool ManejadorPelicula::existePelicula(string titulo)
{
    return instancia->peliculas.find(titulo) != instancia->peliculas.end();
}

void ManejadorPelicula::agregarPelicula(unique_ptr<Pelicula> pelicula)
{
    instancia->peliculas[pelicula->getTitulo()] = move(pelicula);
}

Pelicula *ManejadorPelicula::buscarPelicula(string titulo)
{
    auto p = instancia->peliculas.find(titulo);
    if (p != instancia->peliculas.end())
    {
        return p->second.get();
    }
    return nullptr;
}

map<string, DtPelicula> ManejadorPelicula::listarPeliculas()
{
    map<string, DtPelicula> listadoPeliculas;
    for (const auto &pelicula : instancia->peliculas)
    {
        if (pelicula.second)
        {
            DtPelicula dt = DtPelicula(pelicula.second->getTitulo(), pelicula.second->getSinopsis(), pelicula.second->getPoster());
            listadoPeliculas[pelicula.first] = dt;
        }
    }
    return listadoPeliculas;
}

void ManejadorPelicula::removerPelicula(string titulo)
{
    peliculas.erase(titulo);
}
