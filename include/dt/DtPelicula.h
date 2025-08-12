#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <string>

using namespace std;

class DtPelicula
{
private:
    string titulo;
    string sinopsis;
    // float puntajePromedio; Vas solo como operacion? como se manjea en el dt?
    string poster;

public:
    DtPelicula();
    DtPelicula(string, string, string);
    ~DtPelicula();

    // Getters
    string getTitulo();
    string getSinopsis();
    string getPoster();
    // float getPuntajePromedio(); // Pendiente evaluacion
};

#endif