
#include "ControladorAltaCine.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include "Sala.h"

ControladorAltaCine *ControladorAltaCine::instancia = nullptr;

ControladorAltaCine::ControladorAltaCine() {}

ControladorAltaCine::~ControladorAltaCine() {}

ControladorAltaCine *ControladorAltaCine::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorAltaCine();
    }
    return instancia;
}

void ControladorAltaCine::ingresarSala(int capacidad)
{
    instancia->idDtSala += 1; // No es buena practica tener un valor estatico dentro de un metodo. Esto debe gestionarse como atributo privado de la clase que tiene la coleccion
    DtSala s(idDtSala, capacidad);
    instancia->salas.insert(make_pair(idDtSala, s));
}

void ControladorAltaCine::cancelarCU()
{
    instancia->salas.clear();
}

void ControladorAltaCine::ingresoDirCine(DtDireccion dtDireccion)
{
    instancia->direccion = dtDireccion;
}

void ControladorAltaCine::cancelarAlta()
{
    instancia->direccion.~DtDireccion();
    instancia->salas.clear();
    instancia->idDtSala = -1;
}

void ControladorAltaCine::crearCine()
{

    Cine *nuevoCine = new Cine(direccion);

    for (auto &s : instancia->salas)
    {

        Sala *nuevaSala = new Sala(s.second);
        nuevaSala->setCine(nuevoCine);

        nuevoCine->agregarSala(unique_ptr<Sala>(nuevaSala));

        nuevaSala = nullptr;
    }

    ManejadorCine::getInstancia()->agregarCine(nuevoCine);
    nuevoCine = nullptr;
}

void ControladorAltaCine::cargarDatos()
{
    string dir = "Direccion_";
    map<int, DtSala> carga_salas = {{0, DtSala(0, 50)}, {1, DtSala(1, 50)}, {2, DtSala(2, 50)}, {3, DtSala(3, 50)}, {4, DtSala(4, 50)}, {5, DtSala(5, 50)}};

    for (int ind = 0; ind < 6; ind++)
    {
        Cine *nuevoCine = new Cine(DtDireccion(ind, dir + to_string(ind)));
        for (auto &s : carga_salas)
        {

            Sala *nuevaSala = new Sala(s.second);
            nuevaSala->setCine(nuevoCine);

            nuevoCine->agregarSala(unique_ptr<Sala>(nuevaSala));

            nuevaSala = nullptr;
        }

        ManejadorCine::getInstancia()->agregarCine(nuevoCine);
        nuevoCine = nullptr;
    }
}