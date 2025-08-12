#include "Sesion.h"
#include <cstdlib>

Sesion *Sesion::instancia = nullptr;

Sesion *Sesion::getInstanciaSesion()
{
	if (!instancia)
	{
		instancia = new Sesion();
		instancia->sesionIniciada = false;
	}
	return instancia;
}

Sesion::Sesion() {}

Sesion::~Sesion() {}

Usuario *Sesion ::getUsuario()
{
	return instancia->usuarioActivo;
}

void Sesion ::setUsuario(Usuario *u)
{
	instancia->usuarioActivo = u;
	instancia->sesionIniciada = true;
}

void Sesion::removeUsuario()
{
	instancia->usuarioActivo = nullptr;
	instancia->sesionIniciada = false;
}

bool Sesion ::getSesionIniciada()
{
	return instancia->sesionIniciada;
}