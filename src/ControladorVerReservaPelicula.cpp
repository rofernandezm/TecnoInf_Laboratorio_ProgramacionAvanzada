#include "../include/controllers/ControladorVerReservaPelicula.h"

ControladorVerReservaPelicula *ControladorVerReservaPelicula::instancia = nullptr;

ControladorVerReservaPelicula *ControladorVerReservaPelicula::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorVerReservaPelicula();
    }
    return instancia;
}

ControladorVerReservaPelicula::ControladorVerReservaPelicula() {}
ControladorVerReservaPelicula::~ControladorVerReservaPelicula() {}

map<int, DtReserva*> ControladorVerReservaPelicula::listarFuncionesConReserva()
{

    map<int, DtReserva*> toReturn;
    auto funcion = instancia->pelicula->obtenerFuncionesConReserva();
    if (funcion.empty())
    {
        throw invalid_argument("No hay funciones para esta pelicula");
    }
    else
    {
        int ind = -1;
        for (const auto &f : funcion)
        {
            auto reservas = f->obtenerReservas();
            for (const auto &r : reservas)
            {
                ind += 1;
                if (r->getTipoReserva() == DEBITO)
                {

                    DtDebito *toAdd = new DtDebito(r->getCosto(), r->getCantEntradas(), r->getNombre());
                    toReturn[ind] = toAdd;
                }
                else
                {

                    DtCredito *toAdd = new DtCredito(r->getCosto(), r->getCantEntradas(), dynamic_cast<DtCredito *>(r)->getPorcentajeDescuento(), r->getNombre());
                    toReturn[ind] = toAdd;
                }
            }
        }
    }
    return toReturn;
}

void ControladorVerReservaPelicula::seleccionarPelicula(string titulo)
{
    auto p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (p)
    {
        instancia->pelicula = p;
    }
    else
    {
        throw invalid_argument("Pelicula no encontrada");
    }
}

map<string, DtPelicula> ControladorVerReservaPelicula::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}
