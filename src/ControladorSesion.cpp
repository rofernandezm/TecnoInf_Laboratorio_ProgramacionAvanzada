
#include "ControladorSesion.h"

ControladorSesion *ControladorSesion::instancia = nullptr;

ControladorSesion *ControladorSesion::getInstancia()
{
	if (!instancia)
	{
		instancia = new ControladorSesion();

		// Se crea el usuario administrador
		instancia->createAdminUser();
	}
	return instancia;
}

void ControladorSesion::createAdminUser()
{
	unique_ptr<Usuario> u = make_unique<Usuario>("admin", "admin", TipoUsuario::ADMIN);
	instancia->agregarUsuario(move(u));
}

ControladorSesion::ControladorSesion() {}

ControladorSesion::~ControladorSesion() {}

void ControladorSesion::setContra(string c)
{
	instancia->contra = c;
}

void ControladorSesion::setNombreUsuario(string u)
{
	instancia->nombreUsuario = u;
}

string ControladorSesion::getNombreUsuario()
{
	return instancia->nombreUsuario;
}

string ControladorSesion::getContrasenia()
{
	return instancia->contra;
}

Usuario *ControladorSesion::getUsuario(string s){
	return usuarios.find(s)->second.get();
}

void ControladorSesion::agregarUsuario(unique_ptr<Usuario> u)
{
	instancia->usuarios.insert(make_pair(u->getNombre(), move(u)));
}

bool ControladorSesion::existeUsuario(string nombreUsuario)
{
	return instancia->usuarios.find(nombreUsuario) != instancia->usuarios.end();
}

void ControladorSesion::removerUsuario(string nombreUsuario)
{
	instancia->usuarios.erase(nombreUsuario);
}

void ControladorSesion::ingresoUsuario(string nombreUsuario)
{
	if (!existeUsuario(nombreUsuario))
	{
		throw invalid_argument("\n#### [ERROR] - El usuario no existe. ####\n");
	}
	// Si existe se guarda en memoria
	instancia->nombreUsuario = nombreUsuario;
}

// No se implementa con lanzamiento de excepcion "ContraseniaInvalida" por uso de bool para retorno.
bool ControladorSesion::ingresoContrasenia(string contra)
{
	Usuario *u = instancia->usuarios.find(instancia->nombreUsuario)->second.get();

	// Valida contrasenia con usuario guardado en memoria
	bool contraEsValida = u->validarContra(contra);
	if (contraEsValida)
	{
		instancia->contra = contra;
	}

	u = nullptr;
	return contraEsValida;
}

void ControladorSesion::iniciaSesion()
{
	Sesion::getInstanciaSesion()->setUsuario(instancia->usuarios.find(instancia->nombreUsuario)->second.get());

	cout << "Has iniciado sesión correctamente. ¡Bienvenido, [" << Sesion::getInstanciaSesion()->getUsuario()->getNombre() << "]!" << endl;
	cancelarCU(); // LIBERA MEMORIA
}

void ControladorSesion::cerrarSesion()
{
	if (!Sesion::getInstanciaSesion()->getSesionIniciada())
	{
		throw invalid_argument("\n#### [ERROR] - Sesion inexistente. ####\n");
	}
	Sesion::getInstanciaSesion()->removeUsuario();
}

void ControladorSesion::cancelarCU()
{
	instancia->nombreUsuario = "";
	instancia->contra = "";
}

bool ControladorSesion::esUsuarioAdmin()
{
	return Sesion::getInstanciaSesion()->getUsuario()->getTipoUsuario() == TipoUsuario::ADMIN;
}

bool ControladorSesion::existeSesionIniciada()
{
	return Sesion::getInstanciaSesion()->getSesionIniciada();
}

void ControladorSesion::cargarDatos()
{

	map<string, string> users = {{"user1", "1234"}, {"user2", "1234"}, {"user3", "1234"}, {"user4", "1234"}};
	string urlFoto = "www.fotoPerfil.com/";
	for (auto user : users)
	{
		unique_ptr<Usuario> u = make_unique<Usuario>(user.first, user.second, urlFoto + user.first, TipoUsuario::BASICO);
		instancia->agregarUsuario(move(u));
	}
}

set<Usuario*> ControladorSesion::obtenerUsuarios(){
	set<Usuario*> toReturn;
	for(const auto& u : usuarios){
		toReturn.insert(u.second.get());
	}
	return toReturn;
}