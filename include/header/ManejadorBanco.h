#ifndef MANEJADORBANCO_H
#define MANEJADORBANCO_H

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include "Banco.h"
#include "Financiera.h"

using namespace std;

class ManejadorBanco
{
private:
    static ManejadorBanco *instancia;
    ManejadorBanco();
    ~ManejadorBanco();

    map<string, unique_ptr<Banco>> bancos;
    void cargaDatos();

public:
    static ManejadorBanco *getInstancia();

    void agregarBanco(unique_ptr<Banco> banco);
    bool existeBanco(string nombreBanco);
    Banco *obtenerBanco(string nombre);
    set<Banco *> obtenerBancos();
    set<string> listarNombres(); // devuelve el conjunto de claves (nombres)
};

#endif
