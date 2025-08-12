#ifndef DTDEBITO_H
#define DTDEBITO_H

#include "DtReserva.h"
#include <string>
#include "Utils.h"

using namespace std;

class DtDebito : public DtReserva
{
private:
    string nombreBanco;

public:
    DtDebito(float, int, string);
    ~DtDebito();

    // Getters
    string getNombre();

    // Others
    TipoReserva getTipoReserva(); // Retorna DEBITO
};

#endif
