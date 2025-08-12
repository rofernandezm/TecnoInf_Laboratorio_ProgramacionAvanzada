#ifndef ICONTROLADORSESION_H
#define ICONTROLADORSESION_H

#include <memory>
#include <string>
#include "Usuario.h"

using namespace std;

class IControladorSesion
{
public:
    virtual ~IControladorSesion() {};
    virtual void agregarUsuario(unique_ptr<Usuario>) = 0;
    virtual bool existeUsuario(string) = 0;
    virtual void removerUsuario(string) = 0;
    virtual void ingresoUsuario(string) = 0;
    virtual bool ingresoContrasenia(string) = 0;
    virtual void iniciaSesion() = 0;
    virtual void cerrarSesion() = 0;
    virtual void cancelarCU() = 0;
    virtual bool esUsuarioAdmin() = 0;
    virtual bool existeSesionIniciada() = 0;
    virtual void cargarDatos() = 0;
};

#endif