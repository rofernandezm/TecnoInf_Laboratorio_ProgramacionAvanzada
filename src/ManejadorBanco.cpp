#include "ManejadorBanco.h"

ManejadorBanco *ManejadorBanco::instancia = nullptr;

ManejadorBanco *ManejadorBanco::getInstancia()
{
    if (!instancia)
    {
        instancia = new ManejadorBanco();
        instancia->cargaDatos();
    }
    return instancia;
}

void ManejadorBanco::cargaDatos()
{
    vector<string> cargaBancos = {"SANTANDER", "ITAU", "BROU", "BBVA"};
    map<string, float> cargaFinancieras = {{"CREDITEL", 0.2}, {"PRONTO", 0.1}, {"OCA", 0.3}};
    for (string str : cargaBancos)
    {
        unique_ptr<Banco> banco = make_unique<Banco>(str);
        instancia->agregarBanco(move(banco));
    }
    for (auto &financiera : cargaFinancieras)
    {
        unique_ptr<Financiera> nuevaFin = make_unique<Financiera>(financiera.first, financiera.second);
        instancia->agregarBanco(move(nuevaFin));
    }
}

ManejadorBanco::ManejadorBanco() {}

ManejadorBanco::~ManejadorBanco() {}

void ManejadorBanco::agregarBanco(unique_ptr<Banco> banco)
{
    instancia->bancos[banco->getNombre()] = move(banco);
}

bool ManejadorBanco::existeBanco(string nombreBanco)
{
    return bancos.find(nombreBanco) != bancos.end();
}

Banco *ManejadorBanco::obtenerBanco(string nombre)
{
    return instancia->bancos.find(nombre)->second.get();
}

set<string> ManejadorBanco::listarNombres()
{
    set<string> rtn;
    for (auto &banco : instancia->bancos)
    {
        rtn.insert(banco.first);
    }
    return rtn;
}

set<Banco *> ManejadorBanco::obtenerBancos()
{
    set<Banco *> rtn;
    for (auto &banco : bancos)
    {
        rtn.insert(banco.second.get());
    }
    return rtn;
}