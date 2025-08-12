#ifndef CONTROLADORVERCOMENTARIOSPUNTAJES_H
#define CONTROLADORVERCOMENTARIOSPUNTAJES_H


#include <map>
#include <string>
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "IControladorVerComentariosPuntajes.h"

class ControladorVerComentariosPuntajes : public IControladorVerComentariosPuntajes
{
private:
    static ControladorVerComentariosPuntajes* instancia;
    ControladorVerComentariosPuntajes();
    ~ControladorVerComentariosPuntajes();

public:
    static ControladorVerComentariosPuntajes* getInstancia();
    map<string, DtPelicula> listarPeliculas();
    void seleccionaPelicula(string);
    void listarComentariosYPuntajes(const string& titulo);

};

#endif