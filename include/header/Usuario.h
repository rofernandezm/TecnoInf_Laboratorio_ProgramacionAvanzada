#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include <set>
#include <map>
// #include "Puntaje.h"
// #include "Comentario.h"
#include "Utils.h"

using namespace std;

class Comentario;
class Puntaje;

class Usuario {
private:
    string nombre;
    string contra;
    string urlFoto;
    TipoUsuario tipoUsuario;

    set<Comentario*> comentarios;
    Puntaje *puntaje;

public:
    Usuario();
    Usuario(string, string, TipoUsuario); //urlFoto es opcional
    Usuario(string, string, string, TipoUsuario);
    ~Usuario();

    // Setters
    void setNombre(string);
    void setContra(string);
    void setUrlFoto(string);
    void setTipoUsuario(TipoUsuario);
    void setPuntaje(Puntaje*);

    // Getters
    string getNombre();
    string getContra();
    string getUrlFoto();
    TipoUsuario getTipoUsuario();

    //Others
    bool validarContra(string);
    void agregarComentario(Comentario*);
 };

#endif