#ifndef CONTROLADORPUNTUARPELICULA_H
#define CONTROLADORPUNTUARPELICULA_H

#include <map>
#include <memory>
#include "IControladorPuntuarPelicula.h"
#include "DtPelicula.h"
#include "DtPuntaje.h"
#include "Pelicula.h"
#include "Usuario.h"

class ControladorPuntuarPelicula : public IControladorPuntuarPelicula
{
private:
    static ControladorPuntuarPelicula* instancia;
    ControladorPuntuarPelicula();
    ~ControladorPuntuarPelicula();
    Pelicula *peliculaSeleccionada;
    Puntaje *puntaje;

public:
    static ControladorPuntuarPelicula *getInstancia();

    map<string, DtPelicula> listarPeliculas();
    DtPuntaje seleccionarPelicula(string);
    void ingresarPuntaje(int);
    void cancelarCU();
    void cargarDatos();
};

#endif
