#include "../controllers/ControladorAltaFuncion.h"
#include "../include/header/ManejadorPelicula.h"
#include "../include/dt/DtPelicula.h"

ControladorAltaFuncion *ControladorAltaFuncion::instancia = nullptr;

ControladorAltaFuncion *ControladorAltaFuncion::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorAltaFuncion();
    }
    return instancia;
}

ControladorAltaFuncion::ControladorAltaFuncion() {}
ControladorAltaFuncion::~ControladorAltaFuncion() {}

map<string, DtPelicula> ControladorAltaFuncion::listarPeliculas()
{
    return ManejadorPelicula::getInstancia()->listarPeliculas();
}

// Se optima flujo ya que pelicula->ListarCines() se lo pide al manejador. Ahora solo se controla existencia de pelicula, luego se listan.
map<int, DtCine> ControladorAltaFuncion::elegirPelicula(string titulo)
{
    Pelicula *pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (!pelicula)
    {
        throw invalid_argument("\n#### [ERROR] - Pelicula no encontrada o no existe. ####\n");
        // instancia->pelicula = pelicula;
        // return instancia->pelicula->listarCines();
    }
    this->pelicula = pelicula;
    return ManejadorCine::getInstancia()->listarCines();
}
map<int, DtSala> ControladorAltaFuncion::elegirCine(int idCine)
{
    auto cine = ManejadorCine::getInstancia()->buscarCine(idCine);
    if (!cine)
    {
        throw invalid_argument("\n#### [ERROR] - No se encontro un cine para el id indicado. ####\n");
    }
    this->cine = cine;
    return cine->listarSalas();

    // if (cine != nullptr)
    // {

    // }
    // else
    // {

    //     return {};
    // }
}
void ControladorAltaFuncion::elegirSala(int idSala, DtFecha fecha, DtHorario hora)
{
    this->sala = cine->getSala(idSala);
    if (!this->sala)
    {
        throw invalid_argument("\n#### [ERROR] - Sala no encontrada o no existe. ####\n");
    }
    this->fecha = fecha;
    this->horario = hora;
}
void ControladorAltaFuncion::confirmarAlta()
{
    bool existeFuncion = false;
    if (this->pelicula->tieneFunciones())
    {
        for (auto funcion : this->pelicula->obtenerFunciones())
        {
            if (!existeFuncion)
            {
                bool igualFecha = funcion->getDia().esIgual(this->fecha);
                bool igualSala = funcion->getSala()->getId() == this->sala->getId();
                bool igualCine = funcion->getSala()->getCine()->getId() == this->cine->getId();

                existeFuncion = true && igualSala && igualFecha && igualCine;
                break;
            }
        }
    }
    if (existeFuncion)
    {
        this->cancelarCU();
        throw invalid_argument("\n#### [ERROR] - Ya existe una funcion para la pelicula en la fecha, cine y sala indicados. ####\n");
    }
    this->pelicula->agregarFuncion(make_unique<Funcion>(this->fecha, this->horario, this->sala));
    this->pelicula->agregarCine(this->cine);
    // Limpia memoria
    this->sala = nullptr;
    this->cine = nullptr;
    this->fecha = DtFecha();
    this->horario = DtHorario();
}
void ControladorAltaFuncion::cancelarCU()
{
    this->sala = nullptr;
    this->pelicula = nullptr;
    this->cine = nullptr;
    this->fecha = DtFecha();
    this->horario = DtHorario();
}

void ControladorAltaFuncion::cargarDatos()
{
    map<int, DtCine> cines = ManejadorCine::getInstancia()->listarCines();
    map<string, DtPelicula> peliculas = ManejadorPelicula::getInstancia()->listarPeliculas();

    for (auto pelicula : peliculas)
    {
        Pelicula *p = ManejadorPelicula::getInstancia()->buscarPelicula(pelicula.first);
        if (p)
        {
            for (auto cine : cines)
            {
                Cine *c = ManejadorCine::getInstancia()->buscarCine(cine.second.getId());
                int salaId = getRandomInRange(0, 5);
                Sala *s = c->getSala(salaId);
                Funcion *f = new Funcion(DtFecha(20, 07, 2025), DtHorario("21:00", "23:00"), s);
                p->agregarFuncion(unique_ptr<Funcion>(f));
                p->agregarCine(c);
            }
        }
    }
}