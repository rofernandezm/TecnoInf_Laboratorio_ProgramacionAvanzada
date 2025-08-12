#ifndef CREDITO_H
#define CREDITO_H

#include <memory>
#include <string>
#include "Financiera.h"
#include "Reserva.h"
#include "Utils.h"

using namespace std;

class Credito : public Reserva
{
private:
    Financiera *financiera;

public:
    Credito();
    Credito(float costo, int cantEntradas, Usuario *usuario, Funcion *funcion, Financiera *financiera);
    ~Credito();

    // Getters
    Financiera *getFinanciera();

    // Setters
    void setFinanciera(Financiera *financiera);

    // Others
    string getNombre();
    TipoReserva getTipoReserva();
};

#endif
