#include "Pelicula.h"
#include "Usuario.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(string titulo, string sinopsis, string poster) : titulo(titulo), sinopsis(sinopsis), poster(poster) {}

Pelicula::~Pelicula()
{
    for (auto puntaje : puntajes)
    {
        delete puntaje;
    }
    this->puntajes.clear();
    this->comentarios.clear();
}

string Pelicula::getTitulo()
{
    return this->titulo;
}

string Pelicula::getSinopsis()
{
    return this->sinopsis;
}

string Pelicula::getPoster()
{
    return this->poster;
}

set<Puntaje *> Pelicula::getPuntajes()
{
    return puntajes;
}

map<int, unique_ptr<Comentario>> &Pelicula::getComentarios()
{
    return comentarios;
}

set<Cine *> Pelicula::getCines()
{
    return this->cines;
}

// Setters
void Pelicula::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void Pelicula::setSinopsis(string sinopsis)
{
    this->sinopsis = sinopsis;
}

void Pelicula::setPoster(string poster)
{
    this->poster = poster;
}

// Puntaje
Puntaje *Pelicula::obtenerPuntaje()
{

    Puntaje *rtn = nullptr;

    if (puntajes.size() > 0)
    {
        for (auto puntaje : puntajes)
        {
            if (puntaje->coincideUsuario())
            {
                rtn = puntaje;
                break;
            }
        }
    }

    // No se encontro instancia creada en el set
    if (rtn == nullptr)
    {
        rtn = new Puntaje();
        rtn->setPelicula(this);
        rtn->setUsuario(Sesion::getInstanciaSesion()->getUsuario());
    }

    this->puntajes.insert(rtn); // Se agrega a la coleccion
    return rtn;
}

void Pelicula::agregarPuntaje(Puntaje *puntaje)
{
    this->puntajes.insert(puntaje);
}

float Pelicula::obtenerPromedioPuntajes()
{
    float acc = 0.0f;
    for (auto puntaje : puntajes)
    {
        if (puntaje)
        {
            acc = +puntaje->getValor();
        }
    }

    return acc / puntajes.size(); // Un usuario solo puntua una vez, el promedio se hace por todos los puntajes en la coleccion
}

// Comentarios
void Pelicula::agregarComentario(string texto)
{
    unique_ptr<Comentario> nuevoCom = make_unique<Comentario>(texto, Sesion::getInstanciaSesion()->getUsuario(), this);
    comentarios.insert(make_pair(nuevoCom->getId(), move(nuevoCom)));
}

void Pelicula::agregarComentarioConUsuario(string texto, Usuario *u, Pelicula *p)
{
    unique_ptr<Comentario> nuevoCom = make_unique<Comentario>(texto, u, p);
    comentarios.insert(make_pair(nuevoCom->getId(), move(nuevoCom)));
}

map<int, DtComentario> Pelicula::listarComentarios()
{
    map<int, DtComentario> resultado;
    for (auto &comentario : comentarios)
    {
        if (comentario.second)
        {
            agregarComentariosYRespuestasAlMap(comentario.second.get(), resultado);
        }
    }
    return resultado;
}

// Metodo auxiliar-recursivo para devolver todos los comentarios y sus respuestas en caso de existir en el mismo map.
void Pelicula::agregarComentariosYRespuestasAlMap(Comentario *comentario, map<int, DtComentario> &resultado)
{
    resultado[comentario->getId()] = DtComentario(comentario->getId(), comentario->getTexto());
    // Recorrer respuestas y agregarlas también al map
    for (auto &respuesta : comentario->getRespuestas())
    {
        if (respuesta.second)
        {
            agregarComentariosYRespuestasAlMap(respuesta.second.get(), resultado);
        }
    }
}

// Busqueda recursiva
Comentario *Pelicula::buscarComentario(int id)
{
    // Buscar primero en los comentarios raíz
    auto it = comentarios.find(id);
    if (it != comentarios.end() && it->second)
    {
        return it->second.get();
    }
    // Si no está, buscar recursivamente en las respuestas
    for (auto &comentario : comentarios)
    {
        if (comentario.second)
        {
            Comentario *encontrado = buscarComentarioAux(comentario.second.get(), id);
            if (encontrado)
                return encontrado;
        }
    }
    return nullptr;
}

// Función auxiliar recursiva
Comentario *Pelicula::buscarComentarioAux(Comentario *comentario, int id)
{
    // Primero, buscar en las respuestas directas usando find
    auto &respuestas = comentario->getRespuestas();
    auto it = respuestas.find(id);
    if (it != respuestas.end() && it->second)
    {
        return it->second.get();
    }
    // Si no está, buscar recursivamente en las respuestas de cada respuesta
    for (auto &respuesta : respuestas)
    {
        if (respuesta.second)
        {
            Comentario *encontrado = buscarComentarioAux(respuesta.second.get(), id);
            if (encontrado)
                return encontrado;
        }
    }
    return nullptr;
}

// Cines
map<int, DtCine> Pelicula::listarCines()
{
    return ManejadorCine::getInstancia()->listarCines();
}
void Pelicula::agregarCine(Cine *c)
{
    this->cines.insert(c);
}

// Funciones
map<int, DtFuncion> Pelicula::listarFunciones(int idCine)
{
    // FALTA IMPLEMENTAR SINGLETON DE FECHA.
    DtFecha fecha = ControladorReloj::getInstancia()->getDtFecha();

    map<int, DtFuncion> listadoFunciones;

    for (auto &funcion : funciones)
    {
        if (funcion)
        {
            if (funcion->getDia().mayorIgualQueFecha(fecha))
            {
                if (funcion->getSala()->proyectaEnCine(idCine))
                {
                    listadoFunciones[funcion->getId()] = funcion->obtenerFuncion();
                }
            }
        }
    }
    return listadoFunciones;
} // Valida fecha de llamado, luego busca por salas y valida si se proyecta en cine con idCine

set<Funcion *> Pelicula::obtenerFuncionesConReserva()
{
    set<Funcion *> toReturn;
    for (const auto &f : funciones)
    {
        if (f.get()->tieneReservas())
        {
            toReturn.insert(f.get());
        }
    }
    return toReturn;
}
bool Pelicula::tieneFunciones()
{
    return funciones.size() > 0;
}
set<Funcion *> Pelicula::obtenerFunciones()
{
    set<Funcion *> toReturn;
    for (const auto &f : funciones)
    {
        toReturn.insert(f.get());
    }
    return toReturn;
}

Funcion *Pelicula::obtenerFuncion(int idFuncion)
{
    for (auto &funcion : funciones)
    {
        if (funcion->getId() == idFuncion)
        {
            return funcion.get();
        }
    }
    return nullptr;
}

// Others
void Pelicula::imprimirInfoComentariosyPuntaje()
{
    cout << endl;
    cout << this->titulo << endl;
    cout << "Puntaje promedio: " << this->obtenerPromedioPuntajes() << " (" << this->puntajes.size() << " usuarios)" << endl;
    cout << "Comentarios" << endl;

    for (auto &comentario : comentarios)
    {
        if (comentario.second)
        {
            comentario.second->imprimirComentarioYRespuestas();
        }
    }

    if (puntajes.size() > 0)
    {
        cout << "Puntajes" << endl;
        for (auto puntaje : puntajes)
        {
            if (puntaje)
            {
                cout << puntaje->getUsuario()->getNombre() << ": " << puntaje->getValor() << endl;
            }
        }
    }
}

void Pelicula::eliminarFuncionesYReservas()
{
    for (auto &f : funciones)
    {
        f->eliminarReservas(); // limpia punteros crudos de reservas
    }
    funciones.clear(); // unique_ptr se encarga de destruir las funciones
}

// 3.13 Ver Comentarios y Puntajes de Película: Imprime directo desde Pelicula, ya que debe imprimir todos los links (comentarios y puntajes)

void Pelicula::agregarFuncion(unique_ptr<Funcion> funcion)
{
    this->funciones.insert(move(funcion));
}
