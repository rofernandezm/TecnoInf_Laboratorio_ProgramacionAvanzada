#include "ControladorAltaUsuario.h"

ControladorAltaUsuario *ControladorAltaUsuario::instancia = nullptr;

ControladorAltaUsuario *ControladorAltaUsuario::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorAltaUsuario();
    }
    return instancia;
}

ControladorAltaUsuario::ControladorAltaUsuario() {}

ControladorAltaUsuario::~ControladorAltaUsuario() {}

string ControladorAltaUsuario::getNombreUsuario()
{
    return instancia->nombreUsuario;
}

string ControladorAltaUsuario::getContra()
{
    return instancia->contra;
}

string ControladorAltaUsuario::getUrlFotoPerfil()
{
    return instancia->urlFotoPerfil;
}

void ControladorAltaUsuario::setNombreUsuario(string user)
{
    instancia->nombreUsuario = user;
}

void ControladorAltaUsuario::setContra(string contra)
{
    instancia->contra = contra;
}

bool ControladorAltaUsuario::ingresoUsuario(string user)
{
    bool existeUser = ControladorSesion::getInstancia()->existeUsuario(user);

    // Si no existe lo guarda en memoria
    if (!existeUser)
    {
        instancia->nombreUsuario = user;
    }

    return !existeUser;
}

// Similar a setter. Se respeta colaboracion (No se usara excepcion, sino loop en main para no romper flujo por contrasenia vacia)
void ControladorAltaUsuario::ingresoContrasenia(string contra)
{

    // if(contra.empty()){
    //     throw new invalid_argument("\n#### [ERROR] - Contraseña invalida. ####\n");
    // }
    instancia->contra = contra;
}

void ControladorAltaUsuario::ingresoFotoPerfil(string urlFoto)
{
    instancia->urlFotoPerfil = urlFoto;
}
// OPERACION DE CONTROLADOR REALIZA MISMA ACCION. [REDUNDANTE]
// void ControladorAltaUsuario::setUrlFotoPefil(string url){
//     instancia->urlFotoPerfil = url;
// }

void ControladorAltaUsuario::cancelarCU()
{
    instancia->nombreUsuario = "";
    instancia->contra = "";
    instancia->urlFotoPerfil = "";
    instancia->nuevoAdminUser = false;
}

void ControladorAltaUsuario::confirmarAlta()
{

    unique_ptr<Usuario> u = make_unique<Usuario>();
    u->setNombre(instancia->nombreUsuario);
    u->setContra(instancia->contra);
    u->setUrlFoto(instancia->urlFotoPerfil);
    TipoUsuario tipo = instancia->nuevoAdminUser ? TipoUsuario::ADMIN : TipoUsuario::BASICO;
    u->setTipoUsuario(tipo);

    ControladorSesion::getInstancia()->agregarUsuario(move(u));
    instancia->cancelarCU(); // LIBERA MEMORIA
}

void ControladorAltaUsuario::esUsuarioAdmin(bool nuevoAdminUser)
{
    instancia->nuevoAdminUser = nuevoAdminUser;
}

bool ControladorAltaUsuario::getNuevoAdminUser()
{
    return instancia->nuevoAdminUser;
}