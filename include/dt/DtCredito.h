#ifndef DTCREDITO_H
#define DTCREDITO_H

#include <string>
#include "Utils.h"
#include "DtReserva.h"

using namespace std;

class DtCredito : public DtReserva
{
private:
    float porcentajeDescuento;
    string nombreFinanciera; // Se necesita??

public:
    DtCredito(float, int, float, string);
    ~DtCredito();

    // Getters
    float getPorcentajeDescuento();
    string getNombre();

    // Others
    TipoReserva getTipoReserva(); // Retorna CREDITO
};

#endif
