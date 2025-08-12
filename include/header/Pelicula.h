#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "Cine.h"
// #include "Usuario.h"
#include "Puntaje.h"
#include "Comentario.h"
#include "Funcion.h"
#include "DtComentario.h"
#include "Sesion.h"
#include "ManejadorCine.h"
#include "ControladorReloj.h"

using namespace std;

class Pelicula
{
private:
    string titulo;
    string sinopsis;
    string poster;

    set<Puntaje *> puntajes;                      // Son compartidos con usuario
    map<int, unique_ptr<Comentario>> comentarios; // Usuario tendra referencia, pero son propiedad de la pelicula
    set<unique_ptr<Funcion>> funciones;           // Propiedad de pelicula
    set<Cine *> cines;                            // Son del manejador

    void agregarComentariosYRespuestasAlMap(Comentario *comentario, map<int, DtComentario> &resultado);
    Comentario *buscarComentarioAux(Comentario *comentario, int id);

public:
    Pelicula();
    Pelicula(string, string, string);
    ~Pelicula();

    // Getters
    string getTitulo();
    string getSinopsis();
    string getPoster();
    set<Puntaje *> getPuntajes();
    map<int, unique_ptr<Comentario>> &getComentarios();
    set<Cine *> getCines();

    // Setters
    void setTitulo(string);
    void setSinopsis(string);
    void setPoster(string);

    // Puntaje
    Puntaje *obtenerPuntaje();
    void agregarPuntaje(Puntaje *);
    float obtenerPromedioPuntajes();

    // Comentarios
    void agregarComentario(string);
    void agregarComentarioConUsuario(string, Usuario *, Pelicula *);
    map<int, DtComentario> listarComentarios();
    Comentario *buscarComentario(int id); // Busqueda recursiva

    // Cines
    map<int, DtCine> listarCines();
    void agregarCine(Cine *);

    // Funciones
    map<int, DtFuncion> listarFunciones(int idCine); // Valida fecha de llamado, luego busca por salas y valida si se proyecta en cine con idCine
    Funcion *obtenerFuncion(int);
    void agregarFuncion(unique_ptr<Funcion>);
    void eliminarFuncionesYReservas();
    set<Funcion *> obtenerFuncionesConReserva();
    set<Funcion *> obtenerFunciones();
    bool tieneFunciones();

    // Others
    void imprimirInfoComentariosyPuntaje(); // 3.13 Ver Comentarios y Puntajes de Película: Imprime directo desde Pelicula, ya que debe imprimir todos los links (comentarios y puntajes)
    void obtenerComentariosRecursivos(Comentario *comentario);
    vector<Comentario *> obtenerTodosLosComentarios();
};

#endif
