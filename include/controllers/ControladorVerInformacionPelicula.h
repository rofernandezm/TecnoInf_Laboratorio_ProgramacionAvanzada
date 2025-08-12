#ifndef CONTROLADORVERINFORMACIONPELICULA_H
#define CONTROLADORVERINFORMACIONPELICULA_H

#include <string>
#include <map>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtFuncion.h"
#include "Pelicula.h"
#include "IControladorVerInformacionPelicula.h"

using namespace std;
class ControladorVerInformacionPelicula : public IControladorVerInformacionPelicula
{
private:
    static ControladorVerInformacionPelicula *instancia;
    Pelicula *peliculaSeleccionada;
    Cine *cineSeleccionado;
    ControladorVerInformacionPelicula();

public:
    static ControladorVerInformacionPelicula *getInstancia();
    ~ControladorVerInformacionPelicula();
    map<string, DtPelicula> listarPeliculas();
    DtPelicula seleccionarPelicula(string titulo);
    map<int, DtCine> listarCines();
    map<int, DtFuncion> listarFunciones(int idCine, DtFecha fechaActual);
    void seleccionarCine(int idCine);
    void cancelarCU();
};

#endif
