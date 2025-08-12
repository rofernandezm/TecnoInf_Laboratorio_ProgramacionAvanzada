
#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "IControladorSesion.h"
#include "Sesion.h"
#include "Usuario.h"
#include "Utils.h"
#include "DtUsuario.h"

using namespace std;

class ControladorSesion : public IControladorSesion
{
private:
    static ControladorSesion *instancia;
    ControladorSesion();
    ~ControladorSesion();

    map<string, unique_ptr<Usuario>> usuarios;
    string nombreUsuario;
    string contra;
    void createAdminUser();

public:
    static ControladorSesion *getInstancia();

    // Setters
    void setContra(string c);
    void setNombreUsuario(string u);

    // Getters
    string getNombreUsuario();
    string getContrasenia();
    Usuario *getUsuario(string);

    // Others
    void agregarUsuario(unique_ptr<Usuario>);
    bool existeUsuario(string);
    void removerUsuario(string);
    set<Usuario*> obtenerUsuarios();

    // Controller
    void ingresoUsuario(string);
    bool ingresoContrasenia(string);
    void iniciaSesion();
    void cerrarSesion();
    void cancelarCU();
    bool esUsuarioAdmin();
    bool existeSesionIniciada();
    void cargarDatos();
};

#endif
