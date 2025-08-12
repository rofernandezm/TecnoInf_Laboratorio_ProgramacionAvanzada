#include "Cine.h"

Cine::Cine()
{
    this->id = static_cast<int>(time(nullptr));
}

Cine::Cine(DtDireccion direccion) : direccion(direccion)
{
    this->id = static_cast<int>(time(nullptr));
}

Cine::Cine(DtCine dtCine) : id(dtCine.getId()), direccion(dtCine.getDireccion()) {}

Cine::~Cine()
{
    salas.clear();
}

// Getters
int Cine::getId()
{
    return this->id;
}

DtDireccion Cine::getDireccion()
{
    return this->direccion;
}
Sala* Cine::getSala(int idSala){
    Sala * toReturn = nullptr;

    for(const auto& s : salas){
        if(s->getId() == idSala){
            toReturn = s.get();
        }
    }
    return toReturn;
}


// Setters
void Cine::setId(int id)
{
    this->id = id;
}

void Cine::setDireccion(DtDireccion)
{
    this->direccion = direccion;
}

map<int, DtSala> Cine::listarSalas()
{
    map<int, DtSala> dtSalas;
    for (const auto &sala : salas)
    {
        dtSalas.insert(make_pair(sala->getId(), sala->obtenerDtSala()));
    }
    return dtSalas;
}

DtSala Cine::devolverSala(int idSala)
{
    DtSala rtn;
    for (const auto &sala : salas)
    {
        if (sala->getId() == idSala)
        {
            rtn = sala->obtenerDtSala();
            return rtn;
        }
    }
    return DtSala();
}

DtCine Cine::obtenerInfo()
{
    return DtCine(this->id, this->direccion);
};

void Cine::agregarSala(unique_ptr<Sala> s)
{
    salas.insert(move(s));
}
