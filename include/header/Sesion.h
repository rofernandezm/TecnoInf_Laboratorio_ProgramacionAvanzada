#ifndef SESION_H
#define SESION_H

#include <memory>
#include "Usuario.h"

class Sesion
{

private:
    static Sesion *instancia;
    Sesion();
    ~Sesion();

    bool sesionIniciada;
    Usuario *usuarioActivo;

public:
    static Sesion *getInstanciaSesion();

    // Getters
    Usuario *getUsuario();
    bool getSesionIniciada();

    // Setters
    void setUsuario(Usuario *);

    // Others
    void removeUsuario();
};

#endif
