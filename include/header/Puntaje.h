#ifndef PUNTAJE_H
#define PUNTAJE_H
// #include "Pelicula.h"
#include "Usuario.h"
#include "Sesion.h"

class Pelicula;
class Puntaje
{
private:
    int valor = -1; // Valor utilizado para indicar si el usuario ya puntuo o no
    Pelicula *pelicula;
    Usuario *usuario;

public:
    Puntaje();
    Puntaje(int, Pelicula *, Usuario *);
    ~Puntaje();

    // Getters
    int getValor();
    Pelicula *getPelicula();
    Usuario *getUsuario();

    // Setters
    void setValor(int);
    void setPelicula(Pelicula *);
    void setUsuario(Usuario *);

    // Others
    bool coincideUsuario();
};

#endif
