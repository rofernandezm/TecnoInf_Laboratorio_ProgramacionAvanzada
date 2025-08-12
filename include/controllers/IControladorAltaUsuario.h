// IControladorAltaUsuario.h
#ifndef ICONTROLADORALTAUSUARIO_H
#define ICONTROLADORALTAUSUARIO_H

#include <string>

using namespace std;

class IControladorAltaUsuario {
public:
    virtual ~IControladorAltaUsuario() {};
    
    virtual bool ingresoUsuario(string) = 0;
    virtual void ingresoContrasenia(string) = 0;
    virtual void ingresoFotoPerfil(string) = 0;
    virtual void cancelarCU() = 0;
    virtual void confirmarAlta() = 0;
    virtual void esUsuarioAdmin(bool) = 0;
};

#endif // ICONTROLADORALTAUSUARIO_H
