#ifndef BANCO_H
#define BANCO_H

#include <string>

using namespace std;

class Banco
{
private:
    string nombre;

public:
    Banco();
    Banco(string nombre);
    virtual ~Banco();

    // Getters
    string getNombre();

    // Setters
    void setNombre(string nombre);
};

#endif
