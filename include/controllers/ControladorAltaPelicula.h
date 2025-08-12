#ifndef CONTROLADORALTAPELICULA_H
#define CONTROLADORALTAPELICULA_H
#include <string>
#include <map>
#include <regex>
#include <memory>
#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "IControladorAltaPelicula.h"

using namespace std;

class ControladorAltaPelicula : public IControladorAltaPelicula
{
private:
    static ControladorAltaPelicula *instancia;
    ControladorAltaPelicula();
    ~ControladorAltaPelicula();

    string titulo;
    string sinopsis;
    string poster;

public:
    static ControladorAltaPelicula *getInstancia();

    // Getters
    string getTitulo();
    string getSinopsis();
    string getPoster();

    // Setters
    void setTitulo(string);
    // void getSinopsis(string);
    // void getPoster(string);

    // Controller
    bool ingresoTitulo(string);
    void ingresoSinopsis(string);
    void ingresoPoster(string);
    void cancelarCU();
    void altaPelicula();
    void cargarDatos();
};

#endif