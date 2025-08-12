#include "Puntaje.h"
#include "Pelicula.h"

Puntaje::Puntaje() : valor(0), pelicula(nullptr), usuario(nullptr) {}

Puntaje::Puntaje(int valor, Pelicula *pelicula, Usuario *usuario) : valor(valor), pelicula(pelicula), usuario(usuario) {}

Puntaje::~Puntaje()
{
    this->pelicula = nullptr;
    this->usuario = nullptr;
}

int Puntaje::getValor()
{
    return this->valor;
}

Pelicula *Puntaje::getPelicula()
{
    return this->pelicula;
}

Usuario *Puntaje::getUsuario()
{
    return this->usuario;
}

void Puntaje::setValor(int valor)
{
    this->valor = valor;
}

void Puntaje::setPelicula(Pelicula *pelicula)
{
    this->pelicula = pelicula;
}

void Puntaje::setUsuario(Usuario *usuario)
{
    this->usuario = usuario;
}

bool Puntaje::coincideUsuario()
{
    return Sesion::getInstanciaSesion()->getUsuario()->getNombre() == this->usuario->getNombre();
}