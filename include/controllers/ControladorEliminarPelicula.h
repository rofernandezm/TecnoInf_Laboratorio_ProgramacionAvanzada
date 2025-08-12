#ifndef CONTROLADORELIMINARPELICULA_H
#define CONTROLADORELIMINARPELICULA_H

#include <map>
#include <string>
#include "DtPelicula.h"
#include "Pelicula.h"
#include "IControladorEliminarPelicula.h"

class ControladorEliminarPelicula : public IControladorEliminarPelicula
{
private:
    static ControladorEliminarPelicula *instancia;
    ControladorEliminarPelicula();
    ~ControladorEliminarPelicula();
    Pelicula *peliculaSeleccionada;

public:
    static ControladorEliminarPelicula *getInstancia();

    // Getters
    Pelicula *getPeliculaSeleccionada();

    // Setters
    void setPeliculaSeleccionada(Pelicula *pelicula);

    // Controller
    map<string, DtPelicula> listarPeliculas();
    void seleccionarPelicula(string);
    bool confirmarEliminacion();
    
    void cancelarCU();
};

#endif
