#include "Comentario.h"
#include "Usuario.h"
#include "Pelicula.h"

Comentario::Comentario() : autor(nullptr), pelicula(nullptr)
{
    this->id = static_cast<int>(time(nullptr));
}

Comentario::Comentario(string texto, Usuario *autor, Pelicula *pelicula) : texto(texto), autor(autor), pelicula(pelicula)
{
    this->id = static_cast<int>(time(nullptr));
}

Comentario::~Comentario()
{
    this->autor = nullptr;
    this->pelicula = nullptr;
    this->respuestas.clear();
}

int Comentario::getId()
{
    return this->id;
}

string Comentario::getTexto()
{
    return this->texto;
}

Usuario *Comentario::getAutor()
{
    return this->autor;
}

Pelicula *Comentario::getPelicula()
{
    return this->pelicula;
}

void Comentario::setPelicula(Pelicula *pelicula)
{
    this->pelicula = pelicula;
}

void Comentario::setTexto(string nuevoTexto)
{
    this->texto = nuevoTexto;
}

void Comentario::setAutor(Usuario *autor)
{
    this->autor = autor;
}

void Comentario::imprimirComentarioYRespuestas()
{

    cout << this->autor->getNombre() << ":" << this->texto << endl;
    for (auto &res : respuestas)
    {
        if (res.second)
        {
            res.second->imprimirComentarioYRespuestas();
        }
    }
}

map<int, unique_ptr<Comentario>> &Comentario::getRespuestas()
{
    return respuestas;
}

void Comentario::agregarRespuesta(unique_ptr<Comentario> respuesta)
{
    this->respuestas[respuesta->getId()] = move(respuesta);
}