
#include "ControladorAltaPelicula.h"

ControladorAltaPelicula *ControladorAltaPelicula::instancia = nullptr;

ControladorAltaPelicula *ControladorAltaPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorAltaPelicula();
    }
    return instancia;
}

ControladorAltaPelicula::ControladorAltaPelicula() {}

ControladorAltaPelicula::~ControladorAltaPelicula() {}

// Getters

string ControladorAltaPelicula::getTitulo()
{
    return instancia->titulo;
}

string ControladorAltaPelicula::getSinopsis()
{
    return instancia->sinopsis;
}

string ControladorAltaPelicula::getPoster()
{
    return instancia->poster;
}

// Setters

void ControladorAltaPelicula::setTitulo(string titulo)
{
    instancia->titulo = titulo;
}

// Controller
bool ControladorAltaPelicula::ingresoTitulo(string titulo)
{
    bool existePeli = ManejadorPelicula::getInstancia()->existePelicula(titulo);

    // Si no existe la pelicula guarda el titulo en memoria
    if (!existePeli)
    {
        setTitulo(titulo);
    }
    return existePeli;
}

void ControladorAltaPelicula::ingresoSinopsis(string sinopsis)
{
    instancia->sinopsis = sinopsis;
}

void ControladorAltaPelicula::ingresoPoster(string poster)
{
    instancia->poster = poster;
}

void ControladorAltaPelicula::cancelarCU()
{
    instancia->titulo = "";
    instancia->sinopsis = "";
    instancia->poster = "";
}

void ControladorAltaPelicula::altaPelicula()
{
    unique_ptr<Pelicula> p = make_unique<Pelicula>();
    p->setTitulo(instancia->titulo);
    p->setSinopsis(instancia->sinopsis);
    p->setPoster(instancia->poster);

    ManejadorPelicula::getInstancia()->agregarPelicula(move(p));
    instancia->cancelarCU();
}

void ControladorAltaPelicula::cargarDatos()
{
    map<string, string> peliculas = {
        {"La Isla Siniestra", "Un detective investiga la desaparicion de una paciente en una isla remota, enfrentando una pesadilla psicologica."},
        {"El Origen", "Un ladron de sueños debe implantar una idea en la mente de un heredero, enfrentando múltiples capas de realidad."},
        {"Parasitos", "Una familia pobre se infiltra en la vida de una familia rica, desatando consecuencias inesperadas."},
        {"La La Land", "Una historia de amor entre una actriz y un músico en Los Ángeles, entre sueños y sacrificios."},
        {"Mad Max: Furia en el camino", "En un futuro postapocaliptico, un guerrero se une a una rebelde para liberar a mujeres esclavizadas."},
        {"El Gran Hotel Budapest", "Un conserje y su protegido se ven envueltos en un asesinato y una herencia en tiempos de guerra."},
        {"Coco", "Un niño se adentra en el mundo de los muertos para descubrir su legado familiar y su amor por la música."},
        {"La Teoria del Todo", "La vida de Stephen Hawking, su enfermedad y sus logros cientificos narrados desde sus años universitarios."},
        {"Ex Machina", "Un programador evalúa una inteligencia artificial avanzada y se ve envuelto en un juego de manipulacion."},
        {"La Sociedad de los Poetas Muertos", "Un profesor inspira a sus alumnos a pensar libremente en un estricto colegio de elite."}};

    string poster = "www.posterPelicula.com/";

    for (auto pelicula : peliculas)
    {
        unique_ptr<Pelicula> p = make_unique<Pelicula>();
        p->setTitulo(pelicula.first);
        p->setSinopsis(pelicula.second);
        string urlPath = regex_replace(pelicula.first, regex("\\s+"), "_");
        urlPath = regex_replace(urlPath, regex("[\\:|\\,\\.]"), "");
        p->setPoster(poster + urlPath);

        ManejadorPelicula::getInstancia()->agregarPelicula(move(p));
    }
}