#ifndef CONTROLADORALTAUSUARIO_H
#define CONTROLADORALTAUSUARIO_H
#include <memory>
#include <string>
#include "Sesion.h"
#include "ControladorSesion.h"
#include "IControladorAltaUsuario.h"
#include "Usuario.h"

using namespace std;

class ControladorAltaUsuario : public IControladorAltaUsuario
{
private:
    static ControladorAltaUsuario *instancia;
    ControladorAltaUsuario();
    ~ControladorAltaUsuario();

    string nombreUsuario;
    string contra;
    string urlFotoPerfil;
    bool nuevoAdminUser;

public:
    static ControladorAltaUsuario *getInstancia();

    // Getters
    string getNombreUsuario();
    string getContra();
    string getUrlFotoPerfil();
    bool getNuevoAdminUser();

    // Setters
    void setNombreUsuario(string);
    void setContra(string);

    // Controller
    bool ingresoUsuario(string);
    void ingresoContrasenia(string);
    void ingresoFotoPerfil(string);
    void cancelarCU();
    void confirmarAlta();
    void esUsuarioAdmin(bool);
};

#endif