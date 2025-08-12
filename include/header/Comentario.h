#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include <ctime>
#include <string>
#include <memory>
#include <map>
// #include "Usuario.h"
// #include "Pelicula.h"

using namespace std;
class Usuario;
class Pelicula;
class Comentario
{
private:
    int id;
    string texto;
    Usuario *autor;
    Pelicula *pelicula;
    map<int, unique_ptr<Comentario>> respuestas;

public:
    Comentario();
    Comentario(string, Usuario *, Pelicula *);
    ~Comentario();

    // Getters
    int getId();
    string getTexto();
    Usuario *getAutor();
    Pelicula *getPelicula();
    map<int, unique_ptr<Comentario>>& getRespuestas();

    // Setters
    void setTexto(string texto);
    void setPelicula(Pelicula *);
    void setAutor(Usuario *);
    void agregarRespuesta(unique_ptr<Comentario>);

    // Others
    void imprimirComentarioYRespuestas();
};

#endif
