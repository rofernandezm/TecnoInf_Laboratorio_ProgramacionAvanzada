
#ifndef CONTROLADORALTAFUNCION_H
#define CONTROLADORALTAFUNCION_H

#include "../header/Pelicula.h"
#include "../header/Cine.h"
#include "../header/Sala.h"
#include "../header/Sesion.h"
#include "../header/Funcion.h"

#include "../dt/DtPelicula.h"
#include "../dt/DtCine.h"
#include "../dt/DtSala.h"
#include "IControladorAltaFuncion.h"
#include "ManejadorCine.h"
#include <stdlib.h>
#include <set>
#include <string>
#include <memory>
#include <iostream>
#include <ctime>

using namespace std;

class Pelicula;
class ControladorAltaFuncion : public IControladorAltaFuncion
{
private:
    static ControladorAltaFuncion* instancia;
    ControladorAltaFuncion();
    ~ControladorAltaFuncion();
    
    Pelicula *pelicula;
    Cine *cine;
    Sala *sala;
    DtFecha fecha;
    DtHorario horario;

public:
    static ControladorAltaFuncion* getInstancia();
    map<string, DtPelicula> listarPeliculas();
    map<int, DtCine> elegirPelicula(string);
    map<int, DtSala> elegirCine(int);
    void elegirSala(int, DtFecha, DtHorario);
    void confirmarAlta();
    void cancelarCU();
    void cargarDatos();
};

#endif