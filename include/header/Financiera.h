#ifndef FINANCIERA_H
#define FINANCIERA_H

#include <string>
#include "Banco.h"

using namespace std;

class Financiera : public Banco
{
private:
    float porcentajeDescuento;

public:
    Financiera();
    Financiera(string nombre, float porcentaje);
    ~Financiera();

    // Getters
    float getporcentajeDescuento();

    // Setters
    void setPorcentajeDescuento(float porcentaje);
};

#endif
