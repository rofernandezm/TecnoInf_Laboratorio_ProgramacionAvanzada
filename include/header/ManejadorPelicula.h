#ifndef MANEJADORPELICULAS_H
#define MANEJADORPELICULAS_H

#include <map>
#include <string>
#include <memory>
#include "Pelicula.h"
#include "DtPelicula.h"

using namespace std;

class ManejadorPelicula {
private:
    static ManejadorPelicula* instancia;
    map<string, unique_ptr<Pelicula>> peliculas;
    ~ManejadorPelicula();
    ManejadorPelicula(); // constructor privado

public:
    static ManejadorPelicula* getInstancia();

    bool existePelicula(string titulo);
    void agregarPelicula(unique_ptr<Pelicula>);
    Pelicula *buscarPelicula(string titulo);
    map<string, DtPelicula> listarPeliculas();
    void removerPelicula(string);
};

#endif
