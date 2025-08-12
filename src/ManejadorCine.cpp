
#include "ManejadorCine.h"

ManejadorCine *ManejadorCine::instancia = nullptr;

ManejadorCine::ManejadorCine() {}

ManejadorCine *ManejadorCine::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ManejadorCine();
        instancia->idCine = -1;
    }
    return instancia;
}

void ManejadorCine::agregarCine(Cine *cine)
{
    this->idCine += 1;
    cine->setId(this->idCine);
    this->cines.insert(make_pair(cine->getId(), unique_ptr<Cine>(cine))); //[cine->getId()] = unique_ptr<Cine>(cine);
}

bool ManejadorCine::existeCine(int id)
{
    return instancia->cines.find(id) != instancia->cines.end();
}

Cine *ManejadorCine::buscarCine(int id)
{
    auto it = instancia->cines.find(id);
    return it != instancia->cines.end() ? it->second.get() : nullptr;
}

ManejadorCine::~ManejadorCine()
{
    instancia->cines.clear();
}

std::map<int, DtCine> ManejadorCine::listarCines()
{
    std::map<int, DtCine> rtn;
    for (auto &cine : instancia->cines)
    {
        rtn[cine.first] = DtCine(cine.second->getId(), cine.second->getDireccion());
    }
    return rtn;
}