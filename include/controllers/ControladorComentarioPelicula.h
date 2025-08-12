#ifndef CONTROLADORCOMENTARIOPELICULA_H
#define CONTROLADORCOMENTARIOPELICULA_H

#include "IControladorComentarioPelicula.h"
#include "Pelicula.h"
#include "Comentario.h"
#include "DtPelicula.h"
#include "DtComentario.h"
#include "ControladorSesion.h"

class ControladorComentarioPelicula : public IControladorComentarioPelicula
{
private:
    static ControladorComentarioPelicula* instancia;
    ControladorComentarioPelicula();
    ~ControladorComentarioPelicula();
    
    Pelicula *peliculaSeleccionada;
    Comentario *comentarioSeleccionado;

public:
    static ControladorComentarioPelicula *getInstancia();

    map<string, DtPelicula> listarPeliculas();
    map<int, DtComentario> seleccionarPelicula(string titulo);
    void seleccionarComentario(int idComentario);
    void ingresarComentario(string texto);
    void responderComentario(string texto);
    void cancelarCU();
    void cargarDatos();
};

#endif
