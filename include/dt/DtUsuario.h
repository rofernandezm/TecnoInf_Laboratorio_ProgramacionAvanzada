#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>
#include "Utils.h"

using namespace std;

class DtUsuario
{
private:
    string nombre;
    string contra;
    string urlFoto;
    TipoUsuario tipoUsuario;

public:
    DtUsuario(string, string, TipoUsuario);
    DtUsuario(string, string, string, TipoUsuario);

    //Getters
    string getNombre();
    string getContra();
    string getUrlFoto();
    TipoUsuario getTipoUsuario();
    
    ~DtUsuario();
};

#endif